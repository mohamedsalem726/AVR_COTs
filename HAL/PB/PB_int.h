/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : PB_int.h
*  details : Header file for interface Push Button Driver.
*****************************************************************/

#ifndef PB_INT_H_
#define PB_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "PB_types.h"
#include "PB_cfg.h"

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
  syntax : PB_StateType HPB_enReadPB(u8 Copy_u8Button)

  Description : Get the reading from the button

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Button
  parameters (out) : none
  Return Value     : PB_stateType
******************************************/
PB_StateType HPB_enReadPB(u8 Copy_u8Button);

#endif /* PB_INT_H_ */
