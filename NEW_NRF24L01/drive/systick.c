#include "systick.h"

static uint8_t  fac_us=0;//us?�걱??�3?�y
static uint16_t fac_ms=0;//ms?�걱??�3?�y

void SysTick_Init(void)	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//48000 0000/8=6000 000  HCLK/8

	fac_us=SystemCoreClock/8000000;	//fac_us=48000 000/8000 000=6
	
	fac_ms=(uint16_t)fac_us*1000;//fac_ms=6*1000=6000

}								    

		   
void delay_us(uint32_t nus)
{		
	uint32_t temp;	    	 
	SysTick->LOAD=nus*fac_us; //�???�??  	(SysTick->LOAD?a24bit) ??װ??�y?�??'??� 
	SysTick->VAL=0x00;        //??????�y?�  ��?��y?�??'??�
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //?a�?�1�y   ?????��'�???'??� 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//��'y�??�?'?  
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //1?�???�y?�
	SysTick->VAL =0X00;       //??????�y?�	 
}

void delay_ms(uint16_t nms)
{	 		  	  
	uint32_t temp;		   
	SysTick->LOAD=(uint32_t)nms*fac_ms;//�???�??(SysTick->LOAD?a24bit)
	SysTick->VAL =0x00;           //??????�y?�
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //?a�?�1�y 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//��'y�??�?'?
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //1?�???�y?�
	SysTick->VAL =0X00;       //??????�y?�	  	    
} 


