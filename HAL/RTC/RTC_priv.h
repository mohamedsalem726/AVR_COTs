/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : RTC_priv.h
*  details : Header file for private RTC Driver.
*****************************************************************/
#ifndef RTC_PRIV_H_
#define RTC_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
#define RTC_ADDRESS    0x68
#define RTC_ADDRESS_READ 0x68
#define PTR_SECONDS    0x00
#define PTR_MINUTES    0x01
#define PTR_HOURS      0x02
#define PTR_DAY        0x03
#define PTR_DATE       0x04
#define PTR_MONTH      0x05
#define PTR_YEAR       0x06
#define PTR_CONTORL    0x07


/******************************************
  Local Functions Prototypes
*******************************************/
#define RTC_ENCODE(Number)      ((Number%10)+((Number/10)<<4))

#define RTC_DECODE(Number)      ((Number&0XF)+(10*((Number&0x70)>>4)))

#endif /* RTC_PRIV_H_ */
