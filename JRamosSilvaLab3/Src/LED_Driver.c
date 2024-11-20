/*
 * LED_Driver.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */
#include "LED_Driver.h"

GPIO_PinConfig_t redLed;
GPIO_PinConfig_t greenLed;

void LED_Init(uint8_t ledNum){

	switch(ledNum){
	case RED_LED:


	redLed.PinMode = GPIO_PIN_MODE_GP;
	redLed.PinNumber = GPIO_PIN_NUM_14;
	redLed.PinSpeed = GPIO_PIN_SPEED_HIGH;
	redLed.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
	redLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

	GPIO_ClockControl(GPIOG, ENABLE);

	GPIO_Init(GPIOG, &redLed);
	break;

	case GREEN_LED:
	greenLed.PinMode = GPIO_PIN_MODE_GP;
	greenLed.PinNumber = GPIO_PIN_NUM_13;
	greenLed.PinSpeed = GPIO_PIN_SPEED_HIGH;
	greenLed.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
	greenLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

	GPIO_ClockControl(GPIOG, ENABLE);
	GPIO_Init(GPIOG, &greenLed);
	break;
	}
}

void ToggleLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		GPIO_ToggleOutputPin(GPIOG, redLed.PinNumber);

	case GREEN_LED:
		GPIO_ToggleOutputPin(GPIOG, greenLed.PinNumber);
	}
}

void TurnOffLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		GPIO_WriteToOutputPin(GPIOG, redLed.PinNumber, DISABLE);

	case GREEN_LED:
		GPIO_WriteToOutputPin(GPIOG, greenLed.PinNumber, DISABLE);
	}
}

void TurnOnLED(uint8_t ledNum){

	switch(ledNum){

	case RED_LED:
		GPIO_WriteToOutputPin(GPIOG, redLed.PinNumber, ENABLE);

	case GREEN_LED:
		GPIO_WriteToOutputPin(GPIOG, greenLed.PinNumber, ENABLE);
	}
}

