/*
 * LED_Driver.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */
#include "LED_Driver.h"

GPIO_PinConfig_t redLed;
GPIO_PinConfig_t greenLed;

void LED_Init(uint8_t ledNum){

    switch(ledNum){
    case RED_LED:
        redLed.PinMode = GPIO_PIN_MODE_GP;
        redLed.PinNumber = GPIO_PIN_NUM_14;
        redLed.PinSpeed = GPIO_PIN_SPEED_HIGH;
        redLed.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
        redLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

        GPIO_ClockControl(GPIOG, ENABLE);

        GPIO_Init(GPIOG, &redLed);
        break;

    case GREEN_LED:
        greenLed.PinMode = GPIO_PIN_MODE_GP;
        greenLed.PinNumber = GPIO_PIN_NUM_13;
        greenLed.PinSpeed = GPIO_PIN_SPEED_HIGH;
        greenLed.OPType = GPIO_PIN_OPTYPE_PUSH_PULL;
        greenLed.PinPuPdControl = GPIO_PIN_OPTYPE_PUSH_PULL;

        GPIO_ClockControl(GPIOG, ENABLE);
        GPIO_Init(GPIOG, &greenLed);
        break;
    }
}

void ToggleLED(uint8_t ledNum){
    switch(ledNum){
    case RED_LED:
        GPIO_ToggleOutputPin(GPIOG, redLed.PinNumber);
        break;
    case GREEN_LED:
        GPIO_ToggleOutputPin(GPIOG, greenLed.PinNumber);
        break;
    }
}

void TurnOffLED(uint8_t ledNum){
    switch(ledNum){
    case RED_LED:
        GPIO_WriteToOutputPin(GPIOG, redLed.PinNumber, DISABLE);
        break;
    case GREEN_LED:
        GPIO_WriteToOutputPin(GPIOG, greenLed.PinNumber, DISABLE);
        break;
    }
}

void TurnOnLED(uint8_t ledNum){
    switch(ledNum){
    case RED_LED:
        GPIO_WriteToOutputPin(GPIOG, redLed.PinNumber, ENABLE);
        break;
    case GREEN_LED:
        GPIO_WriteToOutputPin(GPIOG, greenLed.PinNumber, ENABLE);
        break;
    }
}

void LED_TIM2_Init(){
	GPTimer_Config_t tim2;

    // Configure Timer 2 for 5-second interval
	tim2.Auto_Reload = 79999999 ;   // Adjust based on clock frequency and desired period
    tim2.Prescaler_Value = 0;  // Adjust prescaler as needed
    tim2.Auto_Reload_Buffer_Enable = false;
    tim2.Center_Align_Mode_Select = TIMER_MODE_EDGE_ALIGNED;
    tim2.Clock_Division_Select = TIMER_CKD_DIV_1;
    tim2.Disable_Update_event = false;
    tim2.Interrupt_update_enable = true;
    tim2.Master_Mode_Select = TIMER_MMS_RESET;
    tim2.One_Pulse_Mode_enable = false;
    tim2.Timer_CountDown_Mode_enable = false;

    Timer_ClockControl(TIM2, ENABLE);
    Timer_Init(TIM2, &tim2);
    IRQ_Enable(TIM2_IRQ_NUMBER);
}

void LED_TIM5_Init(){
	GPTimer_Config_t tim5;

    // Configure Timer 5 for custom interval
    tim5.Auto_Reload = 0xffffffff;   // Adjust based on clock frequency and desired period
    tim5.Prescaler_Value = 0;  // Adjust prescaler as needed
    tim5.Auto_Reload_Buffer_Enable = false;
    tim5.Center_Align_Mode_Select = TIMER_MODE_EDGE_ALIGNED;
    tim5.Clock_Division_Select = TIMER_CKD_DIV_4;
    tim5.Disable_Update_event = false;
    tim5.Interrupt_update_enable = true;
    tim5.Master_Mode_Select = TIMER_MMS_RESET;
    tim5.One_Pulse_Mode_enable = false;
    tim5.Timer_CountDown_Mode_enable = false;

    Timer_ClockControl(TIM5, ENABLE);
    Timer_Init(TIM5, &tim5);
    IRQ_Enable(TIM5_IRQ_NUMBER);
}

void LED_TIM2_Start(){
    Timer_Start(TIM2);
}

void LED_TIM5_Start(){
    Timer_Start(TIM5);
}

void LED_TIM2_Stop(){
    Timer_Stop(TIM2);
}

void LED_TIM5_Stop(){
    Timer_Stop(TIM5);
}

void LED_TIM2_Reset(){
    Timer_Reset(TIM2);
}

void LED_TIM5_Reset(){
    Timer_Reset(TIM5);
}

uint32_t LED_TIM5_CurrentAutoReloadValue() {
    return TIM5->TIMx_ARR;  // Get current count value from Timer 5
}

uint32_t LED_TIM5_CurrentCountValue(){
	return TIM5->TIMx_CNT;

}

void LED_TIM5_ConfigAutoReload(uint32_t NewValue) {
    TIM5->TIMx_ARR = NewValue; // Update the auto-reload value for Timer 5
}

void LED_TIM5_StartFromCount(uint32_t NewValue) {
    Timer_Stop(TIM5); // Stop Timer 5
    LED_TIM5_ConfigAutoReload(NewValue); // Set the new auto-reload value
    Timer_Reset(TIM5); // Reset Timer 5
    Timer_Start(TIM5); // Start Timer 5 again with the new value
}

