/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : UART_cfg.h
 *  details : Header file for configuration UART Driver.
 ******************************************************************/
#ifndef UART_CFG_H_
#define UART_CFG_H_

/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/
typedef struct
{
	UART_NodeType Node;  //transmitter or receiver or both
	UART_CharSize CharSize;  //range of [5:9] bits
	UART_ModeType Mode; //synchronous or asynchronous mode
	UART_ParityType Parity; //no parity or even or odd parity bit
	UART_NumberOfStopBit StopBits; //either 1 or 2 bits
	UART_BaudRate BaudRate;
}UART_ConfigType;

#endif /* UART_CFG_H_ */
