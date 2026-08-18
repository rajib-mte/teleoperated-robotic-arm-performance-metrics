#include <WiFi.h>

void setup()
{
  Serial.begin(115200);

  delay(2000);

  Serial.println("ESP32 Started");

  WiFi.mode(WIFI_STA);

  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop()
{

}