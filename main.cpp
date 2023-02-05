#include <Arduino.h>
#define GREEN 33
#define YELLOW 25
#define RED 26

void setup()
{
    ledcSetup(0, 5000, 8);
    ledcAttachPin(GREEN, 0);
    ledcSetup(1, 5000, 8);
    ledcAttachPin(YELLOW, 1);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(RED, 2);
}
void loop()
{
  for (int i = 0; i < 255; i++) {
    ledcWrite(0, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    ledcWrite(0, i);
    delay(5);
  }
  delay(1000);
}