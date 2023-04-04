/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TIMER0_int.h
*  details : Header file for interface TIMER0 Driver.
*****************************************************************/

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "TIMER0_types.h"
#include "TIMER0_cfg.h"

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
  syntax : Error_State TIMER0_enInit(const TIMER0_ConfigType * Copy_xConfig)

  Description : this function is to initialize TIMER/COUNTER0
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : pointer to struct of initialization configurations
  parameters (out) : none
  Return Value     : Error_State
******************************************/
Error_State MTIMER0_enInit(const TIMER0_ConfigType * Copy_xConfig);

/******************************************
  syntax : Error_State MTIMER0_enStart(const TIMER0_PrescalerType Copy_enPrescaler)

  Description : this function is to start TIMER/COUNTER0

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : the prescaler value.
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
Error_State MTIMER0_enStart(const TIMER0_PrescalerType Copy_enPrescaler);


/******************************************
  syntax : void TIMER0_voidStop(void)

  Description : Stop the Timer0

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : none
  Return Value     : void
 ******************************************/
void MTIMER0_enStop(void);

/******************************************
  syntax : Error_State TIMER0_enGetCounts(u8 * Copy_u8CounterValue)

  Description : return the number of counts since timer has started

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 * Copy_u8CounterValue
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
Error_State MTIMER0_enGetCounts(u8 * Copy_u8CounterValue);

/******************************************
  syntax : Error_State MTIMER0_enSetDelayTimeMilliSec(const TIMER0_ConfigType * Copy_xConfig , u16 Copy_u16MilliSec)

  Description : delay milliSec function

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : the pointer to config structure and number of millisec
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
void MTIMER0_enSetDelayTimeMilliSec(TIMER0_ModeType Copy_enMode , u16 Copy_u16MilliSec);

/******************************************
  syntax : Error_State MTIMER0_enEnableInt(const TIMER0_InterruptSource Copy_enInterrupt)

  Description : function to enable the timer0 interrupt.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : the interrupt source
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
Error_State MTIMER0_enEnableInt(const TIMER0_InterruptSource Copy_enInterrupt);

/******************************************
  syntax : Error_State MTIMER0_enDisableInt(const TIMER0_InterruptSource Copy_enInterrupt)

  Description : function to disable the timer0 interrupt.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : the interrupt source
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
Error_State MTIMER0_enDisableInt(const TIMER0_InterruptSource Copy_enInterrupt);

/******************************************
  syntax : Error_State MTIMER0_enSetCallBack(TIMER0_InterruptSource Copy_enInterrupt , *Copy_pvCallBackFunc)(void))

  Description : function to Set the Callback Function.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : pointer to the callback function
  parameters (out) : none
  Return Value     : Error_State
 ******************************************/
Error_State MTIMER0_enSetCallBack(TIMER0_InterruptSource Copy_enInterrupt , void (*Copy_pvCallBackFunc)(void));

void MTIMER0_voidOSInit(TIMER0_PrescalerType Copy_enPrescaler,u8 Copy_u8Comparevalue);

#endif /* TIMER0_INT_H_ */
