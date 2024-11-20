

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include <stdio.h>
#include <STM32F429i.h>
#include <InterruptControl.h>

#define ODR0 0
#define ODR1 1
#define ODR2 2
#define ODR3 3
#define ODR4 4
#define ODR5 5
#define ODR6 6
#define ODR7 7
#define ODR8 8
#define ODR9 9
#define ODR10 10
#define ODR11 11
#define ODR12 12
#define ODR13 13
#define ODR14 14
#define ODR15 15


#define INPUT 0
#define OUTPUT 1
#define ALTERNATE_FUNCTION 2
#define ANALOG 3

#define PUSH_PULL 0
#define OPEN_DRAIN 1

#define NO_PULL 00
#define PULL_UP 01
#define PULL_DOWN 10
#define RESERVED 11

#define LOW_SPEED 00
#define MEDIUM_SPEED 01
#define HIGH_SPEED 10
#define HIGHEST_SPEED 11

#define GPIO_INT_DISABLE 0
#define GPIO_INT_FALLING_EDGE 1
#define GPIO_INT_RISING_EDGE 2
#define GPIO_INT_RISING_FALLING_EDGE 3

#define GPIO_PORT_NUMBER_A 0
#define GPIO_PORT_NUMBER_B 1
#define GPIO_PORT_NUMBER_C 2
#define GPIO_PORT_NUMBER_D 3
#define GPIO_PORT_NUMBER_E 4
#define GPIO_PORT_NUMBER_F 5
#define GPIO_PORT_NUMBER_G 6
#define GPIO_PORT_NUMBER_H 7
#define GPIO_PORT_NUMBER_I 8
#define GPIO_PORT_NUMBER_J 9
#define GPIO_PORT_NUMBER_K 10

typedef struct
{
    uint8_t PinNumber;       // Pin Number
    uint8_t PinMode;         // Pin Mode
    uint8_t OPType;          // Output Type
    uint8_t PinSpeed;        // Pin Speed
    uint8_t PinPuPdControl;  // Pin Push up/ Pull Down Control
    uint8_t PinAltFunMode;   // Alternate Function mode
    uint8_t GPIO_PinIntMode;
} GPIO_PinConfig_t;


typedef struct
{
    GPIO_RegDef_t *pGPIOx;           // GPIO port
    GPIO_PinConfig_t GPIO_PinConfig; // The pin configuraitons
} GPIO_Handle_t;


void GPIO_initialize(GPIO_Handle_t *ptr);

void GPIO_clockHandler(GPIO_RegDef_t *ptr, uint8_t toggle);

void GPIO_togglePin(GPIO_RegDef_t *ptr, uint8_t pinNum);

void GPIO_writePin(GPIO_RegDef_t *ptr, uint8_t writePin, uint8_t pinVal);

uint8_t GPIO_readPin(GPIO_RegDef_t *ptr, uint8_t pinNumber);

uint16_t GPIO_portNum(GPIO_RegDef_t *ptr);

void GPIO_NVIC_enable_disable(uint8_t irqNum, uint8_t enable_disable);
#endif /* GPIO_DRIVER_H_ */
