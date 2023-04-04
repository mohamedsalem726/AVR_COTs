/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : UART_Lcfg.c
 *  details : Source file for link time configurations UART Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "UART_types.h"
#include "UART_cfg.h"

/******************************************
  Global Data
 *******************************************/
const UART_ConfigType UART_xConfig =
{TRANS_AND_REC,CHAR_SIZE_8,ASYNCHRONOUS,NO_PARITY,ONE_STOP_BIT,BAUD_RATE_57600};
