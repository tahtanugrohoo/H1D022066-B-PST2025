#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "i used to know you so well";
const char* password = "00000000";

ESP8266WebServer server(80);
String webpage;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);

  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D4, OUTPUT);

  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid,password);

  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  webpage+= "<h1> Web Control Tahta</h1>";
  webpage+= "<p> LED 1 : ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p> LED 2 : ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p> LED 3 : ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p><br>";

  server.on("/", [](){
      server.send(200, "text/html", webpage);
  });

  server.on("/LED1ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH);
    delay(1000);
  });
  server.on("/LED2ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH);
    delay(1000);
  });
  server.on("/LED3ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D4, HIGH);
    delay(1000);
  });
  server.on("/LED1OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW);
    delay(1000);
  });
  server.on("/LED2OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW);
    delay(1000);
  });
  server.on("/LED3OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D4, LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("Webserver dijalankan");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}