/*
 * GPIO.h
 *
 *  Created on: Mar 27, 2024
 *      Author: yusuf
 */
#include 	<stdint.h>
#include 	<stdlib.h>
#include 	"stm32.h"
#include 	"ARMCORE.h"



#ifndef GPIO_H_
#define GPIO_H_

#define		GPIO_PIN_SET			1
#define		GPIO_PIN_RESET			0

#define		GPIO_PORT_SET			0xFFFF
#define		GPIO_PORT_RESET			0x0000


#define		GPIO_MODE_INPUT			0
#define		GPIO_MODE_OUTPUT		1
#define		GPIO_MODE_ALTERNATE		2
#define		GPIO_MODE_ANALOG		3
#define		GPIO_MODE_FT			4
#define		GPIO_MODE_RT			5
#define		GPIO_MODE_RT_FT			6

#define		GPIO_OTYPE_PP			0
#define		GPIO_OTYPE_OD			1

#define		GPIO_OSPEEDR_LOW		0
#define		GPIO_OSPEEDR_MEDIUM		1
#define		GPIO_OSPEEDR_HIGHSPEED	2
#define		GPIO_OSPEEDR_VERYHIGH	3

#define		GPIO_PUPDR_NOPUPD		0
#define		GPIO_PUPDR_PUPD			1
#define		GPIO_PUPDR_PU			2
#define		GPIO_PUPDR_PD			3



#define		NO_ALTERNATE_FUNC		0


typedef enum pinNumber_t{
	pinNumber0,pinNumber1,pinNumber2,pinNumber3,pinNumber4,pinNumber5,pinNumber6,pinNumber7,pinNumber8,pinNumber9,pinNumber10,
	pinNumber11,pinNumber12,pinNumber13,pinNumber14,pinNumber15
}pinNumber_e;
typedef enum LED_t{
	LED_Green=12,LED_Orange,LED_Red,LED_Blue
}LED_e;

typedef struct GPIO_PinConfig_t {
	uint32_t	MODE;
	uint32_t	OTYPE;
	uint32_t	OSPEEDR;
	uint32_t	PUPDR;
	uint32_t	AFR;
	uint32_t	PINNUMBER;
}GPIO_PinConfig_e;

typedef struct GPIO_Handle_e {
	GPIO_RegDef_e* 		GPIOx;
	GPIO_PinConfig_e	pinConfig;
}GPIO_Handle_e;



void gpioWritePin(GPIO_RegDef_e* GPIOx, uint8_t pin, uint8_t val);
void gpioWritePort(GPIO_RegDef_e* GPIOx, uint16_t val);
BOOL gpioReadPin(const GPIO_RegDef_e* GPIOx, uint8_t pin);
uint16_t gpioReadPort(const GPIO_RegDef_e* GPIOx);
void gpioToggle(GPIO_RegDef_e* GPIOx, uint8_t pin);
void gpioInit(GPIO_Handle_e* pGpioHandle);


#endif /* GPIO_H_ */
