#include "flash.h"

uint32_t FLASH_START_ADDR = 0x8006000;//+1024*63; //1024 一页大小1k , 63  flash有64K在最后一页首地址开始写
/*****************************************************************************
功能：flash写

输入：addr:写地址 0-一页大小  data ：4字节数据

返回：无
******************************************************************************/
void WriteFlash(uint32_t addr,uint32_t data)
{
	FLASH_Unlock(); //FLASH解锁
	FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPERR);//清除所有挂起标志位
	FLASH_ErasePage(FLASH_START_ADDR); //擦除FLASH 页
	FLASH_ProgramWord(FLASH_START_ADDR+(addr*4),data); //写入数据
	FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPERR);//??3y±ê????
	FLASH_Lock(); //锁定FLASH
}

void FLASH_WriteByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num)
{
	uint32_t HalfWord;
	Byte_Num = Byte_Num/2;
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
	FLASH_ErasePage(addr);
	while(Byte_Num --)
	{
		HalfWord=*(p++);
		HalfWord|=*(p++)<<8;
		FLASH_ProgramHalfWord(addr, HalfWord);
		addr += 2;
	}
	FLASH_Lock();
}

/*****************************************************************************
功能：读flash

输入：读地址

返回：读到的4字节数据
******************************************************************************/
uint32_t ReadFlash(uint16_t addr)
{
	uint32_t value;
	value = *(uint32_t*)(FLASH_START_ADDR+(addr*4));
	return value;
}

void FLASH_ReadByte(uint32_t addr , uint8_t *p , uint16_t Byte_Num)
{
	while(Byte_Num--)
	{
		*(p++)=*((uint8_t*)addr++);
	}
}

