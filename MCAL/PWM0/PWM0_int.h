/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : PWM0_int.h
*  details : Header file for interface PWM Driver.
*****************************************************************/


#ifndef PWM0_INT_H_
#define PWM0_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "PWM0_types.h"

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
/*Description  :  this function is to initialize FAST PWM on TIMER/COUNTER0       */
/*Input        :  frequency of output signal					                  */
/*             :  Duty cycle for setting ON timer                                 */
/*Output       :  error indicator                                     			  */
/*Configuration:  post-build    								                  */
Error_State MPWM0_u8InitTimer0( u16 Copy_u8Frequency , u8 Copy_u8DutyCycle);


#endif /* PWM0_INT_H_ */
