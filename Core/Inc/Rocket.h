/*
 * Rocket.h
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */
#include "stdbool.h"
#include "LCD_Driver.h"
#include "Enemy.h"
#include "Game_Play.h"

#ifndef ROCKET_H
#define ROCKET_H

// For rocket dimensions
#define ROCKET_WIDTH 20
#define ROCKET_HEIGHT 40

// Screen dimensions
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define MAX_BULLETS 3 // Maximum number of bullets on the screen at once.
extern int bulletCount;


typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed;
    bool active; // Flag to determine if the bullet is active
} Bullet;



typedef struct {
    int x;     // X coordinate of the rocket
    int y;     // Y coordinate of the rocket
    int speed; // Speed of the rocket
    int sideSpeed; //Side speed of rocket
    int life;
} Rocket_t;

//Declaration of struct
extern Rocket_t rocket; // Global rocket instance
extern Bullet firedBullets[MAX_BULLETS];

void moveRocketLeft(void);
void moveRocketRight(void);
void moveRocketForward(void);
void moveRocketBackward(void);

void init_bullets(void);
void fire_bullets(int x, int y);
void update_bullets(void);
void render_bullets(void);

void rederLifes(void);
#endif // ROCKET_H
