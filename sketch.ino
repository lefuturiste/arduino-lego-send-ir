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
    // envoie d'une commande lorsque le Serial recois un caractère
    // lego.sendCommand(mode, vitesse, extra)
    // vitesse = de 3 à 7
    // tester le mode et l'extra pour ne pas avoir de timeout
    lego.sendCommand(4, 7, 10);
  }
}
