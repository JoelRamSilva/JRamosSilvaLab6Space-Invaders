/*
 * Game_Menu.h
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */

#ifndef GAME_MENU_H_
#define GAME_MENU_H_

#include "stm32f4xx_hal.h"
#include "LCD_Driver.h"
#include "ApplicationCode.h"

void menu_init(void);               // Initialize the menu
void menu_render(void);             // Render the start menu
void menu_handle_touch(uint16_t x, uint16_t y);


#endif /* GAME_MENU_H_ */
