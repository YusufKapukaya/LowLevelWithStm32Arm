/*
 * UTILITY.C
 *
 *  Created on: May 3, 2024
 *      Author: yusuf
 */

#include 	"UTILITY.h"


clock_t	delaySec(uint8_t sec)
{
	uint32_t end_tick = getClock()+ sec * 1000;
	while(end_tick != getClock())
		;
}

clock_t	delayMs(uint32_t ms)
{
	uint32_t end_tick = getClock()+ ms;
	while(end_tick != getClock())
		;
}
