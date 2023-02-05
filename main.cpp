#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
int cnt = 0;
Bounce debouncer = Bounce();
void setup() {
    Serial.begin(115200);
    Serial.println("BUTTON");
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
}

void loop() {
    debouncer.update();
    if ( debouncer.fell() ) { 
        cnt++;
        Serial.println(cnt);
    }
}