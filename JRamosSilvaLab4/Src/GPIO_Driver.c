/*
 * GPIO_Driver.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "GPIO_Driver.h"

void GPIO_ClockControl(GPIO_RegDef_t *pPinConfig, uint8_t enableDisable)
{
    if (enableDisable == ENABLE) {
        if (pPinConfig == (GPIO_RegDef_t *)GPIOG) {
            AHB1ENR_CLOCK_ENABLE(GPIOG_RCC_OFFSET);  // Enable clock for GPIOG
        }
        else if (pPinConfig == (GPIO_RegDef_t *)GPIOA) {
            AHB1ENR_CLOCK_ENABLE(GPIOA_RCC_OFFSET);  // Enable clock for GPIOA
        }
    }
    else {  // Disable clock
        if (pPinConfig == (GPIO_RegDef_t *)GPIOG) {
            AHB1ENR_CLOCK_DISABLE(GPIOG_RCC_OFFSET);  // Disable clock for GPIOG
        }
        else if (pPinConfig == (GPIO_RegDef_t *)GPIOA) {
            AHB1ENR_CLOCK_DISABLE(GPIOA_RCC_OFFSET);  // Disable clock for GPIOA
        }
    }
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum, uint8_t pValue){

	if(pValue == ACTIVE){
		pPinConfig->GPIO_ODR |= (ENABLE << pNum);
	}
	else if (pValue == DISABLE){
		pPinConfig->GPIO_ODR &= ~(ENABLE << pNum);
	}
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum){

	if(pPinConfig->GPIO_ODR & (1 << pNum)){
		pPinConfig->GPIO_ODR &= ~(ENABLE << pNum);
	}
	else{
		pPinConfig->GPIO_ODR |= (ENABLE << pNum);
	}
}

void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *pPinConfig){
	uint32_t temp = 0;
	temp = (pPinConfig->PinMode << (2 * pPinConfig->PinNumber));
	pGPIOx->GPIO_MODER &= ~(0x3 << (2 * pPinConfig->PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_MODER |= temp;

	if(pPinConfig->InterruptMode != NO_INTERRUPT){

		if ((pPinConfig->InterruptMode) & FALLING_RISING_INTERRUPT){
			EXTI->EXTI_FTSR |= (1 << pPinConfig->PinNumber);
			EXTI->EXTI_RTSR |= (1 << pPinConfig->PinNumber);
		}
		else if ((pPinConfig->InterruptMode) & FALLING_EDGE_INTERRUPT){
			EXTI->EXTI_FTSR |= (1 << pPinConfig->PinNumber);
			EXTI->EXTI_RTSR &= ~(1 << pPinConfig->PinNumber);
		}

		else if((pPinConfig->InterruptMode) & RISING_EDGE_INTERRUPT){
			EXTI->EXTI_RTSR |= (1 << pPinConfig->PinNumber);
			EXTI->EXTI_FTSR &= ~(1 << pPinConfig->PinNumber);
		}
	}

	pGPIOx->GPIO_OSPEEDR &= ~(0x3 << (2 * pPinConfig->PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_OSPEEDR |= temp;

	pGPIOx->GPIO_PUPDR &= ~(0x3 << (2 * pPinConfig->PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_PUPDR |= temp;

	pGPIOx->GPIO_OTYPER &= ~(0x1 << (pPinConfig->PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_OTYPER |= temp;

	if(pGPIOx->GPIO_MODER == GPIO_PIN_MODE_AFM){
		uint32_t highOrlow = (pPinConfig->PinNumber/8);
		uint32_t highOrLowBitField 	= (pPinConfig->PinNumber% 8);
		uint32_t temp = (4 * highOrLowBitField);

		pGPIOx->GPIO_AFRL_AFRH[highOrlow] &= ~(0xF << (4 * highOrLowBitField));
		pGPIOx->GPIO_AFRL_AFRH[highOrlow] |= temp;
	}
	uint8_t tempRegister = (pPinConfig->PinNumber / 4);
	uint8_t tempBitField = ((pPinConfig->PinNumber % 4));
	uint16_t tempPortCode = getPortNumb(pGPIOx);
	RCC_SYSCFG_ENABLE(14);


	SYSCFG->SYSCFG_EXTICR[tempRegister] &= ~(0xF << (tempBitField * 4));
	SYSCFG->SYSCFG_EXTICR[tempRegister] |= (tempPortCode << (tempBitField * 4));

	EXTI->EXTI_IMR |= (1 << pPinConfig->PinNumber);
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum){
	uint8_t temp;
	temp = ((pPinConfig->GPIO_IDR >> pNum ) & 0x01);
	return temp;
}

uint16_t getPortNumb(GPIO_RegDef_t *pPinConfig){
	if (pPinConfig == GPIOA){
	return GPIOA_PORT;
	}
	return 0;
}

void NVIC_Toggle(uint8_t irq_Num, uint8_t toggle_Control){
	if(toggle_Control){
		IRQ_Enable(irq_Num);
	}
	else{
		IRQ_Disable(irq_Num);
	}
}



