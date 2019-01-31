#ifndef _MOTOR_H
#define _MOTOR_H
#include "stm32f4xx_conf.h" 

void Motor2WInit(void);
void Motor2WSpeed(uint8_t Motor_num, uint8_t Motor_direction, uint8_t Speed );


#define Forward 	0x00
#define Backward	0x01
#define brake		0x02
#define coast		0x03

#define Motor1	11
#define Motor2	12
#define Motor3	13
#define Motor4	14

#endif
