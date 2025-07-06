#ifndef LED_H
#define LED_H

#define LED_R 13
#define LED_G 11
#define LED_B 12
#define PERIOD 2000
#define DIVIDER_PWM  16.0
#define LED_STEP 100
#define led_level  10

void init_led_pwm();
void onRed();
void ofRed();

#endif