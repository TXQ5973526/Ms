#include "flash.h"

uint32_t FLASH_START_ADDR = 0x8006000;//+1024*63; //1024 һҳ��С1k , 63  flash��64K�����һҳ�׵�ַ��ʼд
/*****************************************************************************
���ܣ�flashд

���룺addr:д��ַ 0-һҳ��С  data ��4�ֽ�����

���أ���
******************************************************************************/
void WriteFlash(uint32_t addr,uint32_t data)
{
	FLASH_Unlock(); //FLASH����
	FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPERR);//������й����־λ
	FLASH_ErasePage(FLASH_START_ADDR); //����FLASH ҳ
	FLASH_ProgramWord(FLASH_START_ADDR+(addr*4),data); //д������
	FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPERR);//??3y����????
	FLASH_Lock(); //����FLASH
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
���ܣ���flash

���룺����ַ

���أ�������4�ֽ�����
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

