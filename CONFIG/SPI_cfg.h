/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : SPI_cfg.h
 *  details : Header file for configuration SPI Driver.
 ******************************************************************/
#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/
typedef struct
{
	SPI_NodeState Node;
	SPI_InterruptState InterruptState;
	SPI_DataOrder DataOrder;
	SPI_ClockPolarity ClockPolarity;
	SPI_ClockPhase ClockPhase;
	SPI_ClockPrescaler Prescaler;
}SPI_ConfigType;

#endif /* SPI_CFG_H_ */
