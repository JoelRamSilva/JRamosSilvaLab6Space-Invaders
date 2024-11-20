/*
 * ApplicationCode.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "LED_Driver.h"
#include "Scheduler.h"

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#define NAME_LENGTH 4
#define DEFAULT_DELAY 250000

void applicationInit();

void greenLEDInit();
void redLEDInit();

void toggleGreenLED();
void toggleRedLED();

void activateGreenLED();
void activateRedLED();

void deactivateGreenLED();
void deactivateRedLED();

void appDelay(uint32_t delay);
#endif /* APPLICATIONCODE_H_ */
