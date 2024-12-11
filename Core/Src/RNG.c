/*
 * RNG.c
 *
 *  Created on: Nov 21, 2024
 *      Author: joelrsilva
 */


#include "RNG.h"

RNG_HandleTypeDef hrng;

void RNG_Init(void) {
    // Enable RNG clock
    __HAL_RCC_RNG_CLK_ENABLE();

    // initialize RNG handle
    hrng.Instance = RNG;

    // Initialize RNG
    if (HAL_RNG_Init(&hrng) != HAL_OK) {
    }
}

uint32_t RNG_GetRandomNumber(void) {
    uint32_t randomNumber;
    if (HAL_RNG_GenerateRandomNumber(&hrng, &randomNumber) != HAL_OK) {
    }
    return randomNumber;
}

uint32_t RNG_GetRandomInRange(uint32_t min, uint32_t max) {
    uint32_t randomNumber = RNG_GetRandomNumber();
    return (randomNumber % (max - min + 1)) + min;
}
