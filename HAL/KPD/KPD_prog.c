/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : KPD_prog.c
 *  details : Source file for KPD Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"

#include "Dio_int.h"

#include "KPD_cfg.h"
#include "KPD_priv.h"
#include "KPD_int.h"

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
  syntax : char_t HKPD_enGetPressedKey(void)

  Description: Get the value of the pressed key.

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : Non
  Return Value     : char_t
 ******************************************/
u8 HKPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = NO_PRESSED_KEY_STATE;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8PinState;

	static u8 Local_u8KeypadArray[KPD_NO_OF_ROWS][KPD_NO_OF_COLS] = KPD_ARRAY;
	static u8 Local_u8ColumnArray[KPD_NO_OF_COLS] = {KPD_u8COl0_PIN,KPD_u8COl1_PIN,KPD_u8COl2_PIN,KPD_u8COl3_PIN};
	static u8 Local_u8RowArray[KPD_NO_OF_ROWS] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};

	for(Local_u8RowIndex=0;Local_u8RowIndex<KPD_NO_OF_ROWS;Local_u8RowIndex++)
	{
		/*Activating current ROW*/
		MDIO_voidSetPinValue(Local_u8RowArray[Local_u8RowIndex],DIO_LOW);

		/*looping over Columns to search for pressed key*/
		for(Local_u8ColIndex=0;Local_u8ColIndex<KPD_NO_OF_COLS;Local_u8ColIndex++)
		{
			/*Read the current Column*/
			Local_u8PinState = MDIO_enGetPinValue(Local_u8ColumnArray[Local_u8ColIndex]);

			/*checking if switch is pressed*/
			if(Local_u8PinState==DIO_LOW)
			{
				Local_u8PressedKey =Local_u8KeypadArray[Local_u8RowIndex][Local_u8ColIndex];

				while(Local_u8PinState==DIO_LOW)    //polling(busy waiting) till key is released
				{
					Local_u8PinState = MDIO_enGetPinValue(Local_u8ColumnArray[Local_u8ColIndex]);
				}


				return Local_u8PressedKey;
			}
		}

		/*Deactivating current ROW*/
		MDIO_voidSetPinValue(Local_u8RowArray[Local_u8RowIndex],DIO_HIGH);
	}

	return Local_u8PressedKey;
}


