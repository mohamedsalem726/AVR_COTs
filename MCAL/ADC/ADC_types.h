/*
 * ADC_types.h
 *
 *  Created on: Mar 3, 2023
 *      Author: m_hsa
 */

#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/* Single Ended input channel */
#define ADC_u8SINGLECHANNEL0       0b00000  //ADC0
#define ADC_u8SINGLECHANNEL1       0b00001  //ADC1
#define ADC_u8SINGLECHANNEL2       0b00010  //ADC2
#define ADC_u8SINGLECHANNEL3       0b00011  //ADC3
#define ADC_u8SINGLECHANNEL4       0b00100  //ADC4
#define ADC_u8SINGLECHANNEL5       0b00101  //ADC5
#define ADC_u8SINGLECHANNEL6       0b00110  //ADC6
#define ADC_u8SINGLECHANNEL7       0b00111  //ADC7
/*****************************************************************/

/* Differential input channel */
#define ADC_u8DIFFERENTIALCHANNEL0    0b10000 //Positive differential input ADC0, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL1    0b10001 //Positive differential input ADC1, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL2    0b10010 //Positive differential input ADC2, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL3    0b10011 //Positive differential input ADC3, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL4    0b10100 //Positive differential input ADC4, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL5    0b10101 //Positive differential input ADC5, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL6    0b10110 //Positive differential input ADC6, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL7    0b10111 //Positive differential input ADC7, Negative differential input ADC1, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL8    0b11000 //Positive differential input ADC0, Negative differential input ADC2, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL9    0b11001 //Positive differential input ADC1, Negative differential input ADC2, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL10   0b11010 //Positive differential input ADC2, Negative differential input ADC2, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL11   0b11011 //Positive differential input ADC3, Negative differential input ADC2, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL12   0b11100 //Positive differential input ADC4, Negative differential input ADC2, Gain 1x
#define ADC_u8DIFFERENTIALCHANNEL13   0b11101 //Positive differential input ADC5, Negative differential input ADC2, Gain 1x
/**********************************************************************************************************************************************/

#endif /* ADC_TYPES_H_ */
