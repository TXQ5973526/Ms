#include "irc.h"
#include "usart.h"
#include "led.h"

uint8_t IRCU1;
uint8_t IRCU2;
uint8_t IRCU3;

//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
//u16 USART_RX_STA=0;       //接收状态标记
uint8_t IRCSState(uint8_t pin)
{
	if (pin >= 1 && pin <= 3) {
		uint8_t temp = 0;
		if (PinUARTUseFlag[pin-1] != 1)
		{
			PinUARTUseFlag[pin-1] = 1;
			if (pin == 1) {
				uart3_init(9600);
			} else if (pin == 2) {
				uart2_init(9600);
			} else {
				uart6_init(9600);
			}
		}
		if (pin == 1) {
			temp = IRCU1;
			IRCU1 = 0;
		} else if (pin == 2) {
			temp = IRCU2;
			IRCU2 = 0;
		} else {
			temp = IRCU3;
			IRCU3 = 0;
		}
		return temp;
	}
	BoardLEDAllOpen();
	return 0;
}
