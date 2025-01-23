#include "api.h"
#include "secrets.h"
#include <PubSubClient.h>

bool sendData(const String& sensorData) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected. Cannot send sensor data.");
        return false;
    }

    HTTPClient http;
    String insertUrl = String(POCKETBASE_HOST) + "/sensor_data/records";
    http.begin(insertUrl);
    
    // Set headers
    http.addHeader("Content-Type", "application/json");

    // Prepare payload with sensor reference
    String payload = "{\"field\":\""+ String(PB_FIELD_ID) +"\", " + 
                     sensorData.substring(1); // Remove first '{' and merge

    int httpResponseCode = http.POST(payload);

    if (httpResponseCode == 200 || httpResponseCode == 201) {
        String response = http.getString();
        Serial.println("Sensor Data Insertion Successful");
        http.end();
        return true;
    } else {
        Serial.printf("Sensor Data Insertion Failed. HTTP Error: %d\n", httpResponseCode);
        String errorResponse = http.getString();
        Serial.println("Error Response: " + errorResponse);
        http.end();
        return false;
    }
}

// Example usage
void exampleSensorDataSend() {
    
    String sensorData = "{\"temperature\":25.5,\"humidity\":60.2,\"timestamp\":\"2024-01-15T10:30:00Z\"}";

    if (sendData(sensorData)) {
        Serial.println("Sensor data sent successfully");
    } else {
        Serial.println("Failed to send sensor data");
    }
}

void sendSensorMQTT(const String& data){

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected. Cannot send sensor data.");
        return;
    }

    WiFiClient espClient;
    PubSubClient client(espClient);
    client.setCallback(callback);
    client.setServer(MQTT_SERVER, MQTT_PORT);
    
    if (!client.connect("ESP32Client", MQTT_USER, MQTT_PASSWORD)) {
        Serial.println("Failed to connect to MQTT server");
        return;
    }

    client.publish("sensor_data", data.c_str());
    client.disconnect();
    Serial.println("Sensor data sent via MQTT");

}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}
