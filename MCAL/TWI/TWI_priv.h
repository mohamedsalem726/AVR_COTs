/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : TWI_priv.h
*  details : Header file for private TWI Driver.
*****************************************************************/

#ifndef TWI_PRIV_H_
#define TWI_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
/***********Private macros*************/
#define STATUS_MASK              0xF8
#define FCPU_CLOCK               16000000UL

/************Private bits***************/
#define TWCR_TWINT               7			 //TWI interrupt flag
#define TWCR_TWEA                6			 //TWI Enable Acknowledge bit
#define TWCR_TWSTA               5			 //TWI Start Condition bit
#define TWCR_TWSTO               4			 //TWI Stop Condition bit
#define TWCR_TWWC                3			 //TWI Write Collision flag
#define TWCR_TWEN                2			 //TWI Enable bit
#define TWCR_TWIE                0			 //TWI Interrupt Enable bit

#define TWSR_TWPS1               1           //TWI Prescaler bits
#define TWSR_TWPS0               0

#define TWAR_TWGCE               0           //TWI General Call Enable

/***********Actions' IDs***************/

#define START_ACK                0x08 /* start has been sent */
#define REP_START_ACK            0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK     0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK     0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK         0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   0xB8 /* means that the written byte is transmitted */

/******************************************
  Local Functions Prototypes
*******************************************/

#endif /* TWI_PRIV_H_ */
