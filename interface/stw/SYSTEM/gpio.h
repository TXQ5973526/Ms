#ifndef _GPIO_H
#define _GPIO_H

#include "stm32f4xx_conf.h" 

#define IN1	1
#define IN2	2
#define IN3	3
#define IN4	4
#define IN5	5
#define IN6	6
#define IN7	7
#define IN8	8

#define OUT1	1
#define OUT2	2
#define OUT3	3
#define OUT4	4
#define OUT5	5
#define OUT6	6
#define OUT7	7
#define OUT8	8

#define BLEDR	1
#define BLEDG	2
#define BLEDY	3
#define BLEDB	4

extern uint8_t PinInUseFlag[9];
extern uint8_t PinOutUseFlag[9];
uint8_t WLINState(uint8_t pin);
void WLOUTState(uint8_t pin, uint8_t State);
GPIO_TypeDef* Getbase(uint8_t pinwei, uint8_t pin);
uint32_t GetPin(uint8_t pinwei, uint8_t pin);
void GPIO_AF_Set(GPIO_TypeDef* GPIOx,uint8_t BITx,uint8_t AFx);		//GPIO复用功能设置
void GPIO_Set(GPIO_TypeDef* GPIOx,uint32_t BITx,uint32_t MODE,uint32_t OTYPE,uint32_t OSPEED,uint32_t PUPD);//GPIO设置函数  


#endif 
