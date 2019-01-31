#ifndef __KEY_H
#define	__KEY_H

#include "stm32f0xx.h"

#define Key1	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)
#define Key2	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)
#define Key3	GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)
#define Key4	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)
#define KeyDown	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)



extern void Delay(uint32_t temp);
extern void KEY_Init(void);
extern uint8_t KEY_Down(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
extern uint8_t KEY_Read(void);

#endif /* __KEY_H */

