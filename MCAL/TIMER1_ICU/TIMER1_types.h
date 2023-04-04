/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TIMER1_types.h
 *  details : Declare the types in TIMER1 Driver
 *****************************************************************/

#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

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
	TIMER1_NO_CLOCK,
	TIMER1_NO_PRESCALER,
	TIMER1_8_PRESCALER,
	TIMER1_64_PRESCALER,
	TIMER1_256_PRESCALER,
	TIMER1_1024_PRESCALER
}TIMER1_PrescalerType;

typedef enum
{
	TIMER1_NORMAL_MODE,
	TIMER1_PHASE_CORRECT_PWM,
	TIMER1_CTC_MODE,
	TIMER1_FAST_PWM,
	TIMER1_ICU
}TIMER1_ModeType;

typedef enum
{
	OC1_DISCONNECTED,
	OC1_TOGGLE,
	OC1_CLEAR,
	OC1_SET
}TIMER1_OC1State;

typedef enum
{
	TIMER1_OVER_FLOW,
	TIMER1_COMPARE_MATCH,
	TIMER1_ICU_INT
}TIMER1_InterruptSource;

typedef enum
{
	TIMER1_NON_INVERTING,
	TIMER1_INVERTING
}TIMER1_PWMType;

#endif /* TIMER1_TYPES_H_ */
