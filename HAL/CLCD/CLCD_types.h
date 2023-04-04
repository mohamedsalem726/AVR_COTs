/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : CLCD_types.h
 *  details : Declare the types for CLCD Driver
 *****************************************************************/
#ifndef CLCD_TYPES_H_
#define CLCD_TYPES_H_

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
	CLCD_PA0 = 10,
	CLCD_PA1 ,
	CLCD_PA2 ,
	CLCD_PA3 ,
	CLCD_PA4 ,
	CLCD_PA5 ,
	CLCD_PA6 ,
	CLCD_PA7 ,
	CLCD_PB0 = 20,
	CLCD_PB1 ,
	CLCD_PB2 ,
	CLCD_PB3 ,
	CLCD_PB4 ,
	CLCD_PB5 ,
	CLCD_PB6 ,
	CLCD_PB7 ,
	CLCD_PC0 = 30,
	CLCD_PC1 ,
	CLCD_PC2 ,
	CLCD_PC3 ,
	CLCD_PC4 ,
	CLCD_PC5 ,
	CLCD_PC6 ,
	CLCD_PC7 ,
	CLCD_PD0 = 40,
	CLCD_PD1 ,
	CLCD_PD2 ,
	CLCD_PD3 ,
	CLCD_PD4 ,
	CLCD_PD5 ,
	CLCD_PD6 ,
	CLCD_PD7
}CLCD_ChannelType;

#endif /* CLCD_TYPES_H_ */
