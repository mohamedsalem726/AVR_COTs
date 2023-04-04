/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TIMER0_prog.c
 *  details : Source file for TIMER0 Driver.
 *****************************************************************/


/******************************************
  INCLUDES
 *******************************************/
#include <util/delay.h>
#include "STD_TYPES.h"

#include "Dio_int.h"
#include "TIMER1_int.h"
#include "GIE_int.h"

#include "ULTRASONIC_priv.h"
#include "ULTRASONIC_cfg.h"
#include "ULTRASONIC_types.h"
#include "ULTRASONIC_int.h"

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
void HUltrasonic_voidinit(void)
{
	MTIMER1_voidInit(TIMER1_NORMAL_MODE,TIMER1_8_PRESCALER);
}

void HULTRASONIC_voidTrigger(void)
{
	MDIO_voidSetPinValue(ULTRASONIC_TRIGGER_PIN, DIO_HIGH);
	_delay_ms(TRIGGER_PULSE_DURATION);
	MDIO_voidSetPinValue(ULTRASONIC_TRIGGER_PIN, DIO_LOW);
}




