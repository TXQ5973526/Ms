#include "sys.h"
#include "usart.h"
#include "irc.h"
#include "nrfrc.h"

void ClearNRF(uint8_t NRFCUx_Cache[]);

#if 1
#include <stdio.h>
#include <stdlib.h>
int _write (int fd, char *pBuffer, int size)
{
	for (int i = 0; i < size; i++)
	{
		while (!(USART1->SR & USART_SR_TXE))
		{
		}
		USART_SendData(USART1, pBuffer[i]);
	}
	return size;
}
#endif

//printf支持
#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误
uint8_t USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
uint16_t USART_RX_STA = 0;     //接收状态标记
#endif

//初始化IO 串口1
//bound:波特率
void PrintfInit(void)
{
	uart_init(115200);
}
void uart_init(uint32_t bound)
{
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //使能USART1时钟

	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); //GPIOA10复用为USART1

	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PA9，PA10

	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate = 115200;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART1, &USART_InitStructure); //初始化串口1

	USART_Cmd(USART1, ENABLE);  //使能串口1

	//USART_ClearFlag(USART1, USART_FLAG_TC);

#if EN_USART1_RX
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启相关中断

	//Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
#endif
}

//---------- USB端口读取 ----------
#if EN_USART1_RX
void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	uint8_t Res;
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res = USART_ReceiveData(USART1); //(USART1->DR);	//读取接收到的数据

		if ((USART_RX_STA & 0x8000) == 0) //接收未完成
		{
			if (USART_RX_STA & 0x4000) //接收到了0x0d
			{
				if (Res != 0x0a)
					USART_RX_STA = 0; //接收错误,重新开始
				else
					USART_RX_STA |= 0x8000;	//接收完成了
			}
			else //还没收到0X0D
			{
				if (Res == 0x0d)
					USART_RX_STA |= 0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = Res ;
					USART_RX_STA++;
					if (USART_RX_STA > (USART_REC_LEN - 1))
						USART_RX_STA = 0; //接收数据错误,重新开始接收
				}
			}
		}
	}
}

void PrintfRevice(void)
{
	unsigned char len;
	if (USART_RX_STA & 0x8000)
	{
		len = USART_RX_STA & 0x3fff; //得到此次接收到的数据长度
		//printf("abc:");
		for (unsigned char t = 0; t < len; t++)
		{
			USART_SendData(USART1, USART_RX_BUF[t]);         //向串口1发送数据
			while (USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET); //等待发送结束
		}
		//printf("\r\n\r\n");//插入换行
		USART_RX_STA = 0;
	}
}
#endif
































//----------- U1-U3读取 ------------------------------------------
//PinUARTUseFlag[pin] = num;
//---------- pin ----------
//  0:-2:  对应U1~U3编号管脚
//---------- num ----------
//	0:	未初始化
//	1:	红外遥控器使用（波特率9600）
//	2:	NRF遥控器使用（波特率115200）
uint8_t PinUARTUseFlag[3] = {0};

//初始化IO 串口3 U1
void uart3_init(uint32_t bound)
{
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 		//使能GPIOB时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);		//使能USART3时钟

	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3); 	//GPIOB10复用为USART3
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3); 	//GPIOB11复用为USART3

	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; 	//GPIOB10与GPIOB11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;				//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 				//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 				//上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure); 						//初始化PB10，PB11

	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;					//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;			//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART3, &USART_InitStructure); 					//初始化串口3

	USART_Cmd(USART3, ENABLE);  								//使能串口1

	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);				//开启相关中断

	//Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;			//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;		//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);								//根据指定的参数初始化VIC寄存器、
}
//初始化IO 串口2 U2
void uart2_init(uint32_t bound)
{
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 		//使能GPIOB时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);		//使能USART3时钟

	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_USART2); 	//GPIOB10复用为USART3
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2); 	//GPIOB11复用为USART3

	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6; 		//GPIOB10与GPIOB11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;				//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 				//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 				//上拉
	GPIO_Init(GPIOD, &GPIO_InitStructure); 						//初始化PB10，PB11

	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;					//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;			//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART2, &USART_InitStructure); 					//初始化串口3

	USART_Cmd(USART2, ENABLE);  								//使能串口1

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);				//开启相关中断

	//Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;		//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);								//根据指定的参数初始化VIC寄存器、
}
//初始化IO 串口6 U3
void uart6_init(uint32_t bound)
{
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 		//使能GPIOB时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);		//使能USART3时钟

	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6); 	//GPIOB10复用为USART3
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6); 	//GPIOB11复用为USART3

	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; 	//GPIOB10与GPIOB11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;				//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 				//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 				//上拉
	GPIO_Init(GPIOC, &GPIO_InitStructure); 						//初始化PB10，PB11

	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;					//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;	//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;			//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	USART_Init(USART6, &USART_InitStructure); 					//初始化串口3

	USART_Cmd(USART6, ENABLE);  								//使能串口1

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);				//开启相关中断

	//Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;			//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;		//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);								//根据指定的参数初始化VIC寄存器、
}
void USART3_IRQHandler(void)                				//串口3中断服务程序
{
	if ( PinUARTUseFlag[0] == 1)
	{
		if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		{
			IRCU1 = USART_ReceiveData(USART3);					//(USART1->DR); 	//读取接收到的数据
		}
	}
	else if ( PinUARTUseFlag[0] == 2)
	{
		static uint8_t NRFData_Cache[7];
		static uint8_t NRF_Count = 0;
		char temp;
		if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
		{
			temp = USART_ReceiveData(USART3);
			NRFData_Cache[NRF_Count] = temp;
			if (NRFData_Cache[0] == 0x0A)
			{
				if (NRF_Count >= 1 && NRFData_Cache[1] != 0x03)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 2 && NRFData_Cache[2] != 0xFC) {
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 6 && NRFData_Cache[6] == 0x0D) {
					// if(NRFCUx[0][0] ！= NRFData_Cache[3] && NRFCUx[0][1] ！= NRFData_Cache[4] && NRFCUx[0][2] ！= NRFData_Cache[5])
					// {
					// 	NRFCUx[0][0] = NRFData_Cache[3];
					// 	NRFCUx[0][1] = NRFData_Cache[4];
					// 	NRFCUx[0][2] = NRFData_Cache[5];
					// 	NRFTrusteeshipMotor();
					// }
					NRFCUx[0][0] = NRFData_Cache[3];
					NRFCUx[0][1] = NRFData_Cache[4];
					NRFCUx[0][2] = NRFData_Cache[5];
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
				NRF_Count++;
				if (NRF_Count > 6)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
			} else {
				NRF_Count = 0;
				ClearNRF(NRFData_Cache);
			}
		}
	}
}
void USART2_IRQHandler(void)                				//串口1中断服务程序
{
	if ( PinUARTUseFlag[1] == 1)
	{
		if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
		{
			IRCU2 = USART_ReceiveData(USART2);					//(USART1->DR);		//读取接收到的数据
		}
	}
	else if ( PinUARTUseFlag[1] == 2)
	{
		static uint8_t NRFData_Cache[7];
		static uint8_t NRF_Count = 0;
		char temp;
		if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
		{
			temp = USART_ReceiveData(USART2);
			NRFData_Cache[NRF_Count] = temp;
			if (NRFData_Cache[0] == 0x0A)
			{
				if (NRF_Count >= 1 && NRFData_Cache[1] != 0x03)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 2 && NRFData_Cache[2] != 0xFC) {
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 6 && NRFData_Cache[6] == 0x0D) {
					NRFCUx[1][0] = NRFData_Cache[3];
					NRFCUx[1][1] = NRFData_Cache[4];
					NRFCUx[1][2] = NRFData_Cache[5];
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
				NRF_Count++;
				if (NRF_Count > 6)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
			} else {
				NRF_Count = 0;
				ClearNRF(NRFData_Cache);
			}
		}
	}
}
void USART6_IRQHandler(void)                				//串口1中断服务程序
{
	if ( PinUARTUseFlag[2] == 1)
	{
		if (USART_GetITStatus(USART6, USART_IT_RXNE) != RESET)
		{
			IRCU3 = USART_ReceiveData(USART6);					//(USART1->DR);		//读取接收到的数据
		}
	}
	else if ( PinUARTUseFlag[2] == 2)
	{
		static uint8_t NRFData_Cache[7];
		static uint8_t NRF_Count = 0;
		char temp;
		if (USART_GetITStatus(USART6, USART_IT_RXNE) != RESET)
		{
			temp = USART_ReceiveData(USART6);
			NRFData_Cache[NRF_Count] = temp;
			if (NRFData_Cache[0] == 0x0A)
			{
				if (NRF_Count >= 1 && NRFData_Cache[1] != 0x03)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 2 && NRFData_Cache[2] != 0xFC) {
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				} else if (NRF_Count >= 6 && NRFData_Cache[6] == 0x0D) {
					NRFCUx[1][0] = NRFData_Cache[3];
					NRFCUx[1][1] = NRFData_Cache[4];
					NRFCUx[1][2] = NRFData_Cache[5];
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
				NRF_Count++;
				if (NRF_Count > 6)
				{
					NRF_Count = 0;
					ClearNRF(NRFData_Cache);
				}
			} else {
				NRF_Count = 0;
				ClearNRF(NRFData_Cache);
			}
		}
	}
}
void ClearNRF(uint8_t NRFCUx_Cache[])
{
	NRFCUx_Cache[0] = 0;
	NRFCUx_Cache[1] = 0;
	NRFCUx_Cache[2] = 0;
	NRFCUx_Cache[3] = 0;
	NRFCUx_Cache[4] = 0;
	NRFCUx_Cache[5] = 0;
	NRFCUx_Cache[6] = 0;
}

