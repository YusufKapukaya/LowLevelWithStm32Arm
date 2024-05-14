/*
 * TIMER.c
 *
 *  Created on: May 3, 2024
 *      Author: yusuf
 */


#include 	"TIMER.h"

TIM_RegDef_t* timTab[]={TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,TIMER6,TIMER7,TIMER8,TIMER9,TIMER10,TIMER11,TIMER12,TIMER13,TIMER14};
IRQNumber_t	  irqTimerTab[]={TIMER1_IRQ_NO,TIMER2_IRQ_NO,TIMER3_IRQ_NO,TIMER4_IRQ_NO,TIMER5_IRQ_NO,TIMER6_IRQ_NO,TIMER7_IRQ_NO,
			  	  	  	  	 TIMER8_IRQ_NO,TIMER9_IRQ_NO,TIMER10_IRQ_NO,TIMER11_IRQ_NO,TIMER12_IRQ_NO,TIMER13_IRQ_NO,TIMER14_IRQ_NO};


static void timerClockEnable(TIM_RegDef_t* pTimerX)
{
	if(pTimerX==TIMER1)
		TIMER1_CLOCK_ENABLE();
	else if(pTimerX==TIMER2)
		TIMER2_CLOCK_ENABLE();
	else if(pTimerX==TIMER3)
		TIMER3_CLOCK_ENABLE();
	else if(pTimerX==TIMER4)
		TIMER4_CLOCK_ENABLE();
	else if(pTimerX==TIMER5)
		TIMER5_CLOCK_ENABLE();
	else if(pTimerX==TIMER6)
		TIMER6_CLOCK_ENABLE();
	else if(pTimerX==TIMER7)
		TIMER7_CLOCK_ENABLE();
	else if(pTimerX==TIMER8)
		TIMER8_CLOCK_ENABLE();
	else if(pTimerX==TIMER9)
		TIMER9_CLOCK_ENABLE();
	else if(pTimerX==TIMER10)
		TIMER10_CLOCK_ENABLE();
	else if(pTimerX==TIMER11)
		TIMER11_CLOCK_ENABLE();
	else if(pTimerX==TIMER12)
		TIMER12_CLOCK_ENABLE();
	else if(pTimerX==TIMER13)
		TIMER13_CLOCK_ENABLE();
	else if(pTimerX==TIMER14)
		TIMER14_CLOCK_ENABLE();

}

void timerInit(TIMNO_e timNo, uint32_t prescaler, uint32_t period)
{
	TIM_RegDef_t* pTim=timTab[timNo];
	timerClockEnable(pTim);

	pTim->ARR = period-1;
	pTim->PSC = prescaler-1;

	pTim->CR1 |= (1U<<0);
}

void timerReset(TIMNO_e timNo)
{
	TIM_RegDef_t* pTim=timTab[timNo];
	pTim->CNT=0;

}

void timerStartStop(TIMNO_e timNo, int bStartStop)
{
	TIM_RegDef_t* pTim=timTab[timNo];
	if(bStartStop == TIMER_START)
		pTim->CR1 |= (1U<<0);
	else
		pTim->CR1 &= ~(1U<<0);
}


void timerInterruptConfig(TIMNO_e timNo)
{
	TIM_RegDef_t* pTim=timTab[timNo];
	pTim->DIER |=(1U<<0);
	nvicInterruptEnable(irqTimerTab[timNo]);
}


