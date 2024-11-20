/*
 * Timer_Driver.c
 *
 *  Created on: Oct 9, 2024
 *      Author: joelrsilva
 */
#include "Timer_Driver.h"

void Timer_Init(GPTIMR_RegDef_t *pTimerConfig, GPTimer_Config_t *pinTimer) {
    uint32_t temp = 0;

    // Clear clock division bits and set the new clock division
    temp = pTimerConfig->TIMx_CR1 & ~TIMER_CR1_CKD_MASK;
    temp |= (pinTimer->Clock_Division_Select & TIMER_CR1_CKD_MASK);

    // Clear and set center-aligned mode selection
    temp &= ~TIMER_CR1_CMS_MASK;
    temp |= (pinTimer->Center_Align_Mode_Select & TIMER_CR1_CMS_MASK);

    // Configure timer up/down counting mode
    if (pinTimer->Timer_CountDown_Mode_enable) {
        temp |= TIMER_DIR_DOWNCOUNT;  // Enable down-counting mode
    } else {
        temp &= ~TIMER_DIR_DOWNCOUNT; // Enable up-counting mode
    }

    // Configure auto-reload buffer enablement
    if (pinTimer->Auto_Reload_Buffer_Enable) {
        temp |= TIMER_AUTORELOAD_ENABLE; // Enable auto-reload buffer
    } else {
        temp &= ~TIMER_AUTORELOAD_ENABLE; // Disable auto-reload buffer
    }

    // Configure one-pulse mode
    if (pinTimer->One_Pulse_Mode_enable) {
        temp |= TIMER_OPM_ENABLE;  // Enable one-pulse mode
    } else {
        temp &= ~TIMER_OPM_ENABLE; // Disable one-pulse mode
    }

    // Configure update event disablement
    if (pinTimer->Disable_Update_event) {
        temp |= TIMER_UDIS_DISABLE;  // Disable update events
    } else {
        temp &= ~TIMER_UDIS_DISABLE; // Enable update events
    }

    // Store the updated configuration in CR1
    pTimerConfig->TIMx_CR1 = temp;

    // Configure master mode selection in CR2
    if (pinTimer->Master_Mode_Select) {
        pTimerConfig->TIMx_CR2 |= (TIMER_MMS_ENABLE); // Enable master mode
    } else {
        pTimerConfig->TIMx_CR2 &= ~(TIMER_MMS_ENABLE); // Disable master mode
    }

    // Set prescaler and auto-reload values
    pTimerConfig->TIMx_PSC = pinTimer->Prescaler_Value;
    pTimerConfig->TIMx_ARR = pinTimer->Auto_Reload;

    // Enable or disable interrupt update functionality
    if (pinTimer->Interrupt_update_enable) {
        Timer_Interrupt_Toggle(pTimerConfig, TIMER_ENABLE);
    } else {
        Timer_Interrupt_Toggle(pTimerConfig, TIMER_DISABLE);
    }

    // Start the timer immediately
    Timer_Start(pTimerConfig);
}

void Timer_ClockControl(GPTIMR_RegDef_t *pTimerConfig, uint8_t toggle) {
    if (pTimerConfig == TIM2) {
        if (toggle == TIMER_ENABLE) {
            RCC_TIMx_ENABLE(TIM2_RCC_OFFSET); // Enable TIM2 clock
        } else {
            RCC_TIMx_DISABLE(TIM2_RCC_OFFSET); // Disable TIM2 clock
        }
    } else if (pTimerConfig == TIM5) {
        if (toggle == TIMER_ENABLE) {
            RCC_TIMx_ENABLE(TIM5_RCC_OFFSET); // Enable TIM5 clock
        } else {
            RCC_TIMx_DISABLE(TIM5_RCC_OFFSET); // Disable TIM5 clock
        }
    }
}

void Timer_Start(GPTIMR_RegDef_t *pTimerConfig) {
    pTimerConfig->TIMx_CR1 &= ~(TIMER_CEN_ENABLE); // Start timer by setting CEN bit
    pTimerConfig->TIMx_CR1 |= (TIMER_CEN_ENABLE);
}

void Timer_Stop(GPTIMR_RegDef_t *pTimerConfig) {
    pTimerConfig->TIMx_CR1 &= ~(TIMER_CEN_DISABLE); // Stop timer by clearing CEN bit
    pTimerConfig->TIMx_CR1 |= TIMER_CEN_DISABLE; // Stop timer by clearing CEN bit

}

void Timer_Reset(GPTIMR_RegDef_t *pTimerConfig) {
    pTimerConfig->TIMx_CNT = 0U; // Reset counter to 0
}

uint32_t Timer_Auto_Reload(GPTIMR_RegDef_t *pTimerConfig) {
    return pTimerConfig->TIMx_ARR; // Return the auto-reload value
}

uint32_t Timer_Value(GPTIMR_RegDef_t *pTimerConfig) {
    return pTimerConfig->TIMx_CNT; // Return the current timer count
}

void Timer_Interrupt_Toggle(GPTIMR_RegDef_t *pTimerConfig, uint8_t toggle) {
    if (toggle == TIMER_ENABLE) {
        pTimerConfig->TIMx_DIER |= (1 << TIMER_DIER_UIE_BIT_POS); // Enable update interrupt
    } else {
        pTimerConfig->TIMx_DIER &= ~(1 << TIMER_DIER_UIE_BIT_POS); // Disable update interrupt
    }
}
