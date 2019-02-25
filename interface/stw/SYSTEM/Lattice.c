
#include "Lattice.h"




u16 Lattice_data[12]={0x0a,0x02,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0d};


void Lattice_Send(uint8_t pin,u16 data1,u16 data2,u16 data3,u16 data4,u16 data5,u16 data6,u16 data7,u16 data8){


	if (pin >= 1 && pin <= 3) {
		
		if (PinUARTUseFlag[pin - 1] != 2)
		{
			PinUARTUseFlag[pin - 1] = 2;
			if (pin == 1) {
				uart3_init(115200);
			} else if (pin == 2) {
				uart2_init(115200);
			} else {
				uart6_init(115200);
			}
		}
			

	  Lattice_data[3]=data1;
	  Lattice_data[4]=data2;
	  Lattice_data[5]=data3;
	  Lattice_data[6]=data4;
	  Lattice_data[7]=data5;
	  Lattice_data[8]=data6;
	  Lattice_data[9]=data7;
	  Lattice_data[10]=data8;
	 for(int a=0;a<12;a++)  {
	 switch(pin)
	 {
	 case 1:    USART_SendData( USART3, Lattice_data[a]);break;
	 case 2:	USART_SendData( USART2, Lattice_data[a]);break;
	 case 3:	USART_SendData( USART6, Lattice_data[a]);break;
	}	
	  delay_ms(1); 
}
return ;

}
BoardLEDAllOpen();
}

