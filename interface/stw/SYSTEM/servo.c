#include "servo.h"
#include "pwm.h"
#include "led.h"

#define PWM_Period	20000

void ServoAngle(uint8_t pin, uint32_t angle)
{
	if (pin >= 1 && pin <= 8)
	{
		if (PinOutUseFlag[pin] != 5) {
			PinOutUseFlag[pin] = 5;
			PWMInit(pin, PWM_Period);
		}
		if ( angle > 180 )
			angle = 180;
		angle = 500 + angle * 500 / 45;
		PWMSet(pin, angle);
		return;
	}
	BoardLEDAllOpen();
}
