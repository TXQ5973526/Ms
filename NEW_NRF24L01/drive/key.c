#include "key.h"
#include "stm32f0xx.h"

void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA| RCC_AHBPeriph_GPIOB, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	//GPIO_SetBits(GPIOA, GPIO_Pin_7| GPIO_Pin_6 );

}
	
void Delay(uint32_t temp)
{
  for(; temp!= 0; temp--);
} 
 


uint8_t KEY_Down(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
		  /*检测是否有按键按下 */
   	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 0 ) 
	  {	   
	 	   /*延时消抖*/
	  	 Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 0 )  
					{	 
						/*等待按键释放 */
						while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == 0);   
			 			return 	0	; 
					}
			else
					return 1;
		}
	else
		return 1;
}

uint8_t KEY_Read(void)
{
	unsigned char Key = 0;
	if( Key1 == 0)
		Key |= 1;
	if( Key2 == 0)
		Key |= 1 << 1;
	if( Key3 == 0)
		Key |= 1 << 2;
	if( Key4 == 0)
		Key |= 1 << 3;
	if( KeyDown== 0)
		Key |= 1 << 4;
	return Key;
}
