/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : KPD_int.h
*  details : Header file for interface KPD Driver.
*****************************************************************/

#ifndef KPD_INT_H_
#define KPD_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "KPD_types.h"
#include "KPD_cfg.h"
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
  syntax : char_t HKPD_enGetPressedKey(void)

  Description: Get the value of the pressed key.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : Non
  Return Value     : u8
******************************************/
u8 HKPD_u8GetPressedKey(void);

#endif /* KPD_INT_H_ */
