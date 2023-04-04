/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : GIE_int.h
*  details : Header file for interface GIE Driver.
*****************************************************************/

#ifndef GIE_INT_H_
#define GIE_INT_H_

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

/******************************************
  syntax : void GIE_voidEnable(void)

  Description: Enable the GIE

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : Non
  Return Value     : void
******************************************/
void MGIE_voidEnable(void);

/******************************************
  syntax : void GIE_voidDisable(void)

  Description: Disable the GIE

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : Non
  Return Value     : void
******************************************/
void MGIE_voidDisable(void);

#endif /* GIE_INT_H_ */
