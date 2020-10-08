#include <Arduino.h>

#define ONBOARD_LED 2

int temp;

#ifdef __cplusplus
extern "C"
{
#endif
  uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

void setup()
{
  pinMode(ONBOARD_LED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  /*delay(100);
  digitalWrite(ONBOARD_LED, HIGH);
  delay(100);
  digitalWrite(ONBOARD_LED, LOW);*/
  temp = hallRead();
  Serial.println(temp);
  delay(100);
}