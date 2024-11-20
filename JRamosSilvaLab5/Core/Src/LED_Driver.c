/*
 * LED_Driver.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */
#include "LED_Driver.h"

GPIO_InitTypeDef redLed;
GPIO_InitTypeDef greenLed;

void LED_Init(uint8_t ledNum){

	switch(ledNum){
	case RED_LED:
	__HAL_RCC_GPIOG_CLK_ENABLE();

	redLed.Mode = GPIO_MODE_OUTPUT_PP;
	redLed.Pin = GPIO_PIN_14;
	redLed.Speed = GPIO_SPEED_FREQ_HIGH;
	//redLed.Pull = GPIO_PIN_OPTYPE_PUSH_PULL;
	//redLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	HAL_GPIO_Init(GPIOG, &redLed);
	break;

	case GREEN_LED:
	__HAL_RCC_GPIOG_CLK_ENABLE();

	greenLed.Mode = GPIO_MODE_OUTPUT_PP;
	greenLed.Pin = GPIO_PIN_13;
	greenLed.Speed = GPIO_SPEED_FREQ_HIGH;
	//redLed.Pull = GPIO_PIN_OPTYPE_PUSH_PULL;
	//greenLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	HAL_GPIO_Init(GPIOG, &greenLed);
	break;
	}
}

void ToggleLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		HAL_GPIO_TogglePin(GPIOG, redLed.Pin);

	case GREEN_LED:
		HAL_GPIO_TogglePin(GPIOG, greenLed.Pin);
	}
}

void TurnOffLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		HAL_GPIO_WritePin(GPIOG, redLed.Pin, DISABLE);

	case GREEN_LED:
		HAL_GPIO_WritePin(GPIOG, greenLed.Pin, DISABLE);
	}
}

void TurnOnLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		HAL_GPIO_WritePin(GPIOG, redLed.Pin, ENABLE);

	case GREEN_LED:
		HAL_GPIO_WritePin(GPIOG, greenLed.Pin, ENABLE);
	}
}

