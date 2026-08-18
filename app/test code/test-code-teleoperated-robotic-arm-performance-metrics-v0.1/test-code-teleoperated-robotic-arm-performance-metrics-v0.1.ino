/*
  ESP32-WROOM-32
  Read 4 Potentiometers
*/



#define POT1 32
#define POT2 33
#define POT3 34
#define POT4 35

void setup() {
  Serial.begin(115200);

  // 12-bit ADC (0-4095)
  analogReadResolution(12);
}

void loop() {

  int p1 = analogRead(POT1);
  int p2 = analogRead(POT2);
  int p3 = analogRead(POT3);
  int p4 = analogRead(POT4);

  //p1- min: 490 and max: 3411
  //p2- min: 450 and max: 3480
  //p3- min: 445 and max: 3550
  //p4- min: 325 and max: 3450
  int servo1 = map(analogRead(POT1), 470, 3430, 0, 180);
  int servo2 = map(analogRead(POT2), 440, 3480, 0, 180);
  int servo3 = map(analogRead(POT3), 440, 3550, 0, 180);
  int servo4 = map(analogRead(POT4), 315, 3460, 0, 180);

  Serial.print("P1: ");
  Serial.print(p1);
  Serial.print("Servo-1: ");
  Serial.print(servo1);


  Serial.print("\tP2: ");
  Serial.print(p2);
  Serial.print("Servo-2: ");
  Serial.print(servo2);

  Serial.print("\tP3: ");
  Serial.print(p3);
  Serial.print("Servo-3: ");
  Serial.print(servo3);

  Serial.print("\tP4: ");
  Serial.print(p4);
  Serial.print("Servo-4: ");
  Serial.print(servo4);
  Serial.println();

  delay(20);   // 50 Hz update
}