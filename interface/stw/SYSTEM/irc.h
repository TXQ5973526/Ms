#ifndef _IRC_H
#define _IRC_H

#include "stm32f4xx_conf.h"

#define IR_ButtonNO	0x00
#define IR_Button1	0x80
#define IR_Button2	0x40
#define IR_Button3	0x20
#define IR_Button4	0x10
#define IR_Button5	0x08
#define IR_Button6	0x04

extern uint8_t IRCU1;
extern uint8_t IRCU2;	  
extern uint8_t IRCU3;	  

uint8_t IRCSState(uint8_t pin);

#endif
