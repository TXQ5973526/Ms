#include "gpio.h"
#include "led.h"


//PinInUseFlag[pin] = num;
//PinOutUseFlag[pin] = num;
//---------- pin ----------
//	0:
//	1-8:  对应编号IN1-IN8管脚
//---------- num ----------
//	00:	未初始化
//	01:	GPIO IN
//	02:	GPIO OUT
//	03:	ADC
//	04:	PWM_100	（TIM_OCMode_PWM1）
//	05:	PWM_2000（TIM_OCMode_Toggle）
//	06:	PWM_xx	（TIM_OCMode_Toggle）
//	07:	PWM_xx	（TIM_OCMode_Toggle）
//	08:	PWM_xx	（TIM_OCMode_Toggle）
//	09:	模拟PWM
//	10:	UART
//	11:	模拟UART
//	12:	IIC
//	13:	模拟IIC
uint8_t PinInUseFlag[9] = {0};
uint8_t PinOutUseFlag[9] = {0};
//---------- GPIO输入 ------------------------------------------
uint8_t WLINState(uint8_t pin)
{
	if (pin >= 1 && pin <= 8) {
		GPIO_TypeDef* GPIOx = Getbase(0, pin);
		uint32_t PINx = GetPin(0, pin);
		if (PinInUseFlag[pin] != 1) {
			PinInUseFlag[pin] = 1;
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
			GPIO_Set(GPIOx, PINx, GPIO_Mode_IN, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
		}
		return GPIO_ReadInputDataBit(GPIOx, PINx);
	}
	BoardLEDAllOpen();
	return 0;
}
//---------- GPIO输出 ------------------------------------------
void WLOUTState(uint8_t pin, uint8_t State)
{
	if (pin >= 1 && pin <= 8) {
		GPIO_TypeDef* GPIOx = Getbase(2, pin);
		uint32_t PINx = GetPin(2, pin);
		if (PinOutUseFlag[pin] != 2) {
			PinOutUseFlag[pin] = 2;
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
			GPIO_Set(GPIOx, PINx, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
		}
		if (State == 0) {
			GPIO_ResetBits(GPIOx, PINx);
		} else if (State == 1) {
			GPIO_SetBits(GPIOx, PINx);
		} else if (State == 2) {
			GPIO_ToggleBits(GPIOx, PINx);
		}
		return;
	}
	BoardLEDAllOpen();
}

//---------- 基础接口 -----------------------------------------
//---------- pinwei ----------
//	0	IN AF
//	1	IN GPIO
//	2	OUT AF
//	3	OUT GPIO
GPIO_TypeDef* Getbase(uint8_t pinwei, uint8_t pin)
{
	GPIO_TypeDef* temp;
	//IN AF
	if ( pinwei == 0) {
		switch (pin) {
		case 1:;
		case 2:;
		case 3:;
		case 4: temp = GPIOA; break;
		case 5:;
		case 6: temp = GPIOB; break;
		case 7:;
		case 8: temp = GPIOC; break;
		}
		//IN GPIO
	} else if ( pinwei == 1) {
		switch (pin) {
		case 1:;
		case 2:;
		case 3:;
		case 4:;
		case 5:;
		case 6:;
		case 7:;
		case 8: temp = GPIOE; break;
		}
		//OUT AF
	} else if ( pinwei == 2) {
		switch (pin) {
		case 1:;
		case 2:;
		case 3:;
		case 4: temp = GPIOA; break;
		case 5:;
		case 6: temp = GPIOE; break;
		case 7:;
		case 8: temp = GPIOB; break;
		}
		//OUT GPIO
	} else if ( pinwei == 3) {
		switch (pin) {
		case 1:;
		case 2:;
		case 3:;
		case 4: temp = GPIOD; break;
		case 5:;
		case 6:;
		case 7:;
		case 8: temp = GPIOE; break;
		}
	} else {
		BoardLEDAllOpen();
	}
	return temp;
}
uint32_t GetPin(uint8_t pinwei, uint8_t pin)
{
	uint32_t temp = 0;
	if ( pinwei == 0) {
		switch (pin) {
		case 1: temp = GPIO_Pin_4; break;
		case 2: temp = GPIO_Pin_5; break;
		case 3: temp = GPIO_Pin_6; break;
		case 4: temp = GPIO_Pin_7; break;
		case 5: temp = GPIO_Pin_0; break;
		case 6: temp = GPIO_Pin_1; break;
		case 7: temp = GPIO_Pin_0; break;
		case 8: temp = GPIO_Pin_1; break;
		}
	} else if ( pinwei == 1) {
		switch (pin) {
		case 1: temp = GPIO_Pin_8; break;
		case 2: temp = GPIO_Pin_9; break;
		case 3: temp = GPIO_Pin_10; break;
		case 4: temp = GPIO_Pin_11; break;
		case 5: temp = GPIO_Pin_12; break;
		case 6: temp = GPIO_Pin_13; break;
		case 7: temp = GPIO_Pin_14; break;
		case 8: temp = GPIO_Pin_15; break;
		}
	} else if ( pinwei == 2) {
		switch (pin) {
		case 1: temp = GPIO_Pin_0; break;
		case 2: temp = GPIO_Pin_1; break;
		case 3: temp = GPIO_Pin_2; break;
		case 4: temp = GPIO_Pin_3; break;
		case 5: temp = GPIO_Pin_5; break;
		case 6: temp = GPIO_Pin_6; break;
		case 7: temp = GPIO_Pin_14; break;
		case 8: temp = GPIO_Pin_15; break;
		}
	} else if ( pinwei == 3) {
		switch (pin) {
		case 1: temp = GPIO_Pin_8; break;
		case 2: temp = GPIO_Pin_9; break;
		case 3: temp = GPIO_Pin_10; break;
		case 4: temp = GPIO_Pin_11; break;
		case 5: temp = GPIO_Pin_0; break;
		case 6: temp = GPIO_Pin_1; break;
		case 7: temp = GPIO_Pin_2; break;
		case 8: temp = GPIO_Pin_3; break;
		}
	} else {
		BoardLEDAllOpen();
	}
	return temp;
}

//---------------------------------------------------
//---------------------------------------------------
//GPIO复用设置
//GPIOx:GPIOA~GPIOI.
//BITx:0~15,代表IO引脚编号.
//AFx:0~15,代表AF0~AF15.
//AF0~15设置情况(这里仅是列出常用的,详细的请见407数据手册,56页Table 7):
//AF0:MCO/SWD/SWCLK/RTC   AF1:TIM1/TIM2;            AF2:TIM3~5;               AF3:TIM8~11
//AF4:I2C1~I2C3;          AF5:SPI1/SPI2;            AF6:SPI3;                 AF7:USART1~3;
//AF8:USART4~6;           AF9;CAN1/CAN2/TIM12~14    AF10:USB_OTG/USB_HS       AF11:ETH
//AF12:FSMC/SDIO/OTG/HS   AF13:DCIM                 AF14:                     AF15:EVENTOUT
void GPIO_AF_Set(GPIO_TypeDef* GPIOx, uint8_t BITx, uint8_t AFx)
{
	GPIOx->AFR[BITx >> 3] &= ~(0X0F << ((BITx & 0X07) * 4));
	GPIOx->AFR[BITx >> 3] |= (u32)AFx << ((BITx & 0X07) * 4);
}

//GPIO通用设置
//GPIOx:GPIOA~GPIOI.
//BITx:	0X0000~0XFFFF,位设置,每个位代表一个IO,第0位代表Px0,第1位代表Px1,依次类推.比如0X0101,代表同时设置Px0和Px8.
//		GPIO_Pin_0                 ((uint16_t)0x0001)
//		GPIO_Pin_1                 ((uint16_t)0x0002)
//		GPIO_Pin_2                 ((uint16_t)0x0004)
//		GPIO_Pin_3                 ((uint16_t)0x0008)
//		GPIO_Pin_4                 ((uint16_t)0x0010)
//		GPIO_Pin_5                 ((uint16_t)0x0020)
//		GPIO_Pin_6                 ((uint16_t)0x0040)
//		GPIO_Pin_7                 ((uint16_t)0x0080)
//		GPIO_Pin_8                 ((uint16_t)0x0100)
//		GPIO_Pin_9                 ((uint16_t)0x0200)
//		GPIO_Pin_10                ((uint16_t)0x0400)
//		GPIO_Pin_11                ((uint16_t)0x0800)
//		GPIO_Pin_12                ((uint16_t)0x1000)
//		GPIO_Pin_13                ((uint16_t)0x2000)
//		GPIO_Pin_14                ((uint16_t)0x4000)
//		GPIO_Pin_15                ((uint16_t)0x8000)
//		GPIO_Pin_All               ((uint16_t)0xFFFF)
//MODE:	0~3;模式选择,0,输入(系统复位默认状态);1,普通输出;2,复用功能;3,模拟输入.
//		GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
//		GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
//		GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
//		GPIO_Mode_AN   = 0x03  /*!< GPIO Analog Mode */
//OTYPE:0/1;输出类型选择,0,推挽输出;1,开漏输出.
//		GPIO_OType_PP = 0x00,
//		GPIO_OType_OD = 0x01
//OSPEED:0~3;输出速度设置,0,2Mhz;1,25Mhz;2,50Mhz;3,100Mh.
//		GPIO_Speed_2MHz    GPIO_Low_Speed
//		GPIO_Speed_25MHz   GPIO_Medium_Speed
//		GPIO_Speed_50MHz   GPIO_Fast_Speed
//		GPIO_Speed_100MHz  GPIO_High_Speed
//PUPD:	0~3:上下拉设置,0,不带上下拉;1,上拉;2,下拉;3,保留.
//		GPIO_PuPd_NOPULL = 0x00,
//		GPIO_PuPd_UP     = 0x01,
//		GPIO_PuPd_DOWN   = 0x02
//注意:在输入模式(普通输入/模拟输入)下,OTYPE和OSPEED参数无效!!
void GPIO_Set(GPIO_TypeDef* GPIOx, u32 BITx, u32 MODE, u32 OTYPE, u32 OSPEED, u32 PUPD)
{
	u32 pinpos = 0, pos = 0, curpin = 0;
	for (pinpos = 0; pinpos < 16; pinpos++)
	{
		pos = 1 << pinpos;	//一个个位检查
		curpin = BITx & pos; //检查引脚是否要设置
		if (curpin == pos)	//需要设置
		{
			GPIOx->MODER &= ~(3 << (pinpos * 2));	//先清除原来的设置
			GPIOx->MODER |= MODE << (pinpos * 2);	//设置新的模式
			if ((MODE == 0X01) || (MODE == 0X02))	//如果是输出模式/复用功能模式
			{
				GPIOx->OSPEEDR &= ~(3 << (pinpos * 2));	//清除原来的设置
				GPIOx->OSPEEDR |= (OSPEED << (pinpos * 2)); //设置新的速度值
				GPIOx->OTYPER &= ~(1 << pinpos) ;		//清除原来的设置
				GPIOx->OTYPER |= OTYPE << pinpos;		//设置新的输出模式
			}
			GPIOx->PUPDR &= ~(3 << (pinpos * 2));	//先清除原来的设置
			GPIOx->PUPDR |= PUPD << (pinpos * 2);	//设置新的上下拉
		}
	}
}
