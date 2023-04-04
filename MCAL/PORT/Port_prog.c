/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : Port_prog.c
 *  details : Source file for PORT Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Port_int.h"
#include "Port_cfg.h"
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
  Global Functions body
 *******************************************/

/******************************************
  syntax : void MPort_voidInit(void)

  Description : Initial the Pins

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : Pointer to constant data.
  parameters (out) : none
  Return Value     : void
 ******************************************/
void MPort_voidInit(const Port_Configtype * ConfigPtr)
{
	if(ConfigPtr == NULL)
	{
		// To do Report Error
	}
	else
	{
		u8 Local_u8Counter ;
		u8 Local_u8Pin;
		u8 Local_u8Port;
		for(Local_u8Counter= 0;Local_u8Counter<PORT_PINS_CONFIG_ARR_SIZE;Local_u8Counter++)
		{
			Local_u8Pin =(ConfigPtr[Local_u8Counter].PinNumber)%10 ;
			Local_u8Port =(ConfigPtr[Local_u8Counter].PinNumber)/10 ;
			// step1 : set direction
			if(ConfigPtr[Local_u8Counter].PinDirection == PORT_INPUT || ConfigPtr[Local_u8Counter].PinDirection ==PORT_OUTPUT)
			{
				switch(Local_u8Port)
				{
				case PORTA:DDRA_REG|= (u8)(ConfigPtr[Local_u8Counter].PinDirection<< Local_u8Pin);break;
				case PORTB:DDRB_REG|= (u8)(ConfigPtr[Local_u8Counter].PinDirection<< Local_u8Pin);break;
				case PORTC:DDRC_REG|= (u8)(ConfigPtr[Local_u8Counter].PinDirection<< Local_u8Pin);break;
				case PORTD:DDRD_REG|= (u8)(ConfigPtr[Local_u8Counter].PinDirection<< Local_u8Pin);break;

				}
				// step 2 : config initial pin value
				if(ConfigPtr[Local_u8Counter].InitialValue == PORT_LOW || ConfigPtr[Local_u8Counter].InitialValue == PORT_HIGH)
				{
					switch(Local_u8Port)
					{
					case PORTA:  PORTA_REG |= (u8)(ConfigPtr[Local_u8Counter].InitialValue<< Local_u8Pin);break;
					case PORTB:  PORTB_REG |= (u8)(ConfigPtr[Local_u8Counter].InitialValue<< Local_u8Pin);break;
					case PORTC:  PORTC_REG |= (u8)(ConfigPtr[Local_u8Counter].InitialValue<< Local_u8Pin);break;
					case PORTD:  PORTD_REG |= (u8)(ConfigPtr[Local_u8Counter].InitialValue<< Local_u8Pin);break;

					}
					// step 3 : config Pin Internal Attach
					if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_PULLUP)
					{
						switch(Local_u8Port)
						{
						case PORTA:PORTA_REG |= (u8)(1<< Local_u8Pin);break;
						case PORTB:PORTB_REG |= (u8)(1<< Local_u8Pin);break;
						case PORTC:PORTC_REG |= (u8)(1<< Local_u8Pin);break;
						case PORTD:PORTD_REG |= (u8)(1<< Local_u8Pin);break;
						}
					}
					else
					{
						//report error
					}
				}
				else
				{
					// report Error
				}
			}
			else
			{
				//report error
			}

		}//for
	}//else
}
