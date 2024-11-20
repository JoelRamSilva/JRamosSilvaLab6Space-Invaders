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
#define RCC_OFFSET		0x3800

#define	RCC_BASE_ADDR 	(AHB1_BASE_ADDR + RCC_OFFSET)
#define GPIOG_BASE_ADDR	(AHB1_BASE_ADDR + 0x1800)


typedef struct {
	uint32_t GPIO_MODER;
	uint32_t GPIO_OTYPER;
	uint32_t GPIO_OSPEEDR;
	uint32_t GPIO_PUPDR;
	uint32_t GPIO_IDR;
	uint32_t GPIO_ODR;
	uint32_t GPIO_BSRR;
	uint32_t GPIO_LCKR;
	uint32_t GPIO_AFRL_AFRH[2];		//Aternate function low/high register
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
#define RCC 			((RCC_RegDef_t*) RCC_BASE_ADDR)

#define GPIOG_CLOCK_ENABLE()	(RCC->RCC_AHB1ENR |= (SET << 6))
#define GPIOG_CLOCK_DISABLE()	(RCC->RCC_AHB1ENR &= ~(SET << 6))

#define ACTIVE 		1
#define NON_ACTIVE 	0
#define SET 		1
#define RESET 		0
#define ENABLE 		SET
#define DISABLE 	RESET

#endif /* STM32F4291_H_ */
