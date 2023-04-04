/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : CLCD_cfg.h
 *  details : header file for configuration CLCD Driver.
 *****************************************************************/

#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define CLCD_PORT     DIO_PORTB

/*
 * Please choose the CLCD pins
 */
#define CLCD_RS_PIN   CLCD_PA3
#define CLCD_E_PIN    CLCD_PA2

#define CLCD_D4_PIN   CLCD_PB0
#define CLCD_D5_PIN   CLCD_PB1
#define CLCD_D6_PIN   CLCD_PB2
#define CLCD_D7_PIN   CLCD_PB4

/*
 * Please choose CLCD mode
 * _4_BIT_MODE
 * _8_BIT_MODE
 */
#define CLCD_MODE    _4_BIT_MODE



/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/

#endif /* CLCD_CFG_H_ */
