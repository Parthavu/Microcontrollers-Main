#include <Arduino.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include "time.h"

LiquidCrystal lcd(15, 2, 0, 4, 16, 17);

const char *ssid = "Upadhya Family";
const char *password = "mantriCY163";

const char *ntpServer = "asia.pool.ntp.org";
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 0;

void printLocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    lcd.print("Failed to obtain time");
    return;
  }
  lcd.print(&timeinfo, /*%A, %B %d %Y */"%H:%M:%S");
}

void setup()
{
  Serial.begin(9600);

  //LCD
  lcd.begin(16, 2);

  //connect to WiFi
  lcd.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    lcd.print(".");
  }
  lcd.setCursor(0, 1);
  lcd.print(" CONNECTED");

  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  delay(1000);
  lcd.clear();
  printLocalTime();
}