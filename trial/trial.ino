#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>  // Include this header for SPIFFS support

const char* ssid = "Your WiFi SSID";
const char* password = "Your WiFi Password";

AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        // Read and send the contents of the index.html file
        File file = SPIFFS.open("/index.html", "r");
        if (file) {
            size_t sent = server.streamFile(file, "text/html");
            file.close();
        } else {
            request->send(404, "text/plain", "File not found");
        }
    });

    server.onNotFound([](AsyncWebServerRequest *request){
        request->send(404, "text/plain", "Not Found");
    });

    SPIFFS.begin();
    server.begin();
}

void loop() {
}
