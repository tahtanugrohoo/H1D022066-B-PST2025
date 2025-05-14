#include <Arduino.h>

// deklarasikan pin dalam variabel

int echoPin = D1;
int trgPin = D0;
int lepPin = D7;

// deklarasikan variabel untuk menghitung jarak

long duration;
int distance;

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trgPin, OUTPUT);
  pinMode(lepPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trgPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trgPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trgPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.println(distance);
  Serial.println(" cm");

  // set kondisi untuk menghidupkan lampu LED
  if (distance <= 10)
  {
    digitalWrite(lepPin, HIGH);
  }
  else
  {
    digitalWrite(lepPin, LOW);
  }
  delay(500);
}