/*
 * PWM0_types.h
 *
 *  Created on: Mar 6, 2023
 *      Author: m_hsa
 */

#ifndef PWM0_TYPES_H_
#define PWM0_TYPES_H_

/**************************TIMER0 configurations*************************/
/*possible frequencies represented by value of prescaler to be set in clock select bits*/
#define FREQUENCY_31250      1      //T=32 us
#define FREQUENCY_3906       2		//T=256 us
#define FREQUENCY_488        3		//T=2048 us
#define FREQUENCY_122        4      //T=8129 us
#define FREQUENCY_30         5		//T=32768 us

#endif /* PPWM0_TYPES_H_ */
