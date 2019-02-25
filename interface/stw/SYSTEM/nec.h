#ifndef __NEC_H
#define __NEC_H
#include "stm32f4xx_conf.h" 

#define NEC_ADDRES 0x00
#define NEC_KEY0 0x45
#define NEC_Increase 0x46       //KEY1
#define NEC_Silent 0x47
#define NEC_Prev 0x44 //KEY3
#define NEC_Pause_Play 0x40       //KEY4
#define NEC_Next 0x43       //KEY5
#define NEC_Mode  0x07
#define NEC_Decrease 0x15   //KEY7
#define NEC_KEY8 0x09   //KEY8
#define NEC_KEY9 0x16
#define NEC_KEY10 0x19
#define NEC_KEY11 0x0D
#define NEC_KEY12 0x0C
#define NEC_KEY13 0x18
#define NEC_KEY14 0x5E
#define NEC_KEY15 0x08
#define NEC_KEY16 0x1C
#define NEC_KEY17 0x5A
#define NEC_KEY18 0x42
#define NEC_KEY19 0x52
#define NEC_KEY20 0x4A


u8 NEC_Send_Command(uint8_t Pin,u8 command);
u8 NEC_Adjust_volume(uint8_t Pin,u8 command,u8 DB);
#endif
