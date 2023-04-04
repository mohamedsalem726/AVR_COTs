/*
 * OS_int.h
 *
 *  Created on: Mar 5, 2023
 *      Author: m_hsa
 */

#ifndef OS_INT_H_
#define OS_INT_H_
#include "OS_types.h"
#include "OS_cfg.h"

void OS_voidInit(void);
void OS_voidStart(void);

void OS_voidCreateTask(u8 copy_u8Priority , u16 copy_u16Periodicity ,u16 Copy_u16FirstDelay, void (*copy_pvTaskFunc)(void));

void OS_voidSuspendTask(u8 Copy_u8Priority);

void OS_voidResumeTask(u8 Copy_u8Priority);

void OS_voidDeleteTask(u8 Copy_u8Priority);

#endif /* OS_INT_H_ */
