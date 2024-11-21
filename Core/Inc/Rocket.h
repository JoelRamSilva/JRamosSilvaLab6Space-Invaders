/*
 * Rocket.h
 *
 *  Created on: Nov 20, 2024
 *      Author: joelrsilva
 */

#ifndef ROCKET_H
#define ROCKET_H

typedef struct {
    float x;     // X coordinate of the rocket
    float y;     // Y coordinate of the rocket
    float speed; // Speed of the rocket
} Rocket_t;

extern Rocket_t rocket; // Global rocket instance

void moveRocketLeft(void);
void moveRocketRight(void);
void moveRocketForward(void);
void moveRocketBackward(void);

#endif // ROCKET_H
