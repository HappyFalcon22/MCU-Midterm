/*
 * button.c
 *
 *  Created on: Nov 6, 2022
 *      Author: HP
 */
#include "button.h"

int TimeOutForKeyPress[3] =  {TIME_FOR_AUTO_INCREASING,TIME_FOR_AUTO_INCREASING,TIME_FOR_AUTO_INCREASING};
int flag_pressed[3] = {0,0,0};
int flag_long_pressed[3] = {0,0,0};
int keyReg0[3] = {NORMAL,NORMAL,NORMAL};
int keyReg1[3] = {NORMAL,NORMAL,NORMAL};
int keyReg2[3] = {NORMAL,NORMAL,NORMAL};
int keyReg3[3] = {NORMAL,NORMAL,NORMAL};

void subKeyProcess(int button_index)
{
	flag_pressed[button_index] = 1;
}
void getKeyInput()
{
	for (int i = 0; i < 3; i++)
	{
		keyReg2[i] = keyReg1[i];
		keyReg1[i] = keyReg0[i];
		switch (i)
		{
			case 0:
				keyReg0[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin) ;
				break;
			case 1:
				keyReg0[i] = HAL_GPIO_ReadPin(INCREASED_GPIO_Port, INCREASED_Pin) ;
				break;
			case 2:
				keyReg0[i] = HAL_GPIO_ReadPin(DECREASED_GPIO_Port, DECREASED_Pin) ;
				break;
			default:
				break;
		}
		if ((keyReg1[i] == keyReg0[i]) && (keyReg2[i] == keyReg1[i])){
			if (keyReg2[i] == NORMAL)
				flag_long_pressed[i] = 0;
			if (keyReg2[i] != keyReg3[i])
			{
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] == PRESSED)
				{
					subKeyProcess(i);
					TimeOutForKeyPress[i] = TIME_FOR_AUTO_INCREASING;
				}
			}
			else
			{
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0)
				{
					keyReg3[i] = NORMAL;
					flag_long_pressed[i] = 1;
				}
			}
		}
	}
}

int isButtonPressed(int button_index)
{
	if (flag_pressed[button_index] == 1)
	{
		flag_pressed[button_index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int button_index)
{
	if (flag_long_pressed[button_index] == 1)
	{
		return 1;
	}
	return 0;
}

