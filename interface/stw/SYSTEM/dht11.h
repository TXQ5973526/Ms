#ifndef __DHT11_H
#define __DHT11_H 
#include "stm32f4xx_conf.h"    

void DHT11_IO_IN(void);
void DHT11_IO_OUT(void);									   
void DHT11_DQ_OUT(u8 sta);
u8 DHT11_DQ_IN(void);
u8 DHT11_temperature(uint16_t GPIO_Pin); 
u8 DHT11_humidity(uint16_t GPIO_Pin);
u8 DHT11_Init(uint16_t GPIO_Pin);
u8 DHT11_Read_Data(u8 *temp,u8 *humi);//读取温湿度
u8 DHT11_Read_Byte(void);//读出一个字节
u8 DHT11_Read_Bit(void);//读出一个位
u8 DHT11_Check(void);//检测是否存在DHT11
void DHT11_Rst(void);//复位DHT11    
#endif















