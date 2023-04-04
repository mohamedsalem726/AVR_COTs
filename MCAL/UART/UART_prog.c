/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : UART_prog.c
 *  details : Source file for UART Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include <avr/interrupt.h>
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"


#include "UART_priv.h"
#include "UART_types.h"
#include "UART_cfg.h"
#include "UART_int.h"

/******************************************
  Local Data
 *******************************************/

/******************************************
  Global Data
 *******************************************/


/*global variable used as a flag of interrupt source of transmission [either a string or a character]*/
u8 TRAN_INTERRUPT_SRC = IDLE ;

/*global pointer to set received data asynchronously*/
u8 * GlobalPtrToRecChar = NULL ;

/*global string to send string asynchronously */
char * GlobalString  = NULL;



/******************************************
  Local Functions  body
 *******************************************/
/*Global pointer to function for end of transmission ISR*/
static void (*EndOfTransmission)(void) = NULL ;

/*Global pointer to function for end of receive ISR*/
static void (*EndOfReceive)(void) = NULL ;

/******************************************
  Global Functions body
 *******************************************/
Error_State MUART_enInit(const UART_ConfigType * Copy_pxUart)
{
	//local variable for error checking
	Error_State Local_enErrorState = NO_ERROR;

	/* local variable to assign value of UCSRC register*/
	u8 Local_u8UCSRC_Value = 0;


	/*Switching over different options of exchanged data size*/
	switch(Copy_pxUart->CharSize)
	{
	case CHAR_SIZE_5:
		Local_u8UCSRC_Value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) | ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (0<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0);
		UCSRC = Local_u8UCSRC_Value;
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case CHAR_SIZE_6:
		Local_u8UCSRC_Value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) | ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (0<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
		UCSRC = Local_u8UCSRC_Value;
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case CHAR_SIZE_7:
		Local_u8UCSRC_Value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) | ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0);
		UCSRC = Local_u8UCSRC_Value;
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case CHAR_SIZE_8:
		Local_u8UCSRC_Value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) | ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
		UCSRC = Local_u8UCSRC_Value;
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case CHAR_SIZE_9:
		Local_u8UCSRC_Value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) | ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
		SET_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	default:
		Local_enErrorState = ERROR;
		break;
	}

	/*Switching over different options of Baud Rate*/
	switch(Copy_pxUart->BaudRate)
	{
	case BAUD_RATE_2400: break;
	case BAUD_RATE_4800: UBBRL = 207; break;
	case BAUD_RATE_9600: UBBRL = 103; break;
	case BAUD_RATE_14400: UBBRL = 68; break;
	case BAUD_RATE_19200: UBBRL = 51; break;
	case BAUD_RATE_28800: UBBRL = 34; break;
	case BAUD_RATE_38400: UBBRL = 25; break;
	case BAUD_RATE_57600: UBBRL = 16; break;
	case BAUD_RATE_76800: UBBRL = 12; break;
	case BAUD_RATE_115200: UBBRL = 8; break;
	default: Local_enErrorState = OUT_OF_RANGE_VALUE; break;
	}

	/* Switching over Nodes of USART */
	switch(Copy_pxUart->Node)
	{
	//in case of running as a transmitter
	case TRANSMITTER:
		SET_BIT(UCSRB,UCSRB_TXEN);
		break;
		//in case of running as a receiver
	case RECEIVER:
		SET_BIT(UCSRB,UCSRB_RXEN);
		break;
	case TRANS_AND_REC:
		SET_BIT(UCSRB,UCSRB_TXEN);
		SET_BIT(UCSRB,UCSRB_RXEN);
		break;
	default:
		Local_enErrorState = ERROR;
		break;
	}


	SET_BIT(UCSRB,UCSRB_RXCIE);
	return Local_enErrorState;
}

void MUART_voidSendByteSync(u8 Copy_u8Data)
{
	/*polling till UDR register is ready to receive new data*/
	while((GET_BIT(UCSRA , UCSRA_UDRE))== 0);

	/*assigning data to UDR to get transmitted*/
	UDR = Copy_u8Data;

	/*polling till end of transmission*/
	while((GET_BIT(UCSRA , UCSRA_TXC)) == 0);

	/*clearing end of transmission flag*/
	SET_BIT(UCSRA , UCSRA_TXC);
}

Error_State MUART_enSendByteAsync(u8 Copy_u8Data , void (*CopyPtrToFunc)(void))
{
	/*Local variable for error checking*/
	Error_State Local_enErrorState = NO_ERROR;

	/*Setting flag of source of interrupt to be a single character*/
	TRAN_INTERRUPT_SRC = CHAR;

	/*Polling till UDR register is ready to receive new data*/
	while((GET_BIT(UCSRA , UCSRA_UDRE))== 0);

	/*Assigning data to UDR to get transmitted*/
	UDR = Copy_u8Data;

	/*Enable end of transmission interrupt*/
	SET_BIT(UCSRB, UCSRB_TXCIE);

	/*Checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfTransmission = CopyPtrToFunc ;
	}
	else
	{
		Local_enErrorState = NULL_POINTER ;
	}
	return Local_enErrorState;
}

u8 MUART_u8ReceiveByteSync(void)
{
	/*polling till data is completely received*/
	while((GET_BIT(UCSRA , UCSRA_RXC))==0);

	/*clearing flag and getting received data*/
	return UDR;
}

u8 MUART_u8ReceiveAsync(void)
{

	return UDR;
}
Error_State MUART_enCAllback(void (*CopyPtrToFunc)(void))
{
	/*Local variable for error checking*/
	Error_State Local_enErrorState = NO_ERROR;

	if( (CopyPtrToFunc != NULL))
	{
		EndOfReceive = CopyPtrToFunc;

	}
	else
	{
		Local_enErrorState = NULL_POINTER;
	}

	return Local_enErrorState;
}

void MUART_voidSendStringSync(char_t * Copy_pcharString)
{
	/*local variable to loop over characters of the string*/
	u8 Local_u8Counter = 0 ;

	/*looping over string characters*/
	while(Copy_pcharString[Local_u8Counter] != '\0')
	{
		/*sending characters one by one*/
		MUART_voidSendByteSync(Copy_pcharString[Local_u8Counter]);

		Local_u8Counter++;
	}
}

Error_State MUART_enSendStringAsync(char_t * Copy_pcharString , void (*CopyPtrToFunc)(void))
{
	/*local variable for error checking*/
	Error_State Local_enErrorState = NO_ERROR;

	/*setting flag of source of interrupt to be a string*/
	TRAN_INTERRUPT_SRC = STRING;

	/*set global pointer to access the same address*/
	GlobalString = Copy_pcharString;

	/*polling till UDR register is ready to receive new data*/
	while((GET_BIT(UCSRA , UCSRA_UDRE))== 0);

	if((Copy_pcharString != NULL) && (Copy_pcharString[0] != '\0'))
	{
		/*assigning data to UDR to get transmitted*/
		UDR = Copy_pcharString[0];
	}
	else
	{
		Local_enErrorState = ERROR;
	}

	/*enable end of transmission interrupt*/
	SET_BIT(UCSRB, UCSRB_TXCIE);

	/*checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfTransmission = CopyPtrToFunc;
	}
	else
	{
		Local_enErrorState = NULL_POINTER;
	}

	return Local_enErrorState;

}

void MUART_voidReceiveBufferSync(char_t *Copy_pcharReceivedBuffer , u8 Copy_u8BufferSize)
{
	/*local variable to loop over buffer elements*/
	u8 Local_u8Counter = 0 ;

	/*looping over buffer elements*/
	for(Local_u8Counter=0; Local_u8Counter<Copy_u8BufferSize; Local_u8Counter++)
	{
		/*getting received character*/
		Copy_pcharReceivedBuffer[Local_u8Counter] = MUART_u8ReceiveByteSync();
	}
}


void MUART_voidSendArray(const char_t * Copy_pcharData , u8 Copy_u8Size)
{
	u8 Local_u8Counter;

	for(Local_u8Counter = 0; Local_u8Counter<Copy_u8Size;Local_u8Counter++)
	{
		MUART_voidSendByteSync(Copy_pcharData[Local_u8Counter]);
		_delay_ms(250);
	}
	//_delay_ms(1000);
}


/*ISR for USART end of transmission*/
//void __vector_15 (void)
//{
//	/*in case end of transmission of a single character*/
//	if(TRAN_INTERRUPT_SRC == CHAR)
//	{
//		/*calling notification function*/
//		EndOfTransmission();
//	}
//	else if(TRAN_INTERRUPT_SRC == STRING)
//	{
//		u8 Local_u8Counter = 1;
//
//		/*sending remaining characters*/
//		while(GlobalString[Local_u8Counter] != '\0')
//		{
//			MUART_voidSendByteSync(GlobalString[Local_u8Counter]);
//			Local_u8Counter++;
//		}
//
//		/*calling notification function*/
//		EndOfTransmission();
//	}
//	else
//	{
//		/* Do nothing */
//	}
//}

/*ISR for USART end of receive*/
ISR(USART_RXC_vect)
{
	EndOfReceive();
}
