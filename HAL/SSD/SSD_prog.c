/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : SSD_prog.c
 *  details : Source file for SSD Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"

#include "SSD_priv.h"
#include "SSD_cfg.h"
#include "SSD_int.h"

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
  syntax : void HSSD_voidDisplayNumber(u16 Copy_u16Number)

  Description : Display the number in SSD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u16 Copy_u16Number
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HSSD_voidDisplayNumber(u16 Copy_u16Number)
{
	u8 Local_u8Arr[4] = {0};
	u8 Local_u8Counter1 = 0;
	u8 Local_u8Counter2 = 0;
	while((Copy_u16Number > 0) && (Local_u8Counter1 < 4))
	{
		Local_u8Arr[Local_u8Counter1] = (Copy_u16Number%10);
		Copy_u16Number /= 10;
		Local_u8Counter1++;
	}
	for(Local_u8Counter2 = 0;Local_u8Counter2<SSD_DIPALY_TIME;Local_u8Counter2++)
	{
		Local_u8Counter1 = 0;

		/* Prepare pins to be send to BCD (4bits) */
		MDIO_voidSetPinValue(SSD_A_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],0));
		MDIO_voidSetPinValue(SSD_B_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],1));
		MDIO_voidSetPinValue(SSD_C_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],2));
		MDIO_voidSetPinValue(SSD_D_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],3));

		/* Enable Digit 1 (Remember it is pnp)(active low) */
		MDIO_voidSetPinValue(SSD_DIG1_EN, DIO_LOW);
		_delay_ms(1);
		MDIO_voidSetPinValue(SSD_DIG1_EN, DIO_HIGH);

		Local_u8Counter1 = 1;

		/* Prepare pins to be send to BCD (4bits) */
		MDIO_voidSetPinValue(SSD_A_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],0));
		MDIO_voidSetPinValue(SSD_B_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],1));
		MDIO_voidSetPinValue(SSD_C_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],2));
		MDIO_voidSetPinValue(SSD_D_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],3));

		/* Enable Digit 2 (Remember it is pnp)(active low) */
		MDIO_voidSetPinValue(SSD_DIG2_EN, DIO_LOW);
		_delay_ms(1);
		MDIO_voidSetPinValue(SSD_DIG2_EN, DIO_HIGH);

		Local_u8Counter1 = 2;

		/* Prepare pins to be send to BCD (4bits) */
		MDIO_voidSetPinValue(SSD_A_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],0));
		MDIO_voidSetPinValue(SSD_B_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],1));
		MDIO_voidSetPinValue(SSD_C_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],2));
		MDIO_voidSetPinValue(SSD_D_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],3));

		/* Enable Digit 3 (Remember it is pnp)(active low) */
		MDIO_voidSetPinValue(SSD_DIG3_EN, DIO_LOW);
		_delay_ms(1);
		MDIO_voidSetPinValue(SSD_DIG3_EN, DIO_HIGH);

		Local_u8Counter1 = 3;

		/* Prepare pins to be send to BCD (4bits) */
		MDIO_voidSetPinValue(SSD_A_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],0));
		MDIO_voidSetPinValue(SSD_B_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],1));
		MDIO_voidSetPinValue(SSD_C_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],2));
		MDIO_voidSetPinValue(SSD_D_PIN, GET_BIT(Local_u8Arr[Local_u8Counter1],3));

		/* Enable Digit 4 (Remember it is pnp)(active low) */
		MDIO_voidSetPinValue(SSD_DIG4_EN, DIO_LOW);
		_delay_ms(1);
		MDIO_voidSetPinValue(SSD_DIG4_EN, DIO_HIGH);
	}

}
