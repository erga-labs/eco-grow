#include <WiFi.h>
#include "secrets.h"
#include "pins.h"
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

WiFiClient wifi;
PubSubClient mqttClient(wifi);
char msg[20];


void connectToWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi Connected.");
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.broadcastIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
}


void reconnectMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect with username and password
    if (mqttClient.connect("ESP8266Client", "test", "test")) {
      Serial.println("connected");
      mqttClient.subscribe("test/sensordata");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void sendDummyMQTT(){
    float randomTemperature = random(15, 35) + random(0, 99) / 100.0; // Random between 15.00 and 35.99
    float randomHumidity = random(30, 80) + random(0, 99) / 100.0;    // Random between 30.00 and 80.99
    int randomN = random(10, 50);  // Random N value between 10 and 50
    int randomP = random(5, 30);   // Random P value between 5 and 30
    int randomK = random(10, 40);  // Random K value between 10 and 40
    String key = "your_key_here";  // Replace with the desired key

    // Create a JSON object
    StaticJsonDocument<100> jsonDoc;
    jsonDoc["n"] = randomN;
    jsonDoc["p"] = randomP;
    jsonDoc["k"] = randomK;
    jsonDoc["humidity"] = randomHumidity;
    jsonDoc["temp"] = randomTemperature;
    jsonDoc["key"] = key;

    // Serialize JSON object to a string
    char jsonString[256];
    serializeJson(jsonDoc, jsonString);

    // Print and publish the JSON payload
    Serial.print("JSON Payload: ");
    Serial.println(jsonString);
    mqttClient.publish("esp32/sensordata", jsonString);
}

void setup()
{
    Serial.begin(115200);
    connectToWiFi();
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    mqttClient.setCallback(callback);
    mqttClient.connect("ESP8266Client", "test", "test");

}

void loop()
{
    if (WiFi.status() != WL_CONNECTED){
        connectToWiFi();
        return;
    }

    if (!mqttClient.connected()){
        reconnectMQTT();
        return;
    }

    mqttClient.loop();

    sendDummyMQTT();

    delay(10000);
}