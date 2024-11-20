/*
 * STM32F429i.h
 *
 *  Created on: Jan 25, 2024
 *      Author: joelrsilva
 */

#ifndef STM32F429I_H_
#define STM32F429I_H_
#include <stdint.h>

#define PERIPH_BASE_ADDR 0x40000000
#define AHB1_BASE_ADDR 0x40020000
#define APB2_BASE_ADDR 0x40010000
#define APB1_BASE_ADDR 0x40000000

#define GPIOG_BASE_ADDR (AHB1_BASE_ADDR + 0x1800)
#define GPIOA_BASE_ADDR (AHB1_BASE_ADDR)
#define RCC_BASE_ADDR (AHB1_BASE_ADDR + 0x3800)

#define SYSCONFIG_BASE_ADDR (APB2_BASE_ADDR + 3800)
#define EXTI_BASE_ADDR (APB2_BASE_ADDR + 0x3C00)
#define GPIOG_OFFSET 6
#define GPIOA_OFFSET 0

#define TIM2_OFFSET 0
#define TIM5_OFFSET 3

#define TIM2_BASE_ADDR (APB1_BASE_ADDR)
#define TIM5_BASE_ADDR (APB1_BASE_ADDR + 0x0C00)
#define ACTIVE 1
#define NON_ACTIVE 0
#define SET 1
#define RESET 0
#define ENABLE SET
#define DISABLE RESET

#define SYSCONFIG_OFFSET 14

// NVIC Registers
// Interrupt Set Enable
// enable
#define NVIC_ISER0 ((volatile uint32_t *)0xE000E100)
// disable
#define NVIC_ISER1 ((volatile uint32_t *)0xE000E104)

// Interrupt Clear Enable
#define NVIC_ICER0 ((volatile uint32_t *)0XE000E180)
#define NVIC_ICER1 ((volatile uint32_t *)0xE000E184)

// Interrupt Set Pending
#define NVIC_ISPR0 ((volatile uint32_t *)0XE000E200)
#define NVIC_ISPR1 ((volatile uint32_t *)0XE000E204)

// Interrupt CLear Pending
#define NVIC_ICPR0 ((volatile uint32_t *)0XE000E300)
#define NVIC_ICPR1 ((volatile uint32_t *)0XE000E304)

// Interrupt Priority
#define NVIC_IPR0 ((volatile uint32_t *)0xE000E400)
#define NVIC_IPR1 ((volatile uint32_t *)0xE000E404)

typedef struct
{
	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOA_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFR[2];

} GPIO_RegDef_t;

typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t RESERVED1;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t RESERVED4;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RESERVED3[2];
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t RESERVED5;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t RESERVED6[2];
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RESERVED7[2];
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
} RCC_RegDef_t;

typedef struct
{
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR[4];
	volatile uint32_t SYSCFG_CMPCR;
} SYSCONFIG_RegDef_t;

typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
} EXTI_RegDef_t;

typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	volatile uint32_t RESERVED;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t RESERVED2;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;
	volatile uint32_t TIM2_OR;
	volatile uint32_t TIM5_OR;
} GPTIMR_RegDef_t;

#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDR)
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define TIM2 ((GPTIMR_RegDef_t *)TIM2_BASE_ADDR)
#define TIM5 ((GPTIMR_RegDef_t *)TIM5_BASE_ADDR)
#define SYSCONFIG ((SYSCONFIG_RegDef_t *)SYSCONFIG_BASE_ADDR)
#define EXTI ((EXTI_RegDef_t *)EXTI_BASE_ADDR)
#define RCC ((RCC_RegDef_t *)RCC_BASE_ADDR)
#define AHB1_CLOCK_ENABLE(x) (RCC->RCC_AHB1ENR |= (1 << x))
#define AHB1_CLOCK_DISABLE(x) (RCC->RCC_AHB1ENR &= (1 << x))

#define SYSCONFIG_CLOCK_ENABLE(x) (RCC->RCC_APB2ENR |= (1 << x))
#define SYSCONFIG_CLOCK_DISABLE(x) (RCC->RCC_APB2ENR &= (1 << x))

#define APB1_CLOCK_ENABLE(x) (RCC->RCC_APB1ENR |= (1 << x))
#define APB1_CLOCK_DISABLE(x) (RCC->RCC_APB1ENR &= (1 << x))
#endif /* STM32F429I_H_ */
