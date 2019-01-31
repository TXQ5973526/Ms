#include "motor.h"
#include "stm32f4xx_conf.h" 
#include "gpio.h" 

#define PWM_Period	100
void Motor2WInit(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 	//使能PORTD时钟	
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource12,GPIO_AF_TIM4); //GPIOD12复用为定时器4
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4); //GPIOD13复用为定时器4
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_TIM4); //GPIOD14复用为定时器4
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource15,GPIO_AF_TIM4); //GPIOD15复用为定时器4

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOD, &GPIO_InitStructure);      		//初始化PD12-15
	 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE); 

	TIM_TimeBaseStructure.TIM_Prescaler=83;  					//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	//向上计数模式
	TIM_TimeBaseStructure.TIM_Period=PWM_Period;   					//自动重装载
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;			//重复寄存器，用于自动更新pwm占空比
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);				//初始化定时器14
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//选择定时器模式TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
 	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;	//使能该通道输出

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  						//根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;    	
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;		
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;		
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset; 

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  				
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  	
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  	
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  	

	TIM_ARRPreloadConfig(TIM4,ENABLE);							//ARPE使能 

	TIM_Cmd(TIM4, ENABLE);  									//使能TIM14
	TIM_CtrlPWMOutputs(TIM4, ENABLE);

	//
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);	

}  

void Motor2WSpeed(uint8_t Motor_num, uint8_t Motor_direction, uint8_t Speed )
{	
	if( Speed > PWM_Period)
		Speed = PWM_Period;
	if( Motor_num == Motor1 ){
		if( Motor_direction == Forward )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_0);
			TIM_SetCompare1(TIM4,Speed);
		}
		else if( Motor_direction == Backward )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_0);
			TIM_SetCompare1(TIM4,PWM_Period - Speed);
		}
		else if( Motor_direction == brake )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_0);
			TIM_SetCompare1(TIM4,0);
		}
		else if( Motor_direction == coast )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_0);
			TIM_SetCompare1(TIM4,100);
		}
	}else if( Motor_num == Motor2 ){
		if( Motor_direction == Forward )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_1);
			TIM_SetCompare2(TIM4,PWM_Period - Speed);
		}
		else if ( Motor_direction == Backward )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_1);
			TIM_SetCompare2(TIM4,Speed);
		}
		else if( Motor_direction == brake )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_1);
			TIM_SetCompare2(TIM4,0);
		}
		else if( Motor_direction == coast )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_1);
			TIM_SetCompare2(TIM4,100);
		}
	}else if( Motor_num == Motor3 ){
		if ( Motor_direction == Forward )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_3);
			TIM_SetCompare3(TIM4,Speed);
		}
		else if ( Motor_direction == Backward )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_3);
			TIM_SetCompare3(TIM4,PWM_Period - Speed);
		}
		else if( Motor_direction == brake )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_3);
			TIM_SetCompare3(TIM4,0);
		}
		else if( Motor_direction == coast )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_3);
			TIM_SetCompare3(TIM4,100);
		}
	}else if( Motor_num == Motor4 ){
		if( Motor_direction == Forward )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_4);
			TIM_SetCompare4(TIM4,PWM_Period - Speed);
		}
		else if ( Motor_direction == Backward )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_4);
			TIM_SetCompare4(TIM4,Speed);
		}
		else if( Motor_direction == brake )
		{
			GPIO_SetBits(GPIOD, GPIO_Pin_4);
			TIM_SetCompare4(TIM4,0);
		}
		else if( Motor_direction == coast )
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_4);
			TIM_SetCompare4(TIM4,100);
		}
	}
}

