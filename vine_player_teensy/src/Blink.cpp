/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include "shift-register-driver.h"

#define CLOCK_PIN 14
#define DIN_PIN 16
#define RESET_PIN 15

#define LINE_SIZE 8

static uint8_t shift_pattern[] = {LOW, LOW, LOW, HIGH, LOW, LOW};

int main(void)
{
  // initialize LED digital pin as an output.
#ifdef BLINK
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (true) {
    if (Serial.available()) {
      typed_char = Serial.read();
      if (typed_char == 0x61) digitalWrite(LED_BUILTIN, HIGH);
      else if (typed_char == 0x62) digitalWrite(LED_BUILTIN, LOW);
    }
  }
#else
  struct shift_register_pin_config pin_config = {din_pin : DIN_PIN, clk_pin : CLOCK_PIN, reset_pin : RESET_PIN};
  uint8_t line_size = LINE_SIZE;
  shift_register_init(pin_config, line_size);
  while(true) {
    shift_register_shift_in(shift_pattern, 1u);
    delay(250);
    shift_register_shift_in(&shift_pattern[1], 1u);
    delay(250);
    shift_register_shift_in(&shift_pattern[2], 1u);
    delay(250);
    shift_register_shift_in(&shift_pattern[3], 1u);
    delay(250);
  }

#endif
  return 0;
}
