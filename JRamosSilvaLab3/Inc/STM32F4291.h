/*
 * STM32F429i.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#ifndef STM32F4291_H_
#define STM32F4291_H_

#include <stdint.h>

#define AHB1_BASE_ADDR	0x40020000 //Address for GPIOA
#define APB2_BASE_ADDR	0x40013800
#define RCC_OFFSET		0x3800

#define	RCC_BASE_ADDR 	(AHB1_BASE_ADDR + RCC_OFFSET)
#define GPIOG_BASE_ADDR	(AHB1_BASE_ADDR + 0x1800)

//Button Macros
#define GPIOA_BASE_ADDR					AHB1_BASE_ADDR
#define AHB1ENR_CLOCK_ENABLE(OFFSET)	(RCC->RCC_AHB1ENR |= (SET << OFFSET))
#define AHB1ENR_CLOCK_DISABLE(OFFSET)	(RCC->RCC_AHB1ENR &= ~(SET << OFFSET))

#define	GPIOA_RCC_OFFSET	0
#define GPIOG_RCC_OFFSET	6



typedef struct {
	uint32_t GPIO_MODER;
	uint32_t GPIO_OTYPER;
	uint32_t GPIO_OSPEEDR;
	uint32_t GPIO_PUPDR;
	uint32_t GPIO_IDR;
	uint32_t GPIO_ODR;
	uint32_t GPIO_BSRR;
	uint32_t GPIO_LCKR;
	uint32_t GPIO_AFRL_AFRH[2];		//Alternate function low/high register
}GPIO_RegDef_t;

typedef struct {
	uint32_t RCC_CR;
	uint32_t RCC_PLLCFGR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_AHB1RSTR;
	uint32_t RCC_AHB2RSTR;
	uint32_t RCC_AHB3RSTR;
	uint32_t Reserved1;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_APB2RSTR;
	uint32_t Reserved2[2];
	uint32_t RCC_AHB1ENR;
	uint32_t RCC_AHB2ENR;
	uint32_t RCC_AHB3ENR;
	uint32_t Reserved3;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_APB2ENR;
	uint32_t Reserved4[2];
	uint32_t RCC_AHB1LPENR;
	uint32_t RCC_AHB2LPENR;
	uint32_t RCC_AHB3LPENR;
	uint32_t Reserved5;
	uint32_t RCC_APB1LPENR;
	uint32_t RCC_APB2LPENR;
	uint32_t Reserved6[2];
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	uint32_t Reserved7[2];
	uint32_t RCC_SSCGR;
	uint32_t RCC_PLLI2SCFGR;
	uint32_t RCC_PLLSAICFGR;
	uint32_t RCC_DCKCFGR;
}RCC_RegDef_t;


#define GPIOG 			((GPIO_RegDef_t*) GPIOG_BASE_ADDR) //pointer to GPIOG Base address
#define GPIOA			((GPIO_RegDef_t*) GPIOA_BASE_ADDR)
#define RCC 			((RCC_RegDef_t*) RCC_BASE_ADDR)


#define ACTIVE 		1
#define NON_ACTIVE 	0
#define SET 		1
#define RESET 		0
#define ENABLE 		SET
#define DISABLE 	RESET

//Address for NVIC Register
#define NVIC_ISER0  ((volatile uint32_t*) 0xE000E100)  // SET-ENABLE
#define NVIC_ISER1  ((volatile uint32_t*) 0xE000E104)  // SET-ENABLE

#define NVIC_ICER0  ((volatile uint32_t*) 0xE000E180)  // CLEAR-ENABLE
#define NVIC_ICER1  ((volatile uint32_t*) 0xE000E184)  // CLEAR-ENABLE

#define NVIC_ISPR0  ((volatile uint32_t*) 0xE000E200)  // SET-PENDING
#define NVIC_ISPR1  ((volatile uint32_t*) 0xE000E204)  // SET-PENDING

#define NVIC_ICPR0  ((volatile uint32_t*) 0xE000E280)  // CLEAR-PENDING
#define NVIC_ICPR1  ((volatile uint32_t*) 0xE000E284)  // CLEAR-PENDING


#define RCC_SYSCFG_BASE_ADDR	(APB2_BASE_ADDR + 0x3844)
#define SYSCFG_BASE_ADDR	APB2_BASE_ADDR
#define EXTI_BASE_ADDR		(APB2_BASE_ADDR + 0x400)

typedef struct{
	uint32_t SYSCFG_MEMRMP;
	uint32_t SYSCFG_PMC;
	uint32_t SYSCFG_EXTICR[4];
	uint32_t SYSCFG_CMPCR;
}SYSCFG_RegDef_t;

typedef struct{
	uint32_t EXTI_IMR;
	uint32_t EXTI_EMR;
	uint32_t EXTI_RTSR;
	uint32_t EXTI_FTSR;
	uint32_t EXTI_SWIER;
	uint32_t EXTI_PR;
}EXTI_RegDef_t;

#define SYSCFG		((SYSCFG_RegDef_t*) SYSCFG_BASE_ADDR)
#define EXTI		((EXTI_RegDef_t*) EXTI_BASE_ADDR)
#define RCC_SYSCFG_ENABLE(OFFSET) 	(RCC->RCC_APB2ENR |= (1 << OFFSET))
#define RCC_SYSCFG_DISABLE(OFFSET) 	(RCC->RCC_APB2ENR &= ~(1 << OFFSET))

#endif /* STM32F4291_H_ */
