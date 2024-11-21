/*
 * Game_Play.h
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */

#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#include <stdbool.h>
#include <stdio.h>
#include "Rocket.h"
#include "LCD_Driver.h"

#include "stmpe811.h"
#include "ApplicationCode.h"


void game_init(void);
void game_update(uint16_t x, uint16_t y);
void game_render(void);


#endif // GAME_PLAY_H
