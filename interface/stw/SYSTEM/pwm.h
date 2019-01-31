#ifndef _PWM_H
#define _PWM_H

#include "stm32f4xx_conf.h" 
void PWMSet(uint8_t pin, uint32_t PulseWidth);
void PWMInit(uint8_t pin, uint32_t PWM_Period);
#endif 

