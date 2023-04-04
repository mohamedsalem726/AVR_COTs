/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : GIE_prog.c
*  details : Source file for GIE Driver.
*****************************************************************/

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_priv.h"
#include "GIE_int.h"
#include "Mcu_HW.h"

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
  Global Functions  body
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
void MGIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

/******************************************
  syntax : void GIE_voidDisable(void)

  Description: Disable the GIE

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : Non
  Return Value     : void
******************************************/
void MGIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
