#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SPIFFS.h>
#include <ESP32Servo.h>


// Replace these with your WiFi credentials
const char* ssid = "SSID";  
const char* password = "PASS";  

Servo myServo;
int servoPin = 16; // GPIO pin connected to servo

AsyncWebServer server(80);

void setup() {
  Serial.begin(9600); 

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // Print the IP address

  // Attach the servo motor to the defined pin
  myServo.attach(servoPin);
  myServo.write(90); //start at the middle position

  // initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // HTML file from SPIFFS
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // CSS file from SPIFFS
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  // Handle servo angle changes
  server.on("/servo", HTTP_GET, [](AsyncWebServerRequest *request){
    String angle;
    if (request->hasParam("angle")) {
      angle = request->getParam("angle")->value();
      myServo.write(angle.toInt());
    }
    request->send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
}
