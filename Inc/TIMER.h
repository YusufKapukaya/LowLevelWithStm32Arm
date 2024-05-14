/*
 * TIMER.h
 *
 *  Created on: May 3, 2024
 *      Author: yusuf
 */

#ifndef TIMER_H_
#define TIMER_H_

#include 	<stdint.h>
#include 	"stm32.h"
#include 	"ARMCORE.h"

typedef enum TIMNO{
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_5,
	TIMER_6,
	TIMER_7,
	TIMER_8,
	TIMER_9,
	TIMER_10,
	TIMER_11,
	TIMER_12,
	TIMER_13,
	TIMER_14,
}TIMNO_e;

#define TIMER_STOP		0
#define TIMER_START		1


#define clearITPendingBitTimer6()	(TIMER6->SR &=~(1U<<0))



void timerInit(TIMNO_e timNo, uint32_t prescaler, uint32_t period);
void timerReset(TIMNO_e timNo);
void timerStartStop(TIMNO_e timNo, int bStartStop);
void timerInterruptConfig(TIMNO_e timNo);


#endif /* TIMER_H_ */
