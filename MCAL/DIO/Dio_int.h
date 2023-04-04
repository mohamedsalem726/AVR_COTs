/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Dio_int.h
*  details : Header file for interface DIO Driver.
*****************************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_


/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Dio_types.h"
#include "Dio_cfg.h"
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
  syntax : Dio_LevelType Dio_ReadChannel(Dio_ChanpeSynchronous

  Description: read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : channelId (pin)
  parameters (out) : Non
  Return Value     : Dio_HIGH or DIO_LOW
*****************************************/
Dio_PinLevelType MDIO_enGetPinValue(Dio_ChannelType ChannelId);

/******************************************
  syntax : void MDIO_voidSetPinValue(Dio_ChannelType ChannelId,Dio_LevelType Level);

  Description: write the pin

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : channelId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) : Non
  Return Value     : void
******************************************/
void MDIO_voidSetPinValue(Dio_ChannelType ChannelId,Dio_PinLevelType Level);

/******************************************
  syntax : Dio_PortLevelType MDio_enGetPortValue(Dio_PortType PortId);

  Description: Read the whole port

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType
******************************************/
Dio_PortLevelType MDio_enGetPortValue(Dio_PortType PortId);

/******************************************
  syntax : void MDio_voidSetPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

  Description : write the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void MDIO_voidSetPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

/******************************************
  syntax : void MDio_voidTogglePin(Dio_ChannelType channelId);

  Description : toggle the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void MDIO_voidTogglePin(Dio_ChannelType channelId);

#endif /* DIO_DIO_INT_H_ */
