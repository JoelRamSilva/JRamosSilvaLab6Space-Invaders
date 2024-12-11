#include "Game_Menu.h"


// Play Button Dimensions
#define START_BUTTON_X 50
#define START_BUTTON_Y 144
#define START_BUTTON_WIDTH 140
#define START_BUTTON_HEIGHT 50

// Play Button Dimensions
#define OPTIONS_BUTTON_X 50
#define OPTIONS_BUTTON_Y 210
#define OPTIONS_BUTTON_WIDTH 140
#define OPTIONS_BUTTON_HEIGHT 50

// Initialize the Menu
void menu_init(void) {
    menu_render();
}

//Start Menu
void menu_render(void) {

    LCD_Clear(0, LCD_COLOR_BLACK);
	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(83,50,'S');
	LCD_DisplayChar(99,50,'P');
	LCD_DisplayChar(115,50,'A');
	LCD_DisplayChar(131,50,'C');
	LCD_DisplayChar(147,50,'E');

	LCD_DisplayChar(55,80,'I');
	LCD_DisplayChar(67,80,'N');
	LCD_DisplayChar(83,80,'V');
	LCD_DisplayChar(99,80,'A');
	LCD_DisplayChar(116,80,'D');
	LCD_DisplayChar(131,80,'E');
	LCD_DisplayChar(147,80,'R');
	LCD_DisplayChar(163,80,'S');

    // Draw Start Button
    for (int y = START_BUTTON_Y; y < START_BUTTON_Y + START_BUTTON_HEIGHT; y++) {
        for (int x = START_BUTTON_X; x < START_BUTTON_X + START_BUTTON_WIDTH; x++) {
            LCD_Draw_Pixel(x, y, LCD_COLOR_GREEN);
        }
    }

	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);
	LCD_DisplayChar(88,158,'P');
	LCD_DisplayChar(104,158,'L');
	LCD_DisplayChar(120,158,'A');
	LCD_DisplayChar(136,158,'Y');


}

// Handle Touch Events
void menu_handle_touch(uint16_t x, uint16_t y) {

    // Check if "Start" button was touched
    if (y > 100 && y < 250) {
        // "Start" button pressed
        LCD_Clear(0, LCD_COLOR_BLACK);
    	LCD_SetTextColor(LCD_COLOR_RED);
    	LCD_SetFont(&Font16x24);

    	LCD_DisplayChar(99,50,'G');
    	LCD_DisplayChar(115,50,'A');
    	LCD_DisplayChar(131,50,'M');
    	LCD_DisplayChar(147,50,'E');

    	LCD_DisplayChar(83,80,'S');
    	LCD_DisplayChar(99,80,'T');
    	LCD_DisplayChar(116,80,'A');
    	LCD_DisplayChar(131,80,'R');
    	LCD_DisplayChar(147,80,'T');
    	gameMode = 1;
        //HAL_Delay(1000);

    }
}
