/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : FP_prog.c
 *  details : Source file for FingerPrint Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include <util/delay.h>
#include <stdio.h>
#include "STD_TYPES.h"

#include "UART_int.h"
#include "CLCD_int.h"
#include "PB_int.h"
#include "GIE_int.h"

#include "FP_priv.h"
#include "FP_types.h"
#include "FP_int.h"



/******************************************
  Local Data
 *******************************************/
static volatile u8 Counter=0;
static volatile u8 Buffer[20];

/******************************************
  Global Data
 *******************************************/
extern const UART_ConfigType UART_xConfig;




/******************************************
  Local Functions  body
 *******************************************/
void HFP_Receive(void);

/******************************************
  Global Functions body
 *******************************************/
void HFP_voidInit(void)
{
	MUART_enInit(&UART_xConfig);
	MUART_enCAllback(HFP_Receive);
	MGIE_voidEnable();
	HCLCD_voidInit();
}

void HFP_voidEnroll(u8 Copy_u8ID)
{
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Put Your Finger");
	_delay_ms(1000);
	HFP_voidGenImg();
	_delay_ms(1000);
	HFP_voidImg2Tz(1);
	_delay_ms(1000);
	HFP_voidGenImg();
	_delay_ms(1000);
	HFP_voidImg2Tz(2);
	_delay_ms(1000);
	HFP_voidRegModel();
	_delay_ms(1000);
	HFP_voidStore(Copy_u8ID);
	_delay_ms(1000);
}

u16 HFP_voidMatch(void)
{
	u16 ID;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Put Your Finger");
	_delay_ms(2000);
	HFP_voidGenImg();
	_delay_ms(1000);
	HFP_voidImg2Tz(1);
	_delay_ms(1000);
	ID = HFP_u16Search();
	_delay_ms(1000);
	return ID;
}

static void HFP_voidGenImg(void)
{
	u8 Local_u8Flag =0;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Collect Finger....");
	//HFP_voidClearBuffer();
	while(Local_u8Flag != 1)
	{
		MUART_voidSendArray(f_detect,12);
		_delay_ms(1000);

		if(Buffer[9] == 0x00)
		{
			Local_u8Flag = 1;
			HCLCD_voidClearScreen();
			HCLCD_voidSendString("Finger Collection Success");
			HFP_voidClearBuffer();
			break;
		}
		HFP_voidClearBuffer();
	}

}

static void HFP_voidImg2Tz(u8 Copy_u8Buffer)
{
	u8 Local_u8Flag = 0;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Generating Buffer....");
	while(Local_u8Flag != 1)
	{
		if(Copy_u8Buffer == 1)
		{
			MUART_voidSendArray(f_imz2ch1,13);
		}
		else if(Copy_u8Buffer == 2)
		{
			MUART_voidSendArray(f_imz2ch2,13);
		}

		if(Buffer[9] == 0x00)
		{
			Local_u8Flag=1;
			HCLCD_voidClearScreen();
			HCLCD_voidSendString("Generate Done");
			HFP_voidClearBuffer();
			break;
		}
		HFP_voidClearBuffer();
	}



}

static void HFP_voidRegModel(void)
{

	u8 Local_u8Flag=0;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Create Template");
	while(Local_u8Flag != 1)
	{
		MUART_voidSendArray(f_createModel,12);



		if(Buffer[9] == 0x00)
		{
			Local_u8Flag = 1;
			HCLCD_voidClearScreen();
			HCLCD_voidSendString("Operation Success");
			HFP_voidClearBuffer();
			break;
		}
		HFP_voidClearBuffer();
	}

}


static void HFP_voidStore(u8 Copy_u8ID)
{

	u8 Local_u8Flag = 0;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Storing...");

	while(Local_u8Flag != 1 )
	{
		HFP_voidChechSum(f_storeModel, Copy_u8ID);
		MUART_voidSendArray(f_storeModel, 15);

		if(Buffer[9] == 0x00)
		{
			Local_u8Flag = 1;
			HCLCD_voidClearScreen();
			HCLCD_voidSendString("Stroge Success");
			HFP_voidClearBuffer();
			break;
		}
		HFP_voidClearBuffer();
	}
}

static u16 HFP_u16Search(void)
{
	u16 Local_u16ID;
	u8 Local_Flag=0;
	HCLCD_voidClearScreen();
	HCLCD_voidSendString("Searching....");

	while(Local_Flag != 1)
	{
		MUART_voidSendArray(f_search,17);

		if(Buffer[9] == 0x00)
		{
			Local_Flag = 1;
			HCLCD_voidClearScreen();
			HCLCD_voidSendString("Found finger");
			Local_u16ID = Buffer[11];
			HFP_voidClearBuffer();
			break;
		}
		HFP_voidClearBuffer();
	}
	return Local_u16ID;
}

void HFP_Receive(void)
{
	Buffer[Counter] = MUART_u8ReceiveAsync();
	//HCLCD_voidIntegerToString(Buffer[Counter]);
	Counter++;
}

static void HFP_voidClearBuffer(void)
{
	u8 Local_u8Counter;
	Counter=0;
	for(Local_u8Counter=0;Local_u8Counter<20;Local_u8Counter++)
	{
		Buffer[Local_u8Counter]=0xAA;
	}
}

static void HFP_voidChechSum(char_t * Copy_charArr,u8 Copy_u8PageId)
{
	u8 Local_u8Counter;
	u8 Local_u8Value=0;
	Copy_charArr[12] = Copy_u8PageId;
	for(Local_u8Counter=6;Local_u8Counter<13;Local_u8Counter++)
	{
		Local_u8Value+=(Copy_charArr[Local_u8Counter]);
	}
	Copy_charArr[14] = Local_u8Value;
}
