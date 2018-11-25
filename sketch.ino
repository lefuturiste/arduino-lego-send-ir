#include "LegoRC.h"

// Configuration des pins
int pinIrLed = D8;

int redTimer;

LegoRC lego(pinIrLed, 50);

void setup() {
  Serial.begin(115200);
  pinMode(pinIrLed, OUTPUT);
}

void loop() {
  if (Serial.read() != -1) {
    // TECC 
    // 0001 ou 1001
    // 1 ou 9 // ou 4
    int i = 0;
    int f = 0;
    while (i < 14) {
      while (f < 14) {
        Serial.println("4");
        Serial.println(i);
        Serial.println(f);
        lego.sendCommand(4, i, f);
        delay(3000);
        Serial.println("New loop");
        f = f + 1;
      }
      f = 0;
      i = i + 1;
    }
  }
}
