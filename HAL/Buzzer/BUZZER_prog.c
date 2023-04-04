/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : BUZZER_prog.c
 *  details : Source file for Buzzer Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"

#include "Dio_int.h"

#include "BUZZER_priv.h"
#include "BUZZER_types.h"
#include "BUZZER_cfg.h"
#include "BUZZER_int.h"


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
void HBUZZER_voidTurnOn(void)
{
	MDIO_voidSetPinValue(BUZZER_PIN, DIO_HIGH);
}

void HBUZZER_voidTurnOff(void)
{
	MDIO_voidSetPinValue(BUZZER_PIN, DIO_LOW);
}
