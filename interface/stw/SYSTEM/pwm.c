#include "pwm.h"


void PWMInit_TIM2(uint8_t pin, uint32_t PWM_Period);
void PWMInit_TIM9(uint8_t pin, uint32_t PWM_Period);
void PWMInit_TIM12(uint8_t pin, uint32_t PWM_Period);

void PWMSet(uint8_t pin, uint32_t PulseWidth)
{
	if (pin >= 1 && pin <= 8) {
		if (PinOutUseFlag[pin] != 4) {
			PinOutUseFlag[pin] = 4;
			PWMInit(pin, 100);
		}
		switch (pin) {
		case 1: TIM_SetCompare1(TIM2, PulseWidth); break;
		case 2: TIM_SetCompare2(TIM2, PulseWidth); break;
		case 3: TIM_SetCompare3(TIM2, PulseWidth); break;
		case 4: TIM_SetCompare4(TIM2, PulseWidth); break;
		case 5: TIM_SetCompare1(TIM9, PulseWidth); break;
		case 6: TIM_SetCompare2(TIM9, PulseWidth); break;
		case 7: TIM_SetCompare1(TIM12, PulseWidth); break;
		case 8: TIM_SetCompare2(TIM12, PulseWidth); break;
		}
		return;
	}
	BoardLEDAllOpen();
}
void PWMInit(uint8_t pin, uint32_t PWM_Period)
{
	if(pin>=1&&pin<=4){
		PWMInit_TIM2(pin,PWM_Period);
	}else if(pin<=6){
		PWMInit_TIM9(pin,PWM_Period);
	}else if(pin<=8){
		PWMInit_TIM12(pin,PWM_Period);
	}else{
		return;
	}
	PinOutUseFlag[pin] = 4;
}
void PWMInit_TIM2(uint8_t pin, uint32_t PWM_Period)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	switch (pin) {
	case 1: GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; break;
	case 2: GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; break;
	case 3: GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; break;
	case 4: GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; break;
	}
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);      		//初始化PD12-15

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseStructure.TIM_Prescaler = 83;  					//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数模式
	TIM_TimeBaseStructure.TIM_Period = PWM_Period;   					//自动重装载
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;			//重复寄存器，用于自动更新pwm占空比
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);				//初始化定时器14

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//选择定时器模式TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;	//使能该通道输出
	// TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	// TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	// TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
	switch (pin) {
	case 1: TIM_OC1Init(TIM2, &TIM_OCInitStructure); TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable); break;
	case 2: TIM_OC2Init(TIM2, &TIM_OCInitStructure); TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable); break;
	case 3: TIM_OC3Init(TIM2, &TIM_OCInitStructure); TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable); break;
	case 4: TIM_OC4Init(TIM2, &TIM_OCInitStructure); TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable); break;
	}
	TIM_ARRPreloadConfig(TIM2, ENABLE);							//ARPE使能

	TIM_Cmd(TIM2, ENABLE);  									//使能TIM14
	TIM_CtrlPWMOutputs(TIM2, ENABLE);
}
void PWMInit_TIM9(uint8_t pin, uint32_t PWM_Period)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//使能PORTD时钟

	switch (pin) {
	case 5: GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; break;
	case 6: GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; break;
	}
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOE, &GPIO_InitStructure);      		//初始化PD12-15

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM9,ENABLE);

	TIM_TimeBaseStructure.TIM_Prescaler = 83;  					//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数模式
	TIM_TimeBaseStructure.TIM_Period = PWM_Period;   					//自动重装载
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;			//重复寄存器，用于自动更新pwm占空比
	TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);				//初始化定时器14

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//选择定时器模式TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;	//使能该通道输出

	switch (pin) {
	case 5: TIM_OC1Init(TIM9, &TIM_OCInitStructure); TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable); break;
	case 6: TIM_OC2Init(TIM9, &TIM_OCInitStructure); TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable); break;
	}

	TIM_ARRPreloadConfig(TIM9, ENABLE);							//ARPE使能

	TIM_Cmd(TIM9, ENABLE);  									//使能TIM14
	TIM_CtrlPWMOutputs(TIM9, ENABLE);
}
void PWMInit_TIM12(uint8_t pin, uint32_t PWM_Period)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTD时钟

	switch (pin) {
	case 7: GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM12); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; break;
	case 8: GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12); GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15; break;
	}
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);      		//初始化PD12-15

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);

	TIM_TimeBaseStructure.TIM_Prescaler = 83;  					//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//向上计数模式
	TIM_TimeBaseStructure.TIM_Period = PWM_Period;   					//自动重装载
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;			//重复寄存器，用于自动更新pwm占空比
	TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);				//初始化定时器14

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 				//选择定时器模式TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;	//使能该通道输出

	switch (pin) {
	case 7: TIM_OC1Init(TIM12, &TIM_OCInitStructure); TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable); break;
	case 8: TIM_OC2Init(TIM12, &TIM_OCInitStructure); TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable); break;
	}

	TIM_ARRPreloadConfig(TIM12, ENABLE);							//ARPE使能

	TIM_Cmd(TIM12, ENABLE);  									//使能TIM14
	TIM_CtrlPWMOutputs(TIM12, ENABLE);
}

