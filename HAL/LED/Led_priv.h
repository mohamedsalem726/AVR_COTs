/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : LED_priv.h
*  details : Header file for private LED Driver.
*****************************************************************/

#ifndef LED_PRIV_H_
#define LED_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
typedef enum{
	LED_PA0 = 10,
	LED_PA1 ,
	LED_PA2 ,
	LED_PA3 ,
	LED_PA4 ,
	LED_PA5 ,
	LED_PA6 ,
	LED_PA7 ,
	LED_PB0 = 20,
	LED_PB1 ,
	LED_PB2 ,
	LED_PB3 ,
	LED_PB4 ,
	LED_PB5 ,
	LED_PB6 ,
	LED_PB7 ,
	LED_PC0 = 30,
	LED_PC1 ,
	LED_PC2 ,
	LED_PC3 ,
	LED_PC4 ,
	LED_PC5 ,
	LED_PC6 ,
	LED_PC7 ,
	LED_PD0 = 40,
	LED_PD1 ,
	LED_PD2 ,
	LED_PD3 ,
	LED_PD4 ,
	LED_PD5 ,
	LED_PD6 ,
	LED_PD7
}Led_ChannelType;// channel means pin

typedef enum
{
	LED_ACTIVE_LOW,
	LED_ACTIVE_HIGH
}Led_ActiveType;

/******************************************
  Local Functions Prototypes
*******************************************/

#endif /* LED_PRIV_H_ */
