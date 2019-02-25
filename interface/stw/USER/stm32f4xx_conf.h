#ifndef __STM32F4xx_CONF_H
#define __STM32F4xx_CONF_H


#include "stm32f4xx_adc.h"
#include "stm32f4xx_crc.h"
#include "stm32f4xx_dbgmcu.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_iwdg.h"
#include "stm32f4xx_pwr.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_rtc.h"
#include "stm32f4xx_sdio.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_wwdg.h"
#include "misc.h"
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_fsmc.h"

#include "WaLi.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "irc.h"
#include "led.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "motor.h"
#include "servo.h"
#include "nrfrc.h"
#include "WS2812B.h"
#include "random.h"
#include "Lattice.h"
#include "timer14.h"
#include "Digital_Tube.h"
//#include "rgbled4.h"
//#include "leddisplay.h"
//#include "oled.h"
//#include "myiic.h"
#include "dht11.h"
#include "nec.h" 

#ifdef  USE_FULL_ASSERT
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */


#endif /* __STM32F4xx_CONF_H */
