#include"stm32f0xx.h"
#include "User.h"
#include "rf24l01.h"

unsigned char NRF_Frequency = 0x01;

extern uint8_t TX_ADDRESS[TX_ADR_WIDTH]; //发送地址
extern uint8_t RX_ADDRESS[RX_ADR_WIDTH]; //发送地址
void Mode_choose_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
}

