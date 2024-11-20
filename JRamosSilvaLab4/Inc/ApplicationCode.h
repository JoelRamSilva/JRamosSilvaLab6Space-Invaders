/*
 * ApplicationCode.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "LED_Driver.h"
#include "Scheduler.h"
#include "Button_Drive.h"
#include "STM32F4291.h"

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#define NAME_LENGTH 4
#define DEFAULT_DELAY 250000

// Compile-time switch for Timer usage (0 for Timer 2, 1 for Timer 5)
#define DUAL_TIMER_USAGE 0

// Button interrupt configuration
#define USE_INTERRUPT_FOR_BUTTON 1

void applicationInit();

// LED application functions
void greenLEDInit();
void redLEDInit();

void toggleGreenLED();
void toggleRedLED();

void activateGreenLED();
void activateRedLED();

void deactivateGreenLED();
void deactivateRedLED();

// Application delay function
void appDelay(uint32_t delay);

// Button application functions
void executeButtonPollingRoutine();
void buttonInterruptInit();

#endif /* APPLICATIONCODE_H_ */

