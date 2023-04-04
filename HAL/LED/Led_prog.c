/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : Led_prog.c
 *  details : Source file for LED Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"


#include "Dio_int.h"

#include "Led_priv.h"
#include "Led_cfg.h"
#include "Led_int.h"

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
  syntax : void HLED_voidTurnOn(Led_IDtype LedId)

  Description: Turn on the led.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : LedId
  parameters (out) : Non
  Return Value     : void
 ******************************************/
void HLED_voidTurnOn(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
#if LED_RED_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_RED_PIN, DIO_HIGH);
#elif LED_RED_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_RED_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_GREEN  :
#if LED_GREEN_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_GREEN_PIN, DIO_HIGH);
#elif LED_GREEN_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_GREEN_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_BLUE   :
#if LED_BLUE_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_BLUE_PIN, DIO_HIGH);
#elif LED_BLUE_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_BLUE_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_YELLOW :
#if LED_YELLOW_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_YELLOW_PIN, DIO_HIGH);
#elif LED_YELLOW_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_YELLOW_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	}
}

/******************************************
  syntax : void HLED_voidTurnOff(Led_IDtype LedId)

  Description: Turn off the led.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : LedId
  parameters (out) : Non
  Return Value     : void
 ******************************************/
void HLED_voidTurnOff(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
#if LED_RED_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_RED_PIN, DIO_LOW);
#elif LED_RED_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_RED_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_GREEN  :
#if LED_GREEN_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_GREEN_PIN, DIO_LOW);
#elif LED_GREEN_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_GREEN_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_BLUE   :
#if LED_BLUE_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_BLUE_PIN, DIO_LOW);
#elif LED_BLUE_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_BLUE_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_YELLOW :
#if LED_YELLOW_DIRECTION == LED_ACTIVE_HIGH
		MDIO_voidSetPinValue(LED_YELLOW_PIN, DIO_LOW);
#elif LED_YELLOW_DIRECTION == LED_ACYIVE_LOW
		MDIO_voidSetPinValue(LED_YELLOW_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	}
}

/******************************************
  syntax : void HLED_voidTurnOff(Led_IDtype LedId)

  Description: Toggle the led.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : LedId
  parameters (out) : Non
  Return Value     : void
 ******************************************/
void HLED_voidToggle(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
		MDIO_voidTogglePin(LED_RED_PIN);
		break;
	case LED_GREEN  :
		MDIO_voidTogglePin(LED_GREEN_PIN);
		break;
	case LED_BLUE   :
		MDIO_voidTogglePin(LED_BLUE_PIN);

		break;
	case LED_YELLOW :
		MDIO_voidTogglePin(LED_YELLOW_PIN);

		break;
	}
}
