/*
 * Game_Play.c
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */


#include "Game_Play.h"

int scoreKeeper = 0;
int gameMode;
char displayScoreDeciman = '0';
 // Global variable for y-coordinate

void game_init(void) {
	LCD_Clear(0, LCD_COLOR_BLACK);
	gameMode = 0;

    rocket.x = 140;
    rocket.y = 220;
    rocket.speed = 6;
    rocket.sideSpeed = 2;
    rocket.life = 3;


    scoreKeeper = 0;
    elapsedTime = 0;
    resetTimer();
    // Clear screen
	//printf("\nRendering game elements...\n");

    //printf("\nMADE IT HERE\n");
    init_bullets();
    init_Enemy();
    RNG_Init(); // Initialize RNG
}

// Function to update game logic
void game_update(uint16_t x, uint16_t y){

	//printf("\nIN GAME PLAY \nX: %03d\nY: %03d \n", x, y);
    if (x < 140 && y > 50){
    	//printf("\nMove LEFT");
    	moveRocketLeft();
    }
    else if (x > 145 && y > 51) {
    	//printf("\nMove RIGHT");
    	moveRocketRight();
    }
    else if (x > 145 && y < 50){
        //printf("\nBOOST!!");
        moveRocketForward();
    }else if (x < 144 && y < 50) {
    	fire_bullets(rocket.x, rocket.y - 10); // Fire From rocket position
	}
}



void game_render(void) {


    // Clear screen
    LCD_Clear(0, LCD_COLOR_BLACK);
	LCD_SetTextColor(LCD_COLOR_RED);
	LCD_SetFont(&Font16x24);
	// Render ROCKET!!
    LCD_DisplayChar(rocket.x, rocket.y, '^');
    LCD_DisplayChar(rocket.x - 8,  rocket.y + 10, '/');
    LCD_DisplayChar(rocket.x + 8,  rocket.y + 10, '\\');
    LCD_DisplayChar(rocket.x - 14, rocket.y + 26, '/');
    LCD_DisplayChar(rocket.x + 14, rocket.y + 26, '\\');
    LCD_DisplayChar(rocket.x - 16, rocket.y + 26, 'i');
    LCD_DisplayChar(rocket.x + 17, rocket.y + 26, 'i');

	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16x24);
    // Draw ROCKET!!!
    LCD_DisplayChar(10, 280, 'P');
    LCD_DisplayChar(25, 280, 'E');
    LCD_DisplayChar(41, 280, 'W');
    LCD_DisplayChar(60, 280, 'P');
    LCD_DisplayChar(75, 280, 'E');
    LCD_DisplayChar(91, 280, 'W');



    // Draw ROCKET!!!
    LCD_DisplayChar(142, 280, 'B');
    LCD_DisplayChar(158, 280, 'O');
    LCD_DisplayChar(178, 280, 'O');
    LCD_DisplayChar(198, 280, 'S');
    LCD_DisplayChar(212, 280, 'T');

    //Left Move Arrow
    LCD_DisplayChar(24, 140, '/');
    LCD_DisplayChar(25, 155, '\\');
    LCD_DisplayChar(19, 140, '/');
    LCD_DisplayChar(20, 155, '\\');


    //Right Move Arrow
    LCD_DisplayChar(199, 140, '\\');
    LCD_DisplayChar(198, 155, '/');
    LCD_DisplayChar(195, 140, '\\');
    LCD_DisplayChar(193, 155, '/');


    //Score system
    scoreKeeping(scoreKeeper);
    rederLifes();

    //Render Game Elements
    render_bullets();
    render_Enemy(monster, MAX_MONSTER);

	update_Enemy();
	update_bullets();
	showTimer();
	if (rocket.y < 220){
	rocket.y += 1.0f;
	}

}

bool check_collision_rocket(int rocketX, int rocketY, int rocketWidth, int rocketHeight,
                            int monsterX, int monsterY, int monsterWidth, int monsterHeight) {
    return (rocketX < monsterX + monsterWidth &&
            rocketX + rocketWidth > monsterX &&
            rocketY < monsterY + monsterHeight &&
            rocketY + rocketHeight > monsterY);
}

bool check_collision(int bulletX, int bulletY, int monsterX, int monsterY, int monsterWidth, int monsterHeight) {
    return (bulletX >= monsterX && bulletX <= monsterX + monsterWidth &&
            bulletY >= monsterY && bulletY <= monsterY + monsterHeight);
}


void scoreKeeping(int points) {
    if (points < 0 || points > 9999) {
        return; // make sure it stays within range ADD game over screen here
    }

    // take the module so we can add the exra digits to screen
    int pointsThousands = points / 1000;          // Get the thousands digit
    int pointsHundreds = (points / 100) % 10;     // Get the hundreds digit
    int pointsTens = (points / 10) % 10;          // Get the tens digit
    int pointsOnes = points % 10;                 // Get the ones digit

    // thousands
    if (pointsThousands > 0) {
        char displayThousands = '0' + pointsThousands; // Convert to ASCII
        LCD_DisplayChar(148, 15, displayThousands);    // Adjust position for thousands digit
    }

    // Hunnies
    if (pointsThousands > 0 || pointsHundreds > 0) {
        char displayHundreds = '0' + pointsHundreds;   // Convert to ASCII
        LCD_DisplayChar(168, 15, displayHundreds);     // Adjust position for hundreds digit
    }

    // decimals
    if (pointsThousands > 0 || pointsHundreds > 0 || pointsTens > 0) {
        char displayTens = '0' + pointsTens;           // Convert to ASCII
        LCD_DisplayChar(188, 15, displayTens);         // Adjust position for tens digit
    }

    // singles
    char displayOnes = '0' + pointsOnes;               // Convert to ASCII
    LCD_DisplayChar(212, 15, displayOnes);             // Adjust position for ones digit
}

void game_over(void) {

    LCD_Clear(0, LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_RED);
    LCD_SetFont(&Font16x24);
    LCD_DisplayChar(90, 50, 'G');
    LCD_DisplayChar(110, 50, 'A');
    LCD_DisplayChar(130, 50, 'M');
    LCD_DisplayChar(150, 50, 'E');

    LCD_DisplayChar(90, 80, 'O');
    LCD_DisplayChar(110, 80, 'V');
    LCD_DisplayChar(130, 80, 'E');
    LCD_DisplayChar(150, 80, 'R');
    LCD_DisplayChar(170, 80, '!');

    //Show the score
    LCD_SetTextColor(LCD_COLOR_WHITE);
    LCD_DisplayChar(70, 120, 'S');
    LCD_DisplayChar(90, 120, 'C');
    LCD_DisplayChar(110, 120, 'O');
    LCD_DisplayChar(130, 120, 'R');
    LCD_DisplayChar(150, 120, 'E');
    LCD_DisplayChar(170, 120, ':');


    char scoreBuffer[5];
    sprintf(scoreBuffer, "%d", scoreKeeper);
    for (int i = 0; scoreBuffer[i] != '\0'; i++) {
        LCD_DisplayChar(110 + (i * 20), 150, scoreBuffer[i]);
    }


    HAL_Delay(3000);
    // Reinitialize the game
    game_init();
}


