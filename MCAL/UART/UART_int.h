/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : UART_int.h
*  details : Header file for interface UART Driver.
*****************************************************************/

#ifndef UART_INT_H_
#define UART_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "UART_types.h"
#include "UART_cfg.h"

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/
volatile char_t cont;
volatile char_t rcvData[15];

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/
Error_State MUART_enInit(const UART_ConfigType * Copy_pxUart);

void MUART_voidSendByteSync(u8 Copy_u8Data);

Error_State MUART_enSendByteAsync(u8 Copy_u8Data , void (*CopyPtrToFunc)(void));

u8 MUART_u8ReceiveByteSync(void);
u8 MUART_u8ReceiveAsync(void);

Error_State MUART_enCAllback(void (*CopyPtrToFunc)(void));

void MUART_voidSendStringSync(char_t * Copy_pcharString);

Error_State MUART_enSendStringAsync(char_t * Copy_pcharString , void (*CopyPtrToFunc)(void));

void MUART_voidReceiveBufferSync(char_t *Copy_pcharReceivedBuffer , u8 Copy_u8BufferSize);

void MUART_voidSendArray(const char_t * Copy_pcharData , u8 Copy_u8Size);

void MUART_voidClearBuffer(void);

#endif /* UART_INT_H_ */
