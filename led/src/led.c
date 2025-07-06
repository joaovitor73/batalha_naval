#include "../include/led.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

void init_led_pwm()
{
    uint slice;
    gpio_set_function(LED_R, GPIO_FUNC_PWM); 
    slice = pwm_gpio_to_slice_num(LED_R);   
    pwm_set_clkdiv(slice, DIVIDER_PWM);   
    pwm_set_wrap(slice, PERIOD);           
    pwm_set_gpio_level(LED_R, led_level);    
    pwm_set_enabled(slice, true);        
}

void onRed(){
    pwm_set_gpio_level(LED_R, led_level);
}

void ofRed(){
    pwm_set_gpio_level(LED_R, 0); 
}