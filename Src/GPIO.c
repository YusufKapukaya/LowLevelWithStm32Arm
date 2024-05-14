/*
 * GPIO.c
 *
 *  Created on: Mar 28, 2024
 *      Author: yusuf
 */

#include 	"GPIO.h"

void gpioClockEnable(GPIO_RegDef_e* pGPIOx){
	if(pGPIOx==GPIOA)
		GPIOA_CLOCK_ENABLE();
	else if(pGPIOx==GPIOB)
		GPIOB_CLOCK_ENABLE();
	else if(pGPIOx==GPIOC)
		GPIOC_CLOCK_ENABLE();
	else if(pGPIOx==GPIOD)
		GPIOD_CLOCK_ENABLE();
	else if(pGPIOx==GPIOE)
		GPIOE_CLOCK_ENABLE();
	else if(pGPIOx==GPIOF)
		GPIOF_CLOCK_ENABLE();
	else if(pGPIOx==GPIOG)
		GPIOG_CLOCK_ENABLE();
	else if(pGPIOx==GPIOH)
		GPIOH_CLOCK_ENABLE();
	else if(pGPIOx==GPIOI)
		GPIOI_CLOCK_ENABLE();
}

void gpioWritePin(GPIO_RegDef_e* GPIOx, uint8_t pin, uint8_t val){

if(val)
	GPIOx->ODR |= (1<<pin);
else
	GPIOx->ODR &= ~(1<<pin);
}

void gpioWritePort(GPIO_RegDef_e* GPIOx, uint16_t val){
	GPIOx->ODR = val;
}

BOOL gpioReadPin(const GPIO_RegDef_e* GPIOx, uint8_t pin){
	return !(!(GPIOx->ODR &(1<<pin)));
}

uint16_t gpioReadPort(const GPIO_RegDef_e* GPIOx){
	return (GPIOx->ODR);
}

void gpioToggle(GPIO_RegDef_e* GPIOx, uint8_t pin){
	(GPIOx->ODR ^= (1<<pin));
}

typedef enum PORT_CODE_t{
	PORT_CODE_A,PORT_CODE_B,PORT_CODE_C,PORT_CODE_D,PORT_CODE_E,PORT_CODE_F,PORT_CODE_G,PORT_CODE_H,PORT_CODE_I,WRONG_CODE
}PORT_CODE_t;

static int getPortInfo(GPIO_RegDef_e* GPIOx)
{
	if(GPIOx==GPIOA)
		return PORT_CODE_A;
	else if(GPIOx==GPIOB)
		return PORT_CODE_B;
	else if(GPIOx==GPIOC)
		return PORT_CODE_C;
	else if(GPIOx==GPIOD)
		return PORT_CODE_D;
	else if(GPIOx==GPIOE)
		return PORT_CODE_E;
	else if(GPIOx==GPIOF)
		return PORT_CODE_F;
	else if(GPIOx==GPIOG)
		return PORT_CODE_G;
	else if(GPIOx==GPIOH)
		return PORT_CODE_H;
	else if(GPIOx==GPIOI)
		return PORT_CODE_I;
	else
		return WRONG_CODE;
}

void gpioInit(GPIO_Handle_e* pGpioHandle){
	//Line Clock is enabled
	gpioClockEnable(pGpioHandle->GPIOx);
	//Mode
	if(pGpioHandle->pinConfig.MODE<=GPIO_MODE_ANALOG){
		uint32_t mod=pGpioHandle->pinConfig.MODE<<(2*(pGpioHandle->pinConfig.PINNUMBER));
		pGpioHandle->GPIOx->MODER |= mod;
	}else{
		SYSCFG_CLK_EN();

		uint8_t exti_cr=pGpioHandle->pinConfig.PINNUMBER / 4;
		uint8_t exticr_bit=pGpioHandle->pinConfig.PINNUMBER%4;
		uint8_t port_info=getPortInfo(pGpioHandle->GPIOx);

		SYSCFG->EXTICR[exti_cr] |= (port_info)<<(exticr_bit*4);

		EXTI->IMR |=(1<<pGpioHandle->pinConfig.PINNUMBER);

		if(pGpioHandle->pinConfig.MODE==GPIO_MODE_FT){
			EXTI->RTSR &=~(1<<pGpioHandle->pinConfig.PINNUMBER);
			EXTI->FTSR |=(1<<pGpioHandle->pinConfig.PINNUMBER);
		} else if(pGpioHandle->pinConfig.MODE==GPIO_MODE_RT){
			EXTI->FTSR &=~(1<<pGpioHandle->pinConfig.PINNUMBER);
			EXTI->RTSR |=(1<<pGpioHandle->pinConfig.PINNUMBER);
		} else if(pGpioHandle->pinConfig.MODE==GPIO_MODE_RT_FT){
			EXTI->FTSR |=(1<<pGpioHandle->pinConfig.PINNUMBER);
			EXTI->RTSR |=(1<<pGpioHandle->pinConfig.PINNUMBER);
		}
		if(pGpioHandle->pinConfig.PINNUMBER==pinNumber0)
			nvicInterruptEnable((IRQNumber_t)EXTI0_IRQ_NO);	//EXTI0 Interrupt
		else if(pGpioHandle->pinConfig.PINNUMBER==pinNumber1)
			nvicInterruptEnable((IRQNumber_t)EXTI1_IRQ_NO);	//EXTI1 Interrupt
	}



	//OSPEEDR
	uint32_t ospeedr=pGpioHandle->pinConfig.OSPEEDR<<(2*(pGpioHandle->pinConfig.PINNUMBER));
	pGpioHandle->GPIOx->OSPEEDR |=ospeedr;
	//PUPDR
	uint32_t pupdr=pGpioHandle->pinConfig.PUPDR<<(2*(pGpioHandle->pinConfig.PINNUMBER));
	pGpioHandle->GPIOx->PUPDR |=pupdr;
	//OTYPE
	uint32_t otype=pGpioHandle->pinConfig.OTYPE<<(2*(pGpioHandle->pinConfig.PINNUMBER));
	pGpioHandle->GPIOx->OTYPER |=otype;
	//AFR
	//uint32_t afr=pGpioHandle->pinConfig.AFR<<(2*(pGpioHandle->pinConfig.PINNUMBER));
	//pGpioHandle->GPIOx->AFR |=afr;
}


