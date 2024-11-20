/*
 * InterruptControl.h
 *
 *  Created on: Sep 30, 2024
 *      Author: joelrsilva
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include <stdint.h>
#include <STM32F4291.h>

#define EXTI0_IRQ_NUMBER 6//Line0 interrupt
#define TIM2_IRQ_NUMBER 28//TIM2 interrupt 0x0000 00B0
#define TIM5_IRQ_NUMBER 50//TIM5 interrupt 0x0000 0108


void IRQ_Enable(uint8_t irq_Numb);
void IRQ_Disable(uint8_t irq_Numb);
void IRQ_Clear_Pending(uint8_t irq_Numb);
void IRQ_Set_Pending(uint8_t irq_Numb);

void EXTI_Clear_Pending(uint8_t pinNum);

#endif /* INTERRUPTCONTROL_H_ */
