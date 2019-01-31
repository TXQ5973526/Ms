#include "stm32f0xx.h"
#include "ili9328.h"
#include "rf24l01.h"
#include "User.h"
#include "adc.h"
#include "Led.h"
#include "Key.h"
#include "systick.h"
#include "uart.h"
#include "flash.h"

/* ��ȡ�������ĳ��� */
#define TxBufferSize1   (countof(TxBuffer1) - 1)
#define RxBufferSize1   (countof(TxBuffer1) - 1)
#define countof(a)      (sizeof(a) / sizeof(*(a)))
#define BufferSize 		(countof(Tx_Buffer)-1)

#define abs_dif(X,Y)	( X > Y) ? ( X - Y):( Y - X)

// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����flash
extern __IO uint16_t  RegularConvData_Tab[2];

// �ֲ����������ڴ��flash�����ĵ�ѹֵ
volatile unsigned char Coding8421_X;
volatile unsigned char Coding8421_Y;

unsigned char Coding8421_X_Initial;
unsigned char Coding8421_Y_Initial;
unsigned char Coding8421_X_error;
unsigned char Coding8421_Y_error;
extern unsigned char NRF_Frequency;

uint8_t  Tx_Pair_Buffer[3];
uint8_t  Rx_Pair_Buffer[3];
uint8_t  Tx_Buffer[3]; // ���ߴ��䷢������
uint8_t  Rx_Buffer[7]; // ���ߴ����������
uint8_t  Rx_Buff[3];
int16_t  Data_Buffer[3];
uint8_t  Change_flag = 0;
uint8_t  Mode_flag = 0;
uint32_t Flash_Save, Flash_Load;
uint32_t Flash_Add;
uint8_t  Flash_Flag;

unsigned char LED_Count = 0;
volatile char val1, val2;

static uint8_t CpuID[12];

void PWM_Mode(void);
void Rocker_Mode(void);
void Change_Mode(void);
void Get_ChipID(void);
void Get_Pairing(void);
void TX_Pairing(void);
void RX_Pairing(void);

int main(void)
{
	uint8_t i;
	SystemInit();
	/*********ҡ�˳�ʼ�� AD�ɼ�DMA��ʽ    *********/
	ADC1_DMA_Init();
	/*********LED��ʼ��    *********/
	LED_Init();
	LED_Close();
	Get_ChipID();
	Get_Pairing();
	Flash_Load = ReadFlash(Flash_Add);
	/*********��ʱ��ȷ��AD�ɼ��꣬����Ӱ����������ж�    *********/
	Delay(100);
	/*********ѡ����շ���ģʽ    *********/
	Mode_choose_Init();
/*************************************************************************************************************************************/
/**********************************************************					**********************************************************/
/**********************************************************     ����ģ��    **********************************************************/
/**********************************************************					**********************************************************/
/*************************************************************************************************************************************/
	if( GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7) == 0)		//��ҡ�ˣ�Ϊ���հ�
	{
		/*********	  NRF24L01��ʼ��	*********/
		SPI_RF_Init();
		while(NRF24L01_Check());
		if(Flash_Load == 0xFFFFFFFF)
			RX_Pairing();
		else
			NRF_Frequency = (uint8_t)Flash_Load;
		NRF24L01_RX();
		USART_Configuration();

		while(1)
		{
			//ҡ��ֵ
			Coding8421_X = RegularConvData_Tab[1] / 16;
			Coding8421_Y = RegularConvData_Tab[0] / 16;

			if(NRF24L01_RxPacket(Rx_Buffer) == 0)
			{
				if(Rx_Buffer[0] < 128)
				{
					PWM_Mode();
					Mode_flag = 1;
				}
				else if(Rx_Buffer[0] >= 128)
				{
					Rx_Buffer[0] = Rx_Buffer[0] - 128;
					//PWM_Mode_2();
					Rocker_Mode();
					Mode_flag = 2;
				}
 			}
			else
			{
				LED_Count++;
				if((LED_Count >= 254) && Mode_flag == 1)//PWMģʽ��ҡ�˴����м�λ��ʱ��������
				{
					Rx_Buffer[0] = 0x0A;
					Rx_Buffer[1] = 0x03;
					Rx_Buffer[2] = 0xFC;
					Rx_Buffer[3] = 0;
					Rx_Buffer[4] = 0;
					Rx_Buffer[5] = 0;
					Rx_Buffer[6] = 0x0D;

					LED_Close();
					UART_Send(Rx_Buffer, 7);
				}
				else if((LED_Count >= 254) && Mode_flag == 2)//��λ��ģʽ��ҡ�˴����м�λ��ʱ��������
				{
					Rx_Buffer[0] = 0x0A;
					Rx_Buffer[1] = 0x03;
					Rx_Buffer[2] = 0xFC;
					Rx_Buffer[3] = 0;
					Rx_Buffer[6] = 0x0D;

					LED_Close();
					UART_Send(Rx_Buffer, 7);
				}
			}

			/*********	  ������У��	*********/
			//Coding8421_Check();
		}
	}
/*************************************************************************************************************************************/
/**********************************************************					**********************************************************/
/**********************************************************     ����ģ��    **********************************************************/
/**********************************************************					**********************************************************/
/*************************************************************************************************************************************/
	else
	{

		/*********ҡ�˳�ʼֵ*********/
		Coding8421_X_Initial = RegularConvData_Tab[1] / 16;
		Coding8421_Y_Initial = RegularConvData_Tab[0] / 16;

		/*********NRF24L01��ʼ��	*********/
		SPI_RF_Init();
		while(NRF24L01_Check());
		if(Flash_Load == 0xFFFFFFFF)
			TX_Pairing();
		else
			NRF_Frequency = (uint8_t)Flash_Load;
		NRF24L01_TX();
		KEY_Init();

		while(1)
		{
			/*********ҡ��ֵ	*********/
			Coding8421_X = RegularConvData_Tab[1] / 16;
			Coding8421_Y = RegularConvData_Tab[0] / 16;
			Coding8421_X_error = abs_dif( Coding8421_X , Coding8421_X_Initial);
			Coding8421_Y_error = abs_dif( Coding8421_Y , Coding8421_Y_Initial);

			/*********NRF�������ݰ�*********/
			Tx_Buffer[0] = KEY_Read();//�ɼ�2.4Gң����������Ϣ
			Tx_Buffer[1] = Coding8421_X;//�ɼ�ҡ��X������
			Tx_Buffer[2] = Coding8421_Y;//�ɼ�ҡ��Y������

			Change_Mode();//��סҡ�˼����������λ��ģʽ���������PWMģʽ

			/*********NRF�����ж�*********/
			if((((Tx_Buffer[0] % 128) != 0) || (Coding8421_X_error > 0x0F) || (Coding8421_Y_error > 0x0F))
				&& (Change_flag == 1))

			{
				i = NRF24L01_TxPacket(Tx_Buffer);

				LED_Open();
				LED_Count = 0;
				Change_flag = 0;
			}
			else
			{
				LED_Count ++;
				if( LED_Count >= 200)
				{
					LED_Close();
					Change_flag = 0;
				}
			}

			/*********������У��*********/
			//Coding8421_Check();
		}
	}
}

void PWM_Mode(void)
{
	LED_Open();
	LED_Count = 0;

	if(Rx_Buffer[1] < 128 && Rx_Buffer[2] < 128)//�ж�ҡ�˵�ǰλ�ô�����ѧ�����е�λ��
		Data_Buffer[0] = 2;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] < 128)
		Data_Buffer[0] = 1;
	else if(Rx_Buffer[1] < 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 3;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 4;

	Rx_Buffer[0] = Rx_Buffer[0] % 32;//ȡ����ֵ
	Rx_Buffer[1] = (abs_dif(Rx_Buffer[1], 127.5)) * 1.99;
	Rx_Buffer[2] = (abs_dif(Rx_Buffer[2], 127.5)) * 1.99;

	/*********����ҡ��ǰ������(2134)��Ӧλ�ã������PWMֵ���д���*********/
	if(Data_Buffer[0] == 2)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
		{
			Data_Buffer[1] = Rx_Buffer[2];
			Data_Buffer[2] = 254 - Rx_Buffer[2];
			Data_Buffer[0] = 1;
		}
		else
		{
			Data_Buffer[1] = Rx_Buffer[1];
			Data_Buffer[2] = Rx_Buffer[1];
			Data_Buffer[0] = 3;
		}
	}
	else if(Data_Buffer[0] == 1)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
		{
			Data_Buffer[1] = Rx_Buffer[2];
			Data_Buffer[2] = 254 - Rx_Buffer[2];
			Data_Buffer[0] = 1;
		}
		else
		{
			Data_Buffer[1] = 254 - Rx_Buffer[1];
			Data_Buffer[2] = 254 - Rx_Buffer[1];
			Data_Buffer[0] = 4;
		}
	}
	else if(Data_Buffer[0] == 3)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
		{
			Data_Buffer[1] = 254 - Rx_Buffer[2];
			Data_Buffer[2] = Rx_Buffer[2];
			Data_Buffer[0] = 2;
		}
		else
		{
			Data_Buffer[1] = Rx_Buffer[1];
			Data_Buffer[2] = Rx_Buffer[1];
			Data_Buffer[0] = 3;
		}
	}
	else if(Data_Buffer[0] == 4)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
		{
			Data_Buffer[1] = 254 - Rx_Buffer[2];
			Data_Buffer[2] = Rx_Buffer[2];
			Data_Buffer[0] = 2;
		}
		else
		{
			Data_Buffer[1] = 254 - Rx_Buffer[1];
			Data_Buffer[2] = 254 - Rx_Buffer[1];
			Data_Buffer[0] = 4;
		}
	}

	if(Rx_Buffer[1] <= 50 && Rx_Buffer[2] <= 50)//ҡ�˴����м�λ��ʱ
	{
		Data_Buffer[1] = 0;
		Data_Buffer[2] = 0;
		Data_Buffer[0] = 0;
	}

	Rx_Buffer[3] = (Rx_Buffer[0] | (Data_Buffer[0] << 5));//ҡ�˷���|����ֵ
	Rx_Buffer[4] = (uint8_t)Data_Buffer[1];//���PWM1
	Rx_Buffer[5] = (uint8_t)Data_Buffer[2];//���PWM2

	/*********Э��ͷβ*********/
	Rx_Buffer[0] = 0x0A;
	Rx_Buffer[1] = 0x03;
	Rx_Buffer[2] = 0xFC;
	Rx_Buffer[6] = 0x0D;

	UART_Send(Rx_Buffer, 7);
}

void Rocker_Mode(void)
{
	LED_Open();
	LED_Count = 0;

	if(Rx_Buffer[1] < 128 && Rx_Buffer[2] < 128)
		Data_Buffer[0] = 2;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] < 128)
		Data_Buffer[0] = 1;
	else if(Rx_Buffer[1] < 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 3;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 4;

	Rx_Buffer[0] = Rx_Buffer[0] % 32;
	Rx_Buff[1] = Rx_Buffer[1];
	Rx_Buff[2] = Rx_Buffer[2];
	Rx_Buffer[1] = (abs_dif(Rx_Buffer[1], 127.5)) * 1.99;
	Rx_Buffer[2] = (abs_dif(Rx_Buffer[2], 127.5)) * 1.99;

	if(Data_Buffer[0] == 2)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
			Data_Buffer[0] = 1;
		else
			Data_Buffer[0] = 3;
	}
	else if(Data_Buffer[0] == 1)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
			Data_Buffer[0] = 1;
		else
			Data_Buffer[0] = 4;
	}
	else if(Data_Buffer[0] == 3)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
			Data_Buffer[0] = 2;
		else
			Data_Buffer[0] = 3;
	}
	else if(Data_Buffer[0] == 4)
	{
		if(Rx_Buffer[2] >= Rx_Buffer[1])
			Data_Buffer[0] = 2;
		else
			Data_Buffer[0] = 4;
	}

	if(Rx_Buffer[1] <= 50 && Rx_Buffer[2] <= 50)
	{
		Data_Buffer[0] = 0;
	}

	Rx_Buffer[3] = ((Rx_Buffer[0] % 32) | (Data_Buffer[0] << 5));
	Rx_Buffer[4] = Rx_Buff[2];
	Rx_Buffer[5] = Rx_Buff[1];
	if(Rx_Buffer[4] >= 254)	Rx_Buffer[1] = 253;
	if(Rx_Buffer[5] >= 254)	Rx_Buffer[2] = 253;

	Rx_Buffer[0] = 0x0A;
	Rx_Buffer[1] = 0x03;
	Rx_Buffer[2] = 0xFC;
	Rx_Buffer[6] = 0x0D;

	UART_Send(Rx_Buffer, 7);
}

void Change_Mode(void)
{
	static uint8_t i = 0;
	static uint32_t MODE = 0;

	/*********2.4Gң�ص�һ�ο������ҡ�˰����Ƿ񳤰�*********/
	if(i < 100)
	{
		MODE += Tx_Buffer[0];
		i++;
	}

	if(i >= 100)
	{
		if(MODE > 500)
			Tx_Buffer[0] |= 128;
		else
			Tx_Buffer[0] |= 0;
		Change_flag = 1;
	}
}

void Get_ChipID(void)
{
	CpuID[0] = *(__IO uint8_t*)(0x1FFFF7AC);
	CpuID[1] = *(__IO uint8_t*)(0x1FFFF7AD);
	CpuID[2] = *(__IO uint8_t*)(0x1FFFF7AE);
	CpuID[3] = *(__IO uint8_t*)(0x1FFFF7AF);
	CpuID[4] = *(__IO uint8_t*)(0x1FFFF7B0);
	CpuID[5] = *(__IO uint8_t*)(0x1FFFF7B1);
	CpuID[6] = *(__IO uint8_t*)(0x1FFFF7B2);
	CpuID[7] = *(__IO uint8_t*)(0x1FFFF7B3);
	CpuID[8] = *(__IO uint8_t*)(0x1FFFF7B4);
	CpuID[9] = *(__IO uint8_t*)(0x1FFFF7B5);
	CpuID[10] = *(__IO uint8_t*)(0x1FFFF7B6);
	CpuID[11] = *(__IO uint8_t*)(0x1FFFF7B7);
}

void Get_Pairing(void)
{
	Tx_Pair_Buffer[0] = CpuID[0];
	Tx_Pair_Buffer[1] = CpuID[2];
	Tx_Pair_Buffer[2] = CpuID[5];
}

void TX_Pairing(void)
{
	NRF24L01_TX();
	while(1)
	{
		if(NRF24L01_TxPacket(Tx_Pair_Buffer) == TX_OK)
		{
			break;
		}
	}
	LED_Open();

	NRF24L01_RX();
	while(1)
	{
		if(NRF24L01_RxPacket(Rx_Pair_Buffer) == 0)
		{
			break;
		}
	}
	LED_Close();

	NRF_Frequency = (Rx_Pair_Buffer[0] + Rx_Pair_Buffer[1] + Rx_Pair_Buffer[2]) % 100;
	WriteFlash(Flash_Add, (uint32_t)NRF_Frequency);
}

void RX_Pairing(void)
{
	NRF24L01_RX();
	while(1)
	{
		if(NRF24L01_RxPacket(Rx_Pair_Buffer) == 0)
		{
			Tx_Pair_Buffer[0] += Rx_Pair_Buffer[0];
			Tx_Pair_Buffer[1] += Rx_Pair_Buffer[1];
			Tx_Pair_Buffer[2] += Rx_Pair_Buffer[2];
			break;
		}
	}
	LED_Open();
	Delay(1000);
	NRF24L01_TX();
	while(1)
	{
		if(NRF24L01_TxPacket(Tx_Pair_Buffer) == TX_OK)
		{
			break;
		}
	}
	LED_Close();

	NRF_Frequency = (Tx_Pair_Buffer[0] + Tx_Pair_Buffer[1] + Tx_Pair_Buffer[2]) % 100;
	WriteFlash(Flash_Add, (uint32_t)NRF_Frequency);
}


