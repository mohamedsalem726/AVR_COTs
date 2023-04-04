/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Led_int.h
*  details : Header file for interface LED Driver.
*****************************************************************/

#ifndef LED_INT_H_
#define LED_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Led_types.h"
/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
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
void HLED_voidTurnOn(Led_IDtype LedId);

/******************************************
  syntax : void HLED_voidTurnOff(Led_IDtype LedId)

  Description: Turn off the led.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : LedId
  parameters (out) : Non
  Return Value     : void
******************************************/
void HLED_voidTurnOff(Led_IDtype LedId);

/******************************************
  syntax : void HLED_voidTurnOff(Led_IDtype LedId)

  Description: Toggle the led.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : LedId
  parameters (out) : Non
  Return Value     : void
******************************************/
void HLED_voidToggle(Led_IDtype LedId);

#endif /* LED_INT_H_ */
