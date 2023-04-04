/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TIMER1_prog.c
 *  details : Source file for TIMER1 Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"

#include "TIMER1_priv.h"
#include "TIMER1_types.h"
#include "TIMER1_int.h"

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
/******************************************
  syntax : void MTIMER1_voidInit(TIMER1_ModeType Copy_enMode)

  Description : this function is to initialize TIMER/COUNTER0
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : Mode of the timer.
  parameters (out) : none
  Return Value     : Error_State
******************************************/
void MTIMER1_voidInit(TIMER1_ModeType Copy_enMode , TIMER1_PrescalerType Copy_enPrescaler)
{
	switch(Copy_enMode)
	{
	case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);
		break;
	}
	/* Insert the required clock value in the first three bits (CS10, CS11 and CS12)of TCCR1B Register */
	/********************************Setting prescaler*********************************/

	/*checking for correct input for prescaler*/
	if(((Copy_enPrescaler)>=TIMER1_NO_PRESCALER) && ((Copy_enPrescaler)<=TIMER1_1024_PRESCALER))
	{
		TCCR1B &= PRESCALER_MASK;    //clearing clock select bits to receive new values
		TCCR1B |= Copy_enPrescaler; //setting prescaler to run the timer
	}
	/*in case of wrong input of prescaler*/
	else
	{
		/* Do nothing */
	}
}

void MTIMER1_voidStart(TIMER1_PrescalerType Copy_enPrescaler)
{
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= Copy_enPrescaler;
}

u16 MTIMER1_u16ICUTimeOn(TIMER1_PrescalerType Copy_enPrescaler)
{
	u16 Local_u16Time1;
	u16 Local_u16Time2;
	u16 Local_u16TotalTime;
	u16 Local_u16Distance;
	u16 Local_u16PrescalerArr[5] = {1,8,64,256,1024};

	TCNT1 = 0;
	SET_BIT(TIFR,TIFR_ICF1);

	/* Rising edge,  noise canceler*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	SET_BIT(TCCR1B,TCCR1B_ICNC1);

	while((GET_BIT(TIFR,TIFR_ICF1))==0);
	Local_u16Time1 = ICR1;
	SET_BIT(TIFR,TIFR_ICF1);

	/* Falling edge ,noise canceler*/
	CLR_BIT(TCCR1B,TCCR1B_ICES1);
	SET_BIT(TCCR1B,TCCR1B_ICNC1);

	while((GET_BIT(TIFR,TIFR_ICF1))==0);
	Local_u16Time2 = ICR1;
	SET_BIT(TIFR,TIFR_ICF1);

	Local_u16TotalTime = (Local_u16Time2 - Local_u16Time1);

	Local_u16Distance = ((Local_u16TotalTime*34600)/(FCPU_CLOCK*2/(Local_u16PrescalerArr[Copy_enPrescaler-1])));

	return Local_u16Distance;
}

void MTMER1_voidStop(void)
{
	TCNT1  = 0;
	OCR1A  = 0;
	OCR1B  = 0;
	TCCR1A = 0;
	TCCR1B = 0;
}
