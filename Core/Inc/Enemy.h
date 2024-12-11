/*
 * Enemy.h
 *
 *  Created on: Nov 21, 2024
 *      Author: joelrsilva
 */

#ifndef INC_ENEMY_H_
#define INC_ENEMY_H_

#include <stdlib.h>
#include <stdbool.h>
#include "LCD_Driver.h"
#include "RNG.h"
#include "Game_Play.h"

#define ENEMY_TYPE_METEOR 1
#define ENEMY_TYPE_SPACESHIP 2
#define ENEMY_TYPE_ALIEN 3


#define MAX_MONSTER 3 // Maximum number of bullets on the screen at once
extern int activeMeteorCount;

typedef struct {
    int x;      // X-coordinate
    int y;      // Y-coordinate
    int width;
    int height;
    int speed;  // Falling speed
    bool active;  // Active status
    int type;
} Monster;

extern Monster monster[MAX_MONSTER];

void init_Enemy(void);
void spawn_Enemy(void);
void update_Enemy(void);
void render_Enemy(Monster monster[], int monsterCount);
//void spawn_meteor(Monster monster[], int count);
//void spawn_spaceship(Monster monster[], int count);


#endif /* INC_ENEMY_H_ */
