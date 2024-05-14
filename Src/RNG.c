/*
 * RNG.c
 *
 *  Created on: Apr 18, 2024
 *      Author: yusuf
 */


#include "RNG.h"


void rng_init(BOOL rngOnOff, BOOL interruptOnOff)
{
	RCC->CR |= PLL_ON;				//PLL ON Enable

	while(!(RCC->CR & PLL_READY_FLAG))		//Ready Flag
		;

	if(rngOnOff){
		RNG_CLOCK_ENABLE();			//RNG Clock Enable
		RNG->CR |= RNG_EN;			//RNG generator Enable
	} else {
		RNG_CLOCK_DISABLE();		//RNG Clock Enable
		RNG->CR &=~ RNG_EN;			//RNG generator Enable
	}

	if(interruptOnOff){
		RNG->CR |= RNG_IE;			//RNG Interrupt Enable
		nvicInterruptEnable((IRQNumber_t)HASH_RNG);
	} else {
		RNG->CR &=~ RNG_IE;			//RNG Interrupt Enable
		nvicInterruptDisable((IRQNumber_t)HASH_RNG);
	}
}


uint32_t getRandomNumber(uint32_t min, uint32_t max)
{
	uint32_t rnumber;
	if(RNG->SR & RNG_DRDY){
		rnumber=RNG->DR;
		return rnumber % (max-min+1) + min;
	}
	return -1;
}
