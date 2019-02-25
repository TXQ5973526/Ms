#ifndef __DIGITAL_TUBE_H
#define __DIGITAL_TUBE_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

#include "usart.h"
#include "irc.h"

void LD_NumSet(uint8_t pin,uint16_t data);
void LD_DanSet(uint8_t pin,int num,uint16_t data);
void LD_Set(uint8_t pin,uint16_t data1,uint16_t data2,uint16_t data3,uint16_t data4);

extern uint16_t  DT_data[8];

#endif


