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
#include "LCD_Driver.h"
#include "stmpe811.h"
#include "ApplicationCode.h"
#include "Enemy.h"
#include "Rocket.h"

extern int scoreKeeper;
extern int gameMode;

void game_init(void);
void game_update(uint16_t x, uint16_t y);
void game_render(void);
bool check_collision_rocket(int rocketX, int rocketY, int rocketWidth, int rocketHeight, int monsterX, int monsterY, int monsterWidth, int monsterHeight);
bool check_collision(int bulletX, int bulletY, int monsterX, int monsterY, int monsterWidth, int monsterHeight);
void scoreKeeping(int points);
void game_over(void);

#endif // GAME_PLAY_H
