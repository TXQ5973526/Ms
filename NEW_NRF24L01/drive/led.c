#include "stm32f0xx.h"
#include "led.h"
//yjw
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);		//使能GPIOx时钟
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;				//使能的引脚
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			//设置输出
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			//推挽输出 
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_3;	//高速
		GPIO_Init(GPIOC, &GPIO_InitStruct);	
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

void LED_Open(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}
void LED_Close(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_13 );
}
void LED_Toggle(void)
{
	GPIOC->ODR ^=GPIO_Pin_13;
}

//void LED2_Toggle(void)
//{
//GPIO_WriteBit(GPIOA, GPIO_Pin_12, 
//		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_12))));
//}
