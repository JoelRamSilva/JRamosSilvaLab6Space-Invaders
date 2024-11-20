/*
 * InterruptControl.c
 *
 *  Created on: Feb 23, 2024
 *      Author: joelrsilva
 */

#include <InterruptControl.h>

void IRQ_enable(uint8_t irqNumber){

    if (irqNumber < 32){
        *NVIC_ISER0 |= (1 << (irqNumber % 32));
    }
    else if (irqNumber < 64){
        *NVIC_ISER1 |= (1 << (irqNumber % 32));
    }
}
void IRQ_disable(uint8_t irqNumber){
    if (irqNumber < 32){
        *NVIC_ICER0 |= (1 << (irqNumber % 32));
    }
    else if (irqNumber < 64){
        *NVIC_ICER1 |= (1 << (irqNumber % 32));
    }
}

void IRQ_set(uint8_t irqNumber){
    if (irqNumber < 32){
        *NVIC_ISPR0 |= (1 << (irqNumber % 32));
    }
    else if (irqNumber < 64){
        *NVIC_ISPR1 |= (1 << (irqNumber % 32));
    }
}

void IRQ_clear(uint8_t irqNumber){
    if (irqNumber < 32){
        *NVIC_ICPR0 |= (1 << (irqNumber % 32));
    }
    else if (irqNumber < 64){
        *NVIC_ICPR1 |= (1 << (irqNumber % 32));
    }
}


void EXTI_IRQ_clearPending(uint8_t pinNumber){

    EXTI->EXTI_PR |= (1 << pinNumber);
}
