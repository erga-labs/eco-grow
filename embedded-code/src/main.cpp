#include "ota.h"
#include <WiFi.h>
#include "secrets.h"
#include "api.h"

void connectToWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi Connected.");
    Serial.println(WiFi.localIP());
}


void setup() {
    Serial.begin(115200);
    connectToWiFi();
}

void loop() {

    bool success;
    // Check WiFi and perform OTA
    if (WiFi.status() == WL_CONNECTED) {
        performOTAUpdate();
        success = sendData();
    } else {
        connectToWiFi();
    }

    Serial.println(success ? "Data sent successfully!" : "Failed to send data.");

    delay(60000);  // Wait a minute between update checks
}