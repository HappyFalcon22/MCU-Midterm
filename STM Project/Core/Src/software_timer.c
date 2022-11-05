/*
 * timer.c
 *
 *  Created on: Nov 6, 2022
 *      Author: HP
 */

#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;

// Internal clock generates 10ms interrupts
int tick = 10;

void setTimer1 (int duration)
{
	timer1_counter = duration/tick;
	timer1_flag = 0;
}

void setTimer2 (int duration)
{
	timer2_counter = duration/tick;
	timer2_flag = 0;
}

void timerRun (){
	if (timer1_counter > 0)
	{
		timer1_counter--;
		if (timer1_counter <= 0)
			timer1_flag  = 1;
	}

	if (timer2_counter > 0)
	{
		timer2_counter--;
		if (timer2_counter <= 0)
			timer2_flag  = 1;
	}

}


void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM2 )
	{
		//button_reading() ;
		getKeyInput();
	}
	timerRun();

}
