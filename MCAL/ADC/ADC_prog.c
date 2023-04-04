/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : ADC_prog.c
 *  details : Source file for ADC Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"

#include "ADC_priv.h"
#include "ADC_cfg.h"
#include "ADC_types.h"
#include "ADC_int.h"

/******************************************
  Local Data
 *******************************************/
static u8 *ADC_pu8Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL; /*Global variable to carry notification function*/

static u8 *ADC_pu8ChainChannelArr = NULL;    /*Global variable to carry chain array*/
static u8 ADC_u8ChainSize;                   /*Global variable to carry numbers of channels */
static u16 *ADC_pu16ChainResultArr = NULL;    /*Global variable to carry chain result */
static u8 ADC_u8ChainConversionIndex = 0;    /*Global variable to carry the current conversion index*/

/******************************************
  Global Data
 *******************************************/
u8 ADC_u8BusySate = IDLE;
u8 ADC_u8ISRSource;

/******************************************
  Local Functions  body
 *******************************************/


/******************************************
  Global Functions  body
 *******************************************/
void MADC_voidInit(void)
{
	/* ADC voltage reference */
#if ADC_VOLTAGEREFERENCE == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLTAGEREFERENCE == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLTAGEREFERENCE == INTERNALAREF
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "Wrong Voltage Reference Configuration"
#endif

	/* Set ADC resolution*/
#if ADC_RESOLUTION == _10_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_RESOLUTION == _8_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong Resolution Configuration"
#endif

	/* Conversion Mode Selection */
#if ADC_CONVERSIONMODE == SINGLE_CONVERSION
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#elif ADC_CONVERSIONMODE == AUTO_TRIGGER
	SET_BIT(ADCSRA,ADCSRA_ADATE);

	/* Setting ADC Interrupt Enable */
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	/* Setting Auto Trigger Source */
	SFIOR &= AUTO_TRIGGER_MASK;
	SFIOR |= ADC_AUTO_TRIGGER;

	/* Start First Conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#else
#error "Wrong Conversion Mode Configuration"
#endif

	/* Prescaler Selection */
	/* Clear the Prescaler bits in the ADCSRA register */
	ADCSRA &= PRESCALER_MASK;

	/* Set the required Prescaler into the Prescaler bits */
	ADCSRA |= ADC_PRESCALER;

	/* Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 MADC_u8StartConversionSynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading)
{
	u8 Local_u8ErrorState = NO_ERROR;
	u32 Local_u32Counter = 0;

	if(ADC_u8BusySate == IDLE)
	{
		/* ADC is now busy */
		ADC_u8BusySate = BUSY;

		/* Clear the MUX bits in ADMUX register */
		ADMUX &= MUX_MASK;

		/* Set the required channel into the MUX bits */
		ADMUX |= Copy_u8Channel;

		/* Start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/* Polling (busy waiting) until the conversion complete flag is set or counter reaching time out value */
		while((GET_BIT(ADCSRA,ADCSRA_ADIF) == 0) && (Local_u32Counter != ADC_u32TIMEOUT))
		{
			Local_u32Counter++;
		}

		if(Local_u32Counter == ADC_u32TIMEOUT)
		{
			/* Loop is broken because the timeout is reached */
			Local_u8ErrorState = ERROR;
		}
		else
		{
			/* Loop is broken because the flag is raised */
			/* Clear the conversion complete flag */
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			/* Return the reading */
			*Copy_pu8Reading = ADCH;

			/* ADC is finished, return to IDLE */
			ADC_u8BusySate = IDLE;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}


u8 MADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8 *Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = NO_ERROR;

	if(ADC_u8BusySate == IDLE)
	{
		if((Copy_pu8Reading == NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/* Make ADC busy in order not to work until being IDLE */
			ADC_u8BusySate = BUSY;

			/* Make ISR Source: Single channel asynchronous */
			ADC_u8ISRSource = SINGLE_CHANNEL_ASYNCH;

			/* Initialize the reading variable globally */
			ADC_pu8Reading = Copy_pu8Reading;

			/* Initialize the callback notification function globally */
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/* Clear the MUX bits in ADMUX register */
			ADMUX &= MUX_MASK;

			/* Set the required channel into the MUX bits */
			ADMUX |= Copy_u8Channel;

			/* Start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* ADC interrupt enable */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

u8 MADC_u8StartChainConversionAsynch(ADC_CHAIN_t * Copy_Chain)
{
	u8 Local_u8ErrorState = NO_ERROR;

	/* Check NULL pointer */
	if(Copy_Chain != NULL)
	{
		if(ADC_u8BusySate == IDLE)
		{
			/* Make ADC busy in order not to work until being IDLE */
			ADC_u8BusySate = BUSY;

			/* Make ISR Source: Chain Asynchronous */
			ADC_u8ISRSource = CHAIN_ASYNCH;

			/* Initialize chain channel array */
			ADC_pu8ChainChannelArr = Copy_Chain->Channel;

			/* Initialize result array */
			ADC_pu16ChainResultArr = Copy_Chain->Result;

			/* Initialize chain size */
			ADC_u8ChainSize = Copy_Chain->Size;

			/* Initialize notification function */
			ADC_pvCallBackNotificationFunc = Copy_Chain->NotificatonFunc;

			/* Initialize current conversion index */
			ADC_u8ChainConversionIndex = 0;

			/* Set the required channel(first channel) */
			ADMUX &= MUX_MASK;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/* Start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* ADC interrupt of conversion complete enable */
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_FUNC;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

void __vector_16 (void)
{
	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNCH)
	{
		/* Read ADC result */
#if ADC_RESOLUTION == _8_BITS
		*ADC_pu8Reading = ADCH;
#elif ADC_RESOLUTION == _10_BITS
		*ADC_pu8Reading = ADC;
#endif

		/* Make ADC state IDLE because it finished */
		ADC_u8BusySate = IDLE;

		/* Invoke the callback notification function */
		ADC_pvCallBackNotificationFunc();

		/* Disable ADC conversion complete interrupt */
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSource == CHAIN_ASYNCH)
	{
		/* Read the current conversion */
#if ADC_RESOLUTION == _8_BITS
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex] = ADCH;
#elif ADC_RESOLUTION == _10_BITS
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex] = ADC;
#endif

		/* Increment chain index */
		ADC_u8ChainConversionIndex++;

		/* Check chain is finish or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
			/* Chain is finished */
			/* Make ADC state IDLE because it finished */
			ADC_u8BusySate = IDLE;

			/* Invoke the callback notification function */
			ADC_pvCallBackNotificationFunc();

			/* Disable ADC conversion complete interrupt */
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/* Chain is not finished */
			/* Set required channel */
			ADMUX &= MUX_MASK;
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

			/* Start new conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
}
