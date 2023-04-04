/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TIMER0_priv.h
*  details : Header file for private TIMER0 Driver.
*****************************************************************/
#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
#define OC_ACTION_MASK    0xCF
#define PRESCALER_MASK    0b11111000

#define MAX_NUMBER_OF_OVERFLOW 256



/* TIMSK Bits */
#define TIMSK_TOIE0             0
#define TIMSK_OCIE0             1


/*  TCCR0 Bits */
#define TCCR0_FOC0              7
#define TCCR0_WGM00             6
#define TCCR0_COM01             5
#define TCCR0_COM00             4
#define TCCR0_WGM01             3
#define TCCR0_CS02              2
#define TCCR0_CS01				1
#define TCCR0_CS00				0

/* TIFR Bits */
#define TIFR_OCF0               1
#define TIFR_TOV0               0

/******************************************
  Local Functions Prototypes
*******************************************/


#endif /* TIMER0_PRIV_H_ */
