#include "adc.h"

uint16_t Get_Adc(uint8_t ch);

uint16_t ADCGet(uint16_t pin)
{
	if (pin >= 1 && pin <= 8) {
		GPIO_TypeDef* GPIOx = Getbase(0, pin);
		uint32_t PINx = GetPin(0, pin);

		if (PinInUseFlag[pin] != 4) {
			PinInUseFlag[pin] = 4;

			//---------- 初始化ADC ----------
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
			GPIO_Set(GPIOx, PINx, GPIO_Mode_AN, GPIO_OType_PP, GPIO_Speed_100MHz, GPIO_PuPd_NOPULL);
			RCC->APB2RSTR |= 1 << 8;   	//ADCs复位
			RCC->APB2RSTR &= ~(1 << 8);	//复位结束
			ADC->CCR = 3 << 16;			//ADCCLK=PCLK2/4=84/4=21Mhz,ADC时钟最好不要超过36Mhz

			ADC1->CR1 = 0;   			//CR1设置清零
			ADC1->CR2 = 0;   			//CR2设置清零
			ADC1->CR1 |= 0 << 24;      	//12位模式
			ADC1->CR1 |= 0 << 8;    	//非扫描模式

			ADC1->CR2 &= ~(1 << 1);    	//单次转换模式
			ADC1->CR2 &= ~(1 << 11);   	//右对齐
			ADC1->CR2 |= 0 << 28;    	//软件触发

			ADC1->SQR1 &= ~(0XF << 20);
			ADC1->SQR1 |= 0 << 20;     	//1个转换在规则序列中 也就是只转换规则序列1

			//设置通道pin的采样时间
			ADC1->SMPR2 &= ~(7 << (3 * (pin+3))); 	//通道(pin+3)采样时间清空
			ADC1->SMPR2 |= 7 << (3 * (pin+3)); 		//通道(pin+3)  480个周期,提高采样时间可以提高精确度

			ADC1->CR2 |= 1 << 0;	   	//开启AD转换器

		}
		return Get_Adc(pin+3);
	}
	return 0;
}

//获得ADC值
//ch:通道值 0~16
//返回值:转换结果
uint16_t Get_Adc(uint8_t ch)   
{
	//设置转换序列	  		 
	ADC1->SQR3&=0XFFFFFFE0;//规则序列1 通道ch
	ADC1->SQR3|=ch;		  			    
	ADC1->CR2|=1<<30;       //启动规则转换通道 
	while(!(ADC1->SR&1<<1));//等待转换结束	 	   
	return ADC1->DR;		//返回adc值	
}
