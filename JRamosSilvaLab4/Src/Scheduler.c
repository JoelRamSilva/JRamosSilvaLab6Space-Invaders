/*
 * Scheduler.c
 *
 *  Created on: Sep 9, 2024
 *      Author: joelrsilva
 */

#include "Scheduler.h"


static uint32_t scheduledEvents;

void addSchedulerEvent(uint32_t eventToSchedule){
	scheduledEvents |= eventToSchedule;
}

void removeSchedulerEvent(uint32_t eventToRemove){
	scheduledEvents &= ~(eventToRemove);
}

uint32_t getScheduledEvents(){
	return scheduledEvents;
}
