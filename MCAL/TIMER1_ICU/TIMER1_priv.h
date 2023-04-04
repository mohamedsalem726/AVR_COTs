/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TIMER1_priv.h
*  details : Header file for private TIMER1 Driver.
*****************************************************************/
#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
#define FCPU_CLOCK                  16000000UL
#define PRESCALER_MASK				0b11111000

/*  TCCR1A Bits */
#define TCCR1A_COM1A1            7
#define TCCR1A_COM1A0            6
#define TCCR1A_COM1B1            5
#define TCCR1A_COM1B0            4
#define TCCR1A_FOC1A             3
#define TCCR1A_FOC1B             2
#define TCCR1A_WGM11			 1
#define TCCR1A_WGM10			 0

/*  TCCR1B Bits */
#define TCCR1B_ICNC1             7
#define TCCR1B_ICES1             6
#define TCCR1B_WGM13             4
#define TCCR1B_WGM12             3
#define TCCR1B_CS12              2
#define TCCR1B_CS11			     1
#define TCCR1B_CS10			     0

/* TIFR Bits */
#define TIFR_ICF1               5
#define TIFR_OCF1A              4
#define TIFR_OCF1B              3
#define TIFR_TOV1               2

/* TIMSK Bits */
#define TIMSK_TOIE1             2
#define TIMSK_OCIE1B            3
#define TIMSK_OCIE1A            4
#define TIMSK_TICIE1            5

#endif /* TIMER1_PRIV_H_ */
