/*
 * InterruptControl.c
 *
 *  Created on: Sep 30, 2024
 *      Author: joelrsilva
 */
#include <InterruptControl.h>


void IRQ_Enable(uint8_t irq_Numb){
	HAL_NVIC_EnableIRQ(irq_Numb);
}

void IRQ_Disable(uint8_t irq_Numb){
	HAL_NVIC_DisableIRQ(irq_Numb);
}

void IRQ_Clear_Pending(uint8_t irq_Numb){
	HAL_NVIC_ClearPendingIRQ(irq_Numb);
}

void IRQ_Set_Pending(uint8_t irq_Numb){
	HAL_NVIC_SetPendingIRQ(irq_Numb);
}

void EXTI_Clear_Pending(uint8_t pinNum){
	__HAL_GPIO_EXTI_CLEAR_IT(pinNum);
}
