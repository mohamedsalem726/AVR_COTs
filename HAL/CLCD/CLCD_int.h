/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : CLCD_int.h
*  details : Header file for interface CLCD Driver.
*****************************************************************/
#ifndef CLCD_INT_H_
#define CLCD_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "CLCD_types.h"
#include "CLCD_cfg.h"

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define _4_BIT_MODE   1
#define _8_BIT_MODE   2


#define FONT1    1
#define FONT2    2

#define ENABLE   1
#define DISABLE  2
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
  syntax : void HCLCD_voidInit(void)

  Description : Initialize the LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : void
  parameters (out) : none
  Return Value     : void
******************************************/
void HCLCD_voidInit(void);

/******************************************
  syntax : void HCLCD_voidSendData(u8 Copy_u8Data)

  Description : Send the data to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Data
  parameters (out) : none
  Return Value     : void
******************************************/
void HCLCD_voidSendData(u8 Copy_u8Data);

/******************************************
  syntax : void HCLCD_voidSendCommand(u8 Copy_u8Command)

  Description : Send the command to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Command
  parameters (out) : none
  Return Value     : void
******************************************/
void HCLCD_voidSendCommand(u8 Copy_u8Command);

/******************************************
  syntax : void HCLCD_voidSendString(const char_t * Copy_ps8Str)

  Description : Send the string to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :  const s8 * Copy_ps8Str
  parameters (out) : none
  Return Value     : void
******************************************/
void HCLCD_voidSendString(const char_t * Copy_ps8Str);

/******************************************
  syntax : void HCLCD_voidGotoXY(u8 copy_u8Row,u8 copy_u8Colum)

  Description : Go to specific postion

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Row , u8 Copy_u8Colum
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidGotoXY(u8 Copy_u8Row,u8 Copy_u8Colum);

/******************************************
  syntax : void HCLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)

  Description : Generate new character

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 * ArrPattern , u8 copy_u8charCode
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);

/******************************************
  syntax : void HCLCD_voidDisplayCustomChar(u8 Copy_u8charCode)

  Description :  Display the  new character

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8charCode
  parameters (out) : none
  Return Value     : void
 ******************************************/
void HCLCD_voidDisplayCustomChar(u8 Copy_u8charCode);

void HCLCD_voidIntegerToString(u32 Copy_u32data);

void HCLCD_voidClearScreen(void);

#endif /* CLCD_INT_H_ */
