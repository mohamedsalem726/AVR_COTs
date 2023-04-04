/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TWI_int.h
*  details : Header file for interface TWI Driver.
*****************************************************************/
#ifndef TWI_INT_H_
#define TWI_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "TWI_types.h"
#include "TWI_cfg.h"

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
Error_State MTWI_enInit(const TWI_ConfigType * TWI_xConfig);

TWI_ErrorState MTWI_enSendStartCondition(void);

TWI_ErrorState MTWI_enSendRepeatedStart(void);

TWI_ErrorState MTWI_enSendSlaveAddressWithWriteCmd(u8 Copy_u8SlaveAddress);

TWI_ErrorState MTWI_enSendSlaveAddressWithReadCmd(u8 Copy_u8SlaveAddress);

TWI_ErrorState MTWI_enSendByte(u8 Copy_u8DataByte);

TWI_ErrorState MTWI_enReceiveByteAck(u8 * Copy_pu8ReceiveDataByte);

TWI_ErrorState MTWI_enReceiveByteNoAck(u8 * Copy_pu8ReceiveDataByte);

void MTWI_voidSendStopCondition(void);


#endif /* TWI_INT_H_ */
