/*
 * ApplicationCode.c
 *
 *  Created on: Aug 29, 2024
 *      Author: joelrsilva
 */
#include <stdint.h>

#define GPIOG_RCC_ENABLE_ADDRESS	0x40023830
#define GPIOG_AHB1ENR_BIT_OFFSET	6
#define GPIOG_MODER					0x40021800
#define GPIOG_ODR 					0x40021814
#define GPIOG_MODER_OFFSET 			28
#define LED_ODR_BIT 				14

#define	FIRST_NAME_LENGTH			4

void appDelay(uint32_t delay){
	char firstName[FIRST_NAME_LENGTH] = {'j','o','e','l'};
	[[maybe_unused]] char destinationArray[FIRST_NAME_LENGTH] = {};

	for (int i = 0; i < delay; i++){
		for (int j = 0; j < FIRST_NAME_LENGTH; j++){
			destinationArray[j] = firstName[j];
		}
	}
}

void enablePeripheralsAndClocks(){
	uint32_t *clkPtr = (uint32_t*) GPIOG_RCC_ENABLE_ADDRESS;
	uint32_t *modePtr = (uint32_t*) GPIOG_MODER;
	*clkPtr |= (1 << 6);
	*modePtr &= ~(0x3 << GPIOG_MODER_OFFSET);
	*modePtr |= (0x1 << GPIOG_MODER_OFFSET);
}

void turnOnRedLED(){
	uint32_t *odrPtr = (uint32_t*) GPIOG_ODR;
	*odrPtr |= (1 << LED_ODR_BIT);
}

void turnOffRedLED(){
	uint32_t *odrPtr = (uint32_t*) GPIOG_ODR;
	*odrPtr &= ~(1 << LED_ODR_BIT);
}

void toggleRedLED(){
	uint32_t *gpiogOdrPtr = (uint32_t*) GPIOG_ODR;
	if ((*gpiogOdrPtr & (1 << LED_ODR_BIT)) != 0){
		turnOffRedLED();
	}
	else
		turnOnRedLED();
}