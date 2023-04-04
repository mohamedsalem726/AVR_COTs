/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TWI_cfg.h
 *  details : Header file for configuration TWI Driver.
 ******************************************************************/

#ifndef TWI_CFG_H_
#define TWI_CFG_H_

/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/
typedef struct
{
	TWI_NodeType Node;
	TWI_Prescaler Prescaler;
	TWI_ClockFrequency ClockFrequency;
	u8 Address;
}TWI_ConfigType;

#endif /* TWI_CFG_H_ */
