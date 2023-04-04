/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : SPI_prog.c
 *  details : Source file for SPI Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"

#include "SPI_priv.h"
#include "SPI_types.h"
#include "SPI_cfg.h"
#include "SPI_int.h"


u8 *GlobalePtrToRecChar = NULL;

static void (*EndOfTransceive)(void) = NULL;

Error_State MSPI_enInit(const SPI_ConfigType * SPI_xConfig)
{
	Error_State Local_enErrorState = NO_ERROR;

	/*switching over Node sources*/
	switch(SPI_xConfig->Node)
	{
	case SPI_MASTER: SET_BIT(SPCR,SPCR_MSTR); break;
	case SPI_SLAVE: CLR_BIT(SPCR,SPCR_MSTR); break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/*switching over interrupt sources*/
	switch(SPI_xConfig->InterruptState)
	{
	case INTERRUPT_DISABLE: CLR_BIT(SPCR,SPCR_SPIE); break;
	case INTERRUPT_ENABLE: SET_BIT(SPCR,SPCR_SPIE); break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/*switching over data transfer order*/
	switch(SPI_xConfig->DataOrder)
	{
	case LSB_FIRST: SET_BIT(SPCR,SPCR_DORD); break;
	case MSB_FIRST: CLR_BIT(SPCR,SPCR_DORD); break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/*switching over clock polarity options*/
	switch(SPI_xConfig->ClockPolarity)
	{
	case LEADING_RISING: SET_BIT(SPCR,SPCR_CPOL); break;
	case LEADING_FALLING: CLR_BIT(SPCR,SPCR_CPOL); break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/*switching over clock phase options*/
	switch(SPI_xConfig->ClockPhase)
	{
	case SAMPLE_AT_LEAD: CLR_BIT(SPCR,SPCR_CPHA); break;
	case SETUP_AT_LEAD: SET_BIT(SPCR,SPCR_CPHA); break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/*switching over prescaler values*/
	if(SPI_xConfig->Node == SPI_MASTER)
	{
		switch(SPI_xConfig->Prescaler)
		{
		case CLK_DIV_BY_2:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_4:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_8:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_16:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_32:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_64:
			SET_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X);
			break;
		case CLK_DIV_BY_128 :
			SET_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X);
			break;
		default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
		}
	}
	else
	{
		/* DO nothing */
	}
	/*Enabling SPI peripheral*/
	SET_BIT(SPCR , SPCR_SPE) ;

	return Local_enErrorState;
}

u8 MSPI_u8TransceiveSync(u8 Copy_u8Data)
{
	/*Setting data to be sent*/
	SPDR = Copy_u8Data;

	/*Polling till end of data transfer*/
	while((GET_BIT(SPSR , SPSR_SPIF)) == 0);

	/*Getting received data*/
	return SPDR;
}


Error_State MSPI_voidTransceiveAsync(u8 Copy_u8SendData , u8 *Copy_pu8ReceiveData , void (*CopyPtrToFunc)(void))
{
	/*Local variable for error checking*/
	Error_State Local_enErrorState = NO_ERROR;

	/*Setting data to be sent*/
	SPDR = Copy_u8SendData;

	/*Setting global pointer to access the same address*/
	GlobalePtrToRecChar = Copy_pu8ReceiveData;

	/*Checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfTransceive = CopyPtrToFunc;
	}
	else
	{
		Local_enErrorState = NULL_POINTER;
	}

	return Local_enErrorState;
}


void __vector_12 (void)
{
	/*Getting received character*/
	*GlobalePtrToRecChar = SPDR;

	/*Calling notification function*/
	EndOfTransceive();
}
