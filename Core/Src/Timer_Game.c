/*
 * Timer_Game.c
 *
 *  Created on: Dec 5, 2024
 *      Author: joelrsilva
 */
#include "Timer_Game.h"
bool gotInitTimer = true;
uint32_t elapsedTime = 0;
uint32_t sysTime;

int secondCounter;
int secondDeciCounter;
int minuteCounter;
int minuteDeciCounter;


void showTimer(void) {
    //Get initial time
    if (gotInitTimer) {
    	sysTime = HAL_GetTick();
        gotInitTimer = false;
    }

    //Zerio tick time to initial game time
    uint32_t currentTickTime = HAL_GetTick();
    elapsedTime = currentTickTime - sysTime;


    int totalSeconds = elapsedTime / 1000; // Total seconds
    int seconds = totalSeconds % 60;      // Seconds
    int minutes = totalSeconds / 60;      // Minutes

	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16x24);

    // Minutes
    char displayMin = '0' + (minutes % 10);
    LCD_DisplayChar(25, 15, displayMin);

    // Seconds decimal
    LCD_DisplayChar(37, 13, ':');
    char displaySecTens = '0' + (seconds / 10);
    LCD_DisplayChar(48, 15, displaySecTens);

    // Single Seconds
    char displaySecOnes = '0' + (seconds % 10);
    LCD_DisplayChar(64, 15, displaySecOnes);
}

void resetTimer(void) {
    // Reset timer variables
    gotInitTimer = true; // Ensure initialization happens again
    sysTime = 0;
    secondCounter = 0;
    secondDeciCounter = 0;
    minuteCounter = 0;
    minuteDeciCounter = 0;
}
