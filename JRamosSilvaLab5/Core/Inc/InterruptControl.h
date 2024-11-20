/*
 * InterruptControl.h
 *
 *  Created on: Sep 30, 2024
 *      Author: joelrsilva
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include <stm32f4xx_hal.h>
#include <stdint.h>


#define EXTI0_IRQ_NUMBER 6//Line0 interrupt


void IRQ_Enable(uint8_t irq_Numb);
void IRQ_Disable(uint8_t irq_Numb);
void IRQ_Clear_Pending(uint8_t irq_Numb);
void IRQ_Set_Pending(uint8_t irq_Numb);

void EXTI_Clear_Pending(uint8_t pinNum);
#endif /* INTERRUPTCONTROL_H_ */
