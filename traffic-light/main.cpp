/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define LONG_BLINK_TIME_MS 1000 
#define SHORT_BLINK_TIME_MS 200 
DigitalOut green(ARDUINO_UNO_D2);
DigitalOut yellow(ARDUINO_UNO_D3);
DigitalOut red(ARDUINO_UNO_D4);

void blink(DigitalOut pin, uint32_t delay_ms)
{
    pin = true;
    thread_sleep_for(delay_ms);
    pin = false;
}

void multi_blink(DigitalOut pin, uint32_t delay_ms, int count)
{
    for(int i = 0; i < count; i++)
    {
        thread_sleep_for(delay_ms);
        pin = true;
        thread_sleep_for(delay_ms);
        pin = false;
    }
}

int main()
{
    green = false;
    yellow = false;
    red = false;

    while (true)
    {
        blink(green, LONG_BLINK_TIME_MS);
        multi_blink(green, SHORT_BLINK_TIME_MS, 3);
        blink(yellow, LONG_BLINK_TIME_MS);
        blink(red, LONG_BLINK_TIME_MS);
    }
}
