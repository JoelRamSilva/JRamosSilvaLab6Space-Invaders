/*
 * Rocket.c
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */


#include "Rocket.h"

// Global Rocket instance
Rocket_t rocket = {120.0f, 160.0f, 2.0f}; // Initial X, Y, and speed

// Move the rocket left
void moveRocketLeft(void) {
    rocket.x -= rocket.speed;
    if (rocket.x < 0) rocket.x = 0; // Prevent moving off-screen
}

// Move the rocket right
void moveRocketRight(void) {
    rocket.x += rocket.speed;
    if (rocket.x > 230) rocket.x = 230; // Adjust screen width as needed
}

// Move the rocket forward (up)
void moveRocketForward(void) {
    rocket.y -= rocket.speed;
    if (rocket.y < 0) rocket.y = 0; // Prevent moving off-screen
}

// Move the rocket backward (down)
void moveRocketBackward(void) {
    rocket.y += rocket.speed;
    if (rocket.y > 300) rocket.y = 300; // Adjust screen height as needed
}


