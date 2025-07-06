#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico/stdlib.h"
#include "hardware/adc.h"

#define VRX 26
#define VRY 27
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define SW 28

void init_joystick();
void joystick_read_axis(uint16_t *vrx_value, uint16_t *vry_value); 
void verifica_movimento_eixo_x(uint16_t vrx_value);

#endif