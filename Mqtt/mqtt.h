// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
#ifndef MQTT_H
#define MQTT_H
#include <PubSubClient.h>
#define FSWMsg "Fan SW"
#define FPWMMsg "Fan PWM"

#define initialBufferSize 50
#define FanSWPin 1
#define FanPWMPin 3
extern bool FanSWS;
extern int FanPWMS;
extern char *mqttTopic;
extern PubSubClient client;

void callback(char *topic, byte *payload, unsigned int length);
void executeCommand(char *payload);
#endif