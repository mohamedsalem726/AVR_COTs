/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : EXTI_cfg.h
*  details : Header file for configuration EXTI Driver.
*****************************************************************/

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define EXTI_PINS_CONFIG_ARR_SIZE     3

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef struct
{
	EXTI_Number  Int_Number;
	EXTI_EdgeSource Int_Source;
}EXTI_ConfigType;

#endif /* EXTI_CFG_H_ */
