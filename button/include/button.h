#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h" 

#define BTN_A 5             
#define DEBOUNCE_TIME 200000 

void init_buttons(bool *pressedValue);                          

#endif