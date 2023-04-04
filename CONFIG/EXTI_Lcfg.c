/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : EXTI_Lcfg.c
 *  details : Source file for configuration EXTI Driver.
 *****************************************************************/
/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "EXTI_types.h"
#include "EXTI_cfg.h"

/******************************************
  Global Data
 *******************************************/
const EXTI_ConfigType EXTI_ConfigArr[EXTI_PINS_CONFIG_ARR_SIZE]={
		{EXTI0,EXTI_u8LOWLEVEL},
		{EXTI1,EXTI_u8LOWLEVEL},
		{EXTI2,EXTI_u8LOWLEVEL}
};
