/*
 * ULTRASONIC_int.h
 *
 *  Created on: Mar 2, 2023
 *      Author: m_hsa
 */

#ifndef ULTRASONIC_INT_H_
#define ULTRASONIC_INT_H_
#include "ULTRASONIC_types.h"
#include "ULTRASONIC_cfg.h"
void HUltrasonic_voidinit(void);

u16 HULTRASONIC_u16GetDistance(void);

void Ultrasonic_edgeProcessing(void);

void HULTRASONIC_voidTrigger(void);

#endif /* ULTRASONIC_INT_H_ */
