#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include <DACN2_inferencing.h>


const char* ssid        = "ThinhVV";
const char* password    = "12345678";
const char* mqtt_server = "thingsboard.cloud";
const char* mqtt_token  = "TDCeh7n07VaYelUJUq0q";

#define SCK_PIN    12
#define MISO_PIN   13
#define MOSI_PIN   11
#define SS_PIN     10
#define RST_PIN    14
#define DIO0_PIN   2

#define SENSOR_HEIGHT_HYDRO 100 
#define SENSOR_HEIGHT_CITY  100 

#define MAX_RAIN   200.0
#define MAX_HYDRO  100.0 
#define MAX_CITY   100.0 

WiFiClient espClient;
PubSubClient client(espClient);
QueueHandle_t cloudQueue;

bool isMuted = false;

struct CloudPacket {
  int r; int h; int c; float risk;
};


void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (unsigned int i = 0; i < length; i++) msg += (char)payload[i];
  Serial.print(">> MQTT Recv: "); Serial.println(msg);

  if (msg.indexOf("setMute") != -1) {
    if (msg.indexOf("true") != -1) {
      isMuted = true;
      Serial.println("=> BAT CHE DO IM LANG");
    } else {
      isMuted = false;
      Serial.println("=> TAT CHE DO IM LANG (Coi keu lai)");
    }
  }
}

int run_ai_prediction(float r, float h, float c) {
    float features[3] = {r, h, c};
    signal_t signal;
    numpy::signal_from_buffer(features, 3, &signal);

    ei_impulse_result_t result;
    run_classifier(&signal, &result, false);

    String best_label = "SAFE";
    float max_score = 0.0;

    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        if (result.classification[ix].value > max_score) {
            max_score = result.classification[ix].value;
            best_label = String(result.classification[ix].label);
        }
    }
    Serial.println(">> AI: " + best_label + " (" + String(max_score*100, 1) + "%)");

    if (best_label == "DANGER") return 2;
    if (best_label == "WARNING") return 1;
    return 0;
}

void TaskLoRaService(void *pvParameters) {
  static int lastAiLevel = 0; 

  for (;;) {
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
      String recv = "";
      while (LoRa.available()) recv += (char)LoRa.read();
      Serial.println(">> LoRa Recv: " + recv);

      int idx1 = recv.indexOf('|');
      int idx2 = recv.indexOf('|', idx1 + 1);
      int idx3 = recv.indexOf('|', idx2 + 1);

      if (idx1 != -1) {
        int r = recv.substring(idx1 + 1, idx2).toInt();
        int dist_h = recv.substring(idx2 + 1, idx3).toInt(); 
        int dist_c = recv.substring(idx3 + 1).toInt();       

        int level_h = SENSOR_HEIGHT_HYDRO - dist_h;
        int level_c = SENSOR_HEIGHT_CITY - dist_c;
        if (level_h < 0) level_h = 0;
        if (level_c < 0) level_c = 0;

     
        int currentAiLevel = run_ai_prediction(r, level_h, level_c);

        if (currentAiLevel > lastAiLevel) {
           isMuted = false;
           Serial.println("!!! CAP DO TANG -> AUTO UN-MUTE !!!");
        }
        
        if (currentAiLevel == 0) {
           isMuted = false;
        }
        
        lastAiLevel = currentAiLevel; 

        int cmdToSend = currentAiLevel;
        if (isMuted) {
           if (currentAiLevel == 2) cmdToSend = 3; 
           if (currentAiLevel == 1) cmdToSend = 4; 
        }

        delay(50);
        LoRa.beginPacket();
        LoRa.print("CMD|" + String(cmdToSend));
        LoRa.endPacket();

       
        float pr = (r/MAX_RAIN)*100.0; 
        float ph = (level_h/MAX_HYDRO)*100.0;
        float pc = (level_c/MAX_CITY)*100.0;
        if(pr>100) pr=100; if(ph>100) ph=100; if(pc>100) pc=100;
        float risk_display = (pc*0.5)+(ph*0.3)+(pr*0.2);

        CloudPacket p;
        p.r = r; p.h = level_h; p.c = level_c; p.risk = risk_display;
        xQueueSend(cloudQueue, &p, 0);
      }
    }
    vTaskDelay(10);
  }
}


void TaskWiFiCloud(void *pvParameters) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { vTaskDelay(500); }
  
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback);

  CloudPacket pkt;

  for (;;) {
    if (!client.connected()) {
      if (client.connect("ESP32S3_AI_GW", mqtt_token, NULL)) {
        Serial.println("MQTT Connected!");
        client.subscribe("v1/devices/me/rpc/request/+");
      }
      else vTaskDelay(2000);
    }
    client.loop();

    if (xQueueReceive(cloudQueue, &pkt, pdMS_TO_TICKS(100)) == pdTRUE) {
      StaticJsonDocument<256> doc;
      doc["rain"] = pkt.r;
      doc["hydro"] = pkt.h; 
      doc["city"] = pkt.c;  
      doc["risk"] = pkt.risk; 
      doc["isMuted"] = isMuted; 
      
      String jsonStr;
      serializeJson(doc, jsonStr);
      client.publish("v1/devices/me/telemetry", jsonStr.c_str());
    }
    vTaskDelay(10);
  }
}

void setup() {
  Serial.begin(115200);
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);
  LoRa.setSPI(SPI);
  LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);
  if (!LoRa.begin(433E6)) { Serial.println("LoRa Error!"); while(1); }

  cloudQueue = xQueueCreate(10, sizeof(CloudPacket));

  xTaskCreatePinnedToCore(TaskLoRaService, "LoRaAI", 10240, NULL, 2, NULL, 1);
  xTaskCreatePinnedToCore(TaskWiFiCloud, "Cloud", 8192, NULL, 1, NULL, 0);
  
  Serial.println("He thong AI Gateway San Sang!");
}

void loop() { vTaskDelete(NULL); }