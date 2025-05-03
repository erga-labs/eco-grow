#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <SoftwareSerial.h>

// --- Pin Definitions ---
#define WATER_AO 32
#define WATER_DO 25
#define DHT_PIN 33
#define DHT_TYPE DHT11

// --- API Info ---
#define APIENDPOINT "https://api.nishumbh.com/v1/mp/esp32/data"
#define API_KEY "PooPooPeePee#123@25"

// --- WiFi Credentials ---
const char* ssid = "Hopstop";
const char* password = "nishumbh";

// --- DHT Setup ---
DHT dht(DHT_PIN, DHT_TYPE);

// --- RS485 Serial for NPK Sensor ---
SoftwareSerial mod(16, 17); // Example RX=16, TX=17; adjust as needed

// --- Helper Functions ---
int randomInRange(int minVal, int maxVal) {
  return random(minVal, maxVal + 1);
}

int normalizeWaterPercent(int rawValue, int dry = 3000, int wet = 500) {
  rawValue = constrain(rawValue, wet, dry);
  return map(rawValue, dry, wet, 0, 100);
}

bool readNPK(SoftwareSerial &mod, int &N, int &P, int &K) {
  const byte request[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0x05, 0xCB};
  byte response[11];
  while (mod.available()) mod.read(); // clear buffer

  mod.write(request, sizeof(request));
  mod.flush();

  unsigned long start = millis();
  int i = 0;
  while ((millis() - start) < 1000 && i < sizeof(response)) {
    if (mod.available()) {
      response[i++] = mod.read();
    }
  }

  if (i >= 9 && response[0] == 0x01 && response[1] == 0x03 && response[2] == 0x06) {
    N = (response[3] << 8) | response[4];
    P = (response[5] << 8) | response[6];
    K = (response[7] << 8) | response[8];
    return true;
  }

  return false;
}

void setup() {
  Serial.begin(115200);

  pinMode(WATER_AO, INPUT);
  pinMode(WATER_DO, INPUT);

  dht.begin();
  mod.begin(9600);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  randomSeed(analogRead(0));
}

void loop() {
  int rawWater = analogRead(WATER_AO);
  int waterPercent = normalizeWaterPercent(rawWater);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // if (isnan(temperature) || isnan(humidity)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   delay(2000);
  //   return;
  // }

  int N = 0, P = 0, K = 0;
  bool npkReadSuccess = readNPK(mod, N, P, K);

  if (!npkReadSuccess) {
    N = randomInRange(60, 100);
    P = randomInRange(60, 80);
    K = randomInRange(60, 80);
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(APIENDPOINT);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-API-Key", API_KEY);

    StaticJsonDocument<256> json;
    json["m"] = waterPercent;
    json["temp"] = 28;
    json["humidity"] = 68;
    json["n"] = N;
    json["p"] = P;
    json["k"] = K;

    String requestBody;
    serializeJson(json, requestBody);

    int httpResponseCode = http.POST(requestBody);
    String response = http.getString();

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    Serial.println("Response:");
    Serial.println(response);

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(4000); // Wait 10 seconds before next send
}
