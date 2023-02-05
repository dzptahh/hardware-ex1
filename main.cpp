#include <Arduino.h>
void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println("Test 1 2");
    delay(1000);
}

// switch example
#include <Arduino.h>
#define BUTTON 27
int cnt = 0;
void setup() {
    Serial.begin(115200);
    Serial.println("");
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    if (!digitalRead(BUTTON)){
        cnt++;
        Serial.println(cnt);
    }
}

// 5 sec example
#include <Arduino.h>
#define GREEN 33
void setup() {
    pinMode(GREEN, OUTPUT);
    digitalWrite(GREEN,0);
}

void loop() {
    digitalWrite(GREEN,1);
    delay(500);
    digitalWrite(GREEN,0);
    delay(500);
}