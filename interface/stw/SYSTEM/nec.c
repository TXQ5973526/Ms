#include "nec.h"
void NEC_Send_logic_1(uint8_t Pin)
{
    WLOUTState(Pin,0); //NEC=0;
    delay_us(560);
    WLOUTState(Pin,1);  //NEC=1;
    delay_us(1690);
}
void NEC_Send_logic_0(uint8_t Pin)
{
    WLOUTState(Pin,0); //NEC=0;
    delay_us(560);
    WLOUTState(Pin,1);  //NEC=1;
    delay_us(560);
}

u8 NEC_Send_Command(uint8_t Pin,u8 command)
{
	u8 i,j;
    u8 addres=NEC_ADDRES;
	u8 U_addres=~addres,U_command=~command;
	WLOUTState(Pin,0);
	delay_ms(9);
	WLOUTState(Pin,1);//NEC=1;
	delay_us(4500);
	for(i=0;i<8;i++)
	{
		j=(addres>>i)&0x01;
		if(j==1)
			NEC_Send_logic_1(Pin);
        else
			NEC_Send_logic_0(Pin);			
	}
	for(i=0;i<8;i++)
	{
		j=(U_addres>>i)&0x01;
		if(j==1)
			NEC_Send_logic_1(Pin);
        else
			NEC_Send_logic_0(Pin);			
	}
	for(i=0;i<8;i++)
	{
		j=(command>>i)&0x01;
		if(j==1)
			NEC_Send_logic_1(Pin);
        else
			NEC_Send_logic_0(Pin);			
	}
	for(i=0;i<8;i++)
	{
		j=(U_command>>i)&0x01;
		if(j==1)
			NEC_Send_logic_1(Pin);
        else
			NEC_Send_logic_0(Pin);			
	}
	WLOUTState(Pin,0);//NEC=0;
	delay_us(560);
	WLOUTState(Pin,1);//NEC=1;
	return 0;
}
//��С�������32�������� 
u8 NEC_Adjust_volume(uint8_t Pin,u8 command,u8 DB)
{
	u8 i,j,k,full;
    u8 addres=NEC_ADDRES;
	u8 U_addres=~addres,U_command=~command;
    if((command==NEC_Decrease)&&(DB==100))
        full=35;
    else if((command==NEC_Decrease)&&(DB<100))
        full=31;
    if((command==NEC_Increase)&&(DB==100))
        full=35;
    else if((command==NEC_Increase)&&(DB<100))
        full=31;
    for(k=0;k<DB*0.01*full;k++)     //45
    {
        WLOUTState(Pin,0);
        delay_ms(9);
        WLOUTState(Pin,1);//NEC=1;
        delay_us(4500);
        for(i=0;i<8;i++)
        {
            j=(addres>>i)&0x01;
            if(j==1)
                NEC_Send_logic_1(Pin);
            else
                NEC_Send_logic_0(Pin);			
        }
        for(i=0;i<8;i++)
        {
            j=(U_addres>>i)&0x01;
            if(j==1)
                NEC_Send_logic_1(Pin);
            else
                NEC_Send_logic_0(Pin);			
        }
        for(i=0;i<8;i++)
        {
            j=(command>>i)&0x01;
            if(j==1)
                NEC_Send_logic_1(Pin);
            else
                NEC_Send_logic_0(Pin);			
        }
        for(i=0;i<8;i++)
        {
            j=(U_command>>i)&0x01;
            if(j==1)
                NEC_Send_logic_1(Pin);
            else
                NEC_Send_logic_0(Pin);			
        }
        WLOUTState(Pin,0);//NEC=0;
        delay_us(560);
        WLOUTState(Pin,1);//NEC=1;
        delay_ms(40);
    }
    return 0;
}