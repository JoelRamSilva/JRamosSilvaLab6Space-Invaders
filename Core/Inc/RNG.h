/*
 * RNG.h
 *
 *  Created on: Nov 21, 2024
 *      Author: joelrsilva
 */

#ifndef INC_RNG_H_
#define INC_RNG_H_

#include "stm32f4xx_hal.h"

// Initializes the RNG peripheral
void RNG_Init(void);

// Generates a random 32-bit number
uint32_t RNG_GetRandomNumber(void);

// Generates a random number in a specified range
uint32_t RNG_GetRandomInRange(uint32_t min, uint32_t max);


#endif /* INC_RNG_H_ */
