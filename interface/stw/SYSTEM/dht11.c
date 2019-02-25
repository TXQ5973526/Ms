#include "dht11.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//DHT11 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/7
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
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



//复位DHT11
void DHT11_Rst(void)	   
{                 
	DHT11_IO_OUT(); 	//SET OUTPUT
	DHT11_DQ_OUT(0); 	//拉低DQ
	delay_ms(20);    	//拉低至少18ms
	DHT11_DQ_OUT(1); 	//DQ=1 
	delay_us(30);     	//主机拉高20~40us
}
//等待DHT11的回应
//返回1:未检测到DHT11的存在
//返回0:存在
u8 DHT11_Check(void) 	   
{   
	u8 retry=0;
	DHT11_IO_IN();//SET INPUT	 
    while (DHT11_DQ_IN()&&retry<100)//DHT11会拉低40~80us
	{
		retry++;
		delay_us(1);
	};	 
	if(retry>=100)return 1;
	else retry=0;
    while (!DHT11_DQ_IN()&&retry<100)//DHT11拉低后会再次拉高40~80us
	{
		retry++;
		delay_us(1);
	};
	if(retry>=100)return 1;	    
	return 0;
}
//从DHT11读取一个位
//返回值：1/0
u8 DHT11_Read_Bit(void) 			 
{
 	u8 retry=0;
	while(DHT11_DQ_IN()&&retry<100)//等待变为低电平
	{
		retry++;
		delay_us(1);
	}
	retry=0;
	while(!DHT11_DQ_IN()&&retry<100)//等待变高电平
	{
		retry++;
		delay_us(1);
	}
	delay_us(40);//等待40us
	if(DHT11_DQ_IN())return 1;
	else return 0;		   
}
//从DHT11读取一个字节
//返回值：读到的数据
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
//从DHT11读取一次数据
//temp:温度值(范围:0~50°)
//humi:湿度值(范围:20%~90%)
//返回值：0,正常;1,读取失败
u8 DHT11_Read_Data(u8 *temp,u8 *humi)    
{        
 	u8 buf[5]={0};
	u8 i=0;
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)//读取40位数据
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
//读取温度
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
		for(i=0;i<5;i++)//读取40位数据
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
//读取湿度
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
		for(i=0;i<5;i++)//读取40位数据
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
//初始化DHT11的IO口 DQ 同时检测DHT11的存在
//返回1:不存在
//返回0:存在    	 
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
























