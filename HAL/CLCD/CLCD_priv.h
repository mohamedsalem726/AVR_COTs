/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : CLCD_priv.h
*  details : Header file for private CLCD Driver.
*****************************************************************/
#ifndef CLCD_PRIV_H_
#define CLCD_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
#define REUTURN_HOME                      0x02
#define FUNCTION_SET                      0x32
#define DISPLAY_SETUP                     0x28
#define DISPLAY_ClEAR                     0x01
#define DISPLAY_ON                        0x0E
#define CURSOR_LEFT                       0x10
#define CURSOR_RIGHT                      0x06
#define DISPALY_LEFT                      0x18
#define DISPLAY_RIGHT                     0x1C

#define BLOCK_SIAZE      8

/******************************************
  Local Functions Prototypes
*******************************************/
/******************************************
  syntax : static void HCLCD_voidlatchByte(u8 copy_u8Byte)

  Description : Select the mode of the LCD and Send the byte to LCD

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  : u8 Copy_u8Byte
  parameters (out) : none
  Return Value     : void
******************************************/
static void HCLCD_voidlatchByte(u8 copy_u8Byte);

#endif /* CLCD_PRIV_H_ */
