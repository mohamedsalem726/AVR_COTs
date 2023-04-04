/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : RELAY_prog.c
 *  details : Source file for Relay Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/

#include "STD_TYPES.h"

#include "Dio_int.h"

#include "RELAY_priv.h"
#include "RELAY_types.h"
#include "RELAY_cfg.h"
#include "RELAY_int.h"

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
void HRELAY_voidTurnOn(const RELAY_type Copy_enRelay)
{
	switch(Copy_enRelay)
	{
	case RELAY1:
		MDIO_voidSetPinValue(RELAY1_PIN, DIO_HIGH);
		break;
	case RELAY2:
		MDIO_voidSetPinValue(RELAY2_PIN, DIO_HIGH);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void HRELAY_voidTurnOff(const RELAY_type Copy_enRelay)
{
	switch(Copy_enRelay)
	{
	case RELAY1:
		MDIO_voidSetPinValue(RELAY1_PIN, DIO_LOW);
		break;
	case RELAY2:
		MDIO_voidSetPinValue(RELAY2_PIN, DIO_LOW);
		break;
	default:
		/* Do nothing */
		break;
	}
}
