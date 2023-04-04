/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Port_int.h
*  details : Header file for interface PORT Driver.
*****************************************************************/

#ifndef PORT_INT_H_
#define PORT_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Port_types.h"
#include "Port_cfg.h"

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
  syntax : void MPort_voidInit(void)

  Description : Initial the Pins

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : none
  Return Value     : void
******************************************/
void MPort_voidInit(const Port_Configtype * ConfigPtr);

#endif /* PORT_INT_H_ */
