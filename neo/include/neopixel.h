#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"

#define LED_COUNT 25
#define LED_PIN 7

void npInit();
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void npClear();
void npClearRange(uint start, uint end);
void npWrite();
void npWriteRange(uint start, uint end);
#endif