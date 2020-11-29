/*
 * Shift Register Driver
 * PART NAME HERE
 */

#ifndef SHIFT_REGISTER
#define SHIFT_REGISTER

#include "stdint.h"

struct shift_register_pin_config {
    uint32_t din_pin;
    uint32_t clk_pin;
    uint32_t reset_pin;
};

void
shift_register_init(struct shift_register_pin_config pin_config, uint32_t line_size);

void
shift_register_shift_in(uint8_t* data_array, uint8_t size);

#endif