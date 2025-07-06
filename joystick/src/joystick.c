#include "../include/joystick.h"


void init_joystick()
{
    adc_init();        
    adc_gpio_init(VRX); 
    adc_gpio_init(VRY); 


    gpio_init(SW);             
    gpio_set_dir(SW, GPIO_IN); 
    gpio_pull_up(SW);       
}

void joystick_read_axis(uint16_t *vrx_value, uint16_t *vry_value)
{

    adc_select_input(ADC_CHANNEL_0); 
    sleep_us(2);                    
    *vrx_value = adc_read();        


    adc_select_input(ADC_CHANNEL_1); 
    sleep_us(2);                  
    *vry_value = adc_read();      
}

void verifica_movimento_eixo_x(uint16_t vrx_value)
{
    
}