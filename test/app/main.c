/** @file
 *	@brief	demo main() for CWSW Event Queue and EvQ Extended.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Oct 15, 2019
 *	@author kbecker
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdio.h>
#include <stdlib.h>			/* EXIT_SUCCESS */

// ----	Project Headers -------------------------
#include "ptypes.h"
#include "cwsw_evqueue_ex.h"
#include "cwsw_swtimer.h"
#include "tedlos.h"			/* events and initializer for managed alarms array, indirectly */

// ----	Module Headers --------------------------
#include "cwsw_sm_engine.h"


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
tCwswSwAlarm	tmrOs10ms = {
	/* .tm			= */tmr10ms,
	/* .reloadtm	= */tmr10ms,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evOs_Tmr10msTask,
	/* .tmrstate	= */kSwTimerEnabled
};


tCwswSwAlarm	tmrOs1000ms = {
	/* .tm			= */tmr1000ms,
	/* .reloadtm	= */0,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evOs_Tmr1000msTask,
	/* .tmrstate	= */kSwTimerEnabled
};


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

//! tedlos 10-ms task, launched not via TASK() API, but by maturation of 10-ms timer
static tU32 ct10ms = 0;					// counts ("ct") the number of activations of the task
static char progressbar[1024] = {0};
static void
taskOs10ms(tEvQ_Event ev, tU32 extra)
{
	UNUSED(ev);
	UNUSED(extra);
	progressbar[ct10ms++] = '+';
}


static void
taskOs1000ms(tEvQ_Event ev, tU32 extra)
{
	static tU32 ctActivations = 0;
	UNUSED(ev);
	UNUSED(extra);
	if(++ctActivations > 5)
	{
		(void)Cwsw_EvQX__PostEventId(&tedlos_evqx, evOs_QuitRqst);
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
	//	timer			init	  reload		evq				evid				evcb
	/// the quit event is special, doesn't have an alarm, but the message pump specifically looks for it and terminates itself if seen
	{	 NULL,			  0,	    0,		&tedlos_evqx,	evOs_QuitRqst,	    OsTimerTic	},
	{  &tmrOs10ms,	   tmr10ms,	  tmr10ms,	&tedlos_evqx,	evOs_Tmr10msTask,   taskOs10ms	},
	{ &tmrOs1000ms,	  tmr1000ms, tmr1000ms,	&tedlos_evqx,  evOs_Tmr1000msTask, taskOs1000ms	},
	{0}	/* termination row */
};


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

enum { evStateTransition1, evStateTransition2, evStateTransition3 };
enum { state1, state2 };

bool Transition1Guard(void) {

}

void TransitionState1_State2(void) {
	/*  */
}

void TransitionState2_State1(void) {

}


/* event table for the one state of my little two-state SM */
sme_state_event_t tblState1[] = {
	/* TransitionEvent			Guard				TransitionAction		NewState */
	{ evStateTransition1,	Transition1Guard,	TransitionState1_State2,	state2	},
	{ evStateTransition2,	 	NULL,					NULL,				state2	},
	{ evStateTransition3,		NULL,					NULL,				state1	}
};

/* state function for my little two-state SM */
bool state1_handler(sme_event_t ev)
{
	UNUSED(ev);
	return false;
}

sme_state_table_t stbl_test = {
	.Name = 1,						/* State name - should be an enum */
	.StateHandler = state1_handler,	/* Handler function. Note an internal reaction can provoke a state change. */
	.Events = tblState1				/**< Reference to an array of events for this state. */
};


/* event buffer for my little two-state SM */
tEvQ_Event evbuf_sm1[5] = {0};

/* event table for my little two-state SM */
tEvQ_EvTable evtbl_sm1 = {
	.pEvBuffer = evbuf_sm1,
	.szEvTbl = TABLE_SIZE(evbuf_sm1),
	.validity = kCT_TBL_VALID
};

/* event queue for my little two-state SM */
tEvQ_QueueCtrl ev1_sm1 = {
	.pEventTable = &evtbl_sm1,
	.Queue_Count = 0,
	.idxWrite = 0,
	.idxRead = 0
};

sme_sm_descriptor_t	sm_test[] = {
	.pStateTable = stbl_test,		/**< Reference to this SM's state table. */
	.stPrevious = 0,				/**< Previous state. This is not used by the SM Engine itself, but can be very useful when debugging, to answer the question, "How did I get here?" */
	.stCurrent = 0,					/**< Current state. */
	.pEventQueue = ev1_sm1,
	.evPrevious = 0
};


int
main(void)
{

	tU32 counted_avg = 0, running_avg = 0;
	tCwswClockTics starttic;

	(void)Init(Cwsw_Lib);
	(void)Init(Cwsw_EvQ);




	(void)Init(tedlos);
	tedlos__InitTaskList(tblInitTasks);
	starttic = Cwsw_ClockSvc__TimerTic();
	tedlos__do(&tedlos_evqx);

	tedlos_get_idle_stats(&counted_avg, &running_avg);

	printf("\n\nActual 32-ms avg idleness:\t%li\nrunning avg idleness:\t\t%i\n", counted_avg, running_avg);
	printf("Task Chunkiness: %li\n", Cwsw_ClockSvc__GetMaxMissedTics());
	printf("\nProgress Bar: %s\n", progressbar);
	printf("\nDuration: %li ms\n", Cwsw_ClockSvc__TimerTic() - starttic);
	puts("\nGoodbye\n");

    return (EXIT_SUCCESS);
}
