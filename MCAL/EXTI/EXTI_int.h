/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : EXTI_int.h
*  details : Header file for interface EXTI Driver.
*****************************************************************/

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "EXTI_types.h"
#include "EXTI_cfg.h"

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
  syntax : Error_State MEXTI_enEnableInt(const EXTI_ConfigType * ConfigPtr)

  Description: Enable the EXTI pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : const EXTI_ConfigType * ConfigPtr
  parameters (out) : Non
  Return Value     : Error_State
******************************************/
Error_State MEXTI_enEnableInt(const EXTI_ConfigType * ConfigPtr);

/******************************************
  syntax : Error_State MEXTI_enDisableInt(const EXTI_ConfigType *ConfigPtr)

  Description: Disable the EXTI pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : const EXTI_ConfigType * ConfigPtr
  parameters (out) : Non
  Return Value     : Error_State
******************************************/
Error_State MEXTI_enDisableInt(const EXTI_ConfigType *ConfigPtr);

/******************************************
  syntax : Error_State MEXTI_enSetCallBack(u8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void))

  Description: Set the EXTI callback functions

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void)
  parameters (out) : Non
  Return Value     : Error_State
******************************************/
Error_State MEXTI_enSetCallBack(u8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void));

#endif /* EXTI_EXTI_INT_H_ */
