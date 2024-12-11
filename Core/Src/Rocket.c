/*
 * Rocket.c
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */


#include "Rocket.h"

// Global Rocket
Rocket_t rocket = {120, 160, 6, 1}; // Initial X, Y, and speed and sidespeed
Bullet firedBullets[MAX_BULLETS];



// Moveleft
void moveRocketLeft(void) {
	int i;
    for(i = 0; i <= 5; ++i){
    rocket.x -= rocket.sideSpeed;
  	game_render();
    }
}

// Move right
void moveRocketRight(void) {
	int i;
    for(i = 0; i <= 5; ++i){
    rocket.x += rocket.sideSpeed;
  	game_render(); // Adjust screen width as needed
    }
}

// Move up-boost
void moveRocketForward(void) {
    int i;
    for(i = 0; i <= 12; ++i){
  	rocket.y -= rocket.sideSpeed;
  	game_render();
  	if (rocket.y < 40) rocket.y = 40; // Prevent moving off-screen
    }
}

// Move down
void moveRocketBackward(void){
    rocket.y += rocket.speed;
    if (rocket.y > 300) rocket.y = 300; // Adjust screen height as needed
}




void init_bullets(void) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        firedBullets[i].active = false;
        firedBullets[i].x = 0;
        firedBullets[i].y = 0;
        firedBullets[i].speed = -5;
        firedBullets[i].width = 2;
        firedBullets[i].height = 5;
    }
}

void fire_bullets(int x, int y) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!firedBullets[i].active) {
            firedBullets[i].x = x;
            firedBullets[i].y = y;
            firedBullets[i].speed = -5.0f; // Move firedBullets up
            firedBullets[i].active = true;
            break;
        }
    }
}


void render_bullets(void) {
    LCD_SetTextColor(LCD_COLOR_WHITE);
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (firedBullets[i].active) {
            LCD_DisplayChar(firedBullets[i].x, firedBullets[i].y, '|');
        }
    }
}


void update_bullets(void) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (firedBullets[i].active) {
            // Update bullet position
            firedBullets[i].y += firedBullets[i].speed;

            // Check for collisions with monsters
            for (int j = 0; j < MAX_MONSTER; j++) {
                if (monster[j].active &&
                    check_collision(
                        firedBullets[i].x, firedBullets[i].y,         // Bullet position
                        monster[j].x, monster[j].y,                  // Monster position
                        monster[j].width, monster[j].height)) {      // Monster dimensions
                    // Collision detected
                    firedBullets[i].active = false;
                    monster[j].active = false;
                    scoreKeeper += 1;
                    //printf("Check Collision BOOM! Bullet[%d] hit Monster[%d]\n", i, j);
                    break; // Stop checking other monsters for this bullet
                }
            }

            // Deactivate bullet if it goes off-screen
            if (firedBullets[i].y < 0) {
                firedBullets[i].active = false;
            }
        }
    }
}

void rederLifes(void){
	if(rocket.life == 3){
		LCD_Draw_Circle_Fill(100,25,10,LCD_COLOR_RED);
		LCD_Draw_Circle_Fill(125,25,10,LCD_COLOR_RED);
		LCD_Draw_Circle_Fill(150,25,10,LCD_COLOR_RED);
	} else 	if(rocket.life == 2){
		LCD_Draw_Circle_Fill(125,25,10,LCD_COLOR_RED);
		LCD_Draw_Circle_Fill(150,25,10,LCD_COLOR_RED);
	}else{
			LCD_Draw_Circle_Fill(150,25,10,LCD_COLOR_RED);
	}
}


