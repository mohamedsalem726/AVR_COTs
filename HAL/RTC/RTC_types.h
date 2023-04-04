/***************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : RTC_types.h
*  details : Declare the types for RTC Driver
*****************************************************************/
#ifndef RTC_TYPES_H_
#define RTC_TYPES_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define HOUR12 1
#define HOUR24 0

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#define TIME_FORMAT    0x40
#define hour_12_AM				0x40
#define hour_12_PM				0x60
#define hour_24					0x00
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef enum
{
  Sunday=1,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
}RTC_Days;

typedef enum
{
  AM,
  PM
}RTC_Format;



#endif /* RTC_TYPES_H_ */
