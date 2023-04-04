/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : UART_priv.h
*  details : Header file for private UART Driver.
*****************************************************************/
#ifndef UART_PRIV_H_
#define UART_PRIV_H_

/******************************************
  Local Macros / Functions
*******************************************/
/*************************Private Bits*************************/

#define UCSRA_RXC         7      //Receive complete flag
#define UCSRA_TXC         6      //Transmit complete flag
#define UCSRA_UDRE 		  5      //Date register empty flag
#define UCSRA_PE		  2      //Parity error
#define UCSRA_U2X         1      //Double transmission rate

#define UCSRB_RXCIE       7      //RX complete interrupt enable
#define UCSRB_TXCIE       6      //TX complete interrupt enable
#define UCSRB_UDRIE 	  5      //UART data register empty interrupt enable
#define UCSRB_RXEN        4      //Receiver enable
#define UCSRB_TXEN        3      //Transmitter enable
#define UCSRB_UCSZ2       2      //Bit 2 of character size bits
#define UCSRB_RXB8        1      //Bit no9 of received data in case of 9bits data transmission
#define UCSRB_TXB8        0      //Bit no9 of transmitted data in case of 9bits data transmission

#define UCSRC_URSEL       7      //To select access to USCRC or UBRRH
#define UCSRC_UMSEL       6      //To select either synchronous or asynchronous mode operation
#define UCSRC_UPM1        5      //Two bits for parity select
#define UCSRC_UPM0        4
#define UCSRC_USBS        3      //Stop bit select
#define UCSRC_UCSZ1       2      //Bit 1&0 of character size bits
#define UCSRC_UCSZ0       1

#define UBBRH_URSEL       7      //To select access to UBRRH

/*************************Private macros***************************/
#define IDLE              1
#define STRING            2
#define CHAR              3

/******************************************
  Local Functions Prototypes
*******************************************/
void __vector_15 (void) __attribute__((signal));


#endif /* UART_PRIV_H_ */
