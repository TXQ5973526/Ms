#include "stm32f4xx_conf.h" 
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM14, TIM_IT_Update) == SET)
	{

	}
	TIM_ClearITPendingBit(TIM14, TIM_IT_Update); 
}


