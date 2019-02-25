#include "timer14.h"
#include "stm32f4xx_conf.h"
#include "irc.h"


//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!
void TIM14_Int_Init(u16 arr, u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);  			//使能TIM14时钟

	TIM_TimeBaseInitStructure.TIM_Period = arr; 					//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc;  					//定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;

	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseInitStructure);				//初始化TIM14

	TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE); 						//允许定时器3更新中断
	//TIM_Cmd(TIM14, ENABLE); 											//使能定时器3

	NVIC_InitStructure.NVIC_IRQChannel = TIM8_TRG_COM_TIM14_IRQn; 	//定时器14中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01; 		//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03; 			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}
//定时器时钟为84M。
//分频系数为8400时，计数频率84M/8400=10Khz
//计数为100时是10ms。
//period：周期范围1ms~1s;
void TimerInit(u16 period)
{
	if (period > 1000)
		period = 1000;
	period = period * 10 - 1;
	TIM14_Int_Init(period, 8399);
}

void TimerStart(void)
{
	TIM_Cmd(TIM14, ENABLE);
}
void TimerStop(void)
{
	TIM_Cmd(TIM14, DISABLE);
}
