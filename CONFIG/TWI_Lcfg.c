/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TWI_Lcfg.c
 *  details : Source file for link time configurations TWI Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "TWI_types.h"
#include "TWI_cfg.h"


/******************************************
  Global Data
 *******************************************/
const TWI_ConfigType TWI_xConfig={TWI_MASTER,NO_PRESCALER,CLOCK_100K,0};
