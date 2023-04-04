/*
 * DCMOTOR_prog.c
 *
 *  Created on: Mar 6, 2023
 *      Author: m_hsa
 */


#include "STD_TYPES.h"

#include "Dio_int.h"
#include "PWM0_int.h"

#include "DCMOTOR_types.h"
#include "DCMOTPR_cfg.h"
#include "DCMOTOR_int.h"


void HDCMOTOR_voidDirectionInit(DCMOTOR_RotateType Copy_enRotate)
{
	switch(Copy_enRotate)
	{
	case CLOCK_WISE:
		MDIO_voidSetPinValue(DCMOTOR_IN1, DIO_HIGH);
		MDIO_voidSetPinValue(DCMOTOR_IN2, DIO_LOW);
		break;
	case COUNTER_CLOCK_WISE:
		MDIO_voidSetPinValue(DCMOTOR_IN1, DIO_LOW);
		MDIO_voidSetPinValue(DCMOTOR_IN2, DIO_HIGH);
		break;
	}
}

void HDCMOTOR_voidSpeedInit(u8 Copy_u8Frequency, u8 Copy_u8DutyCycle)
{
	MPWM0_u8InitTimer0(Copy_u8Frequency,Copy_u8DutyCycle);
}

void HDCMOTOR_voidStop(void)
{
	MDIO_voidSetPinValue(DCMOTOR_IN1, DIO_LOW);
	MDIO_voidSetPinValue(DCMOTOR_IN2, DIO_LOW);
	MDIO_voidSetPinValue(DCMOTOR_EN, DIO_LOW);
}
