#include "systick.h"

static uint8_t  fac_us=0;//us?óê±±??ù3?êy
static uint16_t fac_ms=0;//ms?óê±±??ù3?êy

void SysTick_Init(void)	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//48000 0000/8=6000 000  HCLK/8

	fac_us=SystemCoreClock/8000000;	//fac_us=48000 000/8000 000=6
	
	fac_ms=(uint16_t)fac_us*1000;//fac_ms=6*1000=6000

}								    

		   
void delay_us(uint32_t nus)
{		
	uint32_t temp;	    	 
	SysTick->LOAD=nus*fac_us; //ê±???ó??  	(SysTick->LOAD?a24bit) ??×°??êy?µ??'??÷ 
	SysTick->VAL=0x00;        //??????êy?÷  µ±?°êy?µ??'??÷
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //?aê?µ1êy   ?????°×'ì???'??÷ 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//µè'yê±??µ?'?  
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //1?±???êy?÷
	SysTick->VAL =0X00;       //??????êy?÷	 
}

void delay_ms(uint16_t nms)
{	 		  	  
	uint32_t temp;		   
	SysTick->LOAD=(uint32_t)nms*fac_ms;//ê±???ó??(SysTick->LOAD?a24bit)
	SysTick->VAL =0x00;           //??????êy?÷
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //?aê?µ1êy 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//µè'yê±??µ?'?
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //1?±???êy?÷
	SysTick->VAL =0X00;       //??????êy?÷	  	    
} 


