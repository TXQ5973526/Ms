//////////////////////////////////////////////
//  * Ӳ������ ----------------------------
//  *         | PA8-CE          :24L01-CE |
//  *         | PC9-IRQ  :      24L01-IRQ |
//  *         | PC8-CS  :        24L01-CS  |
//  *         | PB13-SPI1-SCK  : 24L01-CLK |
//  *         | PB14-SPI1-MISO : 24L01-DO  |
//  *         | PB15-SPI1-MOSI : 24L01-DIO |
//  *          ----------------------------
//  * ��汾  ��ST3.0.0
//  *
////////////////////////////////////////////

#include  "rf24l01.h"

extern unsigned char NRF_Frequency;
extern unsigned char NRF_Address;

uint8_t TX_ADDRESS[TX_ADR_WIDTH]={0x68,0x86,0x66,0x88,0x28}; //���͵�ַ
uint8_t RX_ADDRESS[RX_ADR_WIDTH]={0x68,0x86,0x66,0x88,0x28}; //���͵�ַ
/*******************************************************************************
* Function Name  : SPI_RF_Init
* Description    : Initializes the peripherals used by the SPI FLASH driver.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/* Ӳ������ ----------------------------
		
	SCK   -   PB3
	MISO  -   PB4  
	MOSI  -   PB5  
 
	CE	-  PB6
	IRQ -  PB7
	CS	-  PA15

*/ 
void SPI_RF_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	
	/*ʹ��GPIOA,GPIOB,���ù���ʱ��*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA| RCC_AHBPeriph_GPIOB|RCC_AHBPeriph_GPIOC, ENABLE);
	/*ʹ��SPI1ʱ��*/ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);//ʹ��SPI1ʱ��

	/*
		������������ - ��ͨIO ʹ������
		CE	-  PB6
		IRQ -  PB7
		CS	-  PA15
	*/
	//CE���� �������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOB, &GPIO_InitStructure);				//��ʼ��PB6

	//CS���� �������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//����
	GPIO_Init(GPIOA, &GPIO_InitStructure);				//��ʼ��PA15

	//IRQ���� ��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	//����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);			//��ʼ��PG8
	
	/////////////////////////////////////////////////////////////////////////////
	
	/*
		������������ - SPI����
		SCK   -   PB3
		MISO  -   PB4  
		MOSI  -   PB5 
	*/
	/* �����Զ���ĺ꣬��������csn���ţ�NRF�������״̬?*/
	/*���� SPI_NRF_SPI�� SCK,MISO,MOSI���ţ�PB3 PB4 PB5 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;//PB3~5���ù������	  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,RF_SCK_AF); 	//PB3����Ϊ SPI1
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource4,RF_MISO_AF); //PB4����Ϊ SPI1
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource5,RF_MOSI_AF); //PB5����Ϊ SPI1

	
	SPI_RF_CS_HIGH() ;
	//˫��ȫ˫��
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	//��ģʽ			
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					  
	//���ݴ�С8λ
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  
	//ʱ�Ӽ��ԣ�����ʱΪ��		 
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;						  
	//��1��������Ч��������Ϊ����ʱ��	  
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;					  
	//NSS�ź����������  
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;						  
 	//8��Ƶ��9MHz	  
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;	
	//��λ��ǰ	 
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				  
 
	SPI_InitStructure.SPI_CRCPolynomial = 7;	
	SPI_Init(SPI1, &SPI_InitStructure); 
	SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
	SPI_Cmd(SPI1, ENABLE); /*!< SD_SPI enable */


}

/*********************************************/
/* �������ܣ���24L01�ļĴ���дֵ��һ���ֽڣ� */
/* ��ڲ�����reg   Ҫд�ļĴ�����ַ          */
/*           value ���Ĵ���д��ֵ            */
/* ���ڲ�����status ״ֵ̬                   */
/*********************************************/
uint8_t NRF24L01_Write_Reg(uint8_t reg,uint8_t value)
{
	uint8_t status;

	SPI_RF_CS_LOW() ;	 //CSN=0;   
 	status = SPI_RF_SendByte(reg);//���ͼĴ�����ַ,����ȡ״ֵ̬
	SPI_RF_SendByte(value);
	SPI_RF_CS_HIGH();   //CSN=1;
	return status;
}

/*************************************************/
/* �������ܣ���24L01�ļĴ���ֵ ��һ���ֽڣ�      */
/* ��ڲ�����reg  Ҫ���ļĴ�����ַ               */
/* ���ڲ�����value �����Ĵ�����ֵ                */
/*************************************************/
uint8_t NRF24L01_Read_Reg(uint8_t reg)
{
 	uint8_t value;

	SPI_RF_CS_LOW() ; //CSN=0;   
 	SPI_RF_SendByte(reg);//���ͼĴ���ֵ(λ��),����ȡ״ֵ̬
	value = SPI_RF_SendByte(NOP);
	SPI_RF_CS_HIGH();  //CSN=1;
	return value;
}

/*********************************************/
/* �������ܣ���24L01�ļĴ���ֵ������ֽڣ�   */
/* ��ڲ�����reg   �Ĵ�����ַ                */
/*           *pBuf �����Ĵ���ֵ�Ĵ������    */
/*           len   �����ֽڳ���              */
/* ���ڲ�����status ״ֵ̬                   */
/*********************************************/
uint8_t NRF24L01_Read_Buf(uint8_t reg,uint8_t *pBuf,uint8_t len)
{
	uint8_t status,u8_ctr;
	SPI_RF_CS_LOW() ;//CSN=0       
  status=SPI_RF_SendByte(reg);//���ͼĴ�����ַ,����ȡ״ֵ̬   	   
 	for(u8_ctr=0;u8_ctr<len;u8_ctr++)
	pBuf[u8_ctr]=SPI_RF_SendByte(0XFF);//��������
	SPI_RF_CS_HIGH(); //CSN=1
  return status;        //���ض�����״ֵ̬
}
/**********************************************/
/* �������ܣ���24L01�ļĴ���дֵ������ֽڣ�  */
/* ��ڲ�����reg  Ҫд�ļĴ�����ַ            */
/*           *pBuf ֵ�Ĵ������               */
/*           len   �����ֽڳ���               */
/**********************************************/
uint8_t NRF24L01_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len)
{
	uint8_t status,u8_ctr;
	SPI_RF_CS_LOW() ;	    
  status = SPI_RF_SendByte(reg);//���ͼĴ���ֵ(λ��),����ȡ״ֵ̬
  for(u8_ctr=0; u8_ctr<len; u8_ctr++)
	SPI_RF_SendByte(*pBuf++); //д������
	SPI_RF_CS_HIGH(); 
  return status;          //���ض�����״ֵ̬
}
/********************************************/
/* �������ܣ����24L01�Ƿ����              */
/* ����ֵ��  0  ����                        */
/*           1  ������                      */
/********************************************/	


uint8_t NRF24L01_Check(void)
{
	uint8_t check_in_buf[5]={0x11,0x22,0x33,0x44,0x55};
	uint8_t check_out_buf[5]={0x00};

	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR, check_in_buf, 5);

	NRF24L01_Read_Buf(READ_REG+TX_ADDR, check_out_buf, 5);

	if((check_out_buf[0] == 0x11)&&\
	   (check_out_buf[1] == 0x22)&&\
	   (check_out_buf[2] == 0x33)&&\
	   (check_out_buf[3] == 0x44)&&\
	   (check_out_buf[4] == 0x55))return 0;
	else return 1;
}
/*********************************************/
/* �������ܣ�����24L01Ϊ       ����/����     */
/*********************************************/

void NRF24L01_RT_Init(void)
{	
	SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//ѡ��ͨ��0����Ч���ݿ��
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//���RX FIFO�Ĵ��� 
	TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//��ַ���һλΪ��������
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//дTX�ڵ��ַ 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//����RX�ڵ��ַ,��ҪΪ��ʹ��ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//ʹ��ͨ��0���Զ�Ӧ��    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//ʹ��ͨ��0�Ľ��յ�ַ  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:10��
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);        						//����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0F);  								//����TX�������,0db����,2Mbps,���������濪��   				

	/******  ���ͽ���ģ������óɽ���ģʽ�����а������£�����ҡ��ҡ��ʱ���л��ɷ���ģʽ   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);  								//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�  									
	//NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0f);	
	
	SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܽ���
}
void NRF24L01_RX(void)
{	
	SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//ѡ��ͨ��0����Ч���ݿ��
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//���RX FIFO�Ĵ��� 
	//TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//��ַ���һλΪ��������
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//дTX�ڵ��ַ 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//����RX�ڵ��ַ,��ҪΪ��ʹ��ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//ʹ��ͨ��0���Զ�Ӧ��    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//ʹ��ͨ��0�Ľ��յ�ַ  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:10��
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);  //����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x07);  								//����TX�������,0db����,2Mbps,���������濪��   				

	/******  ���ͽ���ģ������óɽ���ģʽ�����а������£�����ҡ��ҡ��ʱ���л��ɷ���ģʽ   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0f);  								//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�  										
	
	SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܽ���
}
void NRF24L01_TX(void)
{	
	SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//ѡ��ͨ��0����Ч���ݿ��
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//���RX FIFO�Ĵ��� 
	//TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//��ַ���һλΪ��������
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//дTX�ڵ��ַ 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//����RX�ڵ��ַ,��ҪΪ��ʹ��ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//ʹ��ͨ��0���Զ�Ӧ��    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//ʹ��ͨ��0�Ľ��յ�ַ  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:10��
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);  //����RFͨ��Ϊ2.400GHz  Ƶ��=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x07);  								//����TX�������,0db����,2Mbps,���������濪��   				

	/******  ���ͽ���ģ������óɽ���ģʽ�����а������£�����ҡ��ҡ��ʱ���л��ɷ���ģʽ   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);  								//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�  									
	
	SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܽ���
}


/*********************************************/
/* �������ܣ�����24L01Ϊ����ģʽ             */
/*********************************************/
void NRF24L01_RX_Mode(void)
{

	SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����
	
	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0, (uint8_t*)RX_ADDRESS, RX_ADR_WIDTH);//дRX���յ�ַ
	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);    			//����ͨ��0�Զ�Ӧ��    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01);			//ͨ��0��������  	 
  	NRF24L01_Write_Reg(WRITE_REG+RF_CH,40);	     			//����RF����ͨ��Ƶ�� 		  
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);	//ѡ��ͨ��0����Ч���ݿ��
	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0f);			//����TX�������,0db����,2Mbps,���������濪�� 	     
  	NRF24L01_Write_Reg(WRITE_REG+CONFIG, 0x0f);				//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ
	NRF24L01_Write_Reg(FLUSH_RX,0xff);						//���RX FIFO�Ĵ��� 
	SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܽ���
}

/*********************************************/
/* �������ܣ�����24L01Ϊ����ģʽ             */
/*********************************************/
void NRF24L01_TX_Mode(void)
{
		SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����	    
  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);	//дTX�ڵ��ַ 
  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); //����TX�ڵ��ַ,��ҪΪ��ʹ��ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//ʹ��ͨ��0���Զ�Ӧ��    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//ʹ��ͨ��0�Ľ��յ�ַ  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//�����Զ��ط����ʱ��:500us + 86us;����Զ��ط�����:10��
  	NRF24L01_Write_Reg(WRITE_REG+RF_CH,40);       								//����RFͨ��Ϊ40
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0f);  								//����TX�������,0db����,2Mbps,���������濪��   
  	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);    								//���û�������ģʽ�Ĳ���;PWR_UP,EN_CRC,16BIT_CRC,����ģʽ,���������ж�
	  SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܷ���
}
/*********************************************/
/* �������ܣ�24L01��������                   */
/* ��ڲ�����rxbuf ������������              */
/* ����ֵ�� 0   �ɹ��յ�����                 */
/*          1   û���յ�����                 */
/*********************************************/
uint8_t NRF24L01_RxPacket(uint8_t *rxbuf)
{
	uint8_t state;

	state=NRF24L01_Read_Reg(STATUS);  //��ȡ״̬�Ĵ�����ֵ    	 
	NRF24L01_Write_Reg(WRITE_REG+STATUS,state); //���TX_DS��MAX_RT�жϱ�־
	if(state&RX_OK)//���յ�����
	{
		NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);//��ȡ����
		NRF24L01_Write_Reg(FLUSH_RX,0xff);//���RX FIFO�Ĵ��� 
		return 0; 
	}	   
	return 1;//û�յ��κ�����
}
/**********************************************/
/* �������ܣ�����24L01Ϊ����ģʽ              */
/* ��ڲ�����txbuf  ������������              */
/* ����ֵ�� 0x10    �ﵽ����ط�����������ʧ��*/
/*          0x20    �ɹ��������              */
/*          0xff    ����ʧ��                  */
/**********************************************/
uint8_t NRF24L01_TxPacket(uint8_t *txbuf)
{
	uint8_t state;
   
	SPI_RF_CE_LOW() ;	//CE���ͣ�ʹ��24L01����
  NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);//д���ݵ�TX BUF  32���ֽ�
 	SPI_RF_CE_HIGH();	//CE�øߣ�ʹ�ܷ���
	while (SPI_RF_IRQ()!=0);//�ȴ�������� 
	state=NRF24L01_Read_Reg(STATUS);  //��ȡ״̬�Ĵ�����ֵ	   
	NRF24L01_Write_Reg(WRITE_REG+STATUS,state); //���TX_DS��MAX_RT�жϱ�־
	NRF24L01_Write_Reg(FLUSH_TX,0xff);//���TX FIFO�Ĵ��� 
	if(state&MAX_TX)//�ﵽ����ط�����
	{
		return MAX_TX; 
	}
	if(state&TX_OK)//�������
	{
		return TX_OK;
	}
	return 0xff;//����ʧ��
}					    


/*******************************************************************************
* Function Name  : SPI_FLASH_SendByte
* Description    : Sends a byte through the SPI interface and return the byte
*                  received from the SPI bus.
* Input          : byte : byte to send.
* Output         : None
* Return         : The value of the received byte.
*******************************************************************************/
uint8_t SPI_RF_SendByte(uint8_t byte)
{
  /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_SendData8(SPI1, byte);

  /* Wait to receive a byte */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_ReceiveData8(SPI1);
}
