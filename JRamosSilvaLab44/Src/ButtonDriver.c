/*
 * Button_Driver.c
 *
 *  Created on: Mar 16, 2024
 *      Author: joelrsilva
 */

#include <ButtonDriver.h>

void ButtonDriver_initializeButton()
{
    GPIO_Handle_t buttonConfig = {0};

    buttonConfig.pGPIOx = BUTTON_PORT_VALUE;
    buttonConfig.GPIO_PinConfig.PinNumber = BUTTON_PIN_NUMBER;
    buttonConfig.GPIO_PinConfig.PinMode = INPUT;
    buttonConfig.GPIO_PinConfig.PinSpeed = LOW_SPEED;
    buttonConfig.GPIO_PinConfig.PinPuPdControl = NO_PULL;

    GPIO_clockHandler(BUTTON_PORT_VALUE, ENABLE);

    GPIO_initialize(&buttonConfig);
}

void ButtonDriver_enableButtonClock()
{
    GPIO_clockHandler(BUTTON_PORT_VALUE, ENABLE);
}

bool ButtonDriver_buttonPressed()
{
    if (GPIO_readPin(GPIOA, BUTTON_PIN_NUMBER) == BUTTON_ON)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ButtonDriver_InitInterruptMode()
{
    GPIO_Handle_t buttonConfig = {0};


    buttonConfig.pGPIOx = BUTTON_PORT_VALUE;
    buttonConfig.GPIO_PinConfig.PinNumber = BUTTON_PIN_NUMBER;
    buttonConfig.GPIO_PinConfig.PinMode = INPUT;
    buttonConfig.GPIO_PinConfig.PinSpeed = LOW_SPEED;
    buttonConfig.GPIO_PinConfig.PinPuPdControl = NO_PULL;
    // add this for interrupt
    buttonConfig.GPIO_PinConfig.GPIO_PinIntMode = GPIO_INT_RISING_FALLING_EDGE;

    // Enable the button clock
    GPIO_clockHandler(buttonConfig.pGPIOx, ENABLE);
    GPIO_initialize(&buttonConfig);

    GPIO_NVIC_enable_disable(EXTI0_IRQ_NUMBER, ENABLE);
}
