#include "../include/display.h"

ssd1306_t disp;

void dpRestart(){
   ssd1306_clear(&disp);
}

void dpInit(){
    ssd1306_init_display(&disp);
}

void dpWriteCenter(char *mensage) {
    ssd1306_clear(&disp);
    ssd1306_draw_string_in_center(&disp, 1, mensage);
    ssd1306_show(&disp);
}
