/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : KPD_types.h
*  details : Header file for types KPD Driver.
*****************************************************************/

#ifndef KPD_TYPES_H_
#define KPD_TYPES_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef enum{
	KPD_PA0 = 10,
	KPD_PA1 ,
	KPD_PA2 ,
	KPD_PA3 ,
	KPD_PA4 ,
	KPD_PA5 ,
	KPD_PA6 ,
	KPD_PA7 ,
	KPD_PB0 = 20,
	KPD_PB1 ,
	KPD_PB2 ,
	KPD_PB3 ,
	KPD_PB4 ,
	KPD_PB5 ,
	KPD_PB6 ,
	KPD_PB7 ,
	KPD_PC0 = 30,
	KPD_PC1 ,
	KPD_PC2 ,
	KPD_PC3 ,
	KPD_PC4 ,
	KPD_PC5 ,
	KPD_PC6 ,
	KPD_PC7 ,
	KPD_PD0 = 40,
	KPD_PD1 ,
	KPD_PD2 ,
	KPD_PD3 ,
	KPD_PD4 ,
	KPD_PD5 ,
	KPD_PD6 ,
	KPD_PD7
}Kpd_ChannelType;// channel means pin


#endif /* KPD_TYPES_H_ */
