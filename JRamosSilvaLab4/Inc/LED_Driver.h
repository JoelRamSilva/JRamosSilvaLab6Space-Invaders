/*
 * LED_Driver.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "GPIO_Driver.h"
#include "Timer_Driver.h"


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#define RED_LED		0 //PG14
#define GREEN_LED	1 //PG13

void LED_Init(uint8_t ledNum);
void ToggleLED(uint8_t ledNum);
void TurnOffLED(uint8_t ledNum);
void TurnOnLED(uint8_t ledNum);

//TIMER 2 Functions
void LED_TIM2_Init();
void LED_TIM2_Start();
void LED_TIM2_Stop();
void LED_TIM2_Reset();

//TIMER 5 Functions
void LED_TIM5_Init();
void LED_TIM5_Start();
void LED_TIM5_Stop();
void LED_TIM5_Reset();

uint32_t LED_TIM5_CurrentAutoReloadValue();
uint32_t LED_TIM5_CurrentCountValue();
void LED_TIM5_ConfigAutoReload(uint32_t NewValue);
void LED_TIM5_StartFromCount(uint32_t NewValue);



#endif /* LED_DRIVER_H_ */
