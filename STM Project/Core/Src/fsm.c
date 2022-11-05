/*
 * fsm_simple_button_run.c
 *
 *  Created on: Nov 6, 2022
 *      Author: HP
 */
#include "fsm.h"

void fsm_simple_buttons_run()
{
	switch (status)
	{
		case INIT:
			status = RESET_STATE;
			break;
		case RESET_STATE:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
				status = RESET_STATE;
			if (isButtonPressed(1) == 1)
			{
				if (counter >= 9)
					counter = 0;
				else
					counter++;
				counter_long_pressed = 0;
				status = INCREASED;
				setTimer1(TIME_INVOKE_AUTO);
			}
			if (isButtonPressed(2) == 1)
			{
				if (counter <= 0)
					counter = 9;
				else
					counter--;
				counter_long_pressed = 0;
				status = DECREASED;
				setTimer1(TIME_INVOKE_AUTO);
			}
			break;
		case INCREASED:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
			{
				counter = 0;
				status = RESET_STATE;
			}
			if (isButtonPressed(2) == 1)
			{
				if (counter <= 0)
					counter = 9;
				else
					counter--;
				counter_long_pressed = 0;
				status = DECREASED;
				setTimer1(TIME_INVOKE_AUTO);
			}
			if (isButtonPressed(1) == 1)
			{
				if (isButtonLongPressed(1) == 1)
				{
					counter_long_pressed++;
					if (counter_long_pressed == 3) // Which hold the button for 3s
					{
						setTimer1(TIME_INVOKE_AUTO);
						status = AUTO_INCREASED;
					}
				}
				else {
					if (counter >= 9)
						counter = 0;
					else
						counter++;
					counter_long_pressed = 0;
					status = INCREASED;
				}
			}
			if (timer1_flag == 1)
			{
				setTimer1(1000);
				status = AUTO_DROPDOWN;
			}
			break;
		case DECREASED:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
			{
				counter = 0;
				status = RESET_STATE;
			}
			if (isButtonPressed(1) == 1)
			{
				if (counter >= 9)
					counter = 0;
				else
					counter++;
				counter_long_pressed = 0;
				setTimer1(TIME_INVOKE_AUTO);
				status = INCREASED;
			}
			if (isButtonPressed(2) == 1)
			{
				if (isButtonLongPressed(2) == 1)
				{
					counter_long_pressed ++;
					if (counter_long_pressed == 3)
					{
						setTimer1(TIME_INVOKE_AUTO);
						status = AUTO_DECREASED;
					}
				}
				else
				{
					if (counter <= 0)
						counter = 9;
					else
						counter--;
					counter_long_pressed = 0;
					status = DECREASED;
				}
			}
			if (timer1_flag == 1)
			{
				setTimer1(1000);
				status = AUTO_DROPDOWN;
			}
			break;
		case AUTO_INCREASED:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
			{
				counter = 0;
				status = RESET_STATE;
			}
			if (isButtonPressed(1) == 1)
			{
				if (counter >= 9)
					counter = 0;
				else
					counter++;
				setTimer1(TIME_INVOKE_AUTO);
			}
			if (isButtonPressed(2) == 1)
			{
				if (counter <= 0)
					counter = 9;
				else
					counter--;
				setTimer1(TIME_INVOKE_AUTO);
				counter_long_pressed = 0;
				status = DECREASED;
			}
			if (timer1_flag == 1)
			{
				setTimer1(1000);
				status = AUTO_DROPDOWN;
			}
			break;
		case AUTO_DECREASED:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
			{
				counter = 0;
				status = RESET_STATE;
			}
			if (isButtonPressed(1) == 1)
			{
				if (counter >= 9)
					counter = 0;
				else
					counter++;
				setTimer1(TIME_INVOKE_AUTO);
				counter_long_pressed = 0;
				status = INCREASED;
			}
			if (isButtonPressed(2) == 1)
			{
				if (counter <= 0)
					counter = 9;
				else
					counter--;
				setTimer1(TIME_INVOKE_AUTO);
			}
			if (timer1_flag == 1)
			{
				setTimer1(1000);
				status = AUTO_DROPDOWN;
			}
			break;
		case AUTO_DROPDOWN:
			display7SEG(counter);
			if (isButtonPressed(0) == 1)
			{
				counter = 0;
				status = RESET_STATE;
			}
			if (isButtonPressed(1) == 1)
			{
				if (counter >= 9)
					counter = 0;
				else
					counter++;
				setTimer1(TIME_INVOKE_AUTO);
				counter_long_pressed = 0;
				status = INCREASED;
			}
			if (isButtonPressed(2) == 1)
			{
				if (counter <= 0)
					counter = 9;
				else
					counter--;
				setTimer1(TIME_INVOKE_AUTO);
				counter_long_pressed = 0;
				status = DECREASED;
			}
			if (timer1_flag == 1)
			{
				if (counter > 0)
					counter --;
				setTimer1(1000);
			}
			break;
		default:
			break;
	}
}
