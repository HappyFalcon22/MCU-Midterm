/*
 * led_display.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_LED_PROCESS_H_
#define INC_LED_PROCESS_H_

#include "main.h"
#include "global.h"

#define SEG7_PORT GPIOB

void display7SEG(int num);
void LED_blinky();

#endif /* INC_LED_PROCESS_H_ */
