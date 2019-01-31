#include "sys.h"

int main(void)
{ 
	SCB->VTOR = 0x08000000 | 0x20000;
	Stm32_Clock_Init();	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	BoardLEDInit();
	Motor2WInit();
	Workspace();
}
