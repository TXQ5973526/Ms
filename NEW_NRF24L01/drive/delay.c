#include "delay.h"
#include "uart.h"
static __IO uint32_t TimingDelay;
void TIM2_Init(uint16_t arr,uint16_t psc)//1000,48,48000000/48/1000=1000HZ=1ms�ж�
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��//TIM4ʱ��ʹ��    
	
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc-1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM4�ж�,��������ж�
	 	  
    /*  TIM3 �ж�Ƕ�����*/
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
void TIM2_Set(uint8_t sta)
{
	if(sta)
	{      
		TIM_SetCounter(TIM2,0);//���������
		TIM_Cmd(TIM2, ENABLE);  //ʹ��TIMx	
	}else TIM_Cmd(TIM2, DISABLE);//�رն�ʱ��4	   
}
/*******************************************************************************
*Function:��ʱ�����ʼ��
*parm:none
*description:
*******************************************************************************/
void delay_init(void)	 
{
    TIM2_Init(1000,48);	//������ʱ
}	
/*******************************************************************************
*Function:��ʱ���򣬺��뼶��
*parm:none
*description:
*******************************************************************************/
void delay_ms(uint32_t nTime)
{
    TIM2_Set(1);
    TimingDelay = nTime;
  	while(TimingDelay != 0)
		TimingDelay_Decrement();
}
/*******************************************************************************
* @function : 
* @brief : Decrements the TimingDelay variable.
* @param : None
* @retval:None
  *****************************************************************************/
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }else
  {
    TIM2_Set(0);
  }
}
