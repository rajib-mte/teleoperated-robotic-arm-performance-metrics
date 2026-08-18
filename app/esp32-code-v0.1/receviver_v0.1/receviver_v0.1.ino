#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int cnt = 0;

#define SERVO1_PIN 18
#define SERVO2_PIN 19
#define SERVO3_PIN 21
#define SERVO4_PIN 22
#define SENSOR 4
int trig = 1;

typedef struct {

  int servo1;
  int servo2;
  int servo3;
  int servo4;

} ServoData;



ServoData data;



void OnDataRecv(
const uint8_t * mac,
const uint8_t *incomingData,
int len)

{

  memcpy(&data, incomingData, sizeof(data));


  servo1.write(data.servo1);
  servo2.write(data.servo2);
  servo3.write(data.servo3);
  servo4.write(data.servo4);



  Serial.print("Servo:");

  Serial.print(data.servo1);
  Serial.print(",");
  Serial.print(data.servo2);
  Serial.print(",");
  Serial.print(data.servo3);
  Serial.print(",");
  Serial.println(data.servo4);

}



void setup() {


  Serial.begin(115200);



  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  // servo1.write(30);
  // servo2.write(30);
  // servo3.write(30);
  // servo4.write(30);
  // delay(2000);
  // while(1){
  //   servo1.write(90);
  //   servo2.write(90);
  //   servo3.write(90);
  //   servo4.write(90);
  // }
  // pinMode(SENSOR, INPUT);
  // while(trig){
  //   if(analogRead(SENSOR) > 200) trig = 0;
  // }





  WiFi.mode(WIFI_STA);



  if(esp_now_init()!=ESP_OK)
  {
    Serial.println("ESP-NOW Failed");
    return;
  }



  esp_now_register_recv_cb(OnDataRecv);



}



void loop()
{

}