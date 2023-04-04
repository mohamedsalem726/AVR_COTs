/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : SPI_int.h
*  details : Header file for interface SPI Driver.
*****************************************************************/

#ifndef SPI_INT_H_
#define SPI_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "SPI_types.h"
#include "SPI_cfg.h"
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
Error_State MSPI_enInit(const SPI_ConfigType * SPI_xConfig);

u8 MSPI_u8TransceiveSync(u8 Copy_u8Data);

Error_State MSPI_voidTransceiveAsync(u8 Copy_u8SendData , u8 *Copy_pu8ReceiveData , void (*CopyPtrToFunc)(void));


#endif /* SPI_INT_H_ */
