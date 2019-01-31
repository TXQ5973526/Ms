#include "nrfrc.h"
#include "stm32f4xx_conf.h"


//NRFCUx[x][y]
//x(0~2):0~2对应串口1~3
//y(0~2):0~2对应三个数据
uint8_t NRFCUx[3][3] = {0};

uint8_t NRFKeyState(uint8_t pin)
{
	if (pin >= 1 && pin <= 3) {
		uint8_t temp = 0;
		if (PinUARTUseFlag[pin - 1] != 2)
		{
			PinUARTUseFlag[pin - 1] = 2;
			if (pin == 1) {
				uart3_init(115200);
			} else if (pin == 2) {
				uart2_init(115200);
			} else {
				uart6_init(115200);
			}
		}
		temp = NRFCUx[pin - 1][0];
		temp = temp & 0x1F;
		return temp;
	}
	BoardLEDAllOpen();
	return 0;
}

uint8_t NRFRockerState(uint8_t pin)
{
	if (pin >= 1 && pin <= 3) {
		uint8_t temp = 0;
		if (PinUARTUseFlag[pin - 1] != 2)
		{
			PinUARTUseFlag[pin - 1] = 2;
			if (pin == 1) {
				uart3_init(115200);
			} else if (pin == 2) {
				uart2_init(115200);
			} else {
				uart6_init(115200);
			}
		}
		temp = NRFCUx[pin - 1][0];
		temp = temp >> 5;
		return temp;
	}
	BoardLEDAllOpen();
	return 0;
}
uint8_t NRFRockerValue(uint8_t pin)
{
	if (pin >= 1 && pin <= 3) {
		uint8_t temp = 0;
		if (PinUARTUseFlag[pin - 1] != 2)
		{
			PinUARTUseFlag[pin - 1] = 2;
			if (pin == 1) {
				uart3_init(115200);
			} else if (pin == 2) {
				uart2_init(115200);
			} else {
				uart6_init(115200);
			}
		}
		temp = NRFCUx[pin - 1][0];
		temp = temp >> 5;
		if (temp == NRFRockerQ)
		{
			temp = NRFCUx[pin - 1][2];
		} else if (temp == NRFRockerH)
		{
			temp = NRFCUx[pin - 1][1];
		} else if (temp == NRFRockerZ)
		{
			temp = NRFCUx[pin - 1][2];
		} else if (temp == NRFRockerY)
		{
			temp = 0xff - NRFCUx[pin - 1][1];
		} else {
			temp = 0;
		}
		temp = temp/2.53;
		return temp;
	}
	BoardLEDAllOpen();
	return 0;
}



// uint8_t NRF1Key;
// uint8_t NRFCU1[3];
// uint8_t NRFCU1_Flag = 0;
// uint8_t NRFCU1_Count= 0;
// uint8_t NRFCU1_MotorFlag = 0;//摇杆控制马达标志

// uint8_t NRF2Key;
// uint8_t NRFCU2[3];
// uint8_t NRFCU2_Flag = 0;
// uint8_t NRFCU2_Count= 0;
// uint8_t NRFCU2_MotorFlag = 0;//摇杆控制马达标志

// uint8_t NRF3Key;
// uint8_t NRFCU3[3];
// uint8_t NRFCU3_Flag = 0;
// uint8_t NRFCU3_Count= 0;
// uint8_t NRFCU3_MotorFlag = 0;//摇杆控制马达标志

// char QM1D = Forward;
// char QM2D = Forward;
// char QM3D = Forward;
// char QM4D = Forward;

// char HM1D = Backward;
// char HM2D = Backward;
// char HM3D = Backward;
// char HM4D = Backward;

// char ZM1D = Backward;
// char ZM2D = Forward;
// char ZM3D = Backward;
// char ZM4D = Forward;

// char YM1D = Forward;
// char YM2D = Backward;
// char YM3D = Forward;
// char YM4D = Backward;

// void NRFCS1_Init(void)
// {
// 	uart3_init(115200);
// 	NRFCU1_Flag = 1;
// }
// void NRFCS2_Init(void)
// {
// 	uart2_init(115200);
// 	NRFCU2_Flag = 1;
// }
// void NRFCS3_Init(void)
// {
// 	uart6_init(115200);
// 	NRFCU3_Flag = 1;
// }

// //NRFRC Rocker Control Motor
// void NRFRC1Motor(void)
// {
// 	if( TIM14RunFlag == 0 ){
// 		TIM14RunFlag = 1;
// 		TIM14_Int_Init(20-1,8400-1);//2ms一次中断
// 	}
// 	Motor_Init();
// 	NRFCU1_MotorFlag = 1;
// }

// void NRFRC2Motor(void)
// {
// 	if( TIM14RunFlag == 0 ){
// 		TIM14RunFlag = 1;
// 		TIM14_Int_Init(20-1,8400-1);//2ms一次中断
// 	}
// 	Motor_Init();
// 	NRFCU2_MotorFlag = 1;
// }

// void NRFRC3Motor(void)
// {
// 	if( TIM14RunFlag == 0 ){
// 		TIM14RunFlag = 1;
// 		TIM14_Int_Init(20-1,8400-1);//2ms一次中断
// 	}
// 	Motor_Init();
// 	NRFCU3_MotorFlag = 1;
// }


// void NRFRCMotorSet(XY_e XY,char motor,char dir)
// {
// 	if( XY == XY_Q )

// 	{
// 		switch (motor)
// 		{
// 			case Motor1: QM1D = dir;break;
// 			case Motor2: QM2D = dir;break;
// 			case Motor3: QM3D = dir;break;
// 			case Motor4: QM4D = dir;break;
// 		}
// 	}
// 	else if( XY == XY_H )

// 	{
// 		switch (motor)
// 		{
// 			case Motor1: HM1D = dir;break;
// 			case Motor2: HM2D = dir;break;
// 			case Motor3: HM3D = dir;break;
// 			case Motor4: HM4D = dir;break;
// 		}
// 	}
// 	else if( XY == XY_Z )

// 	{
// 		switch (motor)
// 		{
// 			case Motor1: ZM1D = dir;break;
// 			case Motor2: ZM2D = dir;break;
// 			case Motor3: ZM3D = dir;break;
// 			case Motor4: ZM4D = dir;break;
// 		}

// 	}
// 	else if( XY == XY_Y )

// 	{
// 		switch (motor)
// 		{
// 			case Motor1: YM1D = dir;break;
// 			case Motor2: YM2D = dir;break;
// 			case Motor3: YM3D = dir;break;
// 			case Motor4: YM4D = dir;break;
// 		}
// 	}
// }


















