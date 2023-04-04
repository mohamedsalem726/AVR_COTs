/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : PWM0_prog.c
 *  details : Source file for PWM0 Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"

#include "PWM0_priv.h"
#include "PWM0_types.h"
#include "PWM0_int.h"

/******************************************
  Local Data
 *******************************************/

/******************************************
  Global Data
 *******************************************/

/******************************************
  Local Functions  body
 *******************************************/


/******************************************
  Global Functions body
 *******************************************/
Error_State MPWM0_u8InitTimer0( u16 Copy_u8Frequency , u8 Copy_u8DutyCycle)
{
	Error_State Local_enErrorState = NO_ERROR;

	/* 1- Setting mode of Timer0 to be Fast PWM */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/* 2- Setting inverted mode of OC0 pin */
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* 3- Setting value of OC0 to adjust Duty Cycle */
	OCR0 = ((u16)Copy_u8DutyCycle *256)/100;

	/* 4- Disable all interrupt */
	TIMSK = 0;

	/* 5- Setting prescaler to run Timer0 */
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= Copy_u8Frequency;

	return Local_enErrorState;
}
