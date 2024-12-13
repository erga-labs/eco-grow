#ifndef API_H
#define API_H

#include <HTTPClient.h>
#include <WiFi.h>

bool sendData(const String& sensorData);
void exampleSensorDataSend();

#endif