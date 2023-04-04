/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : RTC_int.h
*  details : Header file for interface RTC Driver.
*****************************************************************/

#ifndef RTC_INT_H_
#define RTC_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "RTC_types.h"
#include "RTC_cfg.h"
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
void HRTC_voidInit(void);

void HRTC_voidSetCurrentTime(const RTC_TimeType *  Copy_xTime);

void HRTC_voidSetCurrentDate(const RTC_DateType *  Copy_xDate);

RTC_TimeType HRTC_xGetCurrentTime(void);

RTC_DateType HRTC_XGetCurrentDate(void);

void HRTC_voidSetDate(const u8 Copy_u8Date);

void HRTC_voidSetMonth(const u8 Copy_u8Month);

void HRTC_voidSetYear(const u8 Copy_u8Year);

void HRTC_voidSetSecond(const u8 Copy_u8Second);

void HRTC_voidSetMinute(const u8 Copy_u8Minute);

void HRTC_voidSetHour(const u8 Copy_u8Hour);

u8 HRTC_u8GetSecond(void);

u8 HRTC_u8GetMinute(void);

u8 HRTC_u8GetHour(void);

u8 HRTC_u8GetDate(void);

u8 HRTC_u8GetMonth(void);

u8 HRTC_u8GetYear(void);

#endif /* RTC_INT_H_ */
