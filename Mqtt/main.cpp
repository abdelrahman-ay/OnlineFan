// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
#include "initConnection.h"
#include "mqtt.h"

bool FanSWS;
int FanPWMS;
unsigned long TlastMsg = 0;
String mqttClient = MqttClient;

void setup()
{
    Serial.begin(115200);
    initWifi();
    client.setServer(MqttBroker, MqttPort);
    client.setCallback(callback);
    // adding random string to the end of the client name to prevent duplicate names
    mqttClient = mqttClient + String(random(0xffff), HEX);
    initMqtt();
    // pin setup
    pinMode(FanSWPin, OUTPUT);
    pinMode(FanPWMPin, OUTPUT);
    FanSWS = 1;
    digitalWrite(FanSWPin, FanSWS);
    FanPWMS = 255;
    analogWrite(FanPWMPin, FanPWMS);
}
void loop()
{
    if (!client.connected())
    {
        initWifi();
        initMqtt();
    }
    client.loop();
    // keep alive
    unsigned long now = millis();
    if (now - TlastMsg > 2000)
    {
        TlastMsg = now;
        Serial.print("System alive");
    }
}