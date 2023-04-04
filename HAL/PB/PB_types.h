/***************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : PB_types.h
*  details : Declare the types for Push Button Driver
*****************************************************************/

#ifndef PB_TYPES_H_
#define PB_TYPES_H_

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
typedef enum
{
	PB_ACTIVE_LOW,
	PB_ACTIVE_HIGH
}PB_ActiveType;

typedef enum{
	PB_PA0 = 10,
	PB_PA1 ,
	PB_PA2 ,
	PB_PA3 ,
	PB_PA4 ,
	PB_PA5 ,
	PB_PA6 ,
	PB_PA7 ,
	PB_PB0 = 20,
	PB_PB1 ,
	PB_PB2 ,
	PB_PB3 ,
	PB_PB4 ,
	PB_PB5 ,
	PB_PB6 ,
	PB_PB7 ,
	PB_PC0 = 30,
	PB_PC1 ,
	PB_PC2 ,
	PB_PC3 ,
	PB_PC4 ,
	PB_PC5 ,
	PB_PC6 ,
	PB_PC7 ,
	PB_PD0 = 40,
	PB_PD1 ,
	PB_PD2 ,
	PB_PD3 ,
	PB_PD4 ,
	PB_PD5 ,
	PB_PD6 ,
	PB_PD7
}PB_ChannelType;// channel means pin

typedef enum
{
	PB_PRESSED,
	PB_NOT_PRESSED
}PB_StateType;

#endif /* PB_TYPES_H_ */
