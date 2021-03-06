/** @file
 *	@brief	demo main() for CWSW Event Queue and EvQ Extended.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Oct 15, 2019
 *	@author Kevin L. Becker
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdio.h>
#include <stdlib.h>				/* EXIT_SUCCESS */

// ----	Project Headers -------------------------
#include "cwsw_arch.h"
#include "cwsw_board.h"
#include "cwsw_bsp_buttons.h"
#include "app-di-buttons.h"
#include "app-do-lamps.h"
#include "stoplite.h"

#include "tedlos.h"				/* tedlos_evqx */

// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

//! tedlos 10-ms timer.
//! Note this compile-time initialization is a legacy of previous development; the timers must be
//! 	created but the initialization is "wiped out" by the initialization done in InitTaskList().
//! Note this sort of compile-time initialization is still suitable for situations where you want
//! 	the timer definitions to be in ROM.
tCwswSwAlarm	Os_tmr_10ms = {
	/* .tm			= */tmr10ms,
	/* .reloadtm	= */tmr10ms,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evOs_Task10ms,
	/* .tmrstate	= */kTmrState_Enabled
};


tCwswSwAlarm	Os_tmr_1000ms = {
	/* .tm			= */tmr1000ms,
	/* .reloadtm	= */0,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evOs_Task1000ms,
	/* .tmrstate	= */kTmrState_Enabled
};


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

//! tedlos 10-ms task, launched not via TASK() API, but by maturation of 10-ms timer
//static tU32 ct10ms = 0;					// counts ("ct") the number of activations of the task
static char progressbar[1024] = {0};
static void
Os_tsk_10ms(tEvQ_Event ev, uint32_t extra)
{
	UNUSED(ev);
	UNUSED(extra);
	Task(AppDO);
}


static void
Os_tsk_1000ms(tEvQ_Event ev, uint32_t extra)
{
	static uint32_t ctActivations = 0;
	UNUSED(ev);
	UNUSED(extra);
	switch(++ctActivations)
	{
	case 1:
		Cwsw_EvQX__PostEventId(&tedlos_evqx, evStopLite_Reenter);
		break;

	case 355:
		Cwsw_EvQX__PostEventId(&tedlos_evqx, evStoplite_StopTask);
		break;
	case 360:
		(void)Cwsw_EvQX__PostEventId(&tedlos_evqx, evOs_QuitRqst);
		break;
	default:
		printf("Time: %i\n", ctActivations);
		break;
	}
}


/** Task initialization table.
 *	We have 2 basic approaches: either, we can have
 *	- one universal set of tasks, where each task is aware of the current ECU state and reacts
 *	  accordingly; or, we can have
 *	- a set of tasks for each ECU mode, each defined in an ECU-mode-specific table, where each task
 *	  is active only in the appropriate ECU state. In this last option, there would be an init table
 *	  for each ECU state, and mode management would call the InitTaskList function at each mode change.
 *
 *	For now, the MVP is to implement the 1st option. I will experiment later w/ the 2nd option.
 *
 *	@note This table must be terminated by a row of all 0 or NULL values.
 */
tTedlosTaskDescriptor tblInitTasks[] = {
	//	timer			init	  	reload				evq				evid					evcb
	/// the quit event is special, doesn't have an alarm, but the message pump specifically looks for it and terminates itself if seen
	{	 NULL,				0,		    0,			&tedlos_evqx,	evOs_QuitRqst,			OsTimerTic					},

	// the following couple of functions are do-nothings for testing purposes
	{  &Os_tmr_10ms,	tmr10ms,	tmr10ms,		&tedlos_evqx,	evOs_Task10ms,			Os_tsk_10ms					},
	{ &Os_tmr_1000ms,	tmr1000ms,	tmr1000ms,		&tedlos_evqx,	evOs_Task1000ms, 		Os_tsk_1000ms				},

	// stoplight task
	//	Note: the stoplight task alarm is initialized via compile-time means.
	//	that component does its own event association.

	// DI task
	{	NULL, 		    	0,			0,			&tedlos_evqx,	evButton_Task,			Btn_tsk_ButtonRead			},

	// End of Table
	{0}	/* termination row */
};


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

int
main(void)
{

	uint32_t counted_avg = 0, running_avg = 0;
	tCwswClockTics starttic;

	// services layer
	(void)Init(Cwsw_Lib);
	(void)Init(Cwsw_EvQ);
	(void)Init(tedlos);

	// driver layer
	(void)Init(Cwsw_Arch);		// Cwsw_Arch__Init()
	(void)Init(buttons);		// app-level sensor component - buttons__Init()

	// app layer
	(void)Init(Stoplite);
	(void)Init(AppDO);			// app-level actuator component (DO = Digital Output)	AppDO__Init()

	// this board-level init function doesn't return until the [QUIT] button is pushed, so it's gotta be last.
	if(!Init(Cwsw_Board))		// Cwsw_Board__Init()
	{
		tedlos__InitTaskList(tblInitTasks);
		starttic = Get(Cwsw_ClockSvc, CurrentTime);

		tedlos__do(&tedlos_evqx);
		tedlos_get_idle_stats(&counted_avg, &running_avg);

		printf("\n\nActual 32-ms avg idleness:\t%i\nrunning avg idleness:\t\t%i\n", counted_avg, running_avg);
		printf("Max missed tics:\t\t%li\n", Cwsw_ClockSvc__GetMaxMissedTics());
		printf("\nProgress Bar: %s\n", progressbar);
		printf("\nDuration: %li ms\n", Get(Cwsw_ClockSvc, CurrentTime) - starttic);
	}

	puts("\nGoodbye\n");
    return (EXIT_SUCCESS);
}
