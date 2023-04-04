/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : ADC_priv.h
*  details : Header file for private ADC Driver.
*****************************************************************/

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
/* Bit of Register */
#define ADMUX_REFS1   7     				 //Reference selection bit1
#define ADMUX_REFS0   6    					 //Reference selection bit0
#define ADMUX_ADLAR   5     				 //ADC left adjust result

#define ADCSRA_ADEN   7                      //ADC enable
#define ADCSRA_ADSC   6                      //Start conversion
#define ADCSRA_ADATE  5                      //Auto trigger enable
#define ADCSRA_ADIF   4                      //Interrupt flag
#define ADCSRA_ADIE   3                      //Interrupt enable
#define ADCSRA_ADPS2  2                      //Prescaler bit2
#define ADCSRA_ADPS1  1                      //Prescaler bit1
#define ADCSRA_ADPS0  0                      //Prescaler bit0
/*************************************************************************************************************/

/* Voltage reference options */
#define AREF            1 //AREF, Internal Vref turned off
#define AVCC            2 //AVCC with external capacitor at AREF pin
#define INTERNALAREF    3 //Internal 2.56V voltage reference with external capacitor at AREF pin
/*************************************************************************************************************/

/* ADC left adjust result */
#define RIGHT_ADJUST   1
#define LEFT_ADJUST    2
/*************************************************************************************************************/

#define _8_BITS         1
#define _10_BITS        2

/* ADC prescaler options */
#define DIV_BY_2     0b001
#define DIV_BY_4     0b010
#define DIV_BY_8     0b011
#define DIV_BY_16    0b100
#define DIV_BY_32    0b101
#define DIV_BY_64    0b110
#define DIV_BY_128   0b111
/*************************************************************************************************************/

/* ADC conversion mode options */
#define SINGLE_CONVERSION    1
#define AUTO_TRIGGER         2
/*************************************************************************************************************/

/* ADC Auto Trigger Mode Options */
#define FREE_RUNNING             0b000
#define ANALOGE_COMPARATOR       0b001
#define EXTI_REQUEST_0           0b010
#define TIMER_0_COMPARE_MATCH    0b011
#define TIMER_0_OVERFLOW         0b100
#define TIMER_COMPARE_MATCH_B    0b101
#define TIMER_1_OVERFLOW         0b110
#define TIMER_1_CAPTURE          0b111
/*************************************************************************************************************/

#define AUTO_TRIGGER_MASK      0b00011111

#define PRESCALER_MASK         0b11111000

#define MUX_MASK               0b11100000

#define IDLE         0
#define BUSY         1

#define SINGLE_CHANNEL_ASYNCH       0
#define CHAIN_ASYNCH                1

/******************************************
  Local Functions Prototypes
*******************************************/
void __vector_16 (void) __attribute__((signal));

#endif /* ADC_PRIV_H_ */
