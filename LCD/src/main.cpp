#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27 for the LCD
int SDA_Pin = D2;                   // SDA pin
int SCL_Pin = D3;                   // SCL pin

void setup()
{
  Wire.begin(SDA_Pin, SCL_Pin);
  Serial.begin(9600);               // Initialize serial communication at 9600 bps
  lcd.init();                       // Initialize the LCD
  lcd.backlight();                  // Turn on the backlight
  lcd.setCursor(0, 0);              // Set cursor to first column of first row
  lcd.print("DEDEDEDEDESTRUCTION"); // Print a message to the LCD
  lcd.setCursor(0, 1);              // Set cursor to first column of second row
  lcd.print("ZEHAHAHAHA");          // Print a message to the LCD
}

void loop()
{
  lcd.scrollDisplayLeft(); // Scroll the display to the left
  delay(300);              // Wait for 300 milliseconds
}