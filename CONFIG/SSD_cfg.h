/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : SSD_cfg.h
 *  details : header file for configuration SSD Driver.
 *****************************************************************/
#ifndef SSD_CFG_H_
#define SSD_CFG_H_


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*
 * Please choose SSD pins
 */
#define SSD_A_PIN   SSD_PB0
#define SSD_B_PIN	SSD_PB1
#define SSD_C_PIN	SSD_PB2
#define SSD_D_PIN	SSD_PB4

/*
 * Please choose enable pins
 */
#define SSD_DIG1_EN  SSD_PA3
#define SSD_DIG2_EN	 SSD_PA2
#define SSD_DIG3_EN	 SSD_PB5
#define SSD_DIG4_EN	 SSD_PB6


/*
 * Please choose the delay
 */
#define SSD_DIPALY_TIME   250

#endif /* SSD_CFG_H_ */
