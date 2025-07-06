#ifndef DISPLAY_H
#define DISPLAY_H

#include "pico/binary_info.h"
#include "../inc/ssd1306.h"
#include "hardware/i2c.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"

#define I2C_SDA 14
#define I2C_SCL 15

void dpInit();
void dpRestart();
void dpWriteCenter(char *mensage);
#endif