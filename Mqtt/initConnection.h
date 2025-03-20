// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
#ifndef INITCONNECTION_H
#define INITCONNECTION_H

#include <WiFi.h>
#include <PubSubClient.h>
// #include "mqtt.h"

#define SSID "Wokwi-GUEST"
#define PASS ""
#define MqttBroker "broker.emqx.io"
#define MqttPort 1883
#define MqttPubTopic "test/0982/"
#define MqttSubTopic "test/0982/"
#define MqttClient "Esp01MqttFanClient"
// credentials are not implemented (using public broker)
#define MqttName "MqttFanEsp01"
#define MqttPassword ""

extern String mqttClient;
void initWifi();
void initMqtt();

#endif