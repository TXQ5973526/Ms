#ifndef __LATTICE_H
#define __LATTICE_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 
#include "WS2812B.h"
#include "led.h"
#include "usart.h"
#include "irc.h"
extern u16 Lattice_data[12];


void Lattice_Send(uint8_t pin,u16 data1,u16 data2,u16 data3,u16 data4,u16 data5,u16 data6,u16 data7,u16 data8);


#endif


