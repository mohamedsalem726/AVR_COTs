/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : CLCD_prog.c
 *  details : Source file for CLCD Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include <stdlib.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_int.h"

#include "CLCD_priv.h"
#include "CLCD_cfg.h"
#include "CLCD_types.h"
#include "CLCD_int.h"

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
  syntax : static void HCLCD_voidlatchByte(u8 copy_u8Byte)

  Description : Select the mode of the LCD and Send the byte to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Byte
  parameters (out) : none
  Return Value     : void
 ******************************************/
static void HCLCD_voidlatchByte(u8 copy_u8Byte)
{
#if CLCD_MODE == _8_BIT_MODE
	MDio_voidSetPortValue(CLCD_PORT, copy_u8Byte);

	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);

#elif CLCD_MODE == _4_BIT_MODE


	MDIO_voidSetPinValue(CLCD_D4_PIN, GET_BIT(copy_u8Byte,4));
	MDIO_voidSetPinValue(CLCD_D5_PIN, GET_BIT(copy_u8Byte,5));
	MDIO_voidSetPinValue(CLCD_D6_PIN, GET_BIT(copy_u8Byte,6));
	MDIO_voidSetPinValue(CLCD_D7_PIN, GET_BIT(copy_u8Byte,7));

	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);

	MDIO_voidSetPinValue(CLCD_D4_PIN, GET_BIT(copy_u8Byte,0));
	MDIO_voidSetPinValue(CLCD_D5_PIN, GET_BIT(copy_u8Byte,1));
	MDIO_voidSetPinValue(CLCD_D6_PIN, GET_BIT(copy_u8Byte,2));
	MDIO_voidSetPinValue(CLCD_D7_PIN, GET_BIT(copy_u8Byte,3));

	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);

	_delay_ms(5);

#else
#error "Wrong mode configuration"
#endif
}


/******************************************
  syntax : PB_StateType HPB_enReadPB(u8 Copy_u8Button)

  Description : Get the reading from the button

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Button
  parameters (out) : none
  Return Value     : PB_stateType
 ******************************************/
void HCLCD_voidInit(void)
{
#if CLCD_MODE == _8_BIT_MODE

	_delay_ms(100);

	HCLCD_voidSendCommand(0x38);
	HCLCD_voidSendCommand(0x0E);
	HCLCD_voidSendCommand(0x01);

	_delay_ms(20);

#elif CLCD_MODE == _4_BIT_MODE


	/* Wait for more than 30ms */
	_delay_ms(100);

	/* Initialize LCD in 4-bit mode */
	HCLCD_voidSendCommand(0x33);

	/* Enable 5x7 mode for chars */
	HCLCD_voidSendCommand(FUNCTION_SET);

	/* Display OFF, Cursor ON */
	HCLCD_voidSendCommand(DISPLAY_SETUP);
	/* Display Clear */
	HCLCD_voidSendCommand(DISPLAY_ON);

	HCLCD_voidSendCommand(DISPLAY_ClEAR);

	HCLCD_voidSendCommand(CURSOR_RIGHT);

	HCLCD_voidSendCommand(0x02);

	_delay_ms(20);
#else
#error "Wrong Mode Configuration"
#endif
}

/******************************************
  syntax : void HCLCD_voidSendData(u8 Copy_u8Data)

  Description : Send the data to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Data
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to high for data */
	MDIO_voidSetPinValue(CLCD_RS_PIN, DIO_HIGH);

	/* Set Data to data pins */
	HCLCD_voidlatchByte(Copy_u8Data);
}

/******************************************
  syntax : void HCLCD_voidSendCommand(u8 Copy_u8Command)

  Description : Send the command to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Command
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS and EN pin to low for Command */
	MDIO_voidSetPinValue(CLCD_RS_PIN, DIO_LOW);


	/* Set command to data pins */
	HCLCD_voidlatchByte(Copy_u8Command);

}

/******************************************
  syntax : void HCLCD_voidSendString(const s8 * Copy_ps8Str)

  Description : Send the string to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :  const s8 * Copy_ps8Str
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidSendString(const char_t * Copy_ps8Str)
{
	u8 Local_u8Counter = 0;

	while(Copy_ps8Str[Local_u8Counter] != '\0')
	{
		HCLCD_voidSendData(Copy_ps8Str[Local_u8Counter]);
		Local_u8Counter++;
	}
}

/******************************************
  syntax : void HCLCD_voidGotoXY(u8 copy_u8Row,u8 copy_u8Colum)

  Description : Go to specific postion

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Row , u8 Copy_u8Colum
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidGotoXY(u8 Copy_u8Row,u8 Copy_u8Colum)
{
	u8 Local_u8Address;

	if(Copy_u8Row == 0)
	{
		/* Location is at first line */
		Local_u8Address=Copy_u8Colum;
	}
	else if(Copy_u8Row == 1)
	{
		/* Location is at second line */
		Local_u8Address=0xC0+Copy_u8Colum;
	}
	else if(Copy_u8Row == 2)
	{
		/* Location is at Third line */
		Local_u8Address=0x94+Copy_u8Colum;
	}
	else if(Copy_u8Row == 3)
	{
		/* Location is at fourth line */
		Local_u8Address=0xD4+Copy_u8Colum;
	}

	/* Set bit number 7 for set DDRAM address command then send the command */
	Local_u8Address = SET_BIT(Local_u8Address,7);

	HCLCD_voidSendCommand(Local_u8Address);
}

/******************************************
  syntax : void HCLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)

  Description : Generate new character

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 * ArrPattern , u8 copy_u8charCode
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	u8 Local_u8CGRAMAddress=0;
	u8 Local_u8Iterator;
	/* Calculate the CGRAM address whose each block is 8 bytes */
	Local_u8CGRAMAddress=(copy_u8charCode*BLOCK_SIAZE);

	/* Send CGRAM address command to LCD with setting bit 6 , clearing bit 7 */
	Local_u8CGRAMAddress = SET_BIT(Local_u8CGRAMAddress,6);

	HCLCD_voidSendCommand(Local_u8CGRAMAddress);

	/* Write the pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		HCLCD_voidSendData(ArrPattern[Local_u8Iterator]);
	}
}


/******************************************
  syntax : void HCLCD_voidDisplayCustomChar(u8 Copy_u8charCode)

  Description :  Display the  new character

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8charCode
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidDisplayCustomChar(u8 Copy_u8charCode)
{
	HCLCD_voidSendData(Copy_u8charCode);
}

void HCLCD_voidIntegerToString(u32 Copy_u32data)
{
	char_t Local_charbuff[16];             /* String to hold the ASCII result */
	itoa(Copy_u32data, Local_charbuff, 10);      /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	HCLCD_voidSendString(Local_charbuff);   /* Display the string */
}

void HCLCD_voidClearScreen(void)
{
	HCLCD_voidSendCommand(DISPLAY_ClEAR);
}
