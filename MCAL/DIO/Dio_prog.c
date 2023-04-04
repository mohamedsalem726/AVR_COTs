/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Dio_prog.c
*  details : Source file for  DIO Driver.
*****************************************************************/

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
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
  syntax : Dio_LevelType MDio_enGetPinValue(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
Dio_PinLevelType MDIO_enGetPinValue(Dio_ChannelType ChannelId)
{
	u8 Local_u8pin = ChannelId % 10;
	u8 Local_u8port = ChannelId / 10;

	Dio_PinLevelType Local_levelType;
	switch(Local_u8port)
	{
		case DIO_PORTA : Local_levelType = GET_BIT( PINA_REG,Local_u8pin); break;
		case DIO_PORTB : Local_levelType = GET_BIT( PINB_REG,Local_u8pin);	break;
		case DIO_PORTC : Local_levelType = GET_BIT( PINC_REG,Local_u8pin);	break;
		case DIO_PORTD : Local_levelType = GET_BIT( PIND_REG,Local_u8pin); break;
		default: break;
	}
    return Local_levelType ;
}
/******************************************
  syntax : void MDIO_voidSetPinValue(Dio_ChannelType ChannelId,Dio_LevelType Level);

  Description : write the pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void MDIO_voidSetPinValue(Dio_ChannelType ChannelId,Dio_PinLevelType Level)
{
	u8 Local_u8pin = ChannelId % 10;
	u8 Local_u8port = ChannelId / 10;

	if(Level == DIO_HIGH)
	{
		switch(Local_u8port)
		{
			case DIO_PORTA : SET_BIT( PORTA_REG,Local_u8pin); break;
			case DIO_PORTB : SET_BIT( PORTB_REG,Local_u8pin); break;
			case DIO_PORTC : SET_BIT( PORTC_REG,Local_u8pin); break;
			case DIO_PORTD : SET_BIT( PORTD_REG,Local_u8pin); break;
			default: break;
		}
	}
	else if (Level == DIO_LOW)
	{
		switch(Local_u8port)
		{
			case DIO_PORTA : CLR_BIT( PORTA_REG,Local_u8pin); break;
			case DIO_PORTB : CLR_BIT( PORTB_REG,Local_u8pin); break;
			case DIO_PORTC : CLR_BIT( PORTC_REG,Local_u8pin); break;
			case DIO_PORTD : CLR_BIT( PORTD_REG,Local_u8pin); break;
			default: break;
		}
	}
}

/******************************************
  syntax : Dio_PortLevelType MDio_enGetPortValue(Dio_PortType PortId);

  Description : Read the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType
******************************************/
Dio_PortLevelType MDIO_enGetPortValue(Dio_PortType PortId)
{
	Dio_PortLevelType Local_u8Reading;

	switch( PortId)
	{
		case DIO_PORTA : Local_u8Reading =  PORTA_REG; break;
		case DIO_PORTB : Local_u8Reading =  PORTB_REG; break;
		case DIO_PORTC : Local_u8Reading =  PORTC_REG; break;
		case DIO_PORTD : Local_u8Reading =  PORTD_REG; break;
		default: break;
	}

	return Local_u8Reading;
}

/******************************************
  syntax : void MDio_voidSetPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

  Description : write the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void MDIO_voidSetPortValue(Dio_PortType PortId,Dio_PortLevelType Level)
{
	switch(PortId)
	{
    	case DIO_PORTA : PORTA_REG = Level; break;
		case DIO_PORTB : PORTB_REG = Level; break;
		case DIO_PORTC : PORTC_REG = Level; break;
		case DIO_PORTD : PORTD_REG = Level; break;
		default: break;
	}
}

/******************************************
  syntax : void MDio_voidTogglePin(Dio_ChannelType channelId);

  Description : toggle the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void MDIO_voidTogglePin(Dio_ChannelType channelId)
{
	u8 Local_u8pin = channelId % 10;
	u8 Local_u8port = channelId/ 10;

	switch(Local_u8port)
	{
		case DIO_PORTA : TOG_BIT(PORTA_REG,Local_u8pin); break;
		case DIO_PORTB : TOG_BIT(PORTB_REG,Local_u8pin); break;
		case DIO_PORTC : TOG_BIT(PORTC_REG,Local_u8pin); break;
		case DIO_PORTD : TOG_BIT(PORTD_REG,Local_u8pin); break;
		default: break;
	}
}


