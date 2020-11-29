/*
 * Shift Register Driver
 * PART NAME HERE
 */

#include "shift-register-driver.h"
#include "assert.h"
#include <Arduino.h>

#define CLOCK_PERIOD_US 50u

struct shift_register_config {
    struct shift_register_pin_config pin_config;
    uint32_t line_size;
    bool initialized;
};

static struct shift_register_config config = {pin_config : {din_pin : 13u, clk_pin : 14u, reset_pin : 15u}, line_size : 8u, initialized : false};

void
shift_register_init(struct shift_register_pin_config pin_config, uint32_t line_size) {
    assert(!config.initialized);

    config.pin_config = pin_config;
    config.line_size = line_size;
    config.initialized = true;

    pinMode(config.pin_config.clk_pin, OUTPUT);
    pinMode(config.pin_config.din_pin, OUTPUT);
    pinMode(config.pin_config.reset_pin, OUTPUT);

    digitalWrite(config.pin_config.reset_pin, LOW);
}

void
shift_register_shift_in(uint8_t* data_array, uint8_t size) {
    assert(config.initialized);
    assert(size <= config.line_size);

    digitalWrite(config.pin_config.reset_pin, HIGH);
    digitalWrite(config.pin_config.clk_pin, LOW);
    for (int i=0; i < size; ++i) {
        digitalWrite(config.pin_config.din_pin, data_array[i]);
        digitalWrite(config.pin_config.clk_pin, HIGH);
        delayMicroseconds(CLOCK_PERIOD_US);
        digitalWrite(config.pin_config.clk_pin, LOW);
        delayMicroseconds(CLOCK_PERIOD_US);
    }
}