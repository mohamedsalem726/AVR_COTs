/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TIMER1_int.h
*  details : Header file for interface TIMER1 Driver.
*****************************************************************/
#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "TIMER1_types.h"
#include "TIMER1_cfg.h"

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
  syntax : void MTIMER1_voidInit(TIMER1_ModeType Copy_enMode)

  Description : this function is to initialize TIMER/COUNTER0
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : Mode of the timer.
  parameters (out) : none
  Return Value     : Error_State
******************************************/
void MTIMER1_voidInit(TIMER1_ModeType Copy_enMode , TIMER1_PrescalerType Copy_enPrescaler);

void MTIMER1_voidStart(TIMER1_PrescalerType Copy_enPrescaler);

u16 MTIMER1_u16ICUTimeOn(TIMER1_PrescalerType Copy_enPrescaler);

void MTMER1_voidStop(void);

#endif /* TIMER1_INT_H_ */
