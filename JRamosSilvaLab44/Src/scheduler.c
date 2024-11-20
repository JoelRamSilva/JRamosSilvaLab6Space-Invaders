/*
 * Scheduler.c
 *
 *  Created on: Jan 25, 2024
 *      Author: joelrsilva
 */

#include <scheduler.h>


static uint32_t scheduledEvents = 0;

uint32_t getScheduledEvents(){
    return scheduledEvents;
}
void addScheduledEvents(uint32_t event){
    scheduledEvents |= (event);
}
void removeSchedulerEvent(uint32_t event){

    scheduledEvents &= ~(event);

}
