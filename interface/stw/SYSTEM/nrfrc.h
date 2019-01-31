#ifndef _NRFC_H
#define _NRFC_H

#include "stm32f4xx_conf.h"

#define NRFKeyNO	0x00
#define NRFKey1		0x01
#define NRFKey2		0x02
#define NRFKey3		0x04
#define NRFKey4		0x08
#define NRFKey5		0x10

#define NRFRockerN	0
#define NRFRockerQ	2
#define NRFRockerH	1
#define NRFRockerZ	3
#define NRFRockerY	4

extern uint8_t NRFCUx[3][3];
uint8_t NRFKeyState(uint8_t pin);
uint8_t NRFRockerState(uint8_t pin);
uint8_t NRFRockerValue(uint8_t pin);
#endif
