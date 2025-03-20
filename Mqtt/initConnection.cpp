// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
#include "initConnection.h"

const char *ssid = SSID;
const char *password = PASS;
const char *mqttServer = MqttBroker;
const char *mqttUser = MqttName;
const char *mqttPassword = MqttPassword;
const char *mqttTopic = MqttTopic;
const int mqttPort = MqttPort;

void initWifi()
{
    // Connecting to WiFi
    Serial.println("Connecting to WiFi");
    WiFi.begin(ssid, password, 6);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println(" ");
    Serial.print("Connected to WiFi : ");
    Serial.println(ssid);
    Serial.print("IP : ");
    Serial.println(WiFi.localIP());
}

WiFiClient espClient;
PubSubClient client(espClient);

void initMqtt()
{
    // Setting up MQTT Broker
    while (!client.connected())
    {
        if (client.connect(mqttClient.c_str()))
        {
            Serial.println("Connected to MQTT broker");
        }
        else
        {
            Serial.print("Failed to connect to MQTT broker, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying...");
            delay(1000);
        }
    }
    // Subscribe to listening topic
    if (client.subscribe(mqttSubTopic))
    {
        Serial.print("Subscribed to topic : ");
        Serial.println(mqttTopic);
    }
    else
    {
        Serial.print("Failed to subscribe to topic : ");
        Serial.println(mqttTopic);
    }
    // publish successful connection to server
    client.publish(mqttPubTopic, "Connected to server");
    Serial.println("Server Connection Sucessfull");
}