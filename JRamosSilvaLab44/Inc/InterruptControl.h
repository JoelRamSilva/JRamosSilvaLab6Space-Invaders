/*
 * InterruptControl.h
 *
 *  Created on: Feb 23, 2024
 *      Author: joelrsilva
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include <stdint.h>
#include <STM32F429i.h>
#include <stdio.h>
#include <STM32F429i.h>
#include <InterruptControl.h>


#define EXTI0_IRQ_NUMBER 6
#define TIM2_IRQ_NUMBER 28
#define TIM5_IRQ_NUMBER 50

void IRQ_enable(uint8_t irqNumber);

void IRQ_disable(uint8_t irqNumber);

void IRQ_clear(uint8_t irqNumber);

void IRQ_set(uint8_t irqNumber);

void EXTI_IRQ_clearPending(uint8_t pinNumber);

#endif // INTERRUPTCONTROL_H_
