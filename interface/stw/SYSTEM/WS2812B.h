#ifndef __WS2812B_H
#define __WS2812B_H
#include "sys.h"
#include "delay.h" 


extern u8  col[4][3];
extern u8 R, G, B;
extern GPIO_TypeDef* GPIOxx;
extern u32 BITxx;
void RGB_SET_Col(u32 COLL);
void RGB_Rst(void);
void RGB_Dow(void);
void RGB_Hig(void);
void RGBLED_Colour(uint16_t pin,uint32_t colour);
void RGBLED_RGB(uint16_t pin,uint8_t Red,uint8_t Green,uint8_t Blue);
void RGBLED_RGBSet (u16 pin,u8 rgb,u8 num);
void RGBLED_Init(uint16_t pin);

void RGBLED3_Colour1(uint16_t pin,uint8_t led_num,uint32_t colour);
void RGBLED3_Colour3(uint16_t pin,uint32_t colour1,uint32_t colour2,uint32_t colour3);
void RGBLED3_RGB(uint16_t pin,uint8_t led_num,uint8_t rgb,uint8_t num);

void RGBfor(uint16_t pin);
#endif
