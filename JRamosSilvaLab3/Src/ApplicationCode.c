/*
 * ApplicationCode.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "ApplicationCode.h"

void applicationInit(){
	 greenLEDInit();
	 deactivateGreenLED();
 	 executeButtonPollingRoutine();

#if	USE_INTERRUPT_FOR_BUTTON != 0
	 buttonInterruptInit();

#elif USE_INTERRUPT_FOR_BUTTON == 0 //check if it is set to 0
	 buttonInit();
	 addSchedulerEvent(BUTTON_POOL_EVENT);
#endif
	 addSchedulerEvent(LED_DELAY_EVENT);
}



void executeButtonPollingRoutine(){
	 if (buttonStatus()){
		 activateGreenLED();
	 }
	 else{
		 deactivateGreenLED();
	 }
}

void greenLEDInit(){
	 LED_Init(GREEN_LED);
}

void redLEDInit(){
	 LED_Init(RED_LED);
}

void toggleGreenLED(){
	ToggleLED(GREEN_LED);
}

void toggleRedLED(){
	ToggleLED(RED_LED);
}

void activateGreenLED(){
	TurnOnLED(GREEN_LED);
}

void activateRedLED(){
	TurnOnLED(RED_LED);
}

void deactivateGreenLED(){
	TurnOffLED(GREEN_LED);
}

void deactivateRedLED(){
	TurnOffLED(RED_LED);
}

void appDelay(uint32_t delay){
	char firstName[NAME_LENGTH] = "Joel";
	[[maybe_unused]]char nameDestination[NAME_LENGTH] = {};

	for (int i = 0; i < DEFAULT_DELAY; i++){
		for (int j = 0; j < NAME_LENGTH; j++){
			nameDestination[j] = firstName[j];
		}
	}
}

#if USE_INTERRUPT_FOR_BUTTON == 0
	buttonInit();
	executeButtonPollingRoutine();
#elif USE_INTERRUPT_FOR_BUTTON == 1
void buttonInterruptInit(){
	button_Init_Interrup_Mode();
}
#endif


void EXTI0_IRQHandler(){
	NVIC_Toggle(EXTI0_IRQ_NUMBER, DISABLE);
	toggleGreenLED();
	EXTI_Clear_Pending(BUTTON_PIN);
	NVIC_Toggle(EXTI0_IRQ_NUMBER, ENABLE);
}







