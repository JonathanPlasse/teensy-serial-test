#include <Arduino.h>
#include "binary_serial.hpp"

uint32_t time = 500;

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(0);
  read_data(&time, sizeof(time));
}

void loop() {
  read_data_if(&time, sizeof(time));
  digitalWrite(13, HIGH);
  delay(time);
  digitalWrite(13, LOW);
  delay(time);
}
