/*
 * GPIO_Driver.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "GPIO_Driver.h"

void GPIO_ClockControl(GPIO_RegDef_t *pPinConfig, uint8_t enableDisable){

	if(enableDisable == ENABLE){
		if(pPinConfig == GPIOG){
			GPIOG_CLOCK_ENABLE();
		}
	}
	else{
		GPIOG_CLOCK_DISABLE();
	}
}

void WriteToOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum, uint8_t pValue){

	if(pValue == ACTIVE){
		pPinConfig->GPIO_ODR |= (ENABLE << pNum);
	}
	else{
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

void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t pPinConfig){
	uint32_t temp = 0;
	temp = (pPinConfig.PinMode << (2 * pPinConfig.PinNumber));
	pGPIOx->GPIO_MODER &= ~(0x3 << (2 * pPinConfig.PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_MODER |= temp;

	pGPIOx->GPIO_OSPEEDR &= ~(0x3 << (2 * pPinConfig.PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_OSPEEDR |= temp;

	pGPIOx->GPIO_PUPDR &= ~(0x3 << (2 * pPinConfig.PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_PUPDR |= temp;

	pGPIOx->GPIO_OTYPER &= ~(0x1 << (pPinConfig.PinNumber)); //0x3 = 0011
	pGPIOx->GPIO_OTYPER |= temp;

	if(pGPIOx->GPIO_MODER == GPIO_PIN_MODE_AFM){
		uint32_t highOrlow = (pPinConfig.PinNumber/8);
		uint32_t highOrLowBitField 	= (pPinConfig.PinNumber% 8);
		uint32_t temp = (4 * highOrLowBitField);

		pGPIOx->GPIO_AFRL_AFRH[highOrlow] &= ~(0xF << (4 * highOrLowBitField));
		pGPIOx->GPIO_AFRL_AFRH[highOrlow] |= temp;
	}
}



