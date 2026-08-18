#include <WiFi.h>
#include <esp_now.h>


#define POT1 32
#define POT2 33
#define POT3 34
#define POT4 35


// C8:2E:18:51:73:E0

// Receiver MAC Address
uint8_t receiverMAC[] = {
  0xC8, 0x2E, 0x18, 0x51, 0x73, 0xE0
};


// Data structure
typedef struct {

  int servo1;
  int servo2;
  int servo3;
  int servo4;

} ServoData;


ServoData data;


// Send callback
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  Serial.print("Send Status: ");

  if(status == ESP_NOW_SEND_SUCCESS)
    Serial.println("Success");
  else
    Serial.println("Failed");
}



void setup() {

  Serial.begin(115200);


  analogReadResolution(12);


  WiFi.mode(WIFI_STA);


  if(esp_now_init() != ESP_OK)
  {
    Serial.println("ESP-NOW Init Failed");
    return;
  }


  esp_now_register_send_cb(OnDataSent);



  esp_now_peer_info_t peerInfo = {};

  memcpy(peerInfo.peer_addr, receiverMAC, 6);

  peerInfo.channel = 0;

  peerInfo.encrypt = false;



  if(esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    Serial.println("Failed to add peer");
    return;
  }

}



void loop() {


  int p1 = analogRead(POT1);
  int p2 = analogRead(POT2);
  int p3 = analogRead(POT3);
  int p4 = analogRead(POT4);



  data.servo1 = map(p1,470,3430,0,180);
  data.servo2 = map(p2,440,3480,0,180);
  data.servo3 = map(p3,440,3550,0,180);
  data.servo4 = map(p4,315,3460,0,180);



  esp_now_send(
    receiverMAC,
    (uint8_t *)&data,
    sizeof(data)
  );


  Serial.print("Servo-1: ");
  Serial.print(data.servo1);
  Serial.print(" | ");
  Serial.print("Servo-2: ");
  Serial.print(data.servo2);
  Serial.print(" | ");
  Serial.print("Servo-3: ");
  Serial.print(data.servo3);
  Serial.print(" | ");
  Serial.print("Servo-4: ");
  Serial.println(data.servo4);

  delay(10);  // 50Hz update rate

}