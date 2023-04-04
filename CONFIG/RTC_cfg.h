/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : RTC_cfg.h
 *  details : Header file for configuration RTC Driver.
 ******************************************************************/
#ifndef RTC_CFG_H_
#define RTC_CFG_H_

/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/
#define MODE HOUR24


/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/
typedef struct
{
	u8 Hours;
	u8 Minutes;
	u8 Seconds;
	u8 TimeFormat;
}RTC_TimeType;

typedef struct
{
	RTC_Days Day;
	u8 Date;
	u8 Mounth;
	u8 Year;
}RTC_DateType;

#endif /* RTC_CFG_H_ */
