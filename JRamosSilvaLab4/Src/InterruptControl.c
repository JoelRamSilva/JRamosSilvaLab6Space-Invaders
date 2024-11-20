/*
 * InterruptControl.c
 *
 *  Created on: Sep 30, 2024
 *      Author: joelrsilva
 */
#include "InterruptControl.h"

void IRQ_Enable(uint8_t irq_Numb){
    if (irq_Numb < 32) {
        *NVIC_ISER0 |= (1 << irq_Numb);
    }
    else if (irq_Numb < 64){
        *NVIC_ISER1 |= (1 << (irq_Numb % 32));
    }
}

void IRQ_Disable(uint8_t irq_Numb){
    if (irq_Numb < 32) {
        *NVIC_ICER0 |= (1 << irq_Numb);
    }
    else if (irq_Numb < 64){
        *NVIC_ICER1 |= (1 << (irq_Numb % 32));
    }
}

void IRQ_Clear_Pending(uint8_t irq_Numb){
    if (irq_Numb < 32) {
        *NVIC_ICPR0 |= (1 << irq_Numb);
    }
    else if (irq_Numb < 64){
        *NVIC_ICPR1 |= (1 << (irq_Numb % 32));
    }
}

void IRQ_Set_Pending(uint8_t irq_Numb){
    if (irq_Numb < 32) {
        *NVIC_ISPR0 |= (1 << irq_Numb);
    }
    else if (irq_Numb < 64){
        *NVIC_ISPR1 |= (1 << (irq_Numb % 32));
    }
}

void EXTI_Clear_Pending(uint8_t pinNum){
    EXTI->EXTI_PR |= (1 << pinNum);  // Acknowledge and clear the EXTI pending interrupt
}
