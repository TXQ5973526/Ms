#ifndef __FLASH_H
#define	__FLASH_H

#include "stm32f0xx.h"
#include "stm32f0xx_flash.h"
uint32_t ReadFlash(uint16_t addr);
void WriteFlash(uint32_t addr,uint32_t data);

void FLASH_WriteByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num);
void FLASH_ReadByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num);

#endif 

