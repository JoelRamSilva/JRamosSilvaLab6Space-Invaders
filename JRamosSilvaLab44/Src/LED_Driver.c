

#include <LED_Driver.h>
#include <GPIO_Driver.h>

static GPIO_Handle_t red;
static GPIO_Handle_t green;
static Timer_Handle_t timer2Handle;
static Timer_Handle_t timer5Handle;

void initializeLED(uint8_t led){

    switch (led){
    case RedLED:
        red.pGPIOx = GPIOG;
        red.GPIO_PinConfig.PinNumber = ODR14;
        red.GPIO_PinConfig.PinMode = OUTPUT;
        red.GPIO_PinConfig.PinSpeed = HIGHEST_SPEED;
        red.GPIO_PinConfig.OPType = PUSH_PULL;
        red.GPIO_PinConfig.PinPuPdControl = NO_PULL;
        GPIO_clockHandler(GPIOG, ENABLE);
        GPIO_initialize(&red);
        break;

    case GreenLED:
        green.pGPIOx = GPIOG;
        green.GPIO_PinConfig.PinNumber = ODR13;
        green.GPIO_PinConfig.PinMode = OUTPUT;
        green.GPIO_PinConfig.PinSpeed = HIGH_SPEED;
        green.GPIO_PinConfig.OPType = PUSH_PULL;
        green.GPIO_PinConfig.PinPuPdControl = NO_PULL;
        GPIO_clockHandler(GPIOG, ENABLE);
        GPIO_initialize(&green);
        break;
    default:
        break;
    }
}
void toggleLED(uint8_t led){
    switch (led){

    case RedLED:
    	GPIO_togglePin(red.pGPIOx, red.GPIO_PinConfig.PinNumber);
        break;

    case GreenLED:
    	GPIO_togglePin(green.pGPIOx, green.GPIO_PinConfig.PinNumber);
        break;
    default:
        break;
    }
}
void deactivateLED(uint8_t led){
    switch (led){
    case RedLED:
        GPIO_writePin(red.pGPIOx, red.GPIO_PinConfig.PinNumber, 0);
        break;
    case GreenLED:
        GPIO_writePin(green.pGPIOx, green.GPIO_PinConfig.PinNumber, 0);
        break;
    default:
        break;
    }
}

void activateLED(uint8_t led){
    switch (led){
    case RedLED:
        GPIO_writePin(red.pGPIOx, red.GPIO_PinConfig.PinNumber, 1);
        break;
    case GreenLED:
        GPIO_writePin(green.pGPIOx, green.GPIO_PinConfig.PinNumber, 1);
        break;
    default:
        break;
    }
}


void LED_timer2Init(){

    timer2Handle.p = TIM2;

    timer2Handle.timerConfig.PrescalerValue = 299;
    timer2Handle.timerConfig.AutoReloadValue = 159999;
    timer2Handle.timerConfig.ClockDivisionSelection = TIMER_CLOCK_DIV_1;
    timer2Handle.timerConfig.MasterModeSelection = TIMER_MASTER_MODE_RESET;
    timer2Handle.timerConfig.OnePulseModeEnablement = false;
    timer2Handle.timerConfig.TimerCountDownModeEnablement = false;
    timer2Handle.timerConfig.InterruptUpdateEnablement = true;
    timer2Handle.timerConfig.DisableUpdateEvent = false;
    timer2Handle.timerConfig.CenterAlignedModeSelection = TIMER_MODE_EDGE_ALIGNED;

    Timer_Clock_Control(timer2Handle.p, ENABLE);
    initTimer(&timer2Handle);
    IRQ_enable(28);

}
void LED_timer2Start(){
    TimerStart(TIM2);
}
void LED_timer2Stop(){
    TimerStop(TIM2);
}
void LED_timer2Reset(){
    TimerReset(TIM2);
}


void LED_timer5Init(){
    timer5Handle.p = TIM5;

    timer5Handle.timerConfig.PrescalerValue = 0;
    timer5Handle.timerConfig.AutoReloadValue = 0xffffffff;
    timer5Handle.timerConfig.ClockDivisionSelection = TIMER_CLOCK_DIV_4;
    timer5Handle.timerConfig.MasterModeSelection = TIMER_MASTER_MODE_RESET;
    timer5Handle.timerConfig.OnePulseModeEnablement = false;
    timer5Handle.timerConfig.TimerCountDownModeEnablement = false;
    timer5Handle.timerConfig.InterruptUpdateEnablement = true;
    timer5Handle.timerConfig.DisableUpdateEvent = false;
    timer5Handle.timerConfig.CenterAlignedModeSelection = TIMER_MODE_EDGE_ALIGNED;

    Timer_Clock_Control(timer5Handle.p, TIMER_ENABLE);
    initTimer(&timer5Handle);
    IRQ_enable(50);
}


void LED_timer5Start(){
    TimerStart(TIM5);
}

void LED_timer5Stop(){
    TimerStop(TIM5);
}

void LED_timer5Reset(){
    TimerReset(TIM5);
}

uint8_t LED_AutoReload5(){
    return timer5Handle.p->TIMx_ARR;
}

uint32_t LED_CountValue5(){
    return timer5Handle.p->TIMx_CNT;
}

void LED_configAutoReload5(uint32_t val){
    timer5Handle.p->TIMx_ARR = val;
}

void LED_CountValue5Upddate(uint32_t val){
    timer5Handle.p->TIMx_CNT = val;
}

void LED_timer5UpdateStart(uint32_t newVal){
    TimerStop(timer5Handle.p);
    LED_configAutoReload5(newVal);
    TimerReset(TIM5);
}
