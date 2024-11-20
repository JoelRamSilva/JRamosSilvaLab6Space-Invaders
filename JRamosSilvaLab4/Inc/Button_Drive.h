/*
 * Button_Drive.h
 *
 *  Created on: Sep 26, 2024
 *      Author: joelrsilva
 */

#ifndef BUTTON_DRIVE_H_
#define BUTTON_DRIVE_H_

#include "GPIO_Driver.h"
#include "stdbool.h"

#define BUTTON_PORT			GPIOA
#define BUTTON_PIN			0
#define BUTTON_PRESSED		1
#define	BUTTON_NOT_PRESSED	0


void buttonInit();
void buttonClock();
bool buttonStatus();

void button_Init_Interrup_Mode();


#endif /* BUTTON_DRIVE_H_ */
