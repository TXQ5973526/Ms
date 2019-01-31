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

/* 获取缓冲区的长度 */
#define TxBufferSize1   (countof(TxBuffer1) - 1)
#define RxBufferSize1   (countof(TxBuffer1) - 1)
#define countof(a)      (sizeof(a) / sizeof(*(a)))
#define BufferSize 		(countof(Tx_Buffer)-1)

#define abs_dif(X,Y)	( X > Y) ? ( X - Y):( Y - X)

// ADC1转换的电压值通过MDA方式传到flash
extern __IO uint16_t  RegularConvData_Tab[2];

// 局部变量，用于存从flash读到的电压值
volatile unsigned char Coding8421_X;
volatile unsigned char Coding8421_Y;

unsigned char Coding8421_X_Initial;
unsigned char Coding8421_Y_Initial;
unsigned char Coding8421_X_error;
unsigned char Coding8421_Y_error;
extern unsigned char NRF_Frequency;

uint8_t  Tx_Pair_Buffer[3];
uint8_t  Rx_Pair_Buffer[3];
uint8_t  Tx_Buffer[3]; // 无线传输发送数据
uint8_t  Rx_Buffer[7]; // 无线传输接收数据
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
	/*********摇杆初始化 AD采集DMA方式    *********/
	ADC1_DMA_Init();
	/*********LED初始化    *********/
	LED_Init();
	LED_Close();
	Get_ChipID();
	Get_Pairing();
	Flash_Load = ReadFlash(Flash_Add);
	/*********延时，确保AD采集完，否则影响接下来的判断    *********/
	Delay(100);
	/*********选择接收发送模式    *********/
	Mode_choose_Init();
/*************************************************************************************************************************************/
/**********************************************************					**********************************************************/
/**********************************************************     接收模块    **********************************************************/
/**********************************************************					**********************************************************/
/*************************************************************************************************************************************/
	if( GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7) == 0)		//无摇杆，为接收板
	{
		/*********	  NRF24L01初始化	*********/
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
			//摇杆值
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
				if((LED_Count >= 254) && Mode_flag == 1)//PWM模式下摇杆处于中间位置时发送数据
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
				else if((LED_Count >= 254) && Mode_flag == 2)//电位器模式下摇杆处于中间位置时发送数据
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

			/*********	  编码盘校验	*********/
			//Coding8421_Check();
		}
	}
/*************************************************************************************************************************************/
/**********************************************************					**********************************************************/
/**********************************************************     发射模块    **********************************************************/
/**********************************************************					**********************************************************/
/*************************************************************************************************************************************/
	else
	{

		/*********摇杆初始值*********/
		Coding8421_X_Initial = RegularConvData_Tab[1] / 16;
		Coding8421_Y_Initial = RegularConvData_Tab[0] / 16;

		/*********NRF24L01初始化	*********/
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
			/*********摇杆值	*********/
			Coding8421_X = RegularConvData_Tab[1] / 16;
			Coding8421_Y = RegularConvData_Tab[0] / 16;
			Coding8421_X_error = abs_dif( Coding8421_X , Coding8421_X_Initial);
			Coding8421_Y_error = abs_dif( Coding8421_Y , Coding8421_Y_Initial);

			/*********NRF发送数据包*********/
			Tx_Buffer[0] = KEY_Read();//采集2.4G遥控器按键信息
			Tx_Buffer[1] = Coding8421_X;//采集摇杆X轴数据
			Tx_Buffer[2] = Coding8421_Y;//采集摇杆Y轴数据

			Change_Mode();//按住摇杆键开机进入电位器模式，否则进入PWM模式

			/*********NRF发送判断*********/
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

			/*********编码盘校验*********/
			//Coding8421_Check();
		}
	}
}

void PWM_Mode(void)
{
	LED_Open();
	LED_Count = 0;

	if(Rx_Buffer[1] < 128 && Rx_Buffer[2] < 128)//判断摇杆当前位置处于数学象限中的位置
		Data_Buffer[0] = 2;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] < 128)
		Data_Buffer[0] = 1;
	else if(Rx_Buffer[1] < 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 3;
	else if(Rx_Buffer[1] >= 128 && Rx_Buffer[2] >= 128)
		Data_Buffer[0] = 4;

	Rx_Buffer[0] = Rx_Buffer[0] % 32;//取按键值
	Rx_Buffer[1] = (abs_dif(Rx_Buffer[1], 127.5)) * 1.99;
	Rx_Buffer[2] = (abs_dif(Rx_Buffer[2], 127.5)) * 1.99;

	/*********定义摇杆前后左右(2134)对应位置，对输出PWM值进行处理*********/
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

	if(Rx_Buffer[1] <= 50 && Rx_Buffer[2] <= 50)//摇杆处于中间位置时
	{
		Data_Buffer[1] = 0;
		Data_Buffer[2] = 0;
		Data_Buffer[0] = 0;
	}

	Rx_Buffer[3] = (Rx_Buffer[0] | (Data_Buffer[0] << 5));//摇杆方向|按键值
	Rx_Buffer[4] = (uint8_t)Data_Buffer[1];//输出PWM1
	Rx_Buffer[5] = (uint8_t)Data_Buffer[2];//输出PWM2

	/*********协议头尾*********/
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

	/*********2.4G遥控第一次开机检测摇杆按键是否长按*********/
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


