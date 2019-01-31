#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f0xx.h"

void SysTick_Init(void);
void delay_ms(uint16_t nms);
void delay_us(uint32_t nus);

#endif /* __SYSTICK_H */
