/*
 * GPIO_Driver.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "STM32F4291.h"
#include "InterruptControl.h"


typedef struct{
uint8_t PinNumber; 	// Pin Number
uint8_t PinMode; 	// Pin Mode
uint8_t OPType; 	// Output Type
uint8_t PinSpeed; 	// Pin Speed
uint8_t PinPuPdControl; // Pin Push up/ Pull Down Control
uint8_t PinAltFunMode; // Alternate Function mode
uint8_t InterruptMode;
}GPIO_PinConfig_t;

#define GPIO_PIN_NUM_0 0
#define GPIO_PIN_NUM_1 1
#define GPIO_PIN_NUM_2 2
#define GPIO_PIN_NUM_3 3
#define GPIO_PIN_NUM_4 4
#define GPIO_PIN_NUM_5 5
#define GPIO_PIN_NUM_6 6
#define GPIO_PIN_NUM_7 7
#define GPIO_PIN_NUM_8 8
#define GPIO_PIN_NUM_9 9
#define GPIO_PIN_NUM_10 10
#define GPIO_PIN_NUM_11 11
#define GPIO_PIN_NUM_12 12
#define GPIO_PIN_NUM_13 13
#define GPIO_PIN_NUM_14 14
#define GPIO_PIN_NUM_15 15

#define GPIO_PIN_MODE_INPUT		0
#define GPIO_PIN_MODE_GP		1
#define GPIO_PIN_MODE_AFM		2
#define GPIO_PIN_MODE_ANALOG	3

#define GPIO_PIN_OPTYPE_PUSH_PULL	0
#define GPIO_PIN_OPTYPE_OPEN_DRAIN	1

#define GPIO_PIN_SPEED_LOW			00
#define GPIO_PIN_SPEED_MEDIUM		01
#define GPIO_PIN_SPEED_HIGH			10
#define GPIO_PIN_SPEED_VERY_HIGH	11

#define GPIO_PIN_PULL_UPDOWN_NOPULL		00
#define GPIO_PIN_PULL_UPDOWN_PULL_UP	01
#define GPIO_PIN_PULL_UPDOWN_PULL_DOWN	10
#define GPIO_PIN_PULL_UPDOWN_RESERVED	11

//Interrupt Macros
#define NO_INTERRUPT 				0
#define	FALLING_EDGE_INTERRUPT		1
#define	RISING_EDGE_INTERRUPT		2
#define	FALLING_RISING_INTERRUPT	3

#define GPIOA_PORT	0
#define GPIOB_PORT	1
#define GPIOC_PORT	2
#define GPIOD_PORT	3
#define GPIOE_PORT	4
#define GPIOF_PORT	5
#define GPIOG_PORT	6
#define GPIOH_PORT	7
#define GPIOI_PORT	8
#define GPIOJ_PORT	9
#define GPIOK_PORT	10

void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t *pPinConfig);
void GPIO_ClockControl(GPIO_RegDef_t *pPinConfig, uint8_t enableDisable);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum, uint8_t pValue); //Writes to the specified output pin of the provided GPIO port
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum);
uint16_t getPortNumb(GPIO_RegDef_t *pPinConfig);
void NVIC_Toggle(uint8_t irq_Num, uint8_t toggle_Control);




#endif /* GPIO_DRIVER_H_ */
