/*
 * stm32.h
 *
 *  Created on: Mar 27, 2024
 *      Author: yusuf
 */

#ifndef STM32_H_
#define STM32_H_
#include 	<stdint.h>

#define		BOOL	uint8_t

#define APB1_BASEADDR						0x40000000
#define APB2_BASEADDR						0x40010000
#define AHB1_BASEADDR						0x40020000
#define AHB2_BASEADDR						0x50050000
#define AHB3_BASEADDR						0x60000000
#define CORTEX_M4_BASEADDR					0x40007800


//	BASE ADRESSE for APB1 CLOCK LINE
#define TIM2_BASEADRESSE					(APB1_BASEADDR)
#define TIM3_BASEADRESSE					(APB1_BASEADDR+0x400)
#define TIM4_BASEADRESSE					(APB1_BASEADDR+0x800)
#define TIM5_BASEADRESSE					(APB1_BASEADDR+0xC00)
#define TIM6_BASEADRESSE					(APB1_BASEADDR+0x1000)
#define TIM7_BASEADRESSE					(APB1_BASEADDR+0x1400)
#define TIM12_BASEADRESSE					(APB1_BASEADDR+0x1800)
#define TIM13_BASEADRESSE					(APB1_BASEADDR+0x1C00)
#define TIM14_BASEADRESSE					(APB1_BASEADDR+0x2000)
#define RTC_BKP_Registers					(APB1_BASEADDR+0x2800)
#define WWDG_BASEADRESSE					(APB1_BASEADDR+0x2C00)
#define IWDG_BASEADRESSE					(APB1_BASEADDR+0x3000)
#define I2S2ext_BASEADRESSE					(APB1_BASEADDR+0x3400)
#define SPI2_I2S2_BASEADRESSE				(APB1_BASEADDR+0x3800)
#define SPI3_I2S3_BASEADRESSE				(APB1_BASEADDR+0x3C00)
#define I2S3EXT_BASEADRESSE					(APB1_BASEADDR+0x4000)
#define USART2_BASEADRESSE					(APB1_BASEADDR+0x4400)
#define USART3_BASEADRESSE					(APB1_BASEADDR+0x4800)
#define UART4_BASEADRESSE					(APB1_BASEADDR+0x4C00)
#define UART5_BASEADRESSE					(APB1_BASEADDR+0x5000)
#define I2C1_BASEADRESSE					(APB1_BASEADDR+0x5400)
#define I2C2_BASEADRESSE					(APB1_BASEADDR+0x5800)
#define I2C3_BASEADRESSE					(APB1_BASEADDR+0x5C00)
#define CAN1_BASEADRESSE					(APB1_BASEADDR+0x6400)
#define CAN2_BASEADRESSE					(APB1_BASEADDR+0x6800)
#define PWR_BASEADRESSE						(APB1_BASEADDR+0x7000)
#define DAC_BASEADRESSE						(APB1_BASEADDR+0x7400)

//	BASE ADRESSE for APB2 CLOCK LINE

#define TIM1_BASEADRESSE					(APB2_BASEADDR)
#define TIM8_BASEADRESSE					(APB2_BASEADDR+0x400)
#define USART1_BASEADRESSE					(APB2_BASEADDR+0x1000)
#define USART6_BASEADRESSE					(APB2_BASEADDR+0x1400)
#define ADC1_ADC2_ADC3_BASEADRESSE			(APB2_BASEADDR+0x2000)
#define SDIO_BASEADRESSE					(APB2_BASEADDR+0x2C00)
#define SPI1_BASEADRESSE					(APB2_BASEADDR+0x3000)
#define SYSCFG_BASEADRESSE					(APB2_BASEADDR+0x3800)
#define EXTI_BASEADRESSE					(APB2_BASEADDR+0x3C00)
#define TIM9_BASEADRESSE					(APB2_BASEADDR+0x4000)
#define TIM10_BASEADRESSE					(APB2_BASEADDR+0x4400)
#define TIM11_BASEADRESSE					(APB2_BASEADDR+0x4800)

#define GPIOA_BASEADRESSE					(AHB1_BASEADDR)
#define GPIOB_BASEADRESSE					(AHB1_BASEADDR+0x400)
#define GPIOC_BASEADRESSE					(AHB1_BASEADDR+0x800)
#define GPIOD_BASEADRESSE					(AHB1_BASEADDR+0xC00)
#define GPIOE_BASEADRESSE					(AHB1_BASEADDR+0x1000)
#define GPIOF_BASEADRESSE					(AHB1_BASEADDR+0x1400)
#define GPIOG_BASEADRESSE					(AHB1_BASEADDR+0x1800)
#define GPIOH_BASEADRESSE					(AHB1_BASEADDR+0x1C00)
#define GPIOI_BASEADRESSE					(AHB1_BASEADDR+0x2000)
#define CRC_BASEADRESSE						(AHB1_BASEADDR+0x3000)
#define RCC_BASEADRESSE						(AHB1_BASEADDR+0x3800)
#define FlashInterfaceReg_BASEADRESSE		(AHB1_BASEADDR+0x3C00)
#define BKPSRAM_BASEADRESSE					(AHB1_BASEADDR+0x4000)
#define DMA1_BASEADRESSE					(AHB1_BASEADDR+0x6000)
#define DMA2_BASEADRESSE					(AHB1_BASEADDR+0x6400)
#define ETHERNET_MAC_BASEADRESSE			(AHB1_BASEADDR+0x8000)
#define USB_OTG_HS_BASEADRESSE				(AHB1_BASEADDR+0x20000)
#define USB_OTG_FS_BASEADRESSE				(AHB1_BASEADDR+0xFFE0000)

#define DCMI_BASEADRESSE					(AHB2_BASEADDR)
#define RNG_BASEADRESSE						(AHB2_BASEADDR+0x10800)

#define FSMC_bank_1_BASEADRESSE				(AHB3_BASEADDR)
#define FSMC_bank_2_BASEADRESSE				(AHB3_BASEADDR+0x10000000)
#define FSMC_bank_3_BASEADRESSE				(AHB3_BASEADDR+0x20000000)
#define FSMC_bank_4_BASEADRESSE				(AHB3_BASEADDR+0x30000000)
#define FSMC_CONTROL_REG_BASEADRESSE		(AHB3_BASEADDR+0x40000000)


typedef struct RCC_RegDef_t {
	volatile uint32_t	CR;
	volatile uint32_t 	PLLCFGR;
	volatile uint32_t	CFGR;
	volatile uint32_t	CIR;
	volatile uint32_t	AHB1RSTR;
	volatile uint32_t	AHB2RSTR;
	volatile uint32_t	AHB3RSTR;
	volatile uint32_t	Reserved6;
	volatile uint32_t	APB1RSTR;
	volatile uint32_t	APB2RSTR;
	volatile uint32_t	Reserved[2];
	volatile uint32_t	AHB1ENR;
	volatile uint32_t	AHB2ENR;
	volatile uint32_t	AHB3ENR;
	volatile uint32_t	Reserved1;
	volatile uint32_t	APB1ENR;
	volatile uint32_t	APB2ENR;
	volatile uint32_t	Reserved2[2];
	volatile uint32_t	AHB1LPENR;
	volatile uint32_t	AHB2LPENR;
	volatile uint32_t	AHB3LPENR;
	volatile uint32_t	Reserved3;
	volatile uint32_t	APB1LPENR;
	volatile uint32_t	APB2LPENR;
	volatile uint32_t	Reserved4[2];
	volatile uint32_t	BDCR;
	volatile uint32_t	CSR;
	volatile uint32_t	Reserved5[2];
	volatile uint32_t	SSCGR;
	volatile uint32_t	PLLI2SCFGR;
}RCC_RegDef_e;

typedef struct GPIO_RegDef_t {
	volatile uint32_t	MODER;
	volatile uint32_t	OTYPER;
	volatile uint32_t	OSPEEDR;
	volatile uint32_t	PUPDR;
	volatile uint32_t	IDR;
	volatile uint32_t	ODR;
	volatile uint32_t	BSRR;
	volatile uint32_t	LCKR;
	volatile uint32_t	AFR[2];
}GPIO_RegDef_e;

typedef struct EXTI_RegDef_t {
	volatile uint32_t	IMR;
	volatile uint32_t	EMR;
	volatile uint32_t	RTSR;
	volatile uint32_t	FTSR;
	volatile uint32_t	SWIER;
	volatile uint32_t	PR;
}EXTI_RegDef_e;

typedef struct SYSCFG_RegDef_t {
	volatile uint32_t	MEMRMP;
	volatile uint32_t	PMC;
	volatile uint32_t	EXTICR[4];
	volatile uint32_t	CMPCR;
}SYSCFG_RegDef_e;

typedef struct RNG_RegDef_t{
	volatile uint32_t CR;
	volatile uint32_t SR;
	volatile uint32_t DR;
}RNG_RegDef_t;

typedef struct TIM_RegDef_t{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
}TIM_RegDef_t;


#define SYSCFG		((SYSCFG_RegDef_e*)SYSCFG_BASEADRESSE)
#define EXTI		((EXTI_RegDef_e*)EXTI_BASEADRESSE)
#define RCC			((RCC_RegDef_e*)RCC_BASEADRESSE)
#define	RNG			((RNG_RegDef_t*)RNG_BASEADRESSE)

#define TIMER1		((TIM_RegDef_t*)TIM1_BASEADRESSE)
#define TIMER2		((TIM_RegDef_t*)TIM2_BASEADRESSE)
#define TIMER3		((TIM_RegDef_t*)TIM3_BASEADRESSE)
#define TIMER4		((TIM_RegDef_t*)TIM4_BASEADRESSE)
#define TIMER5		((TIM_RegDef_t*)TIM5_BASEADRESSE)
#define TIMER6		((TIM_RegDef_t*)TIM6_BASEADRESSE)
#define TIMER7		((TIM_RegDef_t*)TIM7_BASEADRESSE)
#define TIMER8		((TIM_RegDef_t*)TIM8_BASEADRESSE)
#define TIMER9		((TIM_RegDef_t*)TIM9_BASEADRESSE)
#define TIMER10		((TIM_RegDef_t*)TIM10_BASEADRESSE)
#define TIMER11		((TIM_RegDef_t*)TIM11_BASEADRESSE)
#define TIMER12		((TIM_RegDef_t*)TIM12_BASEADRESSE)
#define TIMER13		((TIM_RegDef_t*)TIM13_BASEADRESSE)
#define TIMER14		((TIM_RegDef_t*)TIM14_BASEADRESSE)

#define GPIOA		((GPIO_RegDef_e*)GPIOA_BASEADRESSE)
#define GPIOB		((GPIO_RegDef_e*)GPIOB_BASEADRESSE)
#define GPIOC		((GPIO_RegDef_e*)GPIOC_BASEADRESSE)
#define GPIOD		((GPIO_RegDef_e*)GPIOD_BASEADRESSE)
#define GPIOE		((GPIO_RegDef_e*)GPIOE_BASEADRESSE)
#define GPIOF		((GPIO_RegDef_e*)GPIOF_BASEADRESSE)
#define GPIOG		((GPIO_RegDef_e*)GPIOG_BASEADRESSE)
#define GPIOH		((GPIO_RegDef_e*)GPIOH_BASEADRESSE)
#define GPIOI		((GPIO_RegDef_e*)GPIOI_BASEADRESSE)


#define GPIOA_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<0)) 	//#define		GPIOA_CLCK_EN()		(RCC->AHB1ENR |=(1<<0))
#define GPIOB_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<1))
#define GPIOC_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<2))
#define GPIOD_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<3))
#define GPIOE_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<4))
#define GPIOF_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<5))
#define GPIOG_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<6))
#define GPIOH_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<7))
#define GPIOI_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1U<<8))

#define SYSCFG_CLK_EN()				(RCC->APB2ENR |= (1U<<14))
#define	RNG_CLOCK_ENABLE()			(RCC->AHB2ENR |= (1U<<6))
#define	RNG_CLOCK_DISABLE()			(RCC->AHB2ENR &=~ (1U<<6))


#define	TIMER1_CLOCK_ENABLE()			(RCC->APB2ENR |= (1U<<0))
#define	TIMER8_CLOCK_ENABLE()			(RCC->APB2ENR |= (1U<<1))
#define	TIMER9_CLOCK_ENABLE()			(RCC->APB2ENR |= (1U<<16))
#define	TIMER10_CLOCK_ENABLE()			(RCC->APB2ENR |= (1U<<17))
#define	TIMER11_CLOCK_ENABLE()			(RCC->APB2ENR |= (1U<<18))


#define	TIMER2_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<0))
#define	TIMER3_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<1))
#define	TIMER4_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<2))
#define	TIMER5_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<3))
#define	TIMER6_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<4))
#define	TIMER7_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<5))
#define	TIMER12_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<6))
#define	TIMER13_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<7))
#define	TIMER14_CLOCK_ENABLE()			(RCC->APB1ENR |= (1U<<8))


#endif /* STM32_H_ */
