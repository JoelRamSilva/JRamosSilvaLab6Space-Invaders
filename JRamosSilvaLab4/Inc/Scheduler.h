/*
 * Scheduler.h
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "GPIO_Driver.h"

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


#define LED_TOGGLE_EVENT (1UL << 0)
#define LED_DELAY_EVENT (1UL << 1)
#define BUTTON_POOL_EVENT (1UL << 2)

uint32_t getScheduledEvents();

void addSchedulerEvent(uint32_t eventToSchedule);

void removeSchedulerEvent(uint32_t eventToRemove);




#endif /* SCHEDULER_H_ */
