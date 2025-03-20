// Copyright (C) 2025 AYS- Abdelrahman Yasser Samir
#include "mqtt.h"

char msg[initialBufferSize];
String message = "";
// function called when message is received in subscribed channel
void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
    // execute check for command after receiving message
    executeCommand((char *)payload);
}

void executeCommand(char *payload)
{
    // Switch ON/OFF Fan
    if (payload[0] == 'F' & payload[3] == 'S' & payload[5] == '1')
    {
        FanSWS = 1;
        digitalWrite(FanSWPin, FanSWS);
        Serial.println("Fan Switch ON");
        client.publish(mqttPubTopic, "Fan SWS 1");
    }
    else if (payload[0] == 'F' & payload[3] == 'S' & payload[5] == '0')
    {
        FanSWS = 0;
        digitalWrite(FanSWPin, FanSWS);
        Serial.println("Fan Switch OFF");
        client.publish(mqttPubTopic, "Fan SWS 0");
    }
    // Check if the payload starts with "Fan PWM"
    else if (payload[0] == 'F' & payload[3] == 'P' & payload[5] == 'M')
    {
        // Extract the PWM value (positions 8–10)
        char pwmStr[4]; // Buffer to hold the 3 characters + null terminator
        pwmStr[0] = (char)payload[8];
        pwmStr[1] = (char)payload[9];
        pwmStr[2] = (char)payload[10];
        pwmStr[3] = '\0'; // Null-terminate the string
        // Convert the extracted string to an integer
        int fanSpeed = atoi(pwmStr);
        if (fanSpeed >= 0 && fanSpeed <= 255)
        {
            FanPWMS = fanSpeed;
            analogWrite(FanPWMPin, FanPWMS);
            Serial.print("Fan Speed : ");
            Serial.println(FanPWMS);
            message = "";
            message += "Fan Speed ";
            message += FanPWMS;
            client.publish(mqttPubTopic, message.c_str());
        }
    }
    else
    {
        Serial.println("Invalid Command");
        // commented out to prevent spamming channel because it has the same publish/subscribe channel
        // enable if using different channel for publishing/subscribing
        //  client.publish(mqttPubTopic, "Invalid Command");
    }
}