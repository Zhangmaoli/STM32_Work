#include "led.h" 
#include "delay.h"

//LED IO initialized
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//Enable the GPIOF clock

  //GPIOF9,F10 configuration
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
	
  GPIO_ResetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);
  delay_ms(30);
  GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);
}

