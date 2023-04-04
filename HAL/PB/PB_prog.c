/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : PB_prog.c
 *  details : Source file for Push Button Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_int.h"

#include "PB_priv.h"
#include "PB_cfg.h"
#include "PB_types.h"
#include "PB_int.h"

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
  syntax : PB_StateType HPB_enReadPB(u8 Copy_u8Button)

  Description : Get the reading from the button

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Button
  parameters (out) : none
  Return Value     : PB_stateType
 ******************************************/
PB_StateType HPB_enReadPB(u8 Copy_u8Button)
{
	u8 Local_u8Value;
	PB_StateType Local_enReturn = PB_NOT_PRESSED;
	switch(Copy_u8Button)
	{
	case PB_BUTTON1:
#if PB_ACTIVE_TYPE == PB_ACTIVE_LOW
		do
		{
			Local_u8Value = MDIO_enGetPinValue(PB_BUTTON1);
			_delay_ms(20);
		}while(MDIO_enGetPinValue(PB_BUTTON1) == 0);

		if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#elif PB_ACTIVE_TYPE == PB_ACTIVE_HIGH
		do
		{
			Local_u8Value = MDIO_enGetPinValue(PB_BUTTON1);
			_delay_ms(20);
		}while(MDIO_enGetPinValue(PB_BUTTON1) == 0);
		if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#endif
		break;
	case PB_BUTTON2:
#if PB_ACTIVE_TYPE == PB_ACTIVE_LOW
		do
		{
			Local_u8Value = MDIO_enGetPinValue(PB_BUTTON2);
			_delay_ms(20);
		}while(MDIO_enGetPinValue(PB_BUTTON2) == 0);

		if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#elif PB_ACTIVE_TYPE == PB_ACTIVE_HIGH
		do
		{
			Local_u8Value = MDio_enGetPinValue(PB_BUTTON2);
			_delay_ms(20);
		}while(MDio_enGetPinValue(PB_BUTTON2) == 0);
		if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#endif
		break;
	case PB_BUTTON3:
#if PB_ACTIVE_TYPE == PB_ACTIVE_LOW
		do
		{

			Local_u8Value = MDIO_enGetPinValue(PB_BUTTON3);
			_delay_ms(20);
		}while(MDIO_enGetPinValue(PB_BUTTON3) == 0);

		if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#elif PB_ACTIVE_TYPE == PB_ACTIVE_HIGH
		do
		{

			Local_u8Value = MDio_enGetPinValue(PB_BUTTON3);
			_delay_ms(20);
		}while(MDio_enGetPortValue(PB_BUTTON3) == 0);
		if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#endif
		break;
	case PB_BUTTON4:
#if PB_ACTIVE_TYPE == PB_ACTIVE_LOW
		do
		{

			Local_u8Value = MDIO_enGetPinValue(PB_BUTTON4);
			_delay_ms(20);
		}while(MDIO_enGetPinValue(PB_BUTTON4) == 0);
		if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#elif PB_ACTIVE_TYPE == PB_ACTIVE_HIGH
		Local_u8Value = MDio_enGetPinValue(PB_BUTTON4);
		if(Local_u8Value == DIO_HIGH)
		{
			Local_enReturn = PB_PRESSED;
		}
		else if(Local_u8Value == DIO_LOW)
		{
			Local_enReturn = PB_NOT_PRESSED;
		}
		else
		{
			/* Error */
		}
#endif
		break;
	}



	return Local_enReturn;
}
