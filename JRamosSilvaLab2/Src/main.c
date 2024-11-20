/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "ApplicationCode.h"
#include "Scheduler.h"
#include "GPIO_Driver.h"
#include <stdint.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{


	applicationInit();
	int eventsToRun = 0;

    /* Loop forever */
	for(;;){

	eventsToRun = getScheduledEvents();

	if(eventsToRun & LED_TOGGLE_EVENT){
		toggleRedLED();
	}
	if(eventsToRun & LED_DELAY_EVENT){
		appDelay(DEFAULT_DELAY);
	}
	}
}