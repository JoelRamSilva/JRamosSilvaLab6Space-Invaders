#include <Time_Driver.h>

void initTimer(Timer_Handle_t *t){
    t->p->TIMx_CR1 &= ~TIMER_CR1_CKD_MASK;
    t->p->TIMx_CR1 |= (t->timerConfig.ClockDivisionSelection << 8);

    t->p->TIMx_CR1 &= ~TIMER_CR1_CAM_MASK;
    t->p->TIMx_CR1 |= (t->timerConfig.CenterAlignedModeSelection << 5);

    if (t->timerConfig.TimerCountDownModeEnablement){
        t->p->TIMx_CR1 |= (1U << TIMER_CR1_DIR_BIT_POS);
    }
    else{
        t->p->TIMx_CR1 &= ~(1U << TIMER_CR1_DIR_BIT_POS);
    }

    if (t->timerConfig.AutoReloadBufferEnablement){
        t->p->TIMx_CR1 |= (1U << TIMER_CR1_ARPE_BIT_POS);
    }
    else{
        t->p->TIMx_CR1 &= ~(1U << TIMER_CR1_ARPE_BIT_POS);
    }

    if (t->timerConfig.OnePulseModeEnablement){
        t->p->TIMx_CR1 |= (1U << TIMER_CR1_OPM_BIT_POS);
    }
    else{
        t->p->TIMx_CR1 &= ~(1U << TIMER_CR1_OPM_BIT_POS);
    }

    if (t->timerConfig.DisableUpdateEvent){
        t->p->TIMx_CR1 |= (1U << TIMER_CR1_UDIS_BIT_POS);
    }
    else{
        t->p->TIMx_CR1 &= ~(1U << TIMER_CR1_UDIS_BIT_POS);
    }

    if (t->timerConfig.InterruptUpdateEnablement){
        t->p->TIMx_DIER |= (1U << TIMER_INTERRUPT_BIT_POS);
    }
    else{
        t->p->TIMx_DIER &= ~(1U << TIMER_INTERRUPT_BIT_POS);
    }
    if (t->timerConfig.MasterModeSelection){
        t->p->TIMx_CCR2 |= (1U << TIMER_CR2_MASTERMODE);
    }

    else{
        t->p->TIMx_CCR2 &= ~(1U << TIMER_CR2_MASTERMODE);
    }

    t->p->TIMx_PSC = t->timerConfig.PrescalerValue;
    t->p->TIMx_ARR = t->timerConfig.AutoReloadValue;
}

void Timer_Clock_Control(GPTIMR_RegDef_t *ptr, uint8_t toggle)
{
    if (ptr == TIM2){
        if (toggle == ENABLE)
        {
            APB1_CLOCK_ENABLE(TIM2_OFFSET);
        }
        else
        {
            APB1_CLOCK_DISABLE(TIM2_OFFSET);
        }
    }
    else if (ptr == TIM5)
    {
        if (toggle == ENABLE)
        {
            APB1_CLOCK_ENABLE(TIM5_OFFSET);
        }
        else
        {
            APB1_CLOCK_DISABLE(TIM5_OFFSET);
        }
    }
}

void TimerStart(GPTIMR_RegDef_t *ptr){
    ptr->TIMx_CR1 = TIMER_ENABLE;
}

void TimerStop(GPTIMR_RegDef_t *ptr){
    ptr->TIMx_CR1 = TIMER_DISABLE;
}

void TimerReset(GPTIMR_RegDef_t *ptr){
    ptr->TIMx_CNT = 0U;
}

uint32_t TimerVal(GPTIMR_RegDef_t *ptr){
    return ptr->TIMx_CNT;
}

void TimerInterrupt(GPTIMR_RegDef_t *ptr, uint8_t toggle){
    if (toggle == ENABLE){
        ptr->TIMx_DIER |= (1U << TIMER_DIER_UIE_BIT_POS);
    }
    else if (toggle == DISABLE){
        ptr->TIMx_DIER &= ~(1U << TIMER_DIER_UIE_BIT_POS);
    }
}
