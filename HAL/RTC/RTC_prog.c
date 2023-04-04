/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : RTC_prog.c
 *  details : Source file for RTC Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"

#include "TWI_int.h"

#include "RTC_priv.h"
#include "RTC_types.h"
#include "RTC_cfg.h"
#include "RTC_int.h"

/******************************************
  Local Data
 *******************************************/



/******************************************
  Global Data
 *******************************************/

extern const TWI_ConfigType TWI_xConfig;

/******************************************
  Local Functions  body
 *******************************************/



/******************************************
  Global Functions body
 *******************************************/
void HRTC_voidInit(void)
{
	MTWI_enInit(&TWI_xConfig);

}

void HRTC_voidSetCurrentTime(const RTC_TimeType *  Copy_xTime)
{
	u8 Local_u8DataSent;
	MTWI_enSendStartCondition();
	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);

	MTWI_enSendByte(PTR_SECONDS);

	Local_u8DataSent = RTC_ENCODE(Copy_xTime->Seconds);
	MTWI_enSendByte(Local_u8DataSent);
	Local_u8DataSent = RTC_ENCODE(Copy_xTime->Minutes);
	MTWI_enSendByte(Local_u8DataSent);
	Local_u8DataSent = RTC_ENCODE(Copy_xTime->Hours);
	MTWI_enSendByte(Local_u8DataSent);

	MTWI_voidSendStopCondition();
}

void HRTC_voidSetCurrentDate(const RTC_DateType *  Copy_xDate)
{
	u8 Local_u8DataSent;
	MTWI_enSendStartCondition();
	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);

	MTWI_enSendByte(PTR_DAY);
	Local_u8DataSent =RTC_ENCODE(Copy_xDate->Day);
	MTWI_enSendByte(Local_u8DataSent);
	Local_u8DataSent =RTC_ENCODE(Copy_xDate->Date);
	MTWI_enSendByte(Local_u8DataSent);
	Local_u8DataSent =RTC_ENCODE(Copy_xDate->Mounth);
	MTWI_enSendByte(Local_u8DataSent);
	Local_u8DataSent =RTC_ENCODE(Copy_xDate->Year);
	MTWI_enSendByte(Local_u8DataSent);

	MTWI_voidSendStopCondition();
}

RTC_TimeType HRTC_xGetCurrentTime(void)
{
	RTC_TimeType Local_xCurrentTime;
	u8 Local_u8Holder;

	MTWI_enSendStartCondition();
	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
	MTWI_enSendByte(PTR_SECONDS);

	MTWI_enSendStartCondition();

	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS_READ);

	MTWI_enReceiveByteAck(&Local_u8Holder);
	Local_xCurrentTime.Seconds = RTC_DECODE(Local_u8Holder);
	MTWI_enReceiveByteAck(&Local_u8Holder);
	Local_xCurrentTime.Minutes = RTC_DECODE(Local_u8Holder);
	MTWI_enReceiveByteNoAck(&Local_u8Holder);
	Local_xCurrentTime.Hours = RTC_DECODE(Local_u8Holder);
	MTWI_voidSendStopCondition();

	return Local_xCurrentTime;
}

RTC_DateType HRTC_XGetCurrentDate(void)
{
	RTC_DateType Local_xCurrentDate;
	u8 Local_u8Holder;

	MTWI_enSendStartCondition();
	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
	MTWI_enSendByte(PTR_DAY);

	MTWI_enSendRepeatedStart();

	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);

	MTWI_enReceiveByteAck(&Local_u8Holder);
	Local_xCurrentDate.Date = RTC_DECODE(Local_u8Holder);

	MTWI_enReceiveByteAck(&Local_u8Holder);
	Local_xCurrentDate.Day = RTC_DECODE(Local_u8Holder);

	MTWI_enReceiveByteAck(&Local_u8Holder);
	Local_xCurrentDate.Mounth = RTC_DECODE(Local_u8Holder);

	MTWI_enReceiveByteNoAck(&Local_u8Holder);
	Local_xCurrentDate.Year = RTC_DECODE(Local_u8Holder);

	MTWI_voidSendStopCondition();

	return Local_xCurrentDate;
}

//void HRTC_voidSetDate(const u8 Copy_u8Date)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_DATE);
//	MTWI_enSendByte(Calculate(Copy_u8Date));
//	MTWI_voidSendStopCondition();
//}

//void HRTC_voidSetMonth(const u8 Copy_u8Month)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_MONTH);
//	MTWI_enSendByte(Calculate(Copy_u8Month));
//	MTWI_voidSendStopCondition();
//}

//void HRTC_voidSetYear(const u8 Copy_u8Year)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_YEAR);
//	MTWI_enSendByte(Calculate(Copy_u8Year));
//	MTWI_voidSendStopCondition();
//}

//u8 HRTC_u8GetDate(void)
//{
//	u8 Local_u8CurrentDate=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_DATE);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentDate);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentDate);
//}

//u8 HRTC_u8GetMonth(void)
//{
//	u8 Local_u8CurrentMonth=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_MONTH);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentMonth);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentMonth);
//}
//u8 HRTC_u8GetYear(void)
//{
//	u8 Local_u8CurrentYear=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_DATE);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentYear);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentYear);
//}
//void HRTC_voidSetSecond(const u8 Copy_u8Second)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_SECONDS);
//	MTWI_enSendByte(Calculate(Copy_u8Second));
//	MTWI_voidSendStopCondition();
//}

//void HRTC_voidSetMinute(const u8 Copy_u8Minute)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_MINUTES);
//	MTWI_enSendByte(Calculate(Copy_u8Minute));
//	MTWI_voidSendStopCondition();
//}

//void HRTC_voidSetHour(const u8 Copy_u8Hour)
//{
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_HOURS);
//	MTWI_enSendByte(Calculate(Copy_u8Hour));
//	MTWI_voidSendStopCondition();
//}

//u8 HRTC_u8GetSecond(void)
//{
//	u8 Local_u8CurrentSecond=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_SECONDS);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentSecond);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentSecond&0x7F);
//}

//u8 HRTC_u8GetMinute(void)
//{
//	u8 Local_u8CurrentMinute=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_SECONDS);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentMinute);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentMinute);
//}

//u8 HRTC_u8GetHour(void)
//{
//	u8 Local_u8CurrentHour=0;
//
//	MTWI_enSendStartCondition();
//	MTWI_enSendSlaveAddressWithWriteCmd(RTC_ADDRESS);
//	MTWI_enSendByte(PTR_SECONDS);
//	MTWI_enSendRepeatedStart();
//	MTWI_enSendSlaveAddressWithReadCmd(RTC_ADDRESS);
//	MTWI_enReceiveByteAck(&Local_u8CurrentHour);
//	MTWI_voidSendStopCondition();
//
//	return GetTime(Local_u8CurrentHour&0x3F);
//}




