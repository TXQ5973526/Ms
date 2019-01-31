/******************************************************************/
/* ���ƣ�TFT����                                                   */
/* Ӳ�����ӣ�PB0-PB7---DB0-DB7   ��8λ                             */
/*           PC0-PC7---DB8-DB7   ��8λ                             */
/*           PD2---WR  PC12---RD PC11---CS  PC10---RS  PB11---CM     */            
/* ���ߣ����                                                     */
/*                  ����ַ��	qfv5.taobao.com��                   */
/* ��ϵ��ʽ��QQ:157736309                                         */
/******************************************************************/

#include"stm32f0xx.h"
#include"ili9328.h"
#include "ascii.h"

uint16_t  POINT_COLOR=BLACK;
uint16_t  BACK_COLOR=WHITE;
/**************************************************/
/* �������ܣ�������ʱ��ΪLCD��ʼ��ʱ�����        */
/**************************************************/	

static void delay (int cnt) {

  cnt <<= DELAY_2N;
  while (cnt--);
}
/***************************************************/
/* �������ܣ���ILI9325�ļĴ���д����               */
/* ��ڲ�����val��16λ����                         */
/* ˵����    д16λ���ݣ�                          */
/* ע�⣺ʹ��ʱ��Ҫ��ʹ��LCD_WR_REG(reg)ѡ��Ҫ���� */
/*       ��д���ĸ��Ĵ������档                    */
/***************************************************/
void LCD_WR_DATA(uint16_t val)
{  
	
 	Set_Rs;//���Ĵ���ѡ��
	Clr_Cs;	//Ƭѡ�õ�
 // GPIOB->ODR &= 0xff00;
  GPIOC->ODR &= 0xff00;	//��PB,PC���ݶ˿�ȫ���õ�
	
	GPIOC->ODR|=(val>>8);//д��߰�λ
	
	Clr_nWr; //��дʹ��
	Set_nWr; //��ʹ��
	GPIOC->ODR &= 0xff00;	
	GPIOC->ODR|=((val)&(0x00ff));//д���8λ

	
	Clr_nWr; //��дʹ��
	Set_nWr; //��ʹ��
  Set_Cs;	//��Ƭѡ
}

/****************************************************/
/* �������ܣ���ILI9238��д���������Ӧ�Ĵ���         */
/* ��ڲ�����д����                                 */
/* ˵����    �Ĵ�������16λ����8λ���ӷ�ʽ��Ҫд����*/
/****************************************************/
void LCD_WR_REG(uint16_t cmd)
{
	Clr_Rs;
	
	Clr_Cs;

  GPIOC->ODR &= 0xff00;	
	
	GPIOC->ODR|=(cmd>>8);
	
	Clr_nWr; //��дʹ��
	Set_nWr; //��ʹ��
	GPIOC->ODR &= 0xff00;	
	GPIOC->ODR |=((cmd)&(0x00ff));
	Clr_nWr;
	Set_nWr;
	 Set_Cs;	
	}
/******************************************************/
/* �������ܣw��Ĵ�����д����                        */
/* ��ڲ�����reg���Ĵ�����  data������ֵ             */
/* ˵����    �ú�����ǰ���������ĺϳɣ�Ҳ������������ */
/*           ����һ����÷�����������ϡ�             */
/******************************************************/

void LCD_WR_REG_DATA(uint16_t reg, uint16_t data)
{ 
	 
   	LCD_WR_REG(reg);//ȷ��Ҫд��ļĴ���
   	LCD_WR_DATA(data);//ȷ��д��Ĵ���������
 	
	}	
	
	
/****************************************************/
/* �������ܣ���ILI9238�ж�����                      */
/* ��ڲ���������                               */
/* ˵����    �Ĵ�������16λ����8λ���ӷ�ʽ��Ҫд����*/
/****************************************************/
uint16_t LCD_RD_DATA(void)
{ 
	unsigned short val,val1,val2;
	Set_Rs;
	Set_nWr;
	  GPIOC->MODER&=0xffff0000;
	Clr_nRd;
//	GPIOB->MODER&=0xffff0000;		   

	val2 = GPIOC->IDR;
	Set_nRd;
	Clr_nRd;
	
	val1 = GPIOC->IDR;
	val=((val1)&(0x00ff))+((val2<<8)&(0xff00));
	               //�������˺��������Ϊ���

//GPIOB->MODER|=0x00005555; 
	
	Set_nRd;
	GPIOC->MODER|=0x00005555; 
	return val;
}	

/******************************************************/
/* �������ܣw���Ĵ����������                        */
/* ��ڲ�����reg���Ĵ�����                           */
/* ˵����    �ú�����ǰ���������ĺϳɣ�Ҳ������������ */
/*           ����һ����÷�����������ϡ�             */
/******************************************************/
uint16_t  LCD_RD_REG_DATA (uint16_t  reg) 
{
  uint16_t value;
 	Clr_Cs;
	LCD_WR_REG(reg);    
	value = LCD_RD_DATA();      	
	Set_Cs;
	return value;
}

/*******************************************************/
/* �������ܣ���ʼ��LCD                                 */
/*******************************************************/
void LCD_init (void) 
{// uint16_t i;
	//////////////////////////////////////////////////////////////////////�ܽų�ʼ��
  RCC->AHBENR&=0xffe3ffff;
	RCC->AHBENR|=0x001c0000;
		
	GPIOC->MODER&=0xffff0000;		   // ����PC�ڵ�8λ����Ϊ���������LCD16λ�������ݺͿ�������
	GPIOC->MODER|=0x00005555; 
	GPIOC->ODR &= 0xff00;	

	
	 GPIOC->MODER&= 0xfc0fffff;  //PD2---WR  PC12---RD PC11---CS  PC10---RS  
   GPIOC->MODER|=0x01500000;	 
	 GPIOC->BSRR = 0x00001c00;
	 
	 GPIOD->MODER&= 0xffffffcf;
   GPIOD->MODER|=0x00000010;	 
	 GPIOD->BSRR = 0x00000004;
	 
//////////////////////////////////////////////////////////////////	
	
	delay(5);                             /* Delay 50 ms                        */
  
//************* Start Initial Sequence **********//
	LCD_WR_REG_DATA(0x0001, 0x0100); // set SS and SM bit
	LCD_WR_REG_DATA(0x0002, 0x0200); // set 1 line inversion
	LCD_WR_REG_DATA(0x0003, 0x1030); // set GRAM write direction and BGR=1.
	LCD_WR_REG_DATA(0x0004, 0x0000); // Resize register
	LCD_WR_REG_DATA(0x0008, 0x0207); // set the back porch and front porch
	LCD_WR_REG_DATA(0x0009, 0x0000); // set non-display area refresh cycle ISC[3:0]
	LCD_WR_REG_DATA(0x000A, 0x0000); // FMARK function
	LCD_WR_REG_DATA(0x000C, 0x0000); // RGB interface setting
	LCD_WR_REG_DATA(0x000D, 0x0000); // Frame marker Position
	LCD_WR_REG_DATA(0x000F, 0x0000); // RGB interface polarity
	//*************Power On sequence ****************//
	LCD_WR_REG_DATA(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_REG_DATA(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
	LCD_WR_REG_DATA(0x0012, 0x0000); // VREG1OUT voltage
	LCD_WR_REG_DATA(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude
	LCD_WR_REG_DATA(0x0007, 0x0001);
	delay(2); // Dis-charge capacitor power voltage
	LCD_WR_REG_DATA(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_REG_DATA(0x0011, 0x0227); // Set DC1[2:0], DC0[2:0], VC[2:0]
	delay(5); // Delay 50ms
	LCD_WR_REG_DATA(0x0012, 0x000D); // 0012
	delay(5); // Delay 50ms
	LCD_WR_REG_DATA(0x0013, 0x1200); // VDV[4:0] for VCOM amplitude
	LCD_WR_REG_DATA(0x0029, 0x000A); // 04  VCM[5:0] for VCOMH
	LCD_WR_REG_DATA(0x002B, 0x000D); // Set Frame Rate
	delay(5); // Delay 50ms
	LCD_WR_REG_DATA(0x0020, 0x0000); // GRAM horizontal Address
	LCD_WR_REG_DATA(0x0021, 0x0000); // GRAM Vertical Address
	// ----------- Adjust the Gamma Curve ----------//
	LCD_WR_REG_DATA(0x0030, 0x0000);
	LCD_WR_REG_DATA(0x0031, 0x0404);
	LCD_WR_REG_DATA(0x0032, 0x0003);
	LCD_WR_REG_DATA(0x0035, 0x0405);
	LCD_WR_REG_DATA(0x0036, 0x0808);
	LCD_WR_REG_DATA(0x0037, 0x0407);
	LCD_WR_REG_DATA(0x0038, 0x0303);
	LCD_WR_REG_DATA(0x0039, 0x0707);
	LCD_WR_REG_DATA(0x003C, 0x0504);
	LCD_WR_REG_DATA(0x003D, 0x0808);
	//------------------ Set GRAM area ---------------//
	LCD_WR_REG_DATA(0x0050, 0x0000); // Horizontal GRAM Start Address
	LCD_WR_REG_DATA(0x0051, 0x00EF); // Horizontal GRAM End Address
	LCD_WR_REG_DATA(0x0052, 0x0000); // Vertical GRAM Start Address
	LCD_WR_REG_DATA(0x0053, 0x013F); // Vertical GRAM Start Address
	LCD_WR_REG_DATA(0x0060, 0xA700); // Gate Scan Line
	LCD_WR_REG_DATA(0x0061, 0x0001); // NDL,VLE, REV
	
	LCD_WR_REG_DATA(0x006A, 0x0000); // set scrolling line
	//-------------- Partial Display Control ---------//
	LCD_WR_REG_DATA(0x0080, 0x0000);
	LCD_WR_REG_DATA(0x0081, 0x0000);
	LCD_WR_REG_DATA(0x0082, 0x0000);
	LCD_WR_REG_DATA(0x0083, 0x0000);
	LCD_WR_REG_DATA(0x0084, 0x0000);
	LCD_WR_REG_DATA(0x0085, 0x0000);
	//-------------- Panel Control -------------------//
	LCD_WR_REG_DATA(0x0090, 0x0010);
	LCD_WR_REG_DATA(0x0092, 0x0000);
	LCD_WR_REG_DATA(0x0007, 0x0133); // 262K color and display ON

//	for(i=60000;i>0;i--);  
}
/****************************************************************************
* ��    �ƣ�void GLCD_Test(void)
* ��    �ܣ�����Һ����
* ��ڲ�������
* ���ڲ�������
* ˵    ������ʾ����������Һ�����Ƿ���������
* ���÷�����GLCD_Test();
****************************************************************************/
void GLCD_Test(void)
{
  uint16_t i,j;
  LCD_WR_REG_DATA(0x20, 0);
  LCD_WR_REG_DATA(0x21, 0);

  Clr_Cs; 
  LCD_WR_REG(0x22);
  
  for(i=0;i<320;i++)
    for(j=0;j<240;j++)
    {
      if(i>279)LCD_WR_DATA(0x0000);
      else if(i>239)LCD_WR_DATA(0x001f);
      else if(i>199)LCD_WR_DATA(0x07e0);
      else if(i>159)LCD_WR_DATA(0x07ff);
      else if(i>119)LCD_WR_DATA(0xf800);
      else if(i>79)LCD_WR_DATA(0xf81f);
      else if(i>39)LCD_WR_DATA(0xffe0);
      else LCD_WR_DATA(0xffff);
    }
  Set_Cs;
}

/**********************************************/
/* �������ܣ�������ʾ                         */
/* ˵    ����һ�����ڹر���ʾ��Ŀ���         */
/**********************************************/
void LCD_DisplayOn(void)
{
 	LCD_WR_REG_DATA(0x0007, 0x0133); // ������ʾ
}
/**********************************************/
/* �������ܣ��ر���ʾ                         */
/* ˵    ����������ʹTFT����������ʹ��TFT�ϵ� */
/*           ���ݱ��ֲ��䣬һ������TFT��������*/
/*           ������ģ�����ӣ���������ģ���ʱ */
/*           ��ϣ��Ӱ��TFT����ʾ��          */
/**********************************************/
void LCD_DisplayOff(void)
{
	LCD_WR_REG_DATA(0x0007, 0x0); // �ر���ʾ
}

/***************************************************/
/* �������ܣ������Դ�����                          */
/* ˵    �������ý�Ҫ��ʾ���Դ�XY��ʼ�ͽ�������    */
/* ע    �⣺�����Ժ�Ҫ�ָ����(0,0)���յ�(239,319)*/
/***************************************************/
void LCD_XYRAM(uint16_t xstart ,uint16_t ystart ,uint16_t xend ,uint16_t yend)
{
	LCD_WR_REG_DATA(0x0050, xstart); // ���ú�����GRAM��ʼ��ַ
	LCD_WR_REG_DATA(0x0051, xend); // ���ú�����GRAM������ַ
	LCD_WR_REG_DATA(0x0052, ystart); // ����������GRAM��ʼ��ַ
	LCD_WR_REG_DATA(0x0053, yend); // ����������GRAM������ַ
}

/*******************************************************/
/* �������ܣ�����TFT����ʼ����                         */
/*******************************************************/
void LCD_SetC(uint16_t x, uint16_t y)
{
	LCD_WR_REG_DATA(0x0020,x);  //����X����λ��
	LCD_WR_REG_DATA(0x0021,y);  //����Y����λ��
}
/**********************************************/
/* �������ܣ�����TFT                          */
/* ��ڲ�����color ��ɫֵ                     */
/**********************************************/
void LCD_Clear(uint16_t color)
{
    uint32_t temp;
    LCD_WR_REG_DATA(0x0020,0);//����X����λ��
    LCD_WR_REG_DATA(0x0021,0);//����Y����λ��
    LCD_WR_REG(0x0022);				//ָ��RAM�Ĵ�����׼��д���ݵ�RAM
	for(temp=0;temp<76800;temp++)
	{
		LCD_WR_DATA(color);    
	}
}
/******************************************/
/* �������ܣ���һ�����صĵ�               */
/* ��ڲ�����x,y   �������               */
/******************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y)
{
	LCD_WR_REG_DATA(0x0020,x);//����X����λ��
    LCD_WR_REG_DATA(0x0021,y);//����Y����λ��
	LCD_WR_REG(0x0022);       //��ʼд��GRAM
	LCD_WR_DATA(POINT_COLOR); 
}
/******************************************/
/* �������ܣ���һ��Сʮ�ֱ�               */
/* ��ڲ�����x,y   �������               */
/******************************************/
void DrawCross(uint16_t x,uint16_t y)
{
    uint8_t b;    
    for(b=0; b<10; b++)
    {
        LCD_DrawPoint(240-(x),y-b);
        LCD_DrawPoint(240-(x),y+b);
        LCD_DrawPoint(240-(x+b),y);
        LCD_DrawPoint(240-(x-b),y);
    }
       
}	

/******************************************/
/* �������ܣ���TFTĳһ�����ɫ            */
/* ���ڲ�����color  ����ɫֵ              */
/******************************************/
uint16_t LCD_ReadPoint(uint16_t x,uint16_t y)
{
	uint16_t  color;

	LCD_WR_REG_DATA(0x0020,x);//����X����λ��
  LCD_WR_REG_DATA(0x0021,y);//����Y����λ��
	LCD_WR_REG(0x0022);       //��ʼд��GRAM
	
	GPIOB->MODER&=0xffff0000;		   
  GPIOC->MODER&=0xffff0000;        //��TFT������������Ϊ����
	
	color = LCD_RD_DATA();	  //����GRAMֵ��ע�⣺GRAMֵ�����ȡ���Σ�
	color = LCD_RD_DATA();	  //����GRAMֵ�����ILI932x�����ֲᣩ
	
	GPIOB->MODER|=0x00005555; 
	GPIOC->MODER|=0x00005555; 		  //�ָ���������Ϊ���

	return color;
} 

/**********************************************/
/* �������ܣ���ֱ��                           */
/**********************************************/
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		LCD_DrawPoint(uRow,uCol);//���� 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}
/**********************************************/
/* �������ܣ�������                           */
/**********************************************/
void LCD_DrawRectage(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend,uint16_t color)
{
	POINT_COLOR=color;
	LCD_DrawLine(xstart, ystart, xend, ystart);
	LCD_DrawLine(xstart, yend, xend, yend);
	LCD_DrawLine(xstart, ystart, xstart, yend);
	LCD_DrawLine(xend, ystart, xend, yend);
}
/**********************************************/
/* �������ܣ��������                         */
/**********************************************/
void LCD_Fill(uint16_t xstart ,uint16_t ystart ,uint16_t xend ,uint16_t yend ,uint16_t color)
{                    
    uint32_t max;
	LCD_XYRAM(xstart ,ystart ,xend ,yend); // ����GRAM����
	LCD_WR_REG_DATA(0x0020,xstart);//����X����λ��
    LCD_WR_REG_DATA(0x0021,ystart);//����Y����λ��
    LCD_WR_REG(0x0022);				//ָ��RAM�Ĵ�����׼��д���ݵ�RAM
	max=(uint32_t)((xend-xstart+1)*(yend-ystart+1));    
	while(max--)
	{
		LCD_WR_DATA(color);
	}
	LCD_XYRAM(0x0000 ,0x0000 ,0x00EF ,0X013F); // �ָ�GRAM������ʾ
}
/*******************************************/
/* �������ܣ���Բ                          */
/* ��ڲ�����x0,y0  Բ������               */
/*           r      �뾶(��λ������)       */
/*******************************************/
void LCD_DrawCircle(uint8_t x0, uint16_t y0, uint8_t r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //�ж��¸���λ�õı�־
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		//ʹ��Bresenham�㷨��Բ     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
} 
/**********************************************/
/* �������ܣ���m��n�η�                       */
/**********************************************/
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 
/**********************************************/
/* �������ܣ���ʾ����                         */
/* ��ڲ�����x,y :�������	 	              */
/*           len :���ֵ�λ��				  */
/*           num:��ֵ(0~4294967295);	   	  */
/**********************************************/
void LCD_ShowNum(uint8_t x,uint16_t y,uint32_t num,uint8_t len)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;		 // �˱�������ȥ�����λ��0	
				   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+8*t,y,' ');
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+8*t,y,temp+'0'); 
	}
} 
/**********************************************/
/* �������ܣ���ʾ8*16����Ӣ���ַ�             */
/* ��ڲ�����x,y :�������	 	              */
/*           num:��ĸ�����         	   	  */
/* ע    �⣺x,y��ȡֵҪ��240��320��Χ��      */
/**********************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num)
{
    uint8_t temp;
    uint8_t pos,t;
	      
   	LCD_WR_REG_DATA(0x0020,x);//����X����λ��
    LCD_WR_REG_DATA(0x0021,y);//����Y����λ��
 	/*�����Դ�����*/
	LCD_XYRAM(x,y,x+7,y+15); // ����GRAM����
    LCD_WR_REG(0x0022);	  	 //ָ��RAM�Ĵ�����׼��д���ݵ�RAM
 	
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	for(pos=0;pos<16;pos++)
	{
	    temp=ascii_16[num][pos];
	    for(t=0;t<8;t++)
	    {                 
	        if(temp&0x80)LCD_WR_DATA(POINT_COLOR);
	        else LCD_WR_DATA(BACK_COLOR);    
	        temp<<=1; 
	    }
	}
	/* �ָ��Դ���ʾ����240*320 */
	LCD_XYRAM(0x0000 ,0x0000 ,0x00EF ,0X013F); // �ָ�GRAM������ʾ
	return;
}

uint8_t buf[32]; //���ڴ��16*16����������

// /**********************************************/
// /* �������ܣ���W25X16����ȡ������             */
// /* ��ڲ�����code:GBK���һ���ֽ�             */
// /*           dz_data:��ŵ����������         */
// /**********************************************/
// void Get_GBK_DZK(uint8_t *code, uint8_t *dz_data)
// {
// 	uint8_t GBKH,GBKL;   // GBK���λ���λ					  
// 	uint32_t offset; 	   // ����ƫ����

// 	GBKH=*code;
// 	GBKL=*(code+1);	   // GBKL=*(code+1);
// 	if(GBKH>0XFE||GBKH<0X81)return;
// 	GBKH-=0x81;
// 	GBKL-=0x40;
// 	offset=((uint32_t)192*GBKH+GBKL)*32;//�õ��ֿ��е��ֽ�ƫ���� 
// 	W25X16_Read(dz_data,offset+0x100,32); 		  
// 	return;
// }
// /**********************************************/
// /* �������ܣ���ʾ16*16��������                */
// /* ��ڲ�����x,y :�������	 	              */
// /*           *hz������               	   	  */
// /**********************************************/
// void LCD_Show_hz(uint16_t x,uint16_t y,uint8_t *hz)
// {
// 	uint8_t i,j,temp;
// 	uint8_t dz_data[32];

// 	Get_GBK_DZK(hz, dz_data);

// 	LCD_WR_REG_DATA(0x0020,x);//����X����λ��
//     LCD_WR_REG_DATA(0x0021,y);//����Y����λ��
//  	/*�����Դ�����*/
// 	LCD_XYRAM(x,y,x+15,y+15); // ����GRAM����
//     LCD_WR_REG(0x0022);	  	 //ָ��RAM�Ĵ�����׼��д���ݵ�RAM

//  	for(i=0;i<32;i++)
// 	{
// 		temp=dz_data[i];
// 	 	for(j=0;j<8;j++)
// 		{
// 		 	if(temp&0x80)LCD_WR_DATA(POINT_COLOR);
// 	        else LCD_WR_DATA(BACK_COLOR);    
// 	        temp<<=1; 
// 		}
// 	}

// 	/* �ָ��Դ���ʾ����240*320 */
// 	LCD_XYRAM(0x0000 ,0x0000 ,0x00EF ,0X013F); // �ָ�GRAM������ʾ
// 	
// 	return;
// }

/*********************************************/
/* �������ܣ���ʾ�ַ��������ĺ�Ӣ�ģ�        */
/* ��ڲ�����x,y: ����                       */
/*           *p:�ַ���                       */
/*********************************************/
void LCD_ShowString(uint16_t x,uint16_t y,uint8_t *p)
{         
    while(*p!='\0')	// ���û�н���
    {       
        if(*p>0x80)//���������
		{
			if((*p=='\n')||(x>224))  // ���κͻ���
			{
				y=y+19;   //�����16 �м��3
				x=2;      //2�Ǳ߾�
			}
// 			LCD_Show_hz(x, y, p);
			x+=16;
			p+=2;
		}
		else	   //�����Ӣ��
		{
			if((*p=='\n')||(x>224))   // ���κͻ���
			{
				y=y+19;   //�����16 �м��3
				x=2;      //2�Ǳ߾�
			}
			LCD_ShowChar(x,y,*p);
			x+=8;
			p++;
		}
    }  
}

  


