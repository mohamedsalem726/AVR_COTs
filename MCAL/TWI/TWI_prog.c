/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TWI_prog.c
 *  details : Source file for TWI Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Mcu_HW.h"

#include "CLCD_int.h"

#include "TWI_priv.h"
#include "TWI_types.h"
#include "TWI_cfg.h"
#include "TWI_int.h"

/******************************************
  Local Data
 *******************************************/

/******************************************
  Global Data
 *******************************************/


/******************************************
  Local Functions  body
 *******************************************/


/******************************************
  Global Functions body
 *******************************************/
Error_State MTWI_enInit(const TWI_ConfigType * Copy_xConfig)
{
	/* Local variable for error checking */
	Error_State Local_enErrorState = NO_ERROR;

	/* Check the pointer is not equal NULL */
	if(Copy_xConfig != NULL)
	{
		/* Switch for Master or Slave */
		switch(Copy_xConfig->Node)
		{
		case TWI_MASTER:
			/* Enable master to send ACK bit after receiving data */
			//SET_BIT(TWCR,TWCR_TWEA);

			/* Setting the Clock Frequency */
			switch(Copy_xConfig->ClockFrequency)
			{
			case CLOCK_100K:
				/* Setting the prescaler value and TWBR */
				switch(Copy_xConfig->Prescaler)
				{
				case NO_PRESCALER:
					CLR_BIT(TWSR,TWSR_TWPS0);
					CLR_BIT(TWSR,TWSR_TWPS1);
					TWBR = (((FCPU_CLOCK/CLOCK_100K)-16UL)/2UL);
					//TWBR = 72;
					break;
				case PRESCALER_4:
					SET_BIT(TWSR,TWSR_TWPS0);
					CLR_BIT(TWSR,TWSR_TWPS1);
					TWBR = (((FCPU_CLOCK/CLOCK_100K)-16)/8);
					break;
				default:
					Local_enErrorState = OUT_OF_RANGE_VALUE;
					break;
				}
				break;
				case CLOCK_200K:
					/* Setting the prescaler value and TWBR */
					switch(Copy_xConfig->Prescaler)
					{
					case NO_PRESCALER:
						CLR_BIT(TWSR,TWSR_TWPS0);
						CLR_BIT(TWSR,TWSR_TWPS1);
						TWBR = (((FCPU_CLOCK/CLOCK_200K)-16)/2);
						break;
					case PRESCALER_4:
						SET_BIT(TWSR,TWSR_TWPS0);
						CLR_BIT(TWSR,TWSR_TWPS1);
						TWBR = (((FCPU_CLOCK/CLOCK_200K)-16)/8);
						break;
					case PRESCALER_16:
						CLR_BIT(TWSR,TWSR_TWPS0);
						SET_BIT(TWSR,TWSR_TWPS1);
						TWBR = (((FCPU_CLOCK/CLOCK_200K)-16)/32);
						break;
					default:
						Local_enErrorState = OUT_OF_RANGE_VALUE;
						break;
					}
					break;
					case CLOCK_400K:
						/* Setting the prescaler value and TWBR */
						switch(Copy_xConfig->Prescaler)
						{
						case NO_PRESCALER:
							CLR_BIT(TWSR,TWSR_TWPS0);
							CLR_BIT(TWSR,TWSR_TWPS1);
							TWBR = (((FCPU_CLOCK/CLOCK_400K)-16UL)/2UL);
							//TWBR = 12;
							break;
						case PRESCALER_4:
							SET_BIT(TWSR,TWSR_TWPS0);
							CLR_BIT(TWSR,TWSR_TWPS1);
							TWBR = (((FCPU_CLOCK/CLOCK_400K)-16)/8);
							break;
						default:
							Local_enErrorState = OUT_OF_RANGE_VALUE;
							break;
						}
						break;
						default:
							Local_enErrorState = OUT_OF_RANGE_VALUE;
							break;
			}

			/* Setting address of the node */
			if(Copy_xConfig->Address != 0)
			{
				/* Setting the target address to 7 MSB of the register */
				TWAR = (Copy_xConfig->Address<<1);
			}

			TWCR = ((1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (1<<TWCR_TWEA));
			break;
			case TWI_SLAVE:
				/* Setting the target address to 7 MSB of the register */
				TWAR = (Copy_xConfig->Address<<1);

				//Enable Ack
				SET_BIT(TWCR,TWCR_TWEA);
				/* Enable TWI peripheral */
				SET_BIT(TWCR,TWCR_TWEN);

				break;
			default:
				Local_enErrorState = OUT_OF_RANGE_VALUE;
				break;
		}
	}
	else
	{
		Local_enErrorState = NULL_POINTER;
	}

	return Local_enErrorState;
}

TWI_ErrorState MTWI_enSendStartCondition(void)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* Send Start Condition on the bus*/
	//SET_BIT(TWCR,TWCR_TWSTA);

	/* Clearing flag to perform the required action */
	//SET_BIT(TWCR,TWCR_TWINT);

	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

	/* Polling till interrupt flag is raised again (end of action) */
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* Checking for action ID */
	if((TWSR & STATUS_MASK) != START_ACK)
	{
		Local_enErrorState = START_CONDITION_ERROR;
	}
	else
	{
		/* Do nothing */
	}

	return Local_enErrorState;
}

TWI_ErrorState MTWI_enSendRepeatedStart(void)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Send Start Condition on the bus*/
	//SET_BIT(TWCR,TWCR_TWSTA);

	//SET_BIT(TWCR,TWCR_TWEN);

	/* 2) Clearing flag to perform the required action*/
	//SET_BIT(TWCR,TWCR_TWINT);

	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	/*if((TWSR & STATUS_MASK) != REP_START_ACK)
	{
		Local_enErrorState = REPEATED_START_CONDITION_ERROR;
	}
	else
	{
		/Do nothing/
	}*/

	return Local_enErrorState;
}

TWI_ErrorState MTWI_enSendSlaveAddressWithWriteCmd(u8 Copy_u8SlaveAddress)
{

	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Setting address packet to data register to be sent*/
	TWDR = (Copy_u8SlaveAddress<<1);

	//while(1);
	/* write Operation */
	//CLR_BIT(TWDR,0);

	/* 2) Clear start condition bit*/
	//CLR_BIT(TWCR,TWCR_TWSTA);

	//SET_BIT(TWCR,TWCR_TWEN);

	/* 3) Clearing flag to perform the required action*/
	//SET_BIT(TWCR,TWCR_TWINT);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	/* 4) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 5) Checking for action ID*/
	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_enErrorState = ADDRESS_WITH_WRITE_ERROR;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_enErrorState ;

}

TWI_ErrorState MTWI_enSendSlaveAddressWithReadCmd(u8 Copy_u8SlaveAddress)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Setting address packet to data register to be sent*/
	TWDR = ((Copy_u8SlaveAddress<< 1)|(0x01));

	/* Read Operation */
	//SET_BIT(TWDR,0);

	/* 2) Clear start condition bit*/
	//CLR_BIT(TWCR,TWCR_TWSTA);

	/* 3) Clearing flag to perform the required action*/
	//SET_BIT(TWCR,TWCR_TWINT);

	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	/* 4) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 5) Checking for action ID*/
	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_enErrorState = ADDRESS_WITH_READ_ERROR;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_enErrorState ;
}

TWI_ErrorState MTWI_enSendByte(u8 Copy_u8DataByte)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Setting data byte to get transmitter*/
	TWDR = Copy_u8DataByte;

	/* 2) Clearing flag to perform the required action*/
	//SET_BIT(TWCR,TWCR_TWINT);

	//SET_BIT(TWCR,TWCR_TWEN);

	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) ;

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	if((TWSR & STATUS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_enErrorState = MSTR_WRITE_DATA_ERROR;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_enErrorState;
}

TWI_ErrorState MTWI_enReceiveByteAck(u8 * Copy_pu8ReceivedDataByte)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Clearing flag to allow slave sending data*/
	//SET_BIT(TWCR,TWCR_TWINT);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN) | (1<<TWCR_TWEA);
	/* 2) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 3) Checking for action ID*/
	if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_enErrorState = MSTR_READ_DATA_ERROR;
	}
	else
	{
		/* 4) Getting received data*/
		*Copy_pu8ReceivedDataByte = TWDR;
	}

	return Local_enErrorState;
}

TWI_ErrorState MTWI_enReceiveByteNoAck(u8 * Copy_pu8ReceiveDataByte)
{
	/* Local enum object for error checking */
	TWI_ErrorState Local_enErrorState = TWI_NO_ERROR;

	/* 1) Setting the acknowledge bit */
	CLR_BIT(TWCR,TWCR_TWEA);

	/* 2) Clearing flag to allow slave sending data*/
	//SET_BIT(TWCR,TWCR_TWINT);

	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWCR,TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_NACK)
	{
		Local_enErrorState = MSTR_READ_DATA_ERROR;
	}
	else
	{
		/* 4) Getting received data*/
		*Copy_pu8ReceiveDataByte = TWDR;
	}

	return Local_enErrorState;
}

void MTWI_voidSendStopCondition(void)
{
	/* Generating stop condition on the bus */
	//SET_BIT(TWCR,TWCR_TWSTO);

	/* Clearing flag to perform the required action */
	//SET_BIT(TWCR,TWCR_TWINT) ;

	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
}
