#include "dht11.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//DHT11 ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved										  
//////////////////////////////////////////////////////////////////////////////////
uint16_t GPIO_DHT11Pin_Check;
uint8_t DHT11PinInitFlag[9] = {0};
void DHT11_IO_IN(void)
{
	if(PinInUseFlag[GPIO_DHT11Pin_Check]!=1)
		PinInUseFlag[GPIO_DHT11Pin_Check]=1;
	if(GPIO_DHT11Pin_Check == 1){
		GPIOA->MODER&=~(3<<(4*2));
		GPIOA->MODER|=0<<4*2;		
	}else if(GPIO_DHT11Pin_Check == 2){
		GPIOA->MODER&=~(3<<(5*2));
		GPIOA->MODER|=0<<5*2;		
	}else if(GPIO_DHT11Pin_Check == 3){
		GPIOA->MODER&=~(3<<(6*2));
		GPIOA->MODER|=0<<6*2;		
	}else if(GPIO_DHT11Pin_Check == 4){
		GPIOA->MODER&=~(3<<(7*2));
		GPIOA->MODER|=0<<7*2;		
	}else if(GPIO_DHT11Pin_Check == 5){
		GPIOB->MODER&=~(3<<(0*2));
		GPIOB->MODER|=0<<0*2;		
	}else if(GPIO_DHT11Pin_Check == 6){
		GPIOB->MODER&=~(3<<(1*2));
		GPIOB->MODER|=0<<1*2;				
	}else if(GPIO_DHT11Pin_Check == 7){
		GPIOC->MODER&=~(3<<(0*2));
		GPIOC->MODER|=0<<0*2;				
	}else if(GPIO_DHT11Pin_Check == 8){
		GPIOC->MODER&=~(3<<(1*2));
		GPIOC->MODER|=0<<1*2;				
	}	


}

void DHT11_IO_OUT(void)
{
	if(PinInUseFlag[GPIO_DHT11Pin_Check]!=2)
		PinInUseFlag[GPIO_DHT11Pin_Check]=2;
	if(GPIO_DHT11Pin_Check == 1){
		GPIOA->MODER&=~(3<<(4*2));
		GPIOA->MODER|=1<<4*2;		
	}else if(GPIO_DHT11Pin_Check == 2){
		GPIOA->MODER&=~(3<<(5*2));
		GPIOA->MODER|=1<<5*2;		
	}else if(GPIO_DHT11Pin_Check == 3){
		GPIOA->MODER&=~(3<<(6*2));
		GPIOA->MODER|=1<<6*2;		
	}else if(GPIO_DHT11Pin_Check == 4){
		GPIOA->MODER&=~(3<<(7*2));
		GPIOA->MODER|=1<<7*2;		
	}else if(GPIO_DHT11Pin_Check == 5){
		GPIOB->MODER&=~(3<<(0*2));
		GPIOB->MODER|=1<<0*2;		
	}else if(GPIO_DHT11Pin_Check == 6){
		GPIOB->MODER&=~(3<<(1*2));
		GPIOB->MODER|=1<<1*2;				
	}else if(GPIO_DHT11Pin_Check == 7){
		GPIOC->MODER&=~(3<<(0*2));
		GPIOC->MODER|=1<<0*2;				
	}else if(GPIO_DHT11Pin_Check == 8){
		GPIOC->MODER&=~(3<<(1*2));
		GPIOC->MODER|=1<<1*2;				
	}	
}

void DHT11_DQ_OUT(u8 sta)
{
	if(GPIO_DHT11Pin_Check == 1){
		PAout(4) = sta;
	}else if(GPIO_DHT11Pin_Check == 2){
		PAout(5) = sta;
	}else if(GPIO_DHT11Pin_Check == 3){
		PAout(6) = sta;
	}else if(GPIO_DHT11Pin_Check == 4){
		PAout(7) = sta;
	}else if(GPIO_DHT11Pin_Check == 5){
		PBout(0) = sta;
	}else if(GPIO_DHT11Pin_Check == 6){
		PBout(1) = sta;
	}else if(GPIO_DHT11Pin_Check == 7){
		PCout(0) = sta;
	}else if(GPIO_DHT11Pin_Check == 8){
		PCout(1) = sta;
	}

	PAout(4) = sta;
}

u8 DHT11_DQ_IN(void)
{
	if(GPIO_DHT11Pin_Check == 1){
		return PAin(4);
	}else if(GPIO_DHT11Pin_Check == 2){
		return PAin(5);
	}else if(GPIO_DHT11Pin_Check == 3){
		return PAin(6);
	}else if(GPIO_DHT11Pin_Check == 4){
		return PAin(7);
	}else if(GPIO_DHT11Pin_Check == 5){
		return PBin(0);
	}else if(GPIO_DHT11Pin_Check == 6){
		return PBin(1);
	}else if(GPIO_DHT11Pin_Check == 7){
		return PCin(0);
	}else if(GPIO_DHT11Pin_Check == 8){
		return PCin(1);
	}else {
		return 0;
	}
}



//��λDHT11
void DHT11_Rst(void)	   
{                 
	DHT11_IO_OUT(); 	//SET OUTPUT
	DHT11_DQ_OUT(0); 	//����DQ
	delay_ms(20);    	//��������18ms
	DHT11_DQ_OUT(1); 	//DQ=1 
	delay_us(30);     	//��������20~40us
}
//�ȴ�DHT11�Ļ�Ӧ
//����1:δ��⵽DHT11�Ĵ���
//����0:����
u8 DHT11_Check(void) 	   
{   
	u8 retry=0;
	DHT11_IO_IN();//SET INPUT	 
    while (DHT11_DQ_IN()&&retry<100)//DHT11������40~80us
	{
		retry++;
		delay_us(1);
	};	 
	if(retry>=100)return 1;
	else retry=0;
    while (!DHT11_DQ_IN()&&retry<100)//DHT11���ͺ���ٴ�����40~80us
	{
		retry++;
		delay_us(1);
	};
	if(retry>=100)return 1;	    
	return 0;
}
//��DHT11��ȡһ��λ
//����ֵ��1/0
u8 DHT11_Read_Bit(void) 			 
{
 	u8 retry=0;
	while(DHT11_DQ_IN()&&retry<100)//�ȴ���Ϊ�͵�ƽ
	{
		retry++;
		delay_us(1);
	}
	retry=0;
	while(!DHT11_DQ_IN()&&retry<100)//�ȴ���ߵ�ƽ
	{
		retry++;
		delay_us(1);
	}
	delay_us(40);//�ȴ�40us
	if(DHT11_DQ_IN())return 1;
	else return 0;		   
}
//��DHT11��ȡһ���ֽ�
//����ֵ������������
u8 DHT11_Read_Byte(void)    
{        
    u8 i=0,dat=0;
	for (i=0;i<8;i++) 
	{
   		dat<<=1; 
	    dat|=DHT11_Read_Bit();
    }						    
    return dat;
}
//��DHT11��ȡһ������
//temp:�¶�ֵ(��Χ:0~50��)
//humi:ʪ��ֵ(��Χ:20%~90%)
//����ֵ��0,����;1,��ȡʧ��
u8 DHT11_Read_Data(u8 *temp,u8 *humi)    
{        
 	u8 buf[5]={0};
	u8 i=0;
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)//��ȡ40λ����
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			*humi=buf[0];
			*temp=buf[2];
		}
		else{
			*humi=0;
		}
	}else return 1;
	return 0;	    
}
//��ȡ�¶�
u8 DHT11_temperature(uint16_t GPIO_Pin)    
{
	GPIO_DHT11Pin_Check =GPIO_Pin;	
 	u8 buf[5];
	u8 i=0;
	if(DHT11PinInitFlag[GPIO_Pin]==0)
	{
		DHT11_Init(GPIO_Pin);
		DHT11PinInitFlag[GPIO_Pin]=1;
	}	
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)//��ȡ40λ����
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			return buf[2];
		}
	}
	delay_ms(20); 
	return buf[2];	    
}
//��ȡʪ��
u8 DHT11_humidity(uint16_t GPIO_Pin)    
{
	GPIO_DHT11Pin_Check =GPIO_Pin;		
 	u8 buf[5];
	u8 i=0;
	if(DHT11PinInitFlag[GPIO_Pin]==0)
	{
		DHT11_Init(GPIO_Pin);
		DHT11PinInitFlag[GPIO_Pin]=1;
	}	
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)//��ȡ40λ����
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			return buf[0];
		}
	}
	delay_ms(20); 
	return buf[0];	    
}
//��ʼ��DHT11��IO�� DQ ͬʱ���DHT11�Ĵ���
//����1:������
//����0:����    	 
u8 DHT11_Init(uint16_t GPIO_Pin)
{
	if (GPIO_Pin >= 1 && GPIO_Pin <= 8) {
		GPIO_TypeDef* GPIOx = Getbase(0, GPIO_Pin);
		uint32_t PINx = GetPin(0, GPIO_Pin);
		if (PinInUseFlag[GPIO_Pin] != 2) {
			PinInUseFlag[GPIO_Pin] = 2;
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
			GPIO_Set(GPIOx, PINx, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_50MHz, GPIO_PuPd_UP);
		}
	}
	return 0;
}
























