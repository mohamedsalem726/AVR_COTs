/*
 * DCMOTOR_int..h
 *
 *  Created on: Mar 6, 2023
 *      Author: m_hsa
 */

#ifndef DCMOTOR_INT_H_
#define DCMOTOR_INT_H_

#include "DCMOTOR_types.h"
void HDCMOTOR_voidDirectionInit(DCMOTOR_RotateType Copy_enRotate);


void HDCMOTOR_voidSpeedInit(u8 Copy_u8Frequency, u8 Copy_u8DutyCycle);

void HDCMOTOR_voidStop(void);
#endif /* DCMOTOR_INT_H_ */
