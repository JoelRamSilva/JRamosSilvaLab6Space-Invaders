/*
 * Timer_Driver.h
 *
 *  Created on: Oct 9, 2024
 *      Author: joelrsilva
 */

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

#include "InterruptControl.h"
#include "stdbool.h"

// Timer configuration structure
typedef struct{
	uint32_t Auto_Reload;
	uint8_t  Master_Mode_Select;
	uint8_t	 Clock_Division_Select;
	uint32_t Prescaler_Value;
	uint8_t  Center_Align_Mode_Select;
	bool	 Auto_Reload_Buffer_Enable;
	bool	 Timer_CountDown_Mode_enable;
	bool	 Interrupt_update_enable;
	bool	 Disable_Update_event;
	bool	 One_Pulse_Mode_enable;
} GPTimer_Config_t;

// Function declarations
void Timer_Init(GPTIMR_RegDef_t *pTimerConfig, GPTimer_Config_t *pinTimer);
void Timer_ClockControl(GPTIMR_RegDef_t *pTimerConfig, uint8_t toggle);
void Timer_Start(GPTIMR_RegDef_t *pTimerConfig);
void Timer_Stop(GPTIMR_RegDef_t *pTimerConfig);
void Timer_Reset(GPTIMR_RegDef_t *pTimerConfig);
uint32_t Timer_Value(GPTIMR_RegDef_t *pTimerConfig);
void Timer_Interrupt_Toggle(GPTIMR_RegDef_t *pTimerConfig, uint8_t toggle);
uint32_t Timer_Auto_Reload(GPTIMR_RegDef_t *pTimerConfig);

// Macros for timer configuration
#define TIMER_ENABLE   1
#define TIMER_DISABLE  0

#define TIMER_AUTORELOAD_DISABLE (0x0 << 7)
#define TIMER_AUTORELOAD_ENABLE  (0x1 << 7)

#define TIMER_MMS_RESET          (0x0 << 4)
#define TIMER_MMS_ENABLE         (0x1 << 4)

#define TIMER_CKD_DIV_1    (0U)
#define TIMER_CKD_DIV_2    (1U)
#define TIMER_CKD_DIV_4    (2U)

#define TIMER_CR1_CKD_MASK  (0x3 << 8)
#define TIMER_CR1_CMS_MASK  (0x3 << 5)

#define TIMER_CR2_MASTERMODE (4)

#define TIMER_MODE_EDGE_ALIGNED       (0x0 << 5)
#define TIMER_MODE_CENTER_ALIGNED_1   (0x1 << 5)
#define TIMER_MODE_CENTER_ALIGNED_2   (0x2 << 5)
#define TIMER_MODE_CENTER_ALIGNED_3   (0x3 << 5)

#define TIMER_UDIS_ENABLE  (0x0 << 1)
#define TIMER_UDIS_DISABLE (0x1 << 1)

#define TIMER_OPM_DISABLE (0x0 << 3)
#define TIMER_OPM_ENABLE  (0x1 << 3)

#define TIMER_DIER_UIE_BIT_POS  0

#define TIMER_DIR_UPCOUNT   (0x0 << 4)
#define TIMER_DIR_DOWNCOUNT (0x1 << 4)

#define TIMER_CEN_DISABLE  (0U)
#define TIMER_CEN_ENABLE   (1U)

#define TIMER_URS_ANY_EVENT  (0x0 << 2)
#define TIMER_URS_OVERFLOW   (0x1 << 2)

#endif /* TIMER_DRIVER_H_ */
