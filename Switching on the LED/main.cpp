/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>

DigitalOut green(ARDUINO_UNO_D2);
DigitalOut yellow(ARDUINO_UNO_D3);
DigitalOut red(ARDUINO_UNO_D4);

int main()
{
    green = false;
    yellow = false;
    red = false;

    while (true)
    {
        int input = getchar();
        switch (input) 
        {
            case '0':
               green = false;
               break;
            case '1':
                green = true; 
            case '2':
               yellow = false;
               break;
            case '3':
                yellow = true; 
            case '4':
               red = false;
               break;
            case '5':
                red = true; 
        }
    }
}
