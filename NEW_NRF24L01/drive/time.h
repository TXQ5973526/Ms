#ifndef _TIME_H_
#define _TIME_H_

#include "stm32f0xx.h"

void TIM3_Int_Init(uint16_t arr,uint16_t psc);
void TIM3_IRQHandler(void);
extern void DisPlay(uint8_t Num);
extern unsigned char NRF_Frequency;

#endif  /* _TIME_H_ */
