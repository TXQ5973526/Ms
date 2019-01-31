#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

#define U1 1
#define U2 2
#define U3 3
#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收  	

extern uint8_t PinUARTUseFlag[3];

void PrintfInit(void);
void uart_init(uint32_t bound);
void uart3_init(uint32_t bound);
void uart2_init(uint32_t bound);
void uart6_init(uint32_t bound);

#if EN_USART1_RX 
extern uint8_t  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern uint16_t USART_RX_STA;         		//接收状态标记	
void PrintfRevice(void);
#endif

#endif


