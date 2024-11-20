/*
 * Scheduler.h
 *
 *  Created on: Jan 25, 2024
 *      Author: joelrsilva
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <stdio.h>
#include <stdint.h>


#define TOGGLE_EVENT (1UL << 0)
#define DELAYEVENT (1UL << 1)
#define POLLEVENT (1UL << 2)

uint32_t getScheduledEvents();
void addScheduledEvents(uint32_t event);
void removeSchedulerEvent(uint32_t event);

#endif /* SCHEDULER_H_ */
