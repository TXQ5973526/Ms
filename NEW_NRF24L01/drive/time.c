#include "time.h"

extern uint8_t LED_Value;

void TIM3_Int_Init(uint16_t arr, uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///¡§o1?¡§1TIM3¡§o?¨¤?¡§?
	
  	TIM_TimeBaseInitStructure.TIM_Period = arr; 	//?¨¢???£¤???¨¢?????|¨¬
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;  //??¡ì¡§o?¨¤????¡è??|¨¬
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //?¡§¡ã¡§|???¡§oy??¨º¡§o?
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//3?¡§o???£¤TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //?¡§oD¡§a??¡ì¡§o?¨¤???3?¡§1D??D??
	TIM_Cmd(TIM3,ENABLE); //¡§o1?¡§1??¡ì¡§o?¨¤???3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //??¡ì¡§o?¨¤???3?D??
	NVIC_InitStructure.NVIC_IRQChannelPriority=0; //?¡§¡è??¡§???¡§¡§??1
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//TIM_Cmd(TIM3,DISABLE);
}

//??¡ì¡§o?¨¤???3?D???¡èt??o?£¤¡§oy
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET) //¡§¡ã?3??D??
	{
		DisPlay(LED_Value);
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //??3y?D???¨¤¡§o????
}

