/*
 * ADC_cfg.h
 *
 *  Created on: Mar 3, 2023
 *      Author: m_hsa
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/*Choose ADC voltage reference
 *  Options:
 *         1- AREF          //AREF, Internal Vref turned off
 *         2- AVCC          //AVCC with external capacitor at AREF pin
 *         3- INTERNALAREF  //Internal 2.56V voltage reference with external capacitor at AREF pin
 *******************************************************************************************************/
#define ADC_VOLTAGEREFERENCE      AVCC

/* Choose Number of ADC Bits
 * Options:
 *         1- _8_BITS
 *         2- _10_BITS
 *******************************************************************************************************/
#define ADC_RESOLUTION          _8_BITS


/* Choose ADC Prescaler.
 * Options:
 *         1- DIV_BY_2
 *         2- DIV_BY_4
 *         3- DIV_BY_8
 *         4- DIV_BY_16
 *         5- DIV_BY_32
 *         6- DIV_BY_64
 *         7- DIV_BY_128
 *******************************************************************************************************/
#define ADC_PRESCALER             DIV_BY_128

/* Choose ADC Conversion Mode
 * Options:
 *         1- SINGLE_CONVERSION
 *         2- AUTO_TRIGGER
 *******************************************************************************************************/
#define ADC_CONVERSIONMODE       SINGLE_CONVERSION

/* Choose ADC auto trigger source: Only work in Auto trigger Mode.
 * Options:
 *         1- FREE_RUNNING
 *         2- ANALOGE_COMPARATOR
 *         3- EXTI_REQUEST_0
 *         4- TIMER_0_COMPARE_MATCH
 *         5- TIMER_0_OVERFLOW
 *         6- TIMER_COMPARE_MATCH_B
 *         7- TIMER_1_OVERFLOW
 *         8- TIMER_1_CAPTURE
 *******************************************************************************************************/
#define ADC_AUTO_TRIGGER       FREE_RUNNING

#define ADC_u32TIMEOUT         50000



/* Define struct of ADC chain*/
typedef struct
{
	u8* Channel;
	u16* Result;
	u8   Size;
	void (*NotificatonFunc)(void);
}ADC_CHAIN_t;

#endif /* ADC_CFG_H_ */
