/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : EXTI_types.h
*  details : Header file for types EXTI Driver.
*****************************************************************/

#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_
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
	EXTI0,
	EXTI1,
	EXTI2
}EXTI_Number;

typedef enum
{
	EXTI_u8LOWLEVEL,
	EXTI_u8ANYCHANGE,
	EXTI_u8FALLINGEDGE,
	EXTI_u8RISINGEDGE
}EXTI_EdgeSource;



#endif /* EXTI_TYPES_H_ */
