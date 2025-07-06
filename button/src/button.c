#include "../include/button.h" 
#include <stdio.h>
uint32_t last_time = 0; 
bool *pressed_external_ref = NULL;

void btns_callback(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time()); 
    if (current_time - last_time > DEBOUNCE_TIME){                      
        if (gpio == BTN_A) {
            if (pressed_external_ref != NULL) { // Garante que o ponteiro não seja NULL
                *pressed_external_ref = !(*pressed_external_ref); // Inverte o estado da variável lá no main
            }
        }
        last_time = current_time; 
    }
}

void init_buttons(bool *pressedValue)
{
    gpio_init(BTN_A);                                                                   
    gpio_set_dir(BTN_A, GPIO_IN);                                                       
    gpio_pull_up(BTN_A);                                                        
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, btns_callback); 
    pressed_external_ref = pressedValue;
}