/*
 * ARMCORE.h
 *
 *  Created on: Mar 27, 2024
 *      Author: yusuf
 */

#ifndef ARMCORE_H_
#define ARMCORE_H_


#include 	<stdint.h>
#include 	"time.h"

typedef	uint8_t		IRQNumber_t;

#define NVIC_ISER_BASE		(0xE000E100)
#define NVIC_ICER_BASE		(0XE000E180)

#define SYSTICK_BASE		(0xE000E010)

typedef struct SYSTICK_t{
	uint32_t 	STK_CTRL;
	uint32_t 	STK_LOAD;
	uint32_t 	STK_VAL;
	uint32_t 	STK_CALIB;
}SYSTICK_e;

typedef struct NVIC_ISER_t{
	uint32_t	NVIC_ISER0;
	uint32_t	NVIC_ISER1;
	uint32_t	NVIC_ISER2;
	uint32_t	NVIC_ISER3;
	uint32_t	NVIC_ISER4;
	uint32_t	NVIC_ISER5;
	uint32_t	NVIC_ISER6;
	uint32_t	NVIC_ISER7;
}NVIC_ISER_e;

typedef struct NVIC_ICER_t{
	uint32_t	NVIC_ICER0;
	uint32_t	NVIC_ICER1;
	uint32_t	NVIC_ICER2;
	uint32_t	NVIC_ICER3;
	uint32_t	NVIC_ICER4;
	uint32_t	NVIC_ICER5;
	uint32_t	NVIC_ICER6;
	uint32_t	NVIC_ICER7;
}NVIC_ICER_e;




#define NVIC_ISER		((NVIC_ISER_e*)NVIC_ISER_BASE)
#define NVIC_ICER		((NVIC_ICER_e*)NVIC_ICER_BASE)
#define	SYSTICK			((SYSTICK_e*)SYSTICK_BASE)

void nvicInterruptEnable(IRQNumber_t irqNo);
void nvicInterruptDisable(IRQNumber_t irqNo);

void systickConfig(uint32_t tickCount);
void SysTick_Handler();
clock_t getClock();

#define		EXTI0_IRQ_NO			6
#define		EXTI1_IRQ_NO			7
#define		EXTI2_IRQ_NO			8
#define		EXTI3_IRQ_NO			9
#define		EXTI4_IRQ_NO			10
#define		EXTI9_5_IRQ_NO			23
#define		EXTI15_10_IRQ_NO		40
#define		HASH_RNG				80


#define 	TIMER1_IRQ_NO			27
#define 	TIMER2_IRQ_NO			28
#define 	TIMER3_IRQ_NO			29
#define 	TIMER4_IRQ_NO			30
#define 	TIMER5_IRQ_NO			50
#define 	TIMER6_IRQ_NO			54
#define 	TIMER7_IRQ_NO			55
#define 	TIMER8_IRQ_NO			46
#define 	TIMER9_IRQ_NO			24
#define 	TIMER10_IRQ_NO			25
#define 	TIMER11_IRQ_NO			26
#define 	TIMER12_IRQ_NO			43
#define 	TIMER13_IRQ_NO			44
#define 	TIMER14_IRQ_NO			45

#endif /* ARMCORE_H_ */
