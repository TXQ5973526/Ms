#include "uart.h"
#include <stdarg.h>
#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
  
/* Private functions ---------------------------------------------------------*/

void USART_Configuration(void)//¡ä??¨²3?¨º??¡¥o¡¥¨ºy
  {  

        GPIO_InitTypeDef  GPIO_InitStructure;
        USART_InitTypeDef USART_InitStructure;
                
        RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOA, ENABLE);
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );
                
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_1);
        GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_1);        
        /*
        *  USART1_TX -> PA9 , USART1_RX ->        PA10
        */                                
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;                 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
        GPIO_Init(GPIOA, &GPIO_InitStructure);        
        
        USART_InitStructure.USART_BaudRate = 115200;//¨¦¨¨??¡ä??¨²2¡§¨¬??¨º
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;//¨¦¨¨??¨ºy?Y??
        USART_InitStructure.USART_StopBits = USART_StopBits_1;//¨¦¨¨??¨ª¡ê?1??
        USART_InitStructure.USART_Parity = USART_Parity_No;//¨¦¨¨??D¡ì?¨¦??
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//¨¦¨¨??¨¢¡Â????
        USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//¨¦¨¨??1¡è¡Á¡Â?¡ê¨º?
        USART_Init(USART1, &USART_InitStructure); //????¨¨??¨¢11¨¬?

        USART_Cmd(USART1, ENABLE);//¨º1?¨¹¡ä??¨²1

		}			

void UART_send_byte(uint8_t byte) //¡¤¡é?¨ª1¡Á??¨²¨ºy?Y
{
 while(!((USART1->ISR)&(1<<7)));
 USART1->TDR=byte;	
}		

void UART_Send(uint8_t *Buffer, uint32_t Length)
{
	while(Length != 0)
	{
		while(!((USART1->ISR)&(1<<7)));//¦Ì¨¨¡äy¡¤¡é?¨ª¨ª¨º
		USART1->TDR= *Buffer;
		Buffer++;
		Length--;
	}
}

uint8_t UART_Recive(void)
{	
	while(!(USART1->ISR & (1<<5)));//¦Ì¨¨¡äy?¨®¨º?¦Ì?¨ºy?Y
	return(USART1->RDR);			 //?¨¢3?¨ºy?Y
}


PUTCHAR_PROTOTYPE 
{
/* ??Printf?¨²¨¨Y¡¤¡é¨ª¨´¡ä??¨² */
  USART_SendData(USART1,(uint8_t)  ch);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
	{}
 
  return (ch);
}
		
