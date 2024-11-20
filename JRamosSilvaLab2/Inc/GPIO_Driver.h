/*
 * GPIO_Driver.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "STM32F4291.h"


typedef struct{
uint8_t PinNumber; 	// Pin Number
uint8_t PinMode; 	// Pin Mode
uint8_t OPType; 	// Output Type
uint8_t PinSpeed; 	// Pin Speed
uint8_t PinPuPdControl; // Pin Push up/ Pull Down Control
uint8_t PinAltFunMode; // Alternate Function mode
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

void GPIO_Init(GPIO_RegDef_t *pGPIOx, GPIO_PinConfig_t pPinConfig);
void GPIO_ClockControl(GPIO_RegDef_t *pPinConfig, uint8_t enableDisable);
uint8_t ReadFromInputPin(GPIO_RegDef_t *pPinConfig, uint8_t pinToRead);
void WriteToOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum, uint8_t pValue); //Writes to the specified output pin of the provided GPIO port
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pPinConfig, uint8_t pNum);


#endif /* GPIO_DRIVER_H_ */
