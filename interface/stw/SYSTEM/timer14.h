#ifndef _TIMER14_H
#define _TIMER14_H
#include "stm32f4xx_conf.h" 

extern char TIM14RunFlag;
void TIM14_Int_Init(u16 arr,u16 psc);
void TimerInit(u16 period);

void TimerStart(void);
void TimerStop(void);

#endif
