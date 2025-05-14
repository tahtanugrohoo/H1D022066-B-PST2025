#include <Arduino.h>
#include <Servo.h>

int echoPin = D0;
int trgPin = D1;
int lepPin = D2;
int LEDHijau = D3;
int LEDMerah = D4;

long duration;
int distance;

Servo myServo;

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trgPin, OUTPUT);
  pinMode(lepPin, OUTPUT);
  pinMode(LEDHijau, OUTPUT);
  pinMode(LEDMerah, OUTPUT);
  myServo.attach(D5);
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


  if (distance <= 1500)
  {
    myServo.write(90);
    delay(2000);
    digitalWrite(LEDHijau, HIGH);
    digitalWrite(LEDMerah, LOW);
  }
  else
  {
    myServo.write(0);
    delay(2000);
    digitalWrite(LEDMerah, HIGH);
    digitalWrite(LEDHijau, LOW);
  }
  delay(500);
}