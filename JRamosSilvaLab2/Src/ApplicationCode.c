/*
 * ApplicationCode.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "ApplicationCode.h"

void applicationInit(){
	 redLEDInit();
	 addSchedulerEvent(LED_TOGGLE_EVENT);
	 addSchedulerEvent(LED_DELAY_EVENT);
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
