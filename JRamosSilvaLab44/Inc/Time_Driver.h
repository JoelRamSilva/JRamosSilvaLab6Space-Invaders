#ifndef TIME_DRIVER_H_
#define TIME_DRIVER_H_
#include <stdio.h>
#include <stdint.h>
#include <STM32F429i.h>
#include <stdbool.h>
typedef struct
{
    uint32_t AutoReloadValue;
    uint16_t MasterModeSelection;
    uint8_t ClockDivisionSelection;
    uint16_t PrescalerValue;
    uint8_t CenterAlignedModeSelection;
    bool AutoReloadBufferEnablement;
    bool TimerCountDownModeEnablement;
    bool InterruptUpdateEnablement;
    bool DisableUpdateEvent;
    bool OnePulseModeEnablement;
} GPTImer_Config_t;

typedef struct
{
    GPTIMR_RegDef_t *p;
    GPTImer_Config_t timerConfig;

} Timer_Handle_t;

void initTimer(Timer_Handle_t *t);

void Timer_Clock_Control(GPTIMR_RegDef_t *ptr, uint8_t toggle);

void TimerStart(GPTIMR_RegDef_t *ptr);

void TimerStop(GPTIMR_RegDef_t *ptr);

void TimerReset(GPTIMR_RegDef_t *ptr);

uint32_t TimerVal(GPTIMR_RegDef_t *ptr);

void TimerInterrupt(GPTIMR_RegDef_t *ptr, uint8_t toggle);

#define TIMER_ENABLE (1U)
#define TIMER_DISABLE (0U)

#define TIMER_MASTER_MODE_RESET (0U)
#define TIMER_MASTER_MODE_ENABLE (1U)

#define TIMER_CLOCK_DIV_1 (0U)
#define TIMER_CLOCK_DIV_2 (1U)
#define TIMER_CLOCK_DIV_4 (2U)

#define TIMER_MODE_EDGE_ALIGNED (0U)
#define TIMER_MODE_CENTER_ALIGNED_1 (1U)
#define TIMER_MODE_CENTER_ALIGNED_2 (2U)
#define TIMER_MODE_CENTER_ALIGNED_3 (3U)

#define TIMER_INTERRUPT_BIT_POS (1U)
#define TIMER_CR1_CKD_MASK (0x3 << 8) // Clock Division bits 8-9
#define TIMER_CR1_CAM_MASK (0x3 << 5) // Center Aligned Mode is at bits 5-6

#define TIMER_CR1_DIR_BIT_POS (4)  // Direction bit position for counting mode (0: up, 1: down)
#define TIMER_CR1_ARPE_BIT_POS (7) // Auto-reload preload enable bit position
#define TIMER_CR1_OPM_BIT_POS (3)  // One-pulse mode bit position
#define TIMER_CR1_UDIS_BIT_POS (1) // Update disable bit position
#define TIMER_CR2_MASTERMODE (4)
#define TIMER_DIER_UIE_BIT_POS (0U)

#endif
