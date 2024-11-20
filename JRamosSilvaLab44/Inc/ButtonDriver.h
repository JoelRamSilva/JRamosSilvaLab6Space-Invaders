/*
 * Button_Driver.h
 *
 *  Created on: Feb 20, 2024
 *      Author: joelrsilva
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include <STM32F429i.h>
#include <GPIO_Driver.h>
#include <stdbool.h>
#include <stdio.h>

#define BUTTON_PORT_VALUE GPIOA
#define BUTTON_PIN_NUMBER ODR0

#define BUTTON_OFF 0
#define BUTTON_ON 1

void ButtonDriver_initializeButton();

void ButtonDriver_enableButtonClock();

bool ButtonDriver_buttonPressed();

void ButtonDriver_InitInterruptMode();
#endif /* BUTTON_DRIVER_H_ */
