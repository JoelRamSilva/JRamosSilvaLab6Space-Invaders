/*
 * Timer_Game.h
 *
 *  Created on: Dec 5, 2024
 *      Author: joelrsilva
 */



#ifndef INC_TIMER_GAME_H_
#define INC_TIMER_GAME_H_

#include "Game_Play.h"

extern uint32_t elapsedTime;
extern uint32_t sysTime;
void showTimer(void);
void displayTimer(void);
void resetTimer(void);
#endif /* INC_TIMER_GAME_H_ */
