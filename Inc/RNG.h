/*
 * RNG.h
 *
 *  Created on: Apr 17, 2024
 *      Author: yusuf
 */

#ifndef RNG_H_
#define RNG_H_

//#define
#include 	"ARMCORE.h"
#include 	"stm32.h"

#define		RNG_EN			(1U<<2)
#define		RNG_IE			(1U<<3)


#define		PLL_ON			(1U<<24)
#define		PLL_READY_FLAG	(1U<<25)

#define		RNG_DRDY		(1U<<0)
#define		RNG_CECS		(1U<<1)
#define		RNG_SECS		(1U<<2)
#define		RNG_CEIS		(1U<<5)
#define		RNG_SEIS		(1U<<6)


void rng_init(BOOL rngOnOff, BOOL interruptOnOff);
uint32_t getRandomNumber(uint32_t min, uint32_t max);

#endif /* RNG_H_ */
