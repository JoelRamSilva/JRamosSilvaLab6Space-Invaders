/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 25, 2024
 *  Author: joelrsilva
 *
 */

#include <GPIO_Driver.h>

void GPIO_clockHandler(GPIO_RegDef_t *ptr, uint8_t toggle)
{
    if (ptr == GPIOG && toggle == 1)
    {
        AHB1_CLOCK_ENABLE(GPIOG_OFFSET);
    }
    else if (ptr == GPIOG && toggle == 0)
    {
        AHB1_CLOCK_DISABLE(GPIOG_OFFSET);
    }

    if (ptr == GPIOA && toggle == 1)
    {
        AHB1_CLOCK_ENABLE(GPIOA_OFFSET);
    }
    else if (ptr == GPIOA && toggle == 0)
    {
        AHB1_CLOCK_DISABLE(GPIOA_OFFSET);
    }
}

void GPIO_writePin(GPIO_RegDef_t *ptr, uint8_t writePin, uint8_t pinVal)
{
    if (pinVal == 0)
    {
        // odr register because it's the output data register and we want to set it as 0
        ptr->GPIOx_ODR &= ~(1 << writePin);
    }
    else if (pinVal == 1)
    {
        ptr->GPIOx_ODR |= (1 << writePin);
    }
}

void GPIO_togglePin(GPIO_RegDef_t *ptr, uint8_t pinNum)
{
    // switches between high and low states, only target pin is changed
    ptr->GPIOx_ODR ^= (1 << pinNum);
}

void GPIO_initialize(GPIO_Handle_t *ptr)
{
    // moder config
    uint32_t temp = 0;
    // get the pin mode and pin numbers
    temp = (ptr->GPIO_PinConfig.PinMode << (2 * ptr->GPIO_PinConfig.PinNumber));
    // clear the moder
    ptr->pGPIOx->GPIOx_MODER &= ~(0x3 << (2 * ptr->GPIO_PinConfig.PinNumber));
    // update the moder
    ptr->pGPIOx->GPIOx_MODER |= temp;

    // speed register
    temp = (ptr->GPIO_PinConfig.PinSpeed << (2 * ptr->GPIO_PinConfig.PinNumber));
    ptr->pGPIOx->GPIOx_OSPEEDR &= ~(0x3 << (2 * ptr->GPIO_PinConfig.PinNumber));
    ptr->pGPIOx->GPIOx_OSPEEDR |= temp;

    // pull-up/pull-down
    temp = (ptr->GPIO_PinConfig.PinPuPdControl << (2 * ptr->GPIO_PinConfig.PinNumber));
    ptr->pGPIOx->GPIOA_PUPDR &= ~(0x3 << (2 * ptr->GPIO_PinConfig.PinNumber));
    ptr->pGPIOx->GPIOA_PUPDR |= temp;

    // output type
    temp = (ptr->GPIO_PinConfig.OPType << ptr->GPIO_PinConfig.PinNumber);
    ptr->pGPIOx->GPIOx_OTYPER &= ~(1 << ptr->GPIO_PinConfig.PinNumber);
    ptr->pGPIOx->GPIOx_OTYPER |= temp;

    // alternate function
    if (ptr->GPIO_PinConfig.PinMode == ALTERNATE_FUNCTION)
    {
        uint32_t HighLowReg = ptr->GPIO_PinConfig.PinNumber / 8;
        uint32_t correctBits = ptr->GPIO_PinConfig.PinNumber % 8;

        temp = (ptr->GPIO_PinConfig.PinAltFunMode << (4 * correctBits));
        // clears the register
        ptr->pGPIOx->GPIOx_AFR[HighLowReg] &= ~(0xF << (4 * correctBits));
        // changes it to correct bits
        ptr->pGPIOx->GPIOx_AFR[HighLowReg] |= temp;
    }
    // Interrupt configuration
    if (ptr->GPIO_PinConfig.GPIO_PinIntMode != GPIO_INT_DISABLE)
    {

        uint8_t position = ptr->GPIO_PinConfig.PinNumber % 4;       // gets bit position, so we mod 4
        uint8_t register_index = ptr->GPIO_PinConfig.PinNumber / 4; // get correct exti register
        uint16_t port_code = GPIO_portNum(ptr->pGPIOx);             // Get the correct gpio port

        SYSCONFIG_CLOCK_ENABLE(SYSCONFIG_OFFSET);

        SYSCONFIG->SYSCFG_EXTICR[register_index] &= ~(0xF << (position * 4));      // Clear the EXTI configuration for the pin
        SYSCONFIG->SYSCFG_EXTICR[register_index] |= (port_code << (position * 4)); // Set the EXTI configuration for the pin

        // Configure EXTI interrupt mode
        if (ptr->GPIO_PinConfig.GPIO_PinIntMode == GPIO_INT_RISING_EDGE)
        {
            // enable rising edge trigger, disable falling edge trigger
            EXTI->EXTI_RTSR |= (1 << ptr->GPIO_PinConfig.PinNumber);
            EXTI->EXTI_FTSR &= ~(1 << ptr->GPIO_PinConfig.PinNumber);
        }
        else if (ptr->GPIO_PinConfig.GPIO_PinIntMode == GPIO_INT_FALLING_EDGE)
        {
            // enable falling edge trigger, disable rising edge trigger
            EXTI->EXTI_FTSR |= (1 << ptr->GPIO_PinConfig.PinNumber);
            EXTI->EXTI_RTSR &= ~(1 << ptr->GPIO_PinConfig.PinNumber);
        }
        else if (ptr->GPIO_PinConfig.GPIO_PinIntMode == GPIO_INT_RISING_FALLING_EDGE)
        {
            // enable rising and falling edge triggers
            EXTI->EXTI_RTSR |= (1 << ptr->GPIO_PinConfig.PinNumber);
            EXTI->EXTI_FTSR |= (1 << ptr->GPIO_PinConfig.PinNumber);
        }

        // Enable interrupt delivery
        EXTI->EXTI_IMR |= (1 << ptr->GPIO_PinConfig.PinNumber);
    }
}

uint8_t GPIO_readPin(GPIO_RegDef_t *ptr, uint8_t pinNumber)
{
    uint8_t val = ((ptr->GPIOx_IDR >> pinNumber) & 0x01);
    return val;
}
uint16_t GPIO_portNum(GPIO_RegDef_t *ptr)
{
    if (ptr == GPIOA)
        return GPIO_PORT_NUMBER_A;

    if (ptr == GPIOG)
        return GPIO_PORT_NUMBER_G;

    return 0xFFFF;
}

void GPIO_NVIC_enable_disable(uint8_t irqNum, uint8_t enable_disable)
{
    if (enable_disable) // Enable interrupt
    {
        IRQ_enable(irqNum);
    }
    else // Disable interrupt
    {
        IRQ_disable(irqNum);
    }
}
