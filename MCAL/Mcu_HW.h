/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file     : Mcu_HW.h
 *
 *  breif    : this file contains all registers addresses
 *
 *****************************************************************/

#ifndef MCU_HW_H_
#define MCU_HW_H_

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
 *******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
 *******************************************/
//-------------------DIO-------------------
//------------------ END of DIO------------


#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG   (*((volatile u8*)0x3A))
#define PINA_REG   (*((volatile u8*)0x39))

#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG   (*((volatile u8*)0x37))
#define PINB_REG   (*((volatile u8*)0x36))

#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG   (*((volatile u8*)0x34))
#define PINC_REG   (*((volatile u8*)0x33))

#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG   (*((volatile u8*)0x31))
#define PIND_REG   (*((volatile u8*)0x30))

/***********************************************************************************************/
/* EXTI Register */
#define GICR         *((volatile u8*)0x5B)
#define GIFR         *((volatile u8*)0x5A)
#define MCUCR        *((volatile u8*)0x55)
#define MCUCSR       *((volatile u8*)0x54)


/***********************************************************************************************/

/* GIE Register */
#define SREG     *((volatile u8*)0x5F)



/***********************************************************************************************/

/* Timer Register */

#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define TIMSK *((volatile u8 *)0x59)
#define OCR0  *((volatile u8 *)0x5C)
#define TCCR1A       *((volatile u8 *)(0x4F))
#define TCCR1B       *((volatile u8 *)(0x4E))
#define TCCR2        *((volatile u8*)(0x45))
#define TCNT1H       *((volatile u8 *)(0x4D))
#define TCNT1L       *((volatile u8 *)(0x4C))
#define TCNT1        *((volatile u16*)(0x4C))
#define TCNT2        *((volatile u8 *)(0x44))
#define ICR1H        *((volatile u8 *)(0x47))
#define ICR1L        *((volatile u8 *)(0x46))
#define ICR1         *((volatile u16*)(0x46))
#define OCR1AL       *((volatile u8 *)(0x4A))
#define OCR1AH       *((volatile u8 *)(0x4B))
#define OCR1A        *((volatile u16*)(0x4A))
#define OCR1BL       *((volatile u8 *)(0x48))
#define OCR1BH       *((volatile u8 *)(0x49))
#define OCR1B        *((volatile u16*)(0x48))
#define OCR2         *((volatile u8 *)(0x43))
#define TIFR         *((volatile u8 *)(0x58))
/***********************************************************************************************/

/* ADC Register */
#define ADMUX         *((volatile u8*)0x27)  //ADC multiplexer selection register
#define ADCSRA        *((volatile u8*)0x26)  //ADC control and status register A
#define ADCH          *((volatile u8*)0x25)      //ADC high register
#define ADCL          *((volatile u8*)0x24)      //ADC low register
#define ADC           *((volatile u16*)0x24)
#define SFIOR         *((volatile u8*)0x50)      //Special Function I/O Register
/***********************************************************************************************/

/* UART Register */
#define UDR      *((volatile u8 *)(0x2C))    //USART I/O date register
#define UCSRA    *((volatile u8 *)(0x2B))	   //USART control and status register A
#define UCSRB    *((volatile u8 *)(0x2A))    //USART control and status regisetr B

#define UCSRC    *((volatile u8 *)(0x40))    //USART control and status register C sharing same address with UBRRH
#define UBBRH    *((volatile u8 *)(0x40))    //USART baud rate register high

#define UBBRL    *((volatile u8 *)(0x29))    //USART baud rate register low
/***********************************************************************************************/

/* SPI Register */
#define SPCR     *((volatile u8*)(0x2D))    //SPI Control Register
#define SPSR     *((volatile u8*)(0x2E))    //SPI Status Register
#define SPDR     *((volatile u8*)(0x2F))    //SPI Data Registe
/***********************************************************************************************/

/* TWI Register */
#define TWCR    *((volatile u8*)(0x56))    //TWI Control Register
#define TWDR    *((volatile u8*)(0x23))    //TWI Data Register
#define TWAR    *((volatile u8*)(0x22))    //TWI Slave Address Register
#define TWSR    *((volatile u8*)(0x21))    //TWI Status Register
#define TWBR    *((volatile u8*)(0x20))    //TWI Bit rate Register
/******************************************
  GLOBAL FUNCTIONS MACROS
 *******************************************/

#endif /* MCU_HW_H_ */
