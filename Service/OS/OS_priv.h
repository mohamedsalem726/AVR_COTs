/*
 * OS_priv.h
 *
 *  Created on: Mar 5, 2023
 *      Author: m_hsa
 */

#ifndef OS_PRIV_H_
#define OS_PRIV_H_

typedef struct
{
	u16 Periodicity;
	void(*TaskFunc)(void);
	Task_state State;
	u16 FirstDelay;
	u8 Delay;
}Task_t;

static void voidScheduler(void);

#endif /* OS_PRIV_H_ */
