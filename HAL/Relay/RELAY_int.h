/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : RELAY_int.h
*  details : Header file for interface Relay Driver.
*****************************************************************/

#ifndef RELAY_INT_H_
#define RELAY_INT_H_

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
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/
void HRELAY_voidTurnOn(const RELAY_type Copy_enRelay);

void HRELAY_voidTurnOff(const RELAY_type Copy_enRelay);
#endif /* RELAY_INT_H_ */
