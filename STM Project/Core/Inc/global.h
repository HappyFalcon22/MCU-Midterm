/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"

#define INIT 1
#define RESET_STATE 2
#define INCREASED 3
#define DECREASED 4
#define AUTO_INCREASED 5
#define AUTO_DECREASED 6
#define AUTO_DROPDOWN 7
#define TIME_INVOKE_AUTO 10000

extern int status;
extern int counter;
extern int counter_long_pressed;


#endif /* INC_GLOBAL_H_ */
