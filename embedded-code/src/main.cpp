#include "ota.h"
#include <WiFi.h>
#include "secrets.h"
#include "api.h"
#include <DHT.h>
#include "pins.h"

unsigned long lastOTACheckTime = 0;
unsigned long lastDataSendTime = 0;
const unsigned long OTA_CHECK_INTERVAL = 60 * (60 * 1000);       // 1 hour
const unsigned long DATA_SEND_INTERVAL = 3  * (60 * 1000);        // 3 minutes

DHT dht;

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
}

void setup()
{
    Serial.begin(115200);
    connectToWiFi();
    pinMode(WATER_AO, INPUT);
    pinMode(WATER_DO, INPUT);

    pinMode(DHT_AO, INPUT);

    dht.setup(DHT_AO);
}

void loop()
{

    int AOValue = analogRead(WATER_AO);
    int DOValue = digitalRead(WATER_DO);

    Serial.print("Analog Value: ");
    Serial.println(AOValue);
    Serial.print("Digital Value: ");
    Serial.println(DOValue);

    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("Failed to read from DHT sensor!");
    }
    else
    {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print("%, Temperature: ");
        Serial.print(temperature);
        Serial.println("°C");
    }


    unsigned long currentTime = millis();

    // Check for OTA update once an hour
    if (currentTime - lastOTACheckTime >= OTA_CHECK_INTERVAL) {
        if (WiFi.status() == WL_CONNECTED) {
            if ((checkOTAUpdate())) {
                if (performOTAUpdate()) {
                    // OTA update successful, device will restart
                }
            }
        } else {
            connectToWiFi();
        }
        lastOTACheckTime = currentTime;
    }

    // Send sensor data every 3 minutes
    if (currentTime - lastDataSendTime >= DATA_SEND_INTERVAL) {
        if (WiFi.status() == WL_CONNECTED) {
            exampleSensorDataSend();
        } else {
            connectToWiFi();
        }
        lastDataSendTime = currentTime;
    }

    // Small delay to prevent tight looping
    delay(2000);
}