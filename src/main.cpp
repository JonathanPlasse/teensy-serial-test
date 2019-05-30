#include <Arduino.h>
#include <binary_serial.hpp>
#include <motor.hpp>
#include <Encoder.h>

uint32_t time = 500;
int16_t pwm = 0;

int32_t left_position, right_position;

Motor left_motor(31, 30), right_motor(28, 29);
Encoder left_encoder(20, 21), right_encoder(22, 23);

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(0);
  digitalWrite(13, HIGH);
}

void loop() {
  read_data(&pwm, sizeof(pwm));
  left_motor.set_pwm(pwm);
  right_motor.set_pwm(pwm);
  delay(time);
  left_motor.set_pwm(0);
  right_motor.set_pwm(0);
  left_position = left_encoder.read();
  right_position = right_encoder.read();
  write_data(&left_position, sizeof(left_position));
  write_data(&right_position, sizeof(right_position));
}
