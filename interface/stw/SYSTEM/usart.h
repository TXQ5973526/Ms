#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

#define U1 1
#define U2 2
#define U3 3
#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����  	

extern uint8_t PinUARTUseFlag[3];

void PrintfInit(void);
void uart_init(uint32_t bound);
void uart3_init(uint32_t bound);
void uart2_init(uint32_t bound);
void uart6_init(uint32_t bound);

#if EN_USART1_RX 
extern uint8_t  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern uint16_t USART_RX_STA;         		//����״̬���	
void PrintfRevice(void);
#endif

#endif


