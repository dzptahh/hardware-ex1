#include <Arduino.h>
#include <Bounce2.h>
#define GREEN 33
#define RED 26
#define YELLOW 25
#define BUTTON 27
#define LDR 34
int cnt = 0;
int cy = 0;
int i;
Bounce debouncer = Bounce();
void setup() {
    Serial.begin(115200);
    Serial.println("BUTTON");
    debouncer.attach(BUTTON, INPUT_PULLUP);
    debouncer.interval(25); 
    pinMode(GREEN, OUTPUT);

    pinMode(YELLOW, OUTPUT);

    pinMode(RED, OUTPUT);

    ledcSetup(0, 5000, 8);
    ledcAttachPin(GREEN, 0);
    ledcSetup(1, 5000, 8);
    ledcAttachPin(YELLOW, 1);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(RED, 2);
    Serial.begin(115200);
    Serial.println("LDR");
}

void loop() {
    i = map(analogRead(LDR),2500,4095,0,255);
    if (i < 0)
    {
        i = 0;
    }
    debouncer.update();
    if ( debouncer.fell() ) { 
        cnt++;
        Serial.println(cnt);
        
    }
    if(cnt % 2 > 0)
        {
            ledcWrite(0, i);
        }
        else 
        {
            ledcWrite(0,0);
        }
        if (cnt % 4 > 1)
        {
            ledcWrite(1,i);
        }
        else 
        {
            ledcWrite(1,0);

        }
         if (cnt % 8 > 3)
        {
            ledcWrite(2,i);
        }
        else 
        {
            ledcWrite(2,0);

        }
    Serial.println(analogRead(LDR));
    Serial.println(i);
    delay(100);
}