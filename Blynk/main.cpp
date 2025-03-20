// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
// Control DC Motor Using Blynk and ESP8266
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "BlynkID"
#define BLYNK_DEVICE_NAME "Fan Controller"
#define BLYNK_AUTH_TOKEN "Blynktoken**"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "WiFi Username"; // type your wifi name
char pass[] = "WiFi Password"; // type your wifi password

int M1PWM = D0;
int M1F = D1;
int M1R = D2;

int pinValue1;

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  analogWrite(M1PWM, pinValue1);
  Blynk.virtualWrite(V1, pinValue1);
  Serial.print("V1 Slider Value is ");
  Serial.println(pinValue1);
}

void setup()
{
  pinMode(M1PWM, OUTPUT);
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
