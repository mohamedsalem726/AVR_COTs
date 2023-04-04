/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : KPD_cfg.h
 *  details : header file for configuration KPD Driver.
 *****************************************************************/

#ifndef KPD_CFG_H_
#define KPD_CFG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*
 * PLease choose the pins for row
 */
#define KPD_u8ROW0_PIN   KPD_PC6
#define KPD_u8ROW1_PIN	 KPD_PC5
#define KPD_u8ROW2_PIN   KPD_PC3
#define KPD_u8ROW3_PIN	 KPD_PC2

/*
 * Please choose the pins for columns
 */
#define KPD_u8COl0_PIN   KPD_PD7
#define KPD_u8COl1_PIN   KPD_PD6
#define KPD_u8COl2_PIN   KPD_PD5
#define KPD_u8COl3_PIN   KPD_PD3

/*Set a value to return in case of no pressed keys , out of range of[0-15]*/
#define NO_PRESSED_KEY_STATE          0xFF

/*A configurable array to set values of button*/
#define KPD_ARRAY      {{'7','8','9','/'},\
						{'4','5','6','*'},\
						{'1','2','3','-'},\
						{'C','0','=','+'}}
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/

#endif /* KPD_CFG_H_ */
