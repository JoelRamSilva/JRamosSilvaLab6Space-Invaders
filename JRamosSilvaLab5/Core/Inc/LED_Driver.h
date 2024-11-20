/*
 * LED_Driver.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include <stm32f4xx_hal.h>


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#define RED_LED		0 //PG14
#define GREEN_LED	1 //PG13

void LED_Init(uint8_t ledNum);
void ToggleLED(uint8_t ledNum);
void TurnOffLED(uint8_t ledNum);
void TurnOnLED(uint8_t ledNum);


#endif /* LED_DRIVER_H_ */
