/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : Port_Lcfg.c
 *  details : Source file for link time configurations PORT Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
#include "Port_types.h"
#include "Port_cfg.h"


/******************************************
  Global Data
 *******************************************/
const Port_Configtype Port_ConfigArr[PORT_PINS_CONFIG_ARR_SIZE] = {
		/* KEYPAD PINs */
		/* Columns */
//		{PORT_PD7 , PORT_LOW , PORT_INPUT, PORT_PULLUP},
//		{PORT_PD6 , PORT_LOW , PORT_INPUT, PORT_PULLUP},
//		{PORT_PD5 , PORT_LOW , PORT_INPUT, PORT_PULLUP},
//		{PORT_PD3 , PORT_LOW , PORT_INPUT, PORT_PULLUP},
		/* Rows */
//		{PORT_PC6 , PORT_HIGH , PORT_OUTPUT, PORT_FLOATING},
//		{PORT_PC5 , PORT_HIGH , PORT_OUTPUT, PORT_FLOATING},
//		{PORT_PC3 , PORT_HIGH , PORT_OUTPUT, PORT_FLOATING},
//		{PORT_PC2 , PORT_HIGH , PORT_OUTPUT, PORT_FLOATING},
		/* LCD PINs */
		{PORT_PB0 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		{PORT_PB1 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		{PORT_PB2 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		{PORT_PB4 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		{PORT_PA3 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		{PORT_PA2 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},

		/* EXTI0 PIN */
		//{PORT_PD2 , PORT_HIGH , PORT_INPUT, PORT_PULLUP},

		/* LED GREEN PIN */
		{PORT_PA4 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},

		/* LED BLUE PIN */
		{PORT_PA5 , PORT_HIGH , PORT_OUTPUT, PORT_FLOATING},

		/* LED RED PIN */
		{PORT_PB7 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},

		/* Echo pin for ultrasonic */
		//{PORT_PD6 , PORT_LOW , PORT_INPUT , PORT_FLOATING},

		/* Trigger pin for ultrasonic */
		//{PORT_PC5 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		//{PORT_PC7 , PORT_LOW , PORT_INPUT, PORT_PULLUP},
		/* Temperature pin PA0 */
		//{PORT_PA0, PORT_LOW , PORT_INPUT , PORT_FLOATING},
		/* TX */
//		{PORT_PD1 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		/* Rx */
//		{PORT_PD0 , PORT_LOW , PORT_INPUT, PORT_FLOATING},
		/* MOTOR pins */
		//{PORT_PD0 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		//{PORT_PD1 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		//{PORT_PB3 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		/* SPI pins */
		// SS
		//{PORT_PB4 , PORT_HIGH , PORT_INPUT , PORT_PULLUP},
		//MOSI Master
		//{PORT_PB5 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//MISO Master
		//{PORT_PB6 , PORT_LOW , PORT_INPUT , PORT_FLOATING},
		//SCK Master
		//{PORT_PB7 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING}

		/* LED Port */
		//{PORT_PA0 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA1 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA2 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA3 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA4 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA5 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA6 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		//{PORT_PA7 , PORT_LOW , PORT_OUTPUT , PORT_FLOATING},
		/* Buzzer Pin */
		{PORT_PC6 , PORT_LOW , PORT_OUTPUT, PORT_FLOATING},
		/* LM35 Pin */
		{PORT_PA1 , PORT_LOW , PORT_INPUT , PORT_FLOATING},
};
