/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TWI_types.h
 *  details : Declare the types in TWI Driver
 *****************************************************************/
#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_

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
	TWI_NO_ERROR ,
	START_CONDITION_ERROR ,
	REPEATED_START_CONDITION_ERROR,
	ADDRESS_WITH_WRITE_ERROR,
	ADDRESS_WITH_READ_ERROR,
	MSTR_WRITE_DATA_ERROR,
	MSTR_READ_DATA_ERROR,
}TWI_ErrorState;

typedef enum
{
	TWI_MASTER,
	TWI_SLAVE
}TWI_NodeType;

typedef enum
{
	NO_PRESCALER,
	PRESCALER_4,
	PRESCALER_16,
	PRESCALER_64
}TWI_Prescaler;

typedef enum
{
	CLOCK_100K = 100000UL,
	CLOCK_200K = 200000UL,
	CLOCK_300K = 300000UL,
	CLOCK_400K = 400000UL
}TWI_ClockFrequency;



#endif /* TWI_TYPES_H_ */
