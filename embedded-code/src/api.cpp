#include "api.h"
#include "secrets.h"

bool sendData()
{
   WiFiClient client;

  if (!client.connect(POCKETBASE_HOST, 8080)) {
    Serial.println("Connection failed");
    return false;
  }

  String url = "/api/collections/" + String(PB_COLLECTION_ID) + "/records";
  String payload = "{\"humidity\":\"some_value\",\"temp\":\"some_value\",\"n\":\"some_value\",\"p\":\"some_value\",\"k\":\"some_value\"}";

  client.println("POST " + url + " HTTP/1.1");
  client.println("Host: " + String(POCKETBASE_HOST));
  client.println("Content-Type: application/json");
  client.println("Authorization: Bearer " + String(PB_API_KEY));
  client.println("Content-Length: " + String(payload.length()));
  client.println();
  client.println(payload);

  // Wait for the response
  unsigned long timeout = millis() + 5000;
  while (client.available() == 0) {
    if (millis() > timeout) {
      Serial.println("Client Timeout!");
      client.stop();
      return false;
    }
  }

  // Read the response
  String response = client.readStringUntil('\n');

  if (response.indexOf("\"id\"") != -1) {
    Serial.println("New fields added successfully!");
    return true;
  } else {
    Serial.println("Failed to add new fields.");
    Serial.println(response);
    return false;
  }
}