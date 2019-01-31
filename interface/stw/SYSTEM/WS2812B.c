#include "sys.h"
#include "WS2812B.h"
#include "led.h"

u8 R = 0xff, G = 0xff, B = 0xff;

u8 col[4][3] = {{0x7f, 0x7f, 0x7f}, {0x7f, 0x7f, 0x7f}, {0x7f, 0x7f, 0x7f}, {0x7f, 0x7f, 0x7f}};
GPIO_TypeDef* GPIOxx;
u32 BITxx;
void RGB_Hig(void) 
{


	GPIO_SetBits(GPIOxx, BITxx);

	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
///	__ASM("nop");__ASM("nop");__ASM("nop");
///	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");



	GPIO_ResetBits(GPIOxx, BITxx);

	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");

}
void RGB_Dow(void)
{


	GPIO_SetBits(GPIOxx, BITxx);
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");


	GPIO_ResetBits(GPIOxx, BITxx);

	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
	__ASM("nop"); __ASM("nop"); __ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");
//	__ASM("nop");__ASM("nop");__ASM("nop");

}


void RGB_Rst(void) 
{
	GPIO_ResetBits(GPIOxx, BITxx);
	delay_us(51);
}


void RGB_SET_Col(u32 COLL)
{

	RGB_Rst();
	for (int i = 23; i >= 0; i--) 
	{
		if (COLL >> i & 0x01)
		    RGB_Hig();
		else RGB_Dow();
	}

}



//È«²ÊLEDÄ£¿éÉè¶¨ÑÕÉ«¡£
void RGBLED_Colour(uint16_t pin, u32 colour)
{
	if (pin >= 1 && pin <= 8)
	{
		
		if (PinOutUseFlag[pin] != 2) {
			PinOutUseFlag[pin] = 2;
			GPIO_TypeDef* GPIOx = Getbase(2, pin);
			GPIOxx=GPIOx;
			uint32_t PINx = GetPin(2, pin);
			BITxx=PINx;
			if (PinOutUseFlag[pin] != 2) {
				PinOutUseFlag[pin] = 2;
				RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
				GPIO_Set(GPIOx, PINx, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			}
		}

		u8 red1, green1, blue1;
		red1 = (u8)(colour >> 16);
		green1 = (u8)(colour >> 8);
		blue1 = (u8)colour;

		RGBLED_RGB(pin, red1, green1, blue1);
		return;
	}
	BoardLEDAllOpen();
}
//È«²ÊLEDÄ£¿éÉè¶¨µ¥¸öÑÕÉ«¡£
void RGBLED_RGB(uint16_t pin, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	R = Red, G = Green, B = Blue;
	u8 col1[3] = {Green, Red, Blue};

	if (pin >= 1 && pin <= 8)
	{
	
		if (PinOutUseFlag[pin] != 2) {
			PinOutUseFlag[pin] = 2;
			GPIO_TypeDef* GPIOx = Getbase(2, pin);
			GPIOxx=GPIOx;
			uint32_t PINx = GetPin(2, pin);
			BITxx=PINx;
			if (PinOutUseFlag[pin] != 2) {
				PinOutUseFlag[pin] = 2;
				RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
				GPIO_Set(GPIOx, PINx, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			}
		}

		RGB_Rst();

		for (int i = 0; i < 3; i++)
			for (int j = 7; j >= 0; j--)
				if (col1[i] >> j & 0x01)
					RGB_Hig();
				else
					RGB_Dow();

		return;
	}
	BoardLEDAllOpen();





}

void RGBLED_RGBSet (u16 pin, u8 rgb, u8 num)
{

	switch (num)
	{
	case 1: RGBLED_RGB(pin, rgb, G, B); break;
	case 2: RGBLED_RGB(pin, R, rgb, B); break;
	case 3: RGBLED_RGB(pin, R, G, rgb); break;
	}
}

void RGBLED3_Colour1(uint16_t pin, uint8_t led_num, uint32_t colour)
{
	col[led_num][0] = (u8)(colour >> 8);
	col[led_num][1] = (u8)(colour >> 16);
	col[led_num][2] = (u8)colour;
	RGBfor(pin);
}



void RGBLED3_Colour3(uint16_t pin, uint32_t colour1, uint32_t colour2, uint32_t colour3)
{
	col[1][0] = (u8)(colour1 >> 8);
	col[1][1] = (u8)(colour1 >> 16);
	col[1][2] = (u8)colour1;

	col[2][0] = (u8)(colour2 >> 8);
	col[2][1] = (u8)(colour2 >> 16);
	col[2][2] = (u8)colour2;

	col[3][0] = (u8)(colour3 >> 8);
	col[3][1] = (u8)(colour3 >> 16);
	col[3][2] = (u8)colour3;

	RGBfor(pin);
}
void RGBLED3_RGB(uint16_t pin, uint8_t led_num, uint8_t rgb, uint8_t num)
{

	//RGB 123
	switch (rgb)
	{
	case 1: col[led_num][0] = 0;
		col[led_num][1] = (u8)num;
		col[led_num][2] = 0;	break;
	case 2: col[led_num][0] = (u8)num;
		col[led_num][1] = 0;
		col[led_num][2] = 0;	break;
	case 3: col[led_num][0] = 0;
		col[led_num][1] = 0;
		col[led_num][2] = (u8)num;	break;

	}

	RGBfor(pin);
}





void RGBfor(uint16_t pin)
{

	if (pin >= 1 && pin <= 8)
	{
		
		if (PinOutUseFlag[pin] != 2) {
			PinOutUseFlag[pin] = 2;
			GPIO_TypeDef* GPIOx = Getbase(2, pin);
			GPIOxx=GPIOx;
			uint32_t PINx = GetPin(2, pin);
			BITxx=PINx;
			if (PinOutUseFlag[pin] != 2) {
				PinOutUseFlag[pin] = 2;
				RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
				GPIO_Set(GPIOx, PINx, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
			}
		}

	RGB_Rst();
	for (int i = 0; i < 3; i++)
		for (int j = 7; j >= 0; j--)
			if (col[1][i] >> j & 0x01) RGB_Hig();
			else RGB_Dow();

	for (int i = 0; i < 3; i++)
		for (int j = 7; j >= 0; j--)
			if (col[2][i] >> j & 0x01) RGB_Hig();
			else RGB_Dow();

	for (int i = 0; i < 3; i++)
		for (int j = 7; j >= 0; j--)
			if (col[3][i] >> j & 0x01) RGB_Hig();
			else RGB_Dow();
	RGB_Rst();

		return;
	}
	BoardLEDAllOpen();


}

