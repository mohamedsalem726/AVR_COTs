/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : UART_Lcfg.c
 *  details : Source file for link time configurations UART Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "SPI_types.h"
#include "SPI_cfg.h"

/******************************************
  Global Data
 *******************************************/
const SPI_ConfigType SPI_xConfig =
	{SPI_MASTER,INTERRUPT_DISABLE,LSB_FIRST,LEADING_RISING,SAMPLE_AT_LEAD,CLK_DIV_BY_16};
