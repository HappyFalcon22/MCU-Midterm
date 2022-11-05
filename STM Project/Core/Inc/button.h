/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "led_process.h"
#include "main.h"
#include "global.h"

#define TIME_FOR_AUTO_INCREASING 100
#define NORMAL SET
#define PRESSED RESET

extern int flag_pressed[3];
extern int flag_long_pressed[3];

int isButtonPressed(int index);
int isButtonLongPressed(int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
