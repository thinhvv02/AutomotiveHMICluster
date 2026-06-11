// #include <Arduino.h>
// #include <ArduinoJson.h>
// #include "DFRobotDFPlayerMini.h"

// // --- 1. CẤU HÌNH CHÂN BIẾN TRỞ ---
// const int potTachoPin = 34;   
// const int potSpeedPin = 35;   

// // --- 2. CẤU HÌNH 5 NÚT NHẤN ---
// const int btnTurnLeft = 27;   
// const int btnTurnRight = 26;  
// const int btnHiBeam = 25;     
// const int btnFogLight = 33;   
// const int btnDimLight = 32;   

// // --- 3. BIẾN LƯU TRẠNG THÁI TOGGLE ---
// bool stateTurnLeft  = false;
// bool stateTurnRight = false;
// bool stateHiBeam    = false;
// bool stateFogLight  = false;  
// bool stateDimLight  = false;  

// // --- 4. BIẾN LƯU TRẠNG THÁI VẬT LÝ TRƯỚC ĐÓ ---
// int lastTurnLeft  = HIGH;
// int lastTurnRight = HIGH;
// int lastHiBeam    = HIGH;
// int lastFogLight  = HIGH;     
// int lastDimLight  = HIGH;     

// // --- 5. CẤU HÌNH DFPLAYER ---
// HardwareSerial mySerial(2);
// DFRobotDFPlayerMini player;

// unsigned long lastSendTime = 0;

// void checkButton(int pin, int &lastPhysicalState, bool &toggleState) {
//   int currentState = digitalRead(pin);
//   if (lastPhysicalState == HIGH && currentState == LOW) {
//     toggleState = !toggleState; 
//     delay(50); 
//   }
//   lastPhysicalState = currentState; 
// }

// void setup() {
//   Serial.begin(115200); 
//   mySerial.begin(9600, SERIAL_8N1, 16, 17); 

//   pinMode(btnTurnLeft, INPUT_PULLUP);
//   pinMode(btnTurnRight, INPUT_PULLUP);
//   pinMode(btnHiBeam, INPUT_PULLUP);
//   pinMode(btnFogLight, INPUT_PULLUP); 
//   pinMode(btnDimLight, INPUT_PULLUP); 

//   Serial.println("Đang khởi động phần cứng...");
//   if (!player.begin(mySerial)) {
//     Serial.println("Lỗi: Không tìm thấy DFPlayer!");
//   } else {
//     Serial.println("DFPlayer Sẵn sàng!");
//     player.volume(20);  
//   }
// }

// void loop() {
//   // CHIỀU XUỐNG: NHẬN LỆNH ĐIỀU KHIỂN NHẠC
//   if (Serial.available()) {
//     String cmd = Serial.readStringUntil('\n'); 
//     cmd.trim(); 
//     if (cmd == "play") player.start();
//     else if (cmd == "pause") player.pause();
//     else if (cmd == "next") player.next();
//     else if (cmd == "prev") player.previous();
//     else if (cmd == "vol_up") player.volumeUp();
//     else if (cmd == "vol_down") player.volumeDown();
//   }

//   // BƯỚC THÊM MỚI: Lưu lại trạng thái cũ trước khi quét nút nhấn
//   bool prevTurnLeft  = stateTurnLeft;
//   bool prevTurnRight = stateTurnRight;
//   bool prevHiBeam    = stateHiBeam;
//   bool prevFogLight  = stateFogLight;
//   bool prevDimLight  = stateDimLight;

//   // KIỂM TRA NÚT NHẤN LIÊN TỤC
//   checkButton(btnTurnLeft,  lastTurnLeft,  stateTurnLeft);
//   checkButton(btnTurnRight, lastTurnRight, stateTurnRight);
//   checkButton(btnHiBeam,    lastHiBeam,    stateHiBeam);
//   checkButton(btnFogLight,  lastFogLight,  stateFogLight); 
//   checkButton(btnDimLight,  lastDimLight,  stateDimLight); 

//   // =========================================================
//   // THÊM MỚI: LOGIC KHÓA LẪN (MUTUAL EXCLUSIVITY)
//   // =========================================================
  
//   // 1. Nhóm Xi-nhan: Nếu một bên vừa bật, bên kia bắt buộc phải tắt
//   if (stateTurnLeft && !prevTurnLeft)   stateTurnRight = false;
//   if (stateTurnRight && !prevTurnRight) stateTurnLeft = false;

//   // 2. Nhóm Đèn (Pha / Cốt / Sương mù): Chỉ 1 đèn duy nhất được sáng
//   if (stateHiBeam && !prevHiBeam) {      // Vừa bật đèn Xa
//     stateFogLight = false;
//     stateDimLight = false;
//   }
//   if (stateFogLight && !prevFogLight) {  // Vừa bật đèn Phá sương
//     stateHiBeam = false;
//     stateDimLight = false;
//   }
//   if (stateDimLight && !prevDimLight) {  // Vừa bật đèn Gần
//     stateHiBeam = false;
//     stateFogLight = false;
//   }

//   // CHIỀU LÊN: ĐỌC CẢM BIẾN & GỬI JSON LÊN QT
//   if (millis() - lastSendTime > 100) {
//     int tachoVal = analogRead(potTachoPin);
//     int speedVal = analogRead(potSpeedPin);
//     int currentTacho = map(tachoVal, 0, 4095, 0, 8);
//     int currentSpeed = map(speedVal, 0, 4095, 0, 200);

//     StaticJsonDocument<256> doc; 
//     doc["tacho"] = currentTacho;
//     doc["speed"] = currentSpeed;
//     doc["turnLeft"]  = stateTurnLeft;
//     doc["turnRight"] = stateTurnRight;
//     doc["hiBeam"]    = stateHiBeam;
//     doc["fogLight"]  = stateFogLight; 
//     doc["dimLight"]  = stateDimLight; 

//     serializeJson(doc, Serial);
//     Serial.println(); 
//     lastSendTime = millis();
//   }
// }
#include <Arduino.h>
#include <ArduinoJson.h>
#include "DFRobotDFPlayerMini.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

// =========================================================
// 1. CẤU HÌNH PHẦN CỨNG (PINOUT)
// =========================================================
const int potTachoPin = 34;   
const int potSpeedPin = 35;   

const int btnTurnLeft = 27;   
const int btnTurnRight = 26;  
const int btnHiBeam = 25;     
const int btnFogLight = 33;   
const int btnDimLight = 32;   

const int ledTurnLeft = 18;   
const int ledTurnRight = 19;  
const int ledHiBeam = 21;     
const int ledFogLight = 22;   
const int ledDimLight = 23;   

// =========================================================
// 2. KHAI BÁO BIẾN CHO HMI
// =========================================================
bool stateTurnLeft  = false;
bool stateTurnRight = false;
bool stateHiBeam    = false;
bool stateFogLight  = false;  
bool stateDimLight  = false;  

int lastTurnLeft  = HIGH;
int lastTurnRight = HIGH;
int lastHiBeam    = HIGH;
int lastFogLight  = HIGH;     
int lastDimLight  = HIGH;     

// =========================================================
// 3. CẤU TRÚC FREE-RTOS QUEUE (ĐỂ HMI GIAO TIẾP VỚI AUDIO)
// =========================================================
enum AudioCmdType {
  CMD_PLAY, CMD_PAUSE, CMD_NEXT, CMD_PREV, 
  CMD_VOL_UP, CMD_VOL_DOWN, CMD_REPEAT_ON, CMD_REPEAT_OFF, CMD_PLAY_TRACK
};

struct AudioMessage {
  AudioCmdType type;
  int trackNum; // Chỉ dùng khi type = CMD_PLAY_TRACK
};

QueueHandle_t audioQueue; // Hàng đợi chứa lệnh âm thanh

// =========================================================
// HÀM XỬ LÝ NHẤN NÚT (HỖ TRỢ RTOS)
// =========================================================
void checkButton(int pin, int &lastPhysicalState, bool &toggleState) {
  int currentState = digitalRead(pin);
  if (lastPhysicalState == HIGH && currentState == LOW) {
    toggleState = !toggleState; 
    vTaskDelay(pdMS_TO_TICKS(50)); // Dùng vTaskDelay thay cho delay() để RTOS có thể nhường CPU cho việc khác
  }
  lastPhysicalState = currentState; 
}

// =========================================================
// TASK 1: XỬ LÝ ÂM THANH (Chạy trên Core 0)
// =========================================================
void TaskAudio(void *pvParameters) {
  HardwareSerial mySerial(2);
  DFRobotDFPlayerMini player;
  
  mySerial.begin(9600, SERIAL_8N1, 16, 17); 
  
  if (!player.begin(mySerial)) {
    Serial.println("Lỗi: Không tìm thấy DFPlayer!");
  } else {
    Serial.println("DFPlayer Sẵn sàng!");
    player.volume(20);  
  }

  AudioMessage msg;

  // Vòng lặp vĩnh cửu của Task Audio
  for (;;) {
    // Chờ nhận lệnh từ Queue (Lệnh portMAX_DELAY giúp Task này "ngủ" hoàn toàn không tốn CPU cho đến khi có lệnh mới)
    if (xQueueReceive(audioQueue, &msg, portMAX_DELAY) == pdPASS) {
      switch (msg.type) {
        case CMD_PLAY: player.start(); break;
        case CMD_PAUSE: player.pause(); break;
        case CMD_NEXT: player.next(); break;
        case CMD_PREV: player.previous(); break;
        case CMD_VOL_UP: player.volumeUp(); break;
        case CMD_VOL_DOWN: player.volumeDown(); break;
        case CMD_REPEAT_ON: player.enableLoop(); break;
        case CMD_REPEAT_OFF: player.disableLoop(); break;
        case CMD_PLAY_TRACK: player.play(msg.trackNum); break;
      }
    }
  }
}

// =========================================================
// TASK 2: XỬ LÝ HMI VÀ GIAO TIẾP MÀN HÌNH QT (Chạy trên Core 1)
// =========================================================
void TaskHMI(void *pvParameters) {
  unsigned long lastSendTime = 0;

  for (;;) {
    // --- 2.1 NHẬN LỆNH TỪ QT & ĐẨY VÀO QUEUE CHO AUDIO TASK ---
    if (Serial.available()) {
      String cmd = Serial.readStringUntil('\n'); 
      cmd.trim(); 
      
      AudioMessage msgToSend;
      bool isValidCmd = true;

      if (cmd == "play") msgToSend.type = CMD_PLAY;
      else if (cmd == "pause") msgToSend.type = CMD_PAUSE;
      else if (cmd == "next") msgToSend.type = CMD_NEXT;
      else if (cmd == "prev") msgToSend.type = CMD_PREV;
      else if (cmd == "vol_up") msgToSend.type = CMD_VOL_UP;
      else if (cmd == "vol_down") msgToSend.type = CMD_VOL_DOWN;
      else if (cmd == "repeat_on") msgToSend.type = CMD_REPEAT_ON;
      else if (cmd == "repeat_off") msgToSend.type = CMD_REPEAT_OFF;
      else if (cmd.startsWith("play_track:")) {
        msgToSend.type = CMD_PLAY_TRACK;
        msgToSend.trackNum = cmd.substring(11).toInt();
      } else {
        isValidCmd = false; // Lệnh rác
      }

      if (isValidCmd) {
        // Ném lệnh vào hàng đợi, TaskAudio sẽ tự lấy ra làm
        xQueueSend(audioQueue, &msgToSend, portMAX_DELAY);
      }
    }

    // --- 2.2 ĐỌC TRẠNG THÁI NÚT NHẤN (Lưu trạng thái cũ để khóa lẫn) ---
    bool prevTurnLeft  = stateTurnLeft;
    bool prevTurnRight = stateTurnRight;
    bool prevHiBeam    = stateHiBeam;
    bool prevFogLight  = stateFogLight;
    bool prevDimLight  = stateDimLight;

    checkButton(btnTurnLeft,  lastTurnLeft,  stateTurnLeft);
    checkButton(btnTurnRight, lastTurnRight, stateTurnRight);
    checkButton(btnHiBeam,    lastHiBeam,    stateHiBeam);
    checkButton(btnFogLight,  lastFogLight,  stateFogLight); 
    checkButton(btnDimLight,  lastDimLight,  stateDimLight); 

    // --- 2.3 LOGIC KHÓA LẪN (MUTUAL EXCLUSIVITY) ---
    if (stateTurnLeft && !prevTurnLeft)   stateTurnRight = false;
    if (stateTurnRight && !prevTurnRight) stateTurnLeft = false;

    if (stateHiBeam && !prevHiBeam) {      
      stateFogLight = false; stateDimLight = false;
    }
    if (stateFogLight && !prevFogLight) {  
      stateHiBeam = false; stateDimLight = false;
    }
    if (stateDimLight && !prevDimLight) {  
      stateHiBeam = false; stateFogLight = false;
    }

    // --- 2.4 CẬP NHẬT LED VẬT LÝ ---
    digitalWrite(ledTurnLeft, stateTurnLeft ? HIGH : LOW);
    digitalWrite(ledTurnRight, stateTurnRight ? HIGH : LOW);
    digitalWrite(ledHiBeam, stateHiBeam ? HIGH : LOW);
    digitalWrite(ledFogLight, stateFogLight ? HIGH : LOW);
    digitalWrite(ledDimLight, stateDimLight ? HIGH : LOW);

    // --- 2.5 ĐỌC BIẾN TRỞ VÀ GỬI JSON (Mỗi 100ms) ---
    if (millis() - lastSendTime > 100) {
      StaticJsonDocument<256> doc; 
      doc["tacho"] = map(analogRead(potTachoPin), 0, 4095, 0, 8);
      doc["speed"] = map(analogRead(potSpeedPin), 0, 4095, 0, 200);
      doc["turnLeft"]  = stateTurnLeft;
      doc["turnRight"] = stateTurnRight;
      doc["hiBeam"]    = stateHiBeam;
      doc["fogLight"]  = stateFogLight; 
      doc["dimLight"]  = stateDimLight; 

      serializeJson(doc, Serial);
      Serial.println(); 
      lastSendTime = millis();
    }

    // Delay 10ms để nhường CPU, giúp Watchdog Timer của RTOS không bị kích hoạt lỗi
    vTaskDelay(pdMS_TO_TICKS(10)); 
  }
}

// =========================================================
// SETUP CHÍNH
// =========================================================
void setup() {
  Serial.begin(115200); 

  pinMode(btnTurnLeft, INPUT_PULLUP);
  pinMode(btnTurnRight, INPUT_PULLUP);
  pinMode(btnHiBeam, INPUT_PULLUP);
  pinMode(btnFogLight, INPUT_PULLUP); 
  pinMode(btnDimLight, INPUT_PULLUP); 

  pinMode(ledTurnLeft, OUTPUT);
  pinMode(ledTurnRight, OUTPUT);
  pinMode(ledHiBeam, OUTPUT);
  pinMode(ledFogLight, OUTPUT);
  pinMode(ledDimLight, OUTPUT);

  // Tạo hàng đợi chứa tối đa 10 lệnh Âm thanh
  audioQueue = xQueueCreate(10, sizeof(AudioMessage));

  // Tạo Task HMI trên Core 1 (ưu tiên 1)
  xTaskCreatePinnedToCore(TaskHMI, "TaskHMI", 4096, NULL, 1, NULL, 1);

  // Tạo Task Audio trên Core 0 (ưu tiên 1)
  xTaskCreatePinnedToCore(TaskAudio, "TaskAudio", 4096, NULL, 1, NULL, 0);

  // Xóa Task loop() mặc định của Arduino để giải phóng bộ nhớ RAM
  vTaskDelete(NULL); 
}

void loop() {
  // Bỏ trống hoàn toàn vì đã dùng FreeRTOS Tasks
}