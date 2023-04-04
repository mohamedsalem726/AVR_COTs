/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : Led_cfg.h
 *  details : header file for configuration LED Driver.
 *****************************************************************/

#ifndef LED_CFG_H_
#define LED_CFG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*
 * Please configure pins of leds
 * LED_PIN  ex LED_PB7
 *
 * Please COnfigure Direction
 * LED_ACTIVE_HIGH
 * LED_ACTIVE_LOW
 */
#define LED_RED_PIN            LED_PB7
#define LED_RED_DIRECTION      LED_ACTIVE_HIGH

#define LED_GREEN_PIN          LED_PA4
#define LED_GREEN_DIRECTION    LED_ACTIVE_HIGH

#define LED_BLUE_PIN           LED_PA5
#define LED_BLUE_DIRECTION     LED_ACTIVE_HIGH

#define LED_YELLOW_PIN         LED_PA6
#define LED_YELLOW_DIRECTION   LED_ACTIVE_HIGH


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


#endif /* LED_CFG_H_ */
