#include "stm32f0xx.h"
#include "led.h"
//yjw
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);		//ʹ��GPIOxʱ��
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;				//ʹ�ܵ�����
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;			//�������
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			//������� 
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_3;	//����
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
