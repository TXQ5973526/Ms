#ifndef _LED_H
#define _LED_H

#include "stm32f4xx_conf.h" 

void BoardLEDInit(void);
void BoardLEDAllOpen(void);
void BLEDState(uint8_t pin, uint8_t State);
void LEDPWM(uint8_t pin, uint8_t PulseWidth);
#endif 
