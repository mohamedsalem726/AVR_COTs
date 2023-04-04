/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TIMER0_types.h
 *  details : Declare the types in TIMER0 Driver
 *****************************************************************/

#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

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
/* Timer0 Mode */
typedef enum
{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASE_CORRECT_PWM,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM
}TIMER0_ModeType;

/* Action on OC0|OC1A|OC1B|OC2 pins on over flow or compare match */
typedef enum
{
	OC0_DISCONNECTED,     //OC pin disconnected
	OC0_TOGGLE,           //toggle on compare match or over flow
	OC0_CLEAR,            //clear on compare match or over flow
	OC0_SET               //set on compare match or over flow
}TIMER0_OCState;

/* Timer0 clock prescaler values */
typedef enum
{
	TIMER0_NO_CLOCK,
	TIMER0_NO_PRESCALER,
	TIMER0_8_PRESCALER,
	TIMER0_64_PRESCALER,
	TIMER0_256_PRESCALER,
	TIMER0_1024_PRESCALER,
}TIMER0_PrescalerType;

/* Interrupt sources of timer0 */
typedef enum
{
	TIMER0_OVER_FLOW,
	TIMER0_COMPARE_MATCH,
}TIMER0_InterruptSource;

typedef enum
{
	TIMER0_NON_INVERTING,
	TIMER0_INVERTING
}TIMER0_PWMType;

#endif /* TIMER0_TYPES_H_ */
