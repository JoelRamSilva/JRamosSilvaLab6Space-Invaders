/*
 * LED_Driver.h
 *
 *  Created on: Jan 25, 2024
 *      Author: joelrsilva
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_
#define RedLED 1
#define GreenLED 0

#include <stdio.h>
#include <stdint.h>
#include <Time_Driver.h>
#include <GPIO_Driver.h>


void initializeLED(uint8_t led);

void activateLED(uint8_t led);

void deactivateLED(uint8_t led);

void toggleLED(uint8_t led);

// timer 2
void LED_timer2Init();
void LED_timer2Stop();
void LED_timer2Start();
void LED_timer2Reset();

// timer 5
void LED_timer5Init();
void LED_timer5Stop();
void LED_timer5Start();
void LED_timer5Reset();
void LED_CountValue5Upddate(uint32_t val);

uint8_t LED_AutoReload5();

uint32_t LED_CountValue5();

void LED_configAutoReload5(uint32_t val);

void LED_timer5UpdateStart(uint32_t newVal);

#endif /* LED_DRIVER_H_ */
