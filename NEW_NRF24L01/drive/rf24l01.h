#ifndef _RF24L01_H
#define _RF24L01_H

#include"stm32f0xx.h"

/**********  NRF24L01�Ĵ�����������  ***********/
#define READ_REG        0x00  //�����üĴ���,��5λΪ�Ĵ�����ַ
#define WRITE_REG       0x20  //д���üĴ���,��5λΪ�Ĵ�����ַ
#define RD_RX_PLOAD     0x61  //��RX��Ч����,1~32�ֽ�
#define WR_TX_PLOAD     0xA0  //дTX��Ч����,1~32�ֽ�
#define FLUSH_TX        0xE1  //���TX FIFO�Ĵ���.����ģʽ����
#define FLUSH_RX        0xE2  //���RX FIFO�Ĵ���.����ģʽ����
#define REUSE_TX_PL     0xE3  //����ʹ����һ������,CEΪ��,���ݰ������Ϸ���.
#define NOP             0xFF  //�ղ���,����������״̬�Ĵ���	 
/**********  NRF24L01�Ĵ�����ַ   *************/
#define CONFIG          0x00  //���üĴ�����ַ                             
#define EN_AA           0x01  //ʹ���Զ�Ӧ���� 
#define EN_RXADDR       0x02  //���յ�ַ����
#define SETUP_AW        0x03  //���õ�ַ���(��������ͨ��)
#define SETUP_RETR      0x04  //�����Զ��ط�
#define RF_CH           0x05  //RFͨ��
#define RF_SETUP        0x06  //RF�Ĵ���
#define STATUS          0x07  //״̬�Ĵ���
#define OBSERVE_TX      0x08  // ���ͼ��Ĵ���
#define RPD             0x09  // �ز����Ĵ���
#define RX_ADDR_P0      0x0A  // ����ͨ��0���յ�ַ
#define RX_ADDR_P1      0x0B  // ����ͨ��1���յ�ַ
#define RX_ADDR_P2      0x0C  // ����ͨ��2���յ�ַ
#define RX_ADDR_P3      0x0D  // ����ͨ��3���յ�ַ
#define RX_ADDR_P4      0x0E  // ����ͨ��4���յ�ַ
#define RX_ADDR_P5      0x0F  // ����ͨ��5���յ�ַ
#define TX_ADDR         0x10  // ���͵�ַ�Ĵ���
#define RX_PW_P0        0x11  // ��������ͨ��0��Ч���ݿ��(1~32�ֽ�) 
#define RX_PW_P1        0x12  // ��������ͨ��1��Ч���ݿ��(1~32�ֽ�) 
#define RX_PW_P2        0x13  // ��������ͨ��2��Ч���ݿ��(1~32�ֽ�) 
#define RX_PW_P3        0x14  // ��������ͨ��3��Ч���ݿ��(1~32�ֽ�) 
#define RX_PW_P4        0x15  // ��������ͨ��4��Ч���ݿ��(1~32�ֽ�)
#define RX_PW_P5        0x16  // ��������ͨ��5��Ч���ݿ��(1~32�ֽ�)
#define FIFO_STATUS     0x17  // FIFO״̬�Ĵ���
/*����������������������������������������������������������������������������������������������������������������������������������������*/
//////////////////////////////////////////////
//  * Ӳ������ ----------------------------
//  *         | PB6 -CE        : 24L01-CE  |
//  *         | PB7 -IRQ 	   : 24L01-IRQ |
//  *         | PA15-CS  	   : 24L01-CS  |
//  *         | PB3 -SPI2-SCK  : 24L01-CLK |
//  *         | PB4 -SPI2-MISO : 24L01-DO  |
//  *         | PB5 -SPI2-MOSI : 24L01-DIO |
//  *          ----------------------------
//  * ��汾  ��ST3.0.0
//  *

/* Ӳ������ ----------------------------
	    
	SCK   -   PB3
	MISO  -   PB4  
	MOSI  -   PB5  
 
	CE  -  PB6
	IRQ -  PB7
	CS  -  PA15

*/ 

////////////////////////////////////////////
#define RF_CE_PIN        GPIO_Pin_6
#define RF_CE_PORT       GPIOB
#define RF_CE_PIN_SCK    RCC_AHBPeriph_GPIOB

#define RF_IQR_PIN        GPIO_Pin_7
#define RF_IQR_PORT       GPIOB
#define RF_IQR_PIN_SCK    RCC_AHBPeriph_GPIOB

#define RF_CS_PIN        GPIO_Pin_15
#define RF_CS_PORT       GPIOA
#define RF_CS_PIN_SCK    RCC_AHBPeriph_GPIOA

#define RF_SCK_PIN        GPIO_Pin_3
#define RF_SCK_PORT       GPIOB
#define RF_SCK_PIN_SCK    RCC_AHBPeriph_GPIOB
#define RF_SCK_SOURCE     GPIO_PinSource3
#define RF_SCK_AF         GPIO_AF_0

#define RF_MISO_PIN       GPIO_Pin_4
#define RF_MISO_PORT      GPIOB
#define RF_MISO_PIN_SCK   RCC_AHBPeriph_GPIOB
#define RF_MISO_SOURCE    GPIO_PinSource4
#define RF_MISO_AF        GPIO_AF_0

#define RF_MOSI_PIN       GPIO_Pin_5
#define RF_MOSI_PORT      GPIOB
#define RF_MOSI_PIN_SCK   RCC_AHBPeriph_GPIOB
#define RF_MOSI_SOURCE    GPIO_PinSource5
#define RF_MOSI_AF        GPIO_AF_0

#define RF_SPI1               RCC_APB2Periph_SPI1
#define RF_SPI2               RCC_APB1Periph_SPI2
#define SPI_RF_CS_LOW()       GPIO_ResetBits(GPIOA, GPIO_Pin_15)
#define SPI_RF_CS_HIGH()      GPIO_SetBits(GPIOA, GPIO_Pin_15)
#define SPI_RF_CE_LOW()       GPIO_ResetBits(GPIOB, GPIO_Pin_6)
#define SPI_RF_CE_HIGH()      GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define SPI_RF_IRQ()		  GPIO_ReadInputDataBit ( GPIOB, GPIO_Pin_7) //�ж�����

/******   STATUS�Ĵ���bitλ����      *******/
#define MAX_TX  	0x10  //�ﵽ����ʹ����ж�
#define TX_OK   	0x20  //TX��������ж�
#define RX_OK   	0x40  //���յ������ж�
/*����������������������������������������������������������������������������������������������������*/

/*********     24L01���ͽ������ݿ�ȶ���	  ***********/
#define TX_ADR_WIDTH    5   //5�ֽڵ�ַ���
#define RX_ADR_WIDTH    5   //5�ֽڵ�ַ���
#define TX_PLOAD_WIDTH  32  //32�ֽ���Ч���ݿ��
#define RX_PLOAD_WIDTH  32  //32�ֽ���Ч���ݿ��
/*��������������������������������������������������������������������������������������������������������������*/

extern void SPI_RF_Init(void);
extern uint8_t NRF24L01_Write_Reg(uint8_t reg,uint8_t value);
extern uint8_t NRF24L01_Read_Reg(uint8_t reg);
extern uint8_t NRF24L01_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len);
extern uint8_t NRF24L01_Read_Buf(uint8_t reg,uint8_t *pBuf,uint8_t len);
extern uint8_t NRF24L01_Check(void);

extern void NRF24L01_RT_Init(void);
extern void NRF24L01_RX(void);
extern void NRF24L01_TX(void);

extern void  NRF24L01_RX_Mode(void);
extern void  NRF24L01_TX_Mode(void);
extern uint8_t NRF24L01_RxPacket(uint8_t *rxbuf);
extern uint8_t NRF24L01_TxPacket(uint8_t *txbuf);
extern uint8_t SPI_RF_SendByte(uint8_t byte);
#endif

