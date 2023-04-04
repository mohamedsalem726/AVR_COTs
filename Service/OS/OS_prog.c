/*
 * OS_prog.c
 *
 *  Created on: Mar 5, 2023
 *      Author: m_hsa
 */


#include "STD_TYPES.h"

#include "TIMER0_int.h"
#include "GIE_int.h"

#include "OS_types.h"
#include "OS_priv.h"
#include "OS_cfg.h"
#include "OS_int.h"



extern const TIMER0_ConfigType TIMER0_xConfig;

Task_t SystemTasks[TASK_NUM] = {{NULL}};

void OS_voidInit(void)
{
	MTIMER0_enInit(&TIMER0_xConfig);
	MTIMER0_enSetCallBack(TIMER0_OVER_FLOW, &voidScheduler);
	MTIMER0_enEnableInt(TIMER0_OVER_FLOW);
	MGIE_voidEnable();
}

void OS_voidStart(void)
{
	MTIMER0_enSetDelayTimeMilliSec(TIMER0_NORMAL_MODE,10);
}

void OS_voidCreateTask(u8 copy_u8Priority , u16 copy_u16Periodicity ,u16 Copy_u16FirstDelay, void (*copy_pvTaskFunc)(void))
{
	SystemTasks[copy_u8Priority].Periodicity = copy_u16Periodicity;
	SystemTasks[copy_u8Priority].TaskFunc = copy_pvTaskFunc;
	SystemTasks[copy_u8Priority].State = TASK_READY;
	SystemTasks[copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
}

void OS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void OS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_READY;
}

void OS_voidDeleteTask(u8 Copy_u8Priority)
{
	u8 Local_u8TaskCounter;
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		SystemTasks[Local_u8TaskCounter] = SystemTasks[Local_u8TaskCounter+1];
	}
	SystemTasks[TASK_NUM-1].TaskFunc = NULL;
}

void OS_TaskDelay(u8 Copy_u8Priority , u8 Copy_u8Delay)
{
	SystemTasks[Copy_u8Priority].Delay = Copy_u8Delay;
	SystemTasks[Copy_u8Priority].State = TASK_BLOCKED;
}

static void voidScheduler(void)
{
	u8 Local_u8TaskCounter;

	/* Loop on all tasks to check their periodicity */
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		if(SystemTasks[Local_u8TaskCounter].Delay == 0)
		{
			SystemTasks[Local_u8TaskCounter].State=TASK_READY;
		}
		else
		{
			SystemTasks[Local_u8TaskCounter].Delay--;
		}

		if((SystemTasks[Local_u8TaskCounter].State == TASK_READY))
		{
			/* Invoke the task function */
			if(SystemTasks[Local_u8TaskCounter].Periodicity != 0)
			{
				SystemTasks[Local_u8TaskCounter].FirstDelay--;

				if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity;
				}
			}

		}
	}
}
