#include "led.h"
#include "pwm.h"

void BoardLEDInit(void)
{
	GPIO_Set(GPIOC, GPIO_Pin_8 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_UP);
}
void BoardLEDAllOpen(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}
void BLEDState(uint8_t pin, uint8_t State)
{
	if (pin >= 1 && pin <= 4)
	{
		uint32_t PINx;
		switch (pin) {
		case 1: PINx = GPIO_Pin_15; break;
		case 2: PINx = GPIO_Pin_14; break;
		case 3: PINx = GPIO_Pin_13; break;
		case 4: PINx = GPIO_Pin_8; break;
		}
		if (State == 0) {
			GPIO_ResetBits(GPIOC, PINx);
		} else if (State == 1) {
			GPIO_SetBits(GPIOC, PINx);
		} else if (State == 2) {
			GPIO_ToggleBits(GPIOC, PINx);
		}
		return;
	}
	BoardLEDAllOpen();
}
void LEDPWM(uint8_t pin, uint8_t PulseWidth)
{
	if (pin >= 1 && pin <= 8)
	{
		if (PinOutUseFlag[pin] != 4) {
			PinOutUseFlag[pin] = 4;
			PWMInit(pin,100);
		}
		PWMSet(pin,PulseWidth);
		return;
	}
	BoardLEDAllOpen();
}