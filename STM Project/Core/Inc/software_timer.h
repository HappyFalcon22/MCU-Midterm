/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "button.h"

extern int timer1_flag;
extern int timer2_flag;
extern int tick;

void setTimer1(int duration);
void setTimer2(int duration);
//void clearTimer1();
void timerRun();

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim);


#endif /* INC_SOFTWARE_TIMER_H_ */