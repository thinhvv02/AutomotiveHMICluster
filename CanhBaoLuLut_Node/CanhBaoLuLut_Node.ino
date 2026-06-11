#include <SPI.h>
#include <LoRa.h>

#define NSS_PIN    5
#define RST_PIN    14   
#define DIO0_PIN   2    

#define RAIN_PIN   34   
#define TRIG1_PIN  26   
#define ECHO1_PIN  27
#define TRIG2_PIN  32   
#define ECHO2_PIN  33

#define PIN_BUZ    13  
#define PIN_RED    12   
#define PIN_YEL    4    

volatile int alarmLevel = 0; 

struct SensorData {
  int rain;  
  int dist_hydro; 
  int dist_city;  
};
SensorData currentData;

int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH, 30000); 
  if (duration == 0) return 0; 
  return duration * 0.034 / 2;
}
 
void TaskMeasure(void *pvParameters) {
  pinMode(RAIN_PIN, INPUT);
  pinMode(TRIG1_PIN, OUTPUT); pinMode(ECHO1_PIN, INPUT);
  pinMode(TRIG2_PIN, OUTPUT); pinMode(ECHO2_PIN, INPUT);

  for (;;) {
    int rawRain = analogRead(RAIN_PIN);
    currentData.rain = map(rawRain, 4095, 0, 0, 200);
    if (currentData.rain < 0) currentData.rain = 0; 

    int d1 = getDistance(TRIG1_PIN, ECHO1_PIN);
    if (d1 > 0 && d1 < 300) currentData.dist_hydro = d1;
    else currentData.dist_hydro = 0;

    int d2 = getDistance(TRIG2_PIN, ECHO2_PIN);
    if (d2 > 0 && d2 < 300) currentData.dist_city = d2;
    else currentData.dist_city = 0;

    vTaskDelay(pdMS_TO_TICKS(1000)); 
  }
}

void TaskLoRa(void *pvParameters) {
  vTaskDelay(pdMS_TO_TICKS(1500)); 

  for (;;) {
    String packet = "DATA|" + String(currentData.rain) + "|" + 
                    String(currentData.dist_hydro) + "|" + String(currentData.dist_city);
    
    LoRa.beginPacket();
    LoRa.print(packet);
    LoRa.endPacket();
    Serial.println(">> [Node] Gui: " + packet);

    long startWait = millis();
    bool received = false;
    
    while (millis() - startWait < 800) {
      int packetSize = LoRa.parsePacket();
      if (packetSize) {
        String cmd = "";
        while (LoRa.available()) cmd += (char)LoRa.read();
        
        if (cmd.startsWith("CMD|")) {
          int level = cmd.substring(4).toInt();
          alarmLevel = level; 
          Serial.printf("<< [Node] Lenh bao dong: %d\n", level);
          received = true;
          break; 
        }
      }
      vTaskDelay(10); 
    }

    if (alarmLevel == 0) {
      Serial.println(">> Trạng thái an toàn. Vào Deep Sleep 5 giây...");
      Serial.flush(); 

      esp_sleep_enable_timer_wakeup(5 * 1000000);
      
      esp_deep_sleep_start();
    }

    vTaskDelay(pdMS_TO_TICKS(3000)); 
  }
}

void TaskAlarm(void *pvParameters) {
  pinMode(PIN_BUZ, OUTPUT); 
  pinMode(PIN_RED, OUTPUT); 
  pinMode(PIN_YEL, OUTPUT);
  
  digitalWrite(PIN_RED, LOW); 
  digitalWrite(PIN_YEL, LOW); 
  digitalWrite(PIN_BUZ, LOW);

  for (;;) {
    if (alarmLevel == 2) { 
      digitalWrite(PIN_RED, HIGH); digitalWrite(PIN_YEL, LOW); 
      digitalWrite(PIN_BUZ, HIGH); 
      vTaskDelay(pdMS_TO_TICKS(150)); 
      digitalWrite(PIN_RED, LOW); digitalWrite(PIN_BUZ, LOW);
      vTaskDelay(pdMS_TO_TICKS(150)); 
    } 
    else if (alarmLevel == 3) {
      digitalWrite(PIN_RED, HIGH); digitalWrite(PIN_YEL, LOW); 
      digitalWrite(PIN_BUZ, LOW);  
      vTaskDelay(pdMS_TO_TICKS(500)); 
      digitalWrite(PIN_RED, LOW); 
      vTaskDelay(pdMS_TO_TICKS(500)); 
    }
    else if (alarmLevel == 1) {
      digitalWrite(PIN_RED, LOW); digitalWrite(PIN_YEL, HIGH); 
      digitalWrite(PIN_BUZ, HIGH); 
      vTaskDelay(pdMS_TO_TICKS(500)); 
      digitalWrite(PIN_YEL, LOW); digitalWrite(PIN_BUZ, LOW);
      vTaskDelay(pdMS_TO_TICKS(500)); 
    } 
    else if (alarmLevel == 4) {
      digitalWrite(PIN_RED, LOW); digitalWrite(PIN_YEL, HIGH); 
      digitalWrite(PIN_BUZ, LOW);
      vTaskDelay(pdMS_TO_TICKS(1000)); 
      digitalWrite(PIN_YEL, LOW);
      vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
    else {
      digitalWrite(PIN_RED, LOW); digitalWrite(PIN_YEL, LOW); digitalWrite(PIN_BUZ, LOW);
      vTaskDelay(pdMS_TO_TICKS(200));
    }
  }
}

void setup() {
  Serial.begin(115200);
  LoRa.setPins(NSS_PIN, RST_PIN, DIO0_PIN);
  if (!LoRa.begin(433E6)) { Serial.println("LoRa Error!"); while(1); }
  
  xTaskCreate(TaskMeasure, "Measure", 2048, NULL, 1, NULL);
  xTaskCreate(TaskLoRa,    "LoRa",    4096, NULL, 2, NULL); 
  xTaskCreate(TaskAlarm,   "Alarm",   2048, NULL, 1, NULL);
}

void loop() { vTaskDelete(NULL); }