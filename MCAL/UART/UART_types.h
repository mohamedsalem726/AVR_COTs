/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : UART_types.h
 *  details : Declare the types in UART Driver
 *****************************************************************/

#ifndef UART_TYPES_H_
#define UART_TYPES_H_

/******************************************
  INCLUDES
 *******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
 *******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/

/*Running microcontroller as a transmitter or receiver or both*/
typedef enum
{
	TRANSMITTER,
	RECEIVER,
	TRANS_AND_REC
}UART_NodeType;

/*Speed of transmission either doubled or single*/
typedef enum
{
	SINGLE_SPEED,
	DOUBLE_SPEED
}UART_SpeedType;

/*Different interrupt sources*/
typedef enum
{
	NO_INTERRUPT,
	TRANSMISSION_INTERRUPT_ENABLE,
	RECEIVE_INTERRUPT_ENABLE
}UART_InterruptType;

/*Possible sizes of exchanged data*/
typedef enum
{
	CHAR_SIZE_5,
	CHAR_SIZE_6,
	CHAR_SIZE_7,
	CHAR_SIZE_8,
	CHAR_SIZE_9
}UART_CharSize;

/*Mode of operation*/
typedef enum
{
	ASYNCHRONOUS,
	SYNCHRONOUS
}UART_ModeType;

/*Parity bits*/
typedef enum
{
	NO_PARITY=0,
	EVEN_PARITY=2,
	ODD_PARITY=3
}UART_ParityType;

/*Number of stop bits*/
typedef enum
{
	ONE_STOP_BIT,
	TWO_STOP_BITS
}UART_NumberOfStopBit;

typedef enum
{
	BAUD_RATE_2400 ,
	BAUD_RATE_4800 ,
	BAUD_RATE_9600 ,
	BAUD_RATE_14400 ,
	BAUD_RATE_19200 ,
	BAUD_RATE_28800 ,
	BAUD_RATE_38400 ,
	BAUD_RATE_57600 ,
	BAUD_RATE_76800 ,
	BAUD_RATE_115200 ,
}UART_BaudRate;
#endif /* UART_TYPES_H_ */
