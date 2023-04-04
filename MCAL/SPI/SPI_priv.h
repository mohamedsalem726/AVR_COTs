/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : SPI_priv.h
*  details : Header file for private SPI Driver.
*****************************************************************/
#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
/*************************Private Bits*************************/
#define SPCR_SPIE             7        //SPI Interrupt Enable
#define SPCR_SPE              6        //SPI Enable
#define SPCR_DORD             5        //Data Order
#define SPCR_MSTR             4        //Master Slave Select
#define SPCR_CPOL             3        //Clock Polarity
#define SPCR_CPHA             2        //Clock Phase
#define SPCR_SPR1             1        //SPI Clock Rate Select 1
#define SPCR_SPR0             0        //SPI Clock Rate Select 0

#define SPSR_SPIF             7        //SPI Interrupt Flag
#define SPSR_SPI2X            0        //SPI Double Speed



/******************************************
  Local Functions Prototypes
*******************************************/
void __vector_12 (void) __attribute__((signal));

#endif /* SPI_PRIV_H_ */
