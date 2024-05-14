/*
 * ARMCORE.c
 *
 *  Created on: Apr 5, 2024
 *      Author: yusuf
 */

#include 	"ARMCORE.h"

static int counterTick=0;

void nvicInterruptEnable(IRQNumber_t irqNo)
{
	if(irqNo<32)
	NVIC_ISER->NVIC_ISER0 |=(1<<irqNo);
	else if(irqNo>=32 && irqNo<64)
	NVIC_ISER->NVIC_ISER1 |=(1<<irqNo%32);
	else if(irqNo>=64 && irqNo<96)
	NVIC_ISER->NVIC_ISER2 |=(1<<irqNo%32);
}

void nvicInterruptDisable(IRQNumber_t irqNo)
{
	if(irqNo<32)
	NVIC_ICER->NVIC_ICER0 &=~(1<<irqNo);
	else if(irqNo>=32 && irqNo<64)
	NVIC_ICER->NVIC_ICER1 &=~(1<<irqNo%32);
	else if(irqNo>=64 && irqNo<96)
	NVIC_ICER->NVIC_ICER2 &=~(1<<irqNo%32);
}


void systickConfig(uint32_t tickCount)
{
	SYSTICK->STK_LOAD= tickCount-1;
	SYSTICK->STK_VAL=0;
	SYSTICK->STK_CTRL &=~(1U<<16);
	SYSTICK->STK_CTRL |=(1U<<2);
	SYSTICK->STK_CTRL |=(1U<<1);
	SYSTICK->STK_CTRL |=(1U<<0);
}

clock_t getClock()
{
	return counterTick;
}

void SysTick_Handler()
{
	counterTick++;
}
