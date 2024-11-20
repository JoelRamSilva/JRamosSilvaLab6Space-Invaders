/*
 * ApplicationCode.c
 *
 *  Created on: Jan 25, 2024
 *      Author: joelrsilva
 */

#include <ApplicationCode.h>
//volatile bool flagStarted = false;
// initialize LED
void GreenInt()
{
    initializeLED(GreenLED);
}
void RedInt()
{
    initializeLED(RedLED);
}
void BothInt()
{
    initializeLED(RedLED);
    initializeLED(GreenLED);
}

void executeButtonPollingRoutine(){
    if (ButtonDriver_buttonPressed()){
        // GreenToggle();
        GreenOn();
    }
    else{
        GreenOff();
    }
}

// toggle LED
void GreenToggle(){
    toggleLED(GreenLED);
}
void RedToggle(){
    toggleLED(RedLED);
}


void GreenOn(){
    activateLED(GreenLED);
}
void RedOn(){
    activateLED(RedLED);
}

// turn off LED
void GreenOff(){
    deactivateLED(GreenLED);
}
void RedOff(){
    deactivateLED(RedLED);
}

void delayProto(uint32_t timeDelay){
    char name[NAME_LENGTH] = "Joel";
    [[maybe_unused]] char destination[NAME_LENGTH];
    for (int i = 0; i < timeDelay; i++)
    {
        for (int j = 0; j < NAME_LENGTH; j++)
        {
            destination[j] = name[j];
        }
    }
}

#if DAUL_TIMER_USAGE
void Application_ButtonInitInterruptMode(){
    // Initialize the button for interrupt mode
    ButtonDriver_InitInterruptMode();
}
#endif


void Application_Init(){

    BothInt();

#if DAUL_TIMER_USAGE
    // Timer 5 and Button Initialization for DAUL_TIMER_USAGE = 1
    Application_ButtonInitInterruptMode();
    LED_timer5Init();
#else
    // Timer 2 Initialization for DAUL_TIMER_USAGE = 0
    LED_timer2Init();
    LED_timer2Start();
#endif

    // Common initialization logic
    addScheduledEvents(DELAYEVENT);
}

#if !DAUL_TIMER_USAGE
void TIM2_IRQHandler(void){
    if (TIM2->TIMx_SR & 0x01){
        TIM2->TIMx_SR &= ~(0x01);

        static uint8_t ledState = 0;
        if (ledState){
            RedOff(); // Turn off the Red LED
            ledState = 0;
        }
        else{
            RedOn(); // Turn on the Red LED for 3 seconds
            ledState = 1;

            LED_timer2Reset();
        }
    }
}

#endif

// Timer 5's Interrupt Handler - Compile in only if DAUL_TIMER_USAGE is 1
#if DAUL_TIMER_USAGE
void TIM5_IRQHandler(void){
	TimerInterrupt(TIM5, DISABLE);
    if (TIM5->TIMx_SR & 0x1) // Check update interrupt flag
    {
        TIM5->TIMx_SR &= ~(0x01); // Clear interrupt flag
        IRQ_clear(TIM5_IRQ_NUMBER);
        GreenToggle();
    }
	TimerInterrupt(TIM5, ENABLE);

}
#endif

#if DAUL_TIMER_USAGE
void EXTI0_IRQHandler(){
    // Disable the interrupt
    GPIO_NVIC_enable_disable(EXTI0_IRQ_NUMBER, DISABLE);

    if (ButtonDriver_buttonPressed()){
		LED_timer5Start();

    }
    else{
		LED_timer5Stop();
		uint32_t elapsedTime = LED_CountValue5();
		LED_configAutoReload5(elapsedTime);
		LED_timer5Reset();
		LED_timer5Start(); // Start Timer 5 to wait for the duration
    }
	EXTI_IRQ_clearPending(BUTTON_PIN_NUMBER);
	GPIO_NVIC_enable_disable(EXTI0_IRQ_NUMBER, ENABLE);

}

#endif
