/*
 * Button_Drive.c
 *
 *  Created on: Sep 26, 2024
 *      Author: joelrsilva
 */

#include <Button_Drive.h>



void buttonInit(){
	GPIO_PinConfig_t userButton = {0};

	userButton.PinMode = GPIO_PIN_MODE_INPUT;
	userButton.PinNumber = BUTTON_PIN;
	userButton.PinSpeed = GPIO_PIN_SPEED_LOW;
	userButton.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
	userButton.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

	buttonClock();
	GPIO_Init(GPIOA, &userButton);
}

void buttonClock(){
	GPIO_ClockControl(GPIOA, ENABLE);
}

bool buttonStatus(){

	if (GPIO_ReadFromInputPin(GPIOA, BUTTON_PIN) == BUTTON_PRESSED){
		return true;
	}
	else{
		return false;
	}
}

void button_Init_Interrup_Mode(){
	GPIO_PinConfig_t userButton = {0};

	userButton.PinMode = GPIO_PIN_MODE_INPUT;
	userButton.PinNumber = BUTTON_PIN;
	userButton.PinSpeed = GPIO_PIN_SPEED_LOW;
	userButton.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
	userButton.PinPuPdControl = GPIO_PIN_PULL_UPDOWN_NOPULL;
	userButton.InterruptMode = FALLING_RISING_INTERRUPT;

	buttonClock();
	GPIO_Init(GPIOA, &userButton);
	NVIC_Toggle(EXTI0_IRQ_NUMBER, SET);
}
