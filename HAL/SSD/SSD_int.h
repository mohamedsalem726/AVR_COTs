/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : SSD_int.h
*  details : Header file for interface SSD Driver.
*****************************************************************/

#ifndef SSD_INT_H_
#define SSD_INT_H_

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
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void HSSD_voidDisplayNumber(u16 Copy_u16Number)

  Description : Display the number in SSD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u16 Copy_u16Number
  parameters (out) : none
  Return Value     : void
******************************************/
void HSSD_voidDisplayNumber(u16 Copy_u16Number);

#endif /* SSD_INT_H_ */
