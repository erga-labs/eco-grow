#include "ota.h"

bool performOTAUpdate() {
    HTTPClient http;
    http.begin(OTA_SERVER_URL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String payload = "api_key=" + String(OTA_API_KEY);
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

bool checkOTAUpdate(){

    HTTPClient http;
    http.begin(OTA_VERSION_CHECK_URL);  // URL that returns the latest available version
    
    int httpCode = http.GET();
    
    if (httpCode == 200) {
        String latestVersion = http.getString();
        http.end();
        
        // Compare current version with latest version
        if (latestVersion != CURRENT_VERSION) {
            Serial.println("New version available: " + latestVersion);
            return true;
        } else {
            Serial.println("No new version available");
            return false;
        }
    } else {
        Serial.println("Failed to check for updates");
        http.end();
        return false;
    }
}
