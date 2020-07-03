/** @file tedlos.h
 *	@brief	The Event-Dispatching Loop OS.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Feb 19, 2020
 *	@author: kbecker
 */

#ifndef APP_TEDLOS_H_
#define APP_TEDLOS_H_

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdint.h>				/* uint32_t */

// ----	Project Headers -------------------------
#include "cwsw_evqueue_ex.h"	/* ptEvQ_QueueCtrlEx */

// ----	Module Headers --------------------------
#include "tedlosevents.h"
#include "tedlos_scheduler.h"	/* OsTimerTic */
#include "tedlos_cfg.h"			/* interrupt drive? */

#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

/*	Table of tasks for the init function.
 */
typedef struct eTedlosTaskDescriptor {
	ptCwswSwAlarm		pAlarm;
	tCwswClockTics		tm_init;
	tCwswClockTics		tm_rearm;
	ptEvQ_QueueCtrlEx	pEvqxCtrl;
	int16_t				evid;
	ptEvQ_EvHandlerFunc	pf;			//
} tTedlosTaskDescriptor, *ptTedlosTaskDescriptor;


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

/** TEDLOS event queue.
 *	Public so that application-level tasks can see it, for their initialization.
 */
extern tEvQ_QueueCtrlEx tedlos_evqx;


// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

// ---- Discrete Functions -------------------------------------------------- {
extern void tedlos__Init(void);
extern void	tedlos__InitTaskList(ptTedlosTaskDescriptor tasktable);	/* note this is a pointer to one row of the table. Termination must be whole row == 0 */

extern void tedlos__do(ptEvQ_QueueCtrlEx tedlos_evqx);
extern void tedlos_get_idle_stats(uint32_t *counted_avg, uint32_t *running_avg);

// ---- /Discrete Functions ------------------------------------------------- }

// ---- Targets for Get/Set APIs -------------------------------------------- {

// ---- /Targets for Get/Set APIs ------------------------------------------- }

#ifdef	__cplusplus
}
#endif

#endif /* APP_TEDLOS_H_ */
