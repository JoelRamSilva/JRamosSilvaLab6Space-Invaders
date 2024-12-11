/*
 * Enemy.c
 *
 *  Created on: Nov 21, 2024
 *      Author: joelrsilva
 */

#include "Enemy.h"


Monster monster[MAX_MONSTER];
int monsterCount = MAX_MONSTER;
int activeMeteorCount = 0;

void init_Enemy(void){
    for (int i = 0; i < MAX_MONSTER; i++) {
    	monster[i].active = false; //Enemies inactive initially
    	monster[i].x = 0;
    	monster[i].y = 0;
        monster[i].width = 20;
        monster[i].height = 20;
    }
}


void spawn_Enemy(void) {
    for (int i = 0; i < MAX_MONSTER; i++) {
        if (!monster[i].active) {
            monster[i].x = RNG_GetRandomInRange(20, 220); // Random X-position
            monster[i].y = 20;                           // Start at the top
            monster[i].speed = RNG_GetRandomInRange(1, 2); // Random speed
            monster[i].type = RNG_GetRandomInRange(1, 3); // Random type
            monster[i].active = true;

            // Monster types attributes
            switch (monster[i].type) {
                case ENEMY_TYPE_METEOR:
                    monster[i].width = 25;
                    monster[i].height = 20;
                    break;

                case ENEMY_TYPE_SPACESHIP:
                    monster[i].width = 32;
                    monster[i].height = 26;
                    break;

                case ENEMY_TYPE_ALIEN:
                    monster[i].width = 36;
                    monster[i].height = 25;
                    break;
            }

//            printf("Spawned Monster[%d]: Type=%d, X=%d, Y=%d, Speed=%d\n",
//                   i, monster[i].type, monster[i].x, monster[i].y, monster[i].speed);
            break; // Spawn one monster at a time
        }
    }
}

void render_Enemy(Monster monster[], int monsterCount){
	    for (int i = 0; i < monsterCount; i++) {
	        if (monster[i].active) {
	            switch (monster[i].type) {
	                case 1: // Meteor
	                	LCD_SetTextColor(LCD_COLOR_RED);
	                	LCD_SetFont(&Font16x24);
	                    LCD_DisplayChar(monster[i].x +9,  monster[i].y, '|');
	                    LCD_DisplayChar(monster[i].x + 5,  monster[i].y + 9, '-');
	                    LCD_DisplayChar(monster[i].x,  	   monster[i].y + 3, '\\');
	                    LCD_DisplayChar(monster[i].x - 3, monster[i].y - 14, '/');
	                    LCD_DisplayChar(monster[i].x + 9, monster[i].y - 32, '_');
	                    LCD_DisplayChar(monster[i].x + 16, monster[i].y - 17, '\\');
	                    LCD_DisplayChar(monster[i].x + 13,  monster[i].y - 16, '_');
	                    break;

	                case 2: // Enemy Ship
	                	LCD_SetTextColor(LCD_COLOR_RED);
	                	LCD_SetFont(&Font16x24);
	                    LCD_DisplayChar(monster[i].x + 15, monster[i].y, '|');
	                    LCD_DisplayChar(monster[i].x + 10,  monster[i].y, '\\');
	                    LCD_DisplayChar(monster[i].x + 20,  monster[i].y, '/');
	                    LCD_DisplayChar(monster[i].x + 28, monster[i].y - 16, '.');
	                    LCD_DisplayChar(monster[i].x + 5, monster[i].y - 16, '.');
	                    LCD_DisplayChar(monster[i].x 	, monster[i].y, 'I');
	                    LCD_DisplayChar(monster[i].x + 30, monster[i].y, 'I');
	                    break;

	                case 3: //Alien Ship
	                	LCD_SetTextColor(LCD_COLOR_GREEN);
	                	LCD_SetFont(&Font16x24);
	                    LCD_DisplayChar(monster[i].x + 16, monster[i].y, 'O');
	                    LCD_DisplayChar(monster[i].x + 26,  monster[i].y, ')');
	                    LCD_DisplayChar(monster[i].x + 6,  monster[i].y, '(');
	                    LCD_DisplayChar(monster[i].x + 30,  monster[i].y, ')');
	                    LCD_DisplayChar(monster[i].x + 2,  monster[i].y, '(');
	                    LCD_DisplayChar(monster[i].x + 32,  monster[i].y, ')');
	                    LCD_DisplayChar(monster[i].x ,  monster[i].y, '(');
	                    break;
	            }
	        }
	    }
	}



void update_Enemy(void) {
    for (int i = 0; i < MAX_MONSTER; i++) {
        if (monster[i].active) {
            if (monster[i].type == ENEMY_TYPE_ALIEN) {
                // Alien chasing the player
                int distance = monster[i].x - rocket.x;
                monster[i].x += (distance > 0) ? -monster[i].speed : monster[i].speed;
            }

            monster[i].y += monster[i].speed; // Move downward

            // Rocket Collision
            if (check_collision_rocket(rocket.x, rocket.y, ROCKET_WIDTH, ROCKET_HEIGHT,
                                       monster[i].x, monster[i].y, monster[i].width, monster[i].height)) {
                //printf("Collision detected! Rocket hit by Monster[%d]\n", i);
                //printf("Number of Lives: [%d]\n", rocket.life);
                monster[i].active = false; // Deactivate monster
                rocket.life -= 1;         // Decrease score
                if (rocket.life == 0) {
                	//printf("GAME OVER\n");
                    game_over();           // Handle game over
                    return;                // Exit update to prevent further logic
                }
            }

            // Deactivate if off-screen
            if (monster[i].y > SCREEN_HEIGHT) {
                monster[i].active = false;
            }
        }
    }
}


