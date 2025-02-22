/*
 * ESP8266 Web Server for Temperature & Humidity Monitoring
 * 
 * This project uses ESP8266 to host a simple web server displaying 
 * temperature and humidity data from two DHT22 sensors.
 * 
 * Author: Yodha Ardiansyah
 * Website: https://arunovasi.my.id
 * 
 * License: MIT
 */

#include <ESP8266WiFi.h>
#include <DHT.h>

// WiFi Credentials (Replace with your actual WiFi details)
const char* ssid = "YOUR_WIFI_SSID";       
const char* password = "YOUR_WIFI_PASSWORD";  

// DHT Sensor Configuration
#define DHTTYPE DHT22
#define DHTPIN1 14  // GPIO14 (D5) for first sensor
#define DHTPIN2 13  // GPIO13 (D7) for second sensor

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Initialize sensors
  dht1.begin();
  dht2.begin();

  // Connect to WiFi
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.begin();
  Serial.println("Web Server Started...");
}

void loop() {
  WiFiClient client = server.available();  // Look for new clients
  
  if (!client) {
    return;
  }
  
  Serial.println("New client connected");
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Read temperature and humidity from both sensors
  float humidity1 = dht1.readHumidity();
  float temperature1 = dht1.readTemperature();
  float humidity2 = dht2.readHumidity();
  float temperature2 = dht2.readTemperature();

  // HTML Page Content
  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Temperature & Humidity Monitoring</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<meta http-equiv='refresh' content='2'>";  // Auto-refresh every 2 seconds
  html += "<style>body { font-family: Arial, sans-serif; text-align: center; color: #333; }";
  html += ".container { max-width: 500px; margin: auto; padding: 20px; background-color: #f2f2f2; border-radius: 8px; box-shadow: 0px 0px 10px rgba(0,0,0,0.1); }";
  html += ".sensor { padding: 10px; margin-top: 20px; }";
  html += ".sensor h2 { font-size: 1.5em; color: #007BFF; }";
  html += ".value { font-size: 2em; margin: 10px 0; color: #333; }</style></head><body>";
  html += "<div class='container'><h1>Temperature & Humidity Monitoring</h1>";

  // Sensor 1 Data
  html += "<div class='sensor'><h2>Sensor 1</h2>";
  if (isnan(humidity1) || isnan(temperature1)) {
    html += "<p>Failed to read data from Sensor 1</p>";
  } else {
    html += "<p>Humidity: <span class='value'>" + String(humidity1) + " %</span></p>";
    html += "<p>Temperature: <span class='value'>" + String(temperature1) + " °C</span></p>";
  }

  // Sensor 2 Data
  html += "</div><div class='sensor'><h2>Sensor 2</h2>";
  if (isnan(humidity2) || isnan(temperature2)) {
    html += "<p>Failed to read data from Sensor 2</p>";
  } else {
    html += "<p>Humidity: <span class='value'>" + String(humidity2) + " %</span></p>";
    html += "<p>Temperature: <span class='value'>" + String(temperature2) + " °C</span></p>";
  }

  html += "</div></div></body></html>";

  // Send HTTP Response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println();
  client.println(html);
  client.stop();
  Serial.println("Client Disconnected");
}
