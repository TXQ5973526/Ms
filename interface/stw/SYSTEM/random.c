#include "random.h"
#include "delay.h"

uint8_t RandomInit(void)
{
	uint8_t Count = 0;
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
	RNG_Cmd(ENABLE);
	while (RNG_GetFlagStatus(RNG_FLAG_DRDY) == RESET && Count < 200)	//等待随机数就绪
	{
		Count++;
		delay_us(100);
	}
	if (Count >= 200)
	{
		return 1;
	} else {
		return 0;
	}
}

int RandomNum(int min, int max)
{
	static uint8_t RanIn = 0;
	if (RanIn == 0) {
		RanIn = 1;
		RandomInit();
	}
	while (RNG_GetFlagStatus(RNG_FLAG_DRDY) == RESET);
	return RNG_GetRandomNumber() % (max - min + 1) + min;
}


