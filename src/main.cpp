#include <DHT.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <Hash.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <SocketIoClient.h>
#include <WiFiManager.h>


const char* ssid = "1906";
const char* password = "123456789";

#define DHT_SENSOR_PIN 4
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

int counter = 0;
SocketIOclient socketIO;

void setup() {
  Serial.begin(115200);
  dht_sensor.begin(); // Initialize the DHT sensor

  // WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}




void loop() {
  float humidity = dht_sensor.readHumidity();
  float temperature = dht_sensor.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
  }

  // Add a delay to prevent printing too frequently
  delay(1000);
}
