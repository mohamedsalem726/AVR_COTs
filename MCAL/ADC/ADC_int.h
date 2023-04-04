/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : ADC_int.h
*  details : Header file for interface ADC Driver.
*****************************************************************/
#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "ADC_types.h"
#include "ADC_cfg.h"
void MADC_voidInit(void);

u8 MADC_u8StartConversionSynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading);

u8 MADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void));

u8 MADC_u8StartChainConversionAsynch(ADC_CHAIN_t * Copy_Chain);

#endif /* ADC_INT_H_ */
