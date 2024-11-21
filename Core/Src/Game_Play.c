/*
 * Game_Play.c
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */


#include "Game_Play.h"

 // Global variable for y-coordinate

void game_init(void) {
    LCD_Clear(0, LCD_COLOR_BLACK);
    rocket.x = 140.0f;
    rocket.y = 220.0f;
    rocket.speed = 6.0f;

    // Clear screen
	printf("\nRendering game elements...\n");
    LCD_Clear(0, LCD_COLOR_BLACK);
	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(83,50,'S');
	LCD_DisplayChar(99,50,'P');
    // Draw rocket
    LCD_DisplayChar((int)rocket.x, (int)rocket.y, '^');
    LCD_DisplayChar((int)rocket.x - 8, (int)rocket.y + 10, '/');
    LCD_DisplayChar((int)rocket.x + 8, (int)rocket.y + 10, '\\');
    LCD_DisplayChar((int)rocket.x - 14, (int)rocket.y + 26, '/');
    LCD_DisplayChar((int)rocket.x + 14, (int)rocket.y + 26, '\\');
    LCD_DisplayChar((int)rocket.x - 16, (int)rocket.y + 26, 'i');
    LCD_DisplayChar((int)rocket.x + 17, (int)rocket.y + 26, 'i');
}

// Function to update game logic
void game_update(uint16_t x, uint16_t y) {

	//printf("\nIN GAME PLAY \nX: %03d\nY: %03d \n", x, y);
    if (x > 0 && x < 40 && y > 0 && y < 300){
  	  printf("\nMove LEFT");
  	rocket.x -= rocket.speed;
  	if (rocket.x < 20) rocket.x = 20; // Keep rocket within screen bounds
    }
    else if (x > 200 && x < 220 && y > 0 && y < 300) {
  	  printf("\nMove RIGHT");
  	rocket.x += rocket.speed;
  	if (rocket.x > 250) rocket.x = 250; // Adjust based on screen width
    }
    game_render();
}



// Function to render game elements
void game_render(void) {
    // Clear screen
    LCD_Clear(0, LCD_COLOR_BLACK);
	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_SetFont(&Font16x24);
    // Draw rocket
    LCD_DisplayChar((int)rocket.x, (int)rocket.y, '^');
    LCD_DisplayChar((int)rocket.x - 8, (int)rocket.y + 10, '/');
    LCD_DisplayChar((int)rocket.x + 8, (int)rocket.y + 10, '\\');
    LCD_DisplayChar((int)rocket.x - 14, (int)rocket.y + 26, '/');
    LCD_DisplayChar((int)rocket.x + 14, (int)rocket.y + 26, '\\');
    LCD_DisplayChar((int)rocket.x - 16, (int)rocket.y + 26, 'i');
    LCD_DisplayChar((int)rocket.x + 17, (int)rocket.y + 26, 'i');
}

