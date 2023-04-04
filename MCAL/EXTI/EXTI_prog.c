/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : EXTI_prog.c
 *  details : Source file for EXTI Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_priv.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "Mcu_HW.h"

/******************************************
  Local Data
 *******************************************/

static void (*MEXTI_pvCallBackArr[3])(void) = {NULL , NULL, NULL};

/******************************************
  Global Data
 *******************************************/




/******************************************
  Local Functions  body
 *******************************************/


/******************************************
  Global Functions  body
 *******************************************/


/******************************************
  syntax : EXTI_ErrorStatus MEXTI_enEnableInt(const EXTI_ConfigType * ConfigPtr)

  Description: Enable the EXTI pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : const EXTI_ConfigType * ConfigPtr
  parameters (out) : Non
  Return Value     : EXTI_ErrorStatus
 ******************************************/
Error_State MEXTI_enEnableInt(const EXTI_ConfigType * ConfigPtr)
{
	Error_State Local_enErrorState = NO_ERROR;
	u8 Local_u8Counter;
	for(Local_u8Counter = 0 ; Local_u8Counter<EXTI_PINS_CONFIG_ARR_SIZE;Local_u8Counter++)
	{
		switch(ConfigPtr[Local_u8Counter].Int_Number)
		{
		case EXTI0:
			switch(ConfigPtr[Local_u8Counter].Int_Source)
			{
			case EXTI_u8LOWLEVEL:    CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8ANYCHANGE:   SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8FALLINGEDGE: CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8RISINGEDGE:  SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			default: Local_enErrorState = ERROR; break;
			}
			SET_BIT(GICR,GICR_INT0);
			break;
			case EXTI1:
				switch(ConfigPtr[Local_u8Counter].Int_Source)
				{
				case EXTI_u8LOWLEVEL:    CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
				case EXTI_u8ANYCHANGE:   SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
				case EXTI_u8FALLINGEDGE: CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
				case EXTI_u8RISINGEDGE:  SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
				default: Local_enErrorState = ERROR; break;
				}
				SET_BIT(GICR,GICR_INT1);
				break;
				case EXTI2:
					switch(ConfigPtr[Local_u8Counter].Int_Source)
					{
					case EXTI_u8FALLINGEDGE: SET_BIT(MCUCSR,MCUCSR_ISC2);  break;
					case EXTI_u8RISINGEDGE:  CLR_BIT(MCUCSR,MCUCSR_ISC2);  break;
					default: Local_enErrorState = ERROR; break;
					}
					SET_BIT(GICR,GICR_INT2);
					break;
					default:
						Local_enErrorState = ERROR;
						break;
		}

	}
	return Local_enErrorState;
}

/******************************************
  syntax : EXTI_ErrorStatus MEXTI_enDisableInt(const EXTI_ConfigType *ConfigPtr)

  Description: Disable the EXTI pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : const EXTI_ConfigType * ConfigPtr
  parameters (out) : Non
  Return Value     : EXTI_ErrorStatus
 ******************************************/
Error_State MEXTI_enDisableInt(const EXTI_ConfigType *ConfigPtr)
{
	Error_State Local_enErrorState = NO_ERROR;
	u8 Local_u8Counter;
	for(Local_u8Counter = 0 ; Local_u8Counter<EXTI_PINS_CONFIG_ARR_SIZE;Local_u8Counter++)
	{
		switch(ConfigPtr[Local_u8Counter].Int_Number)
		{
		case EXTI0: CLR_BIT(GICR,GICR_INT0); break;
		case EXTI1: CLR_BIT(GICR,GICR_INT1); break;
		case EXTI2: CLR_BIT(GICR,GICR_INT2); break;
		default: Local_enErrorState = ERROR; break;
		}
	}
	return Local_enErrorState;
}

/******************************************
  syntax : EXTI_ErrorStatus MEXTI_enSetCallBack(cu8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void))

  Description: Set the EXTI callback functions

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void)
  parameters (out) : Non
  Return Value     : EXTI_ErrorStatus
 ******************************************/
Error_State MEXTI_enSetCallBack(u8 Copy_u8ExtiIndex , void (*Copy_pvIntFunc)(void))
{
	Error_State local_enErrorState = NO_ERROR;

	if(Copy_pvIntFunc != NULL)
	{
		MEXTI_pvCallBackArr[Copy_u8ExtiIndex] = Copy_pvIntFunc;
	}
	else
	{
		local_enErrorState = ERROR;
	}
	return local_enErrorState;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(MEXTI_pvCallBackArr[0] != NULL)
	{
		MEXTI_pvCallBackArr[0]();
	}
	else
	{
		/* Do Nothing */
	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(MEXTI_pvCallBackArr[1] != NULL)
	{
		MEXTI_pvCallBackArr[1]();
	}
	else
	{
		/* Do Nothing */
	}
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(MEXTI_pvCallBackArr[2] != NULL)
	{
		MEXTI_pvCallBackArr[2]();
	}
	else
	{
		/* Do Nothing */
	}
}
