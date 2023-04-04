/***************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : SPI_types.h
 *  details : Declare the types in SPI Driver
 *****************************************************************/

#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

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
typedef enum
{
	SPI_MASTER,  //Node as a master
	SPI_SLAVE    //Node as a slave
}SPI_NodeState;

typedef enum
{
	INTERRUPT_DISABLE,   //Enable end of data transfer interrupt
	INTERRUPT_ENABLE     //Disable end of data transfer interrupt
}SPI_InterruptState;

typedef enum
{
	LSB_FIRST,    //Sending LSB first
	MSB_FIRST     //Sending MSB first
}SPI_DataOrder;

typedef enum
{
	LEADING_RISING,   //Leading edge is rising & trailing edge is falling
	LEADING_FALLING   //Leading edge is falling & trailing edge is rising
}SPI_ClockPolarity;

typedef enum
{
	SAMPLE_AT_LEAD,     //sample(receive) at leading edge and setup(send) at trailing edge
	SETUP_AT_LEAD       //setup(send) at leading edge and sample(receive) at trailing edge
}SPI_ClockPhase;

typedef enum
{
	CLK_DIV_BY_2,
	CLK_DIV_BY_4,
	CLK_DIV_BY_8,
	CLK_DIV_BY_16,
	CLK_DIV_BY_32,
	CLK_DIV_BY_64,
	CLK_DIV_BY_128
}SPI_ClockPrescaler;

#endif /* SPI_TYPES_H_ */
