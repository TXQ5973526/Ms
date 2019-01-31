//////////////////////////////////////////////
//  * 硬件连接 ----------------------------
//  *         | PA8-CE          :24L01-CE |
//  *         | PC9-IRQ  :      24L01-IRQ |
//  *         | PC8-CS  :        24L01-CS  |
//  *         | PB13-SPI1-SCK  : 24L01-CLK |
//  *         | PB14-SPI1-MISO : 24L01-DO  |
//  *         | PB15-SPI1-MOSI : 24L01-DIO |
//  *          ----------------------------
//  * 库版本  ：ST3.0.0
//  *
////////////////////////////////////////////

#include  "rf24l01.h"

extern unsigned char NRF_Frequency;
extern unsigned char NRF_Address;

uint8_t TX_ADDRESS[TX_ADR_WIDTH]={0x68,0x86,0x66,0x88,0x28}; //发送地址
uint8_t RX_ADDRESS[RX_ADR_WIDTH]={0x68,0x86,0x66,0x88,0x28}; //发送地址
/*******************************************************************************
* Function Name  : SPI_RF_Init
* Description    : Initializes the peripherals used by the SPI FLASH driver.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
/* 硬件连接 ----------------------------
		
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
	
	/*使能GPIOA,GPIOB,复用功能时钟*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA| RCC_AHBPeriph_GPIOB|RCC_AHBPeriph_GPIOC, ENABLE);
	/*使能SPI1时钟*/ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);//使能SPI1时钟

	/*
		配置下列引脚 - 普通IO 使能作用
		CE	-  PB6
		IRQ -  PB7
		CS	-  PA15
	*/
	//CE引脚 推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);				//初始化PB6

	//CS引脚 推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//普通输出模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;		//上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);				//初始化PA15

	//IRQ引脚 上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	//输入
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;	//上拉
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;	//100MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);			//初始化PG8
	
	/////////////////////////////////////////////////////////////////////////////
	
	/*
		配置下列引脚 - SPI引脚
		SCK   -   PB3
		MISO  -   PB4  
		MOSI  -   PB5 
	*/
	/* 这是自定义的宏，用于拉高csn引脚，NRF进入空闲状态?*/
	/*配置 SPI_NRF_SPI的 SCK,MISO,MOSI引脚，PB3 PB4 PB5 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;//PB3~5复用功能输出	  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,RF_SCK_AF); 	//PB3复用为 SPI1
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource4,RF_MISO_AF); //PB4复用为 SPI1
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource5,RF_MOSI_AF); //PB5复用为 SPI1

	
	SPI_RF_CS_HIGH() ;
	//双线全双工
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	//主模式			
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					  
	//数据大小8位
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  
	//时钟极性，空闲时为低		 
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;						  
	//第1个边沿有效，上升沿为采样时刻	  
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;					  
	//NSS信号由软件产生  
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;						  
 	//8分频，9MHz	  
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;	
	//高位在前	 
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				  
 
	SPI_InitStructure.SPI_CRCPolynomial = 7;	
	SPI_Init(SPI1, &SPI_InitStructure); 
	SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
	SPI_Cmd(SPI1, ENABLE); /*!< SD_SPI enable */


}

/*********************************************/
/* 函数功能：给24L01的寄存器写值（一个字节） */
/* 入口参数：reg   要写的寄存器地址          */
/*           value 给寄存器写的值            */
/* 出口参数：status 状态值                   */
/*********************************************/
uint8_t NRF24L01_Write_Reg(uint8_t reg,uint8_t value)
{
	uint8_t status;

	SPI_RF_CS_LOW() ;	 //CSN=0;   
 	status = SPI_RF_SendByte(reg);//发送寄存器地址,并读取状态值
	SPI_RF_SendByte(value);
	SPI_RF_CS_HIGH();   //CSN=1;
	return status;
}

/*************************************************/
/* 函数功能：读24L01的寄存器值 （一个字节）      */
/* 入口参数：reg  要读的寄存器地址               */
/* 出口参数：value 读出寄存器的值                */
/*************************************************/
uint8_t NRF24L01_Read_Reg(uint8_t reg)
{
 	uint8_t value;

	SPI_RF_CS_LOW() ; //CSN=0;   
 	SPI_RF_SendByte(reg);//发送寄存器值(位置),并读取状态值
	value = SPI_RF_SendByte(NOP);
	SPI_RF_CS_HIGH();  //CSN=1;
	return value;
}

/*********************************************/
/* 函数功能：读24L01的寄存器值（多个字节）   */
/* 入口参数：reg   寄存器地址                */
/*           *pBuf 读出寄存器值的存放数组    */
/*           len   数组字节长度              */
/* 出口参数：status 状态值                   */
/*********************************************/
uint8_t NRF24L01_Read_Buf(uint8_t reg,uint8_t *pBuf,uint8_t len)
{
	uint8_t status,u8_ctr;
	SPI_RF_CS_LOW() ;//CSN=0       
  status=SPI_RF_SendByte(reg);//发送寄存器地址,并读取状态值   	   
 	for(u8_ctr=0;u8_ctr<len;u8_ctr++)
	pBuf[u8_ctr]=SPI_RF_SendByte(0XFF);//读出数据
	SPI_RF_CS_HIGH(); //CSN=1
  return status;        //返回读到的状态值
}
/**********************************************/
/* 函数功能：给24L01的寄存器写值（多个字节）  */
/* 入口参数：reg  要写的寄存器地址            */
/*           *pBuf 值的存放数组               */
/*           len   数组字节长度               */
/**********************************************/
uint8_t NRF24L01_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len)
{
	uint8_t status,u8_ctr;
	SPI_RF_CS_LOW() ;	    
  status = SPI_RF_SendByte(reg);//发送寄存器值(位置),并读取状态值
  for(u8_ctr=0; u8_ctr<len; u8_ctr++)
	SPI_RF_SendByte(*pBuf++); //写入数据
	SPI_RF_CS_HIGH(); 
  return status;          //返回读到的状态值
}
/********************************************/
/* 函数功能：检测24L01是否存在              */
/* 返回值；  0  存在                        */
/*           1  不存在                      */
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
/* 函数功能：设置24L01为       发送/接收     */
/*********************************************/

void NRF24L01_RT_Init(void)
{	
	SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//选择通道0的有效数据宽度
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//清除RX FIFO寄存器 
	TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//地址最后一位为编码数据
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//写TX节点地址 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//设置RX节点地址,主要为了使能ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//使能通道0的接收地址  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//设置RF通道为2.400GHz  频率=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);        						//设置RF通道为2.400GHz  频率=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0F);  								//设置TX发射参数,0db增益,2Mbps,低噪声增益开启   				

	/******  发送接收模块均设置成接受模式，当有按键按下，或者摇杆摇动时，切换成发送模式   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);  								//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,发送模式,开启所有中断  									
	//NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0f);	
	
	SPI_RF_CE_HIGH();	//CE置高，使能接收
}
void NRF24L01_RX(void)
{	
	SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//选择通道0的有效数据宽度
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//清除RX FIFO寄存器 
	//TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//地址最后一位为编码数据
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//写TX节点地址 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//设置RX节点地址,主要为了使能ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//使能通道0的接收地址  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//设置RF通道为2.400GHz  频率=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);  //设置RF通道为2.400GHz  频率=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x07);  								//设置TX发射参数,0db增益,2Mbps,低噪声增益开启   				

	/******  发送接收模块均设置成接受模式，当有按键按下，或者摇杆摇动时，切换成发送模式   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0f);  								//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式,开启所有中断  										
	
	SPI_RF_CE_HIGH();	//CE置高，使能接收
}
void NRF24L01_TX(void)
{	
	SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置	  
	
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);						//选择通道0的有效数据宽度
	NRF24L01_Write_Reg(FLUSH_RX,0xff);											//清除RX FIFO寄存器 
	//TX_ADDRESS[4] = NRF_Frequency;RX_ADDRESS[4] = NRF_Frequency;					//地址最后一位为编码数据
	  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);		//写TX节点地址 
	  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); 	//设置RX节点地址,主要为了使能ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//使能通道0的接收地址  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  		//NRF24L01_Write_Reg(WRITE_REG+RF_CH,0);        						//设置RF通道为2.400GHz  频率=2400 + 0 MHz
  		NRF24L01_Write_Reg(WRITE_REG+RF_CH,NRF_Frequency);  //设置RF通道为2.400GHz  频率=2400 + NRF_Frequency MHz
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x07);  								//设置TX发射参数,0db增益,2Mbps,低噪声增益开启   				

	/******  发送接收模块均设置成接受模式，当有按键按下，或者摇杆摇动时，切换成发送模式   *****/
	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);  								//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,发送模式,开启所有中断  									
	
	SPI_RF_CE_HIGH();	//CE置高，使能接收
}


/*********************************************/
/* 函数功能：设置24L01为接收模式             */
/*********************************************/
void NRF24L01_RX_Mode(void)
{

	SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置
	
	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0, (uint8_t*)RX_ADDRESS, RX_ADR_WIDTH);//写RX接收地址
	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);    			//开启通道0自动应答    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01);			//通道0接收允许  	 
  	NRF24L01_Write_Reg(WRITE_REG+RF_CH,40);	     			//设置RF工作通道频率 		  
  	NRF24L01_Write_Reg(WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);	//选择通道0的有效数据宽度
	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0f);			//设置TX发射参数,0db增益,2Mbps,低噪声增益开启 	     
  	NRF24L01_Write_Reg(WRITE_REG+CONFIG, 0x0f);				//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式
	NRF24L01_Write_Reg(FLUSH_RX,0xff);						//清除RX FIFO寄存器 
	SPI_RF_CE_HIGH();	//CE置高，使能接收
}

/*********************************************/
/* 函数功能：设置24L01为发送模式             */
/*********************************************/
void NRF24L01_TX_Mode(void)
{
		SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置	    
  	NRF24L01_Write_Buf(WRITE_REG+TX_ADDR,(uint8_t*)TX_ADDRESS,TX_ADR_WIDTH);	//写TX节点地址 
  	NRF24L01_Write_Buf(WRITE_REG+RX_ADDR_P0,(uint8_t*)RX_ADDRESS,RX_ADR_WIDTH); //设置TX节点地址,主要为了使能ACK	  
  	NRF24L01_Write_Reg(WRITE_REG+EN_AA,0x01);     								//使能通道0的自动应答    
  	NRF24L01_Write_Reg(WRITE_REG+EN_RXADDR,0x01); 								//使能通道0的接收地址  
  	NRF24L01_Write_Reg(WRITE_REG+SETUP_RETR,0x1a);								//设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  	NRF24L01_Write_Reg(WRITE_REG+RF_CH,40);       								//设置RF通道为40
  	NRF24L01_Write_Reg(WRITE_REG+RF_SETUP,0x0f);  								//设置TX发射参数,0db增益,2Mbps,低噪声增益开启   
  	NRF24L01_Write_Reg(WRITE_REG+CONFIG,0x0e);    								//配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式,开启所有中断
	  SPI_RF_CE_HIGH();	//CE置高，使能发送
}
/*********************************************/
/* 函数功能：24L01接收数据                   */
/* 入口参数：rxbuf 接收数据数组              */
/* 返回值： 0   成功收到数据                 */
/*          1   没有收到数据                 */
/*********************************************/
uint8_t NRF24L01_RxPacket(uint8_t *rxbuf)
{
	uint8_t state;

	state=NRF24L01_Read_Reg(STATUS);  //读取状态寄存器的值    	 
	NRF24L01_Write_Reg(WRITE_REG+STATUS,state); //清除TX_DS或MAX_RT中断标志
	if(state&RX_OK)//接收到数据
	{
		NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);//读取数据
		NRF24L01_Write_Reg(FLUSH_RX,0xff);//清除RX FIFO寄存器 
		return 0; 
	}	   
	return 1;//没收到任何数据
}
/**********************************************/
/* 函数功能：设置24L01为发送模式              */
/* 入口参数：txbuf  发送数据数组              */
/* 返回值； 0x10    达到最大重发次数，发送失败*/
/*          0x20    成功发送完成              */
/*          0xff    发送失败                  */
/**********************************************/
uint8_t NRF24L01_TxPacket(uint8_t *txbuf)
{
	uint8_t state;
   
	SPI_RF_CE_LOW() ;	//CE拉低，使能24L01配置
  NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);//写数据到TX BUF  32个字节
 	SPI_RF_CE_HIGH();	//CE置高，使能发送
	while (SPI_RF_IRQ()!=0);//等待发送完成 
	state=NRF24L01_Read_Reg(STATUS);  //读取状态寄存器的值	   
	NRF24L01_Write_Reg(WRITE_REG+STATUS,state); //清除TX_DS或MAX_RT中断标志
	NRF24L01_Write_Reg(FLUSH_TX,0xff);//清除TX FIFO寄存器 
	if(state&MAX_TX)//达到最大重发次数
	{
		return MAX_TX; 
	}
	if(state&TX_OK)//发送完成
	{
		return TX_OK;
	}
	return 0xff;//发送失败
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
