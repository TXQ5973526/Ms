
#include "Digital_Tube.h"


uint16_t DT_data[8]={0x0a,0x01,0xfe,0x00,0x00,0x00,0x00,0x0d};






void LD_NumSet(uint8_t pin,uint16_t data){



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

	DT_data[3]= (data/1000);
	DT_data[4]=	(data/100%10);	
	DT_data[5]=	(data%1000/10);
	DT_data[6]=	(data%10);   


	 for(int a=0;a<8;a++)  {
	 switch(pin)
	 {
	 case 1:    USART_SendData( USART3, DT_data[a]);break;
	 case 2:	USART_SendData( USART2, DT_data[a]);break;
	 case 3:	USART_SendData( USART6, DT_data[a]);break;
	}	
	  delay_ms(1); 
}
return ;

}
BoardLEDAllOpen();
}


void LD_DanSet(uint8_t pin,int num,uint16_t data){



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

	DT_data[7-num]=	data;
   
	 for(int a=0;a<8;a++)  {
	 switch(pin)
	 {
	 case 1:    USART_SendData( USART3, DT_data[a]);break;
	 case 2:	USART_SendData( USART2, DT_data[a]);break;
	 case 3:	USART_SendData( USART6, DT_data[a]);break;
	}	
	  delay_ms(1); 
}
return ;

}
BoardLEDAllOpen();
}

void LD_Set(uint8_t pin,uint16_t data1,uint16_t data2,uint16_t data3,uint16_t data4){



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

	DT_data[3]= data1;
	DT_data[4]=	data2;
	DT_data[5]=	data3;
	DT_data[6]=	data4;   

   
	 for(int a=0;a<8;a++)  {
	 switch(pin)
	 {
	 case 1:    USART_SendData( USART3, DT_data[a]);break;
	 case 2:	USART_SendData( USART2, DT_data[a]);break;
	 case 3:	USART_SendData( USART6, DT_data[a]);break;
	}	
	  delay_ms(1); 
    }
return ;

}
BoardLEDAllOpen();
}




