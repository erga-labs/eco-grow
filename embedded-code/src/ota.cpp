#include "ota.h"

bool performOTAUpdate() {
    HTTPClient http;
    http.begin(OTA_SERVER_URL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String payload = "api_key=" + String(API_KEY);
    int httpCode = http.POST(payload);

    if (httpCode == 200) {
        int contentLength = http.getSize();
        Serial.printf("Firmware size: %d bytes\n", contentLength);

        if (Update.begin(contentLength)) {
            size_t written = Update.writeStream(http.getStream());
            if (written == contentLength && Update.end(true)) {
                Serial.println("OTA Update Successful");
                http.end();
                delay(1000);
                ESP.restart();
                return true;
            }
        }
    } else {
        Serial.printf("OTA Update Failed. HTTP Error: %d\n", httpCode);
    }

    http.end();
    return false;
}