/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TEMP_prog.c
 *  details : Source file for Temperature Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"

#include "ADC_int.h"

#include "TEMP_types.h"
#include "TEMP_priv.h"
#include "TEMP_cfg.h"
#include "TEMP_int.h"


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
u8 HTEMP_u8GetTemperature(void)
{
	u8 Local_u8Reading;
	u16 local_u16Analog_mv;
	u16 Local_u8Temperature;
	MADC_voidInit();

	MADC_u8StartConversionSynch(ADC_u8SINGLECHANNEL0, &Local_u8Reading);
#if TEMPERATURE_VALUE == CELSIUS
	local_u16Analog_mv = (((u32)Local_u8Reading*500UL)/256UL);

	Local_u8Temperature = local_u16Analog_mv / 10;

#elif TEMPERATURE_VALUE == FAHRENHEIT
	Local_u8Temperature = ((1.8*Local_u8Reading) +32);
#endif

	return Local_u8Temperature;
}
