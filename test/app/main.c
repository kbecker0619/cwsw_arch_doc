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

// ----	Module Headers --------------------------
#include "cwsw_swtimer.h"
#include "tedlosevents.h"	/* events and initializer for managed alarms array */


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

enum {
	tmr10ms   =   10 / Cwsw_ClockSvc_TicResolution,
	tmr25ms   =   25 / Cwsw_ClockSvc_TicResolution,
	tmr50ms   =   50 / Cwsw_ClockSvc_TicResolution,
	tmr100ms  =  100 / Cwsw_ClockSvc_TicResolution,
	tmr250ms  =  250 / Cwsw_ClockSvc_TicResolution,
	tmr500ms  =  500 / Cwsw_ClockSvc_TicResolution,
	tmr1000ms = 1000 / Cwsw_ClockSvc_TicResolution
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

typedef enum eOsEvqEvents tOsEvqEvents, *pOsEvqEvents;


// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

static bool quit_requested = false;

//! tedlos event queue data
//!  @{

tEvQ_Event tblEventBuff[16] = {0};						//!< OS event buffer
tEvQ_EvTable evTbl	= {									//!< OS event table
	/* .pEvBuffer	= */tblEventBuff,
	/* .szEvTbl		= */TABLE_SIZE(tblEventBuff),
	/* .validity	= */kCT_TBL_VALID
};

tEvHA_EvHandlerAssoc AssocArr[kNumOsEvqEvents] = {0};	//!< OS event handler LUT
tEvQ_EvHndlrAssocTable tblEvH = {						//!< OS event handler association table
	/* .pEvtHndlrLut	= */AssocArr,
	/* .szEvtHandlerTbl = */TABLE_SIZE(AssocArr),
	/* .validity		= */kCT_TBL_VALID
};

tEvQ_QueueCtrlEx tedlos_evqx = {						//!< OS event queue
	/* .EvQ_Ctrl	= */{
		/* .pEventTable	= */&evTbl,
		/* .Queue_Count	= */0,
		/* .idxWrite	= */0,
		/* .idxRead		= */0
	},
	/* .pEvHndlrs	= */&tblEvH
};
//! @}

//! tedlos 10-ms timer
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

#include "ManagedAlarms.h"
static ptCwswSwAlarm ManagedAlarms[] = ListOfManagedAlarms;


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

static tU32 idlecounts = 0;
static tU32 maxcounts = 0;
static tU32 countavg = 0;
static tU32 countbins[32] = {0};
static tU32 bin = 0;
void OsTimerTic(tEvQ_Event ev, tU32 extra)
{
	tU32 tmridx;
	UNUSED(extra);
	// manage SW timers
	for(tmridx = 0; tmridx < TABLE_SIZE(ManagedAlarms); tmridx++)
	{
		Cwsw_SwAlarm__ManageTimer(ManagedAlarms[tmridx]);
	} while(0);

	do {	// save idle count data
		countbins[bin++] = idlecounts;
		if(idlecounts > maxcounts)			{ maxcounts = idlecounts; }
		if(bin >= TABLE_SIZE(countbins))	{ bin = 0; }
		if(!countavg)						{ countavg = idlecounts; }
		countavg -= (tU32)(countavg / TO_U32(TABLE_SIZE(countbins)));
		countavg += (tU32)(idlecounts / TO_U32(TABLE_SIZE(countbins)));
		idlecounts = 0;
	} while(0);

	do {	// temporary, metric-related, so i can set breakpoints
		if(ev.evId == evOs_QuitRqst)		{ quit_requested = true; }

	} while(0);
}

//! tedlos 10-ms task, launched not via TASK() API, but by maturation of 10-ms timer
static tU32 ct10ms = 0;
static char progressbar[1024] = {0};
static void taskOs10ms(tEvQ_Event ev, tU32 extra)
{
	UNUSED(ev);
	UNUSED(extra);
	progressbar[ct10ms++] = '+';
}

static void taskOs1000ms(tEvQ_Event ev, tU32 extra)
{
	UNUSED(ev);
	UNUSED(extra);
	quit_requested = true;
}

static void
tedlos__init(void)
{
	cwsw_assert(!Cwsw_EvQX__SetEvHandler(&tedlos_evqx, evOs_TmrHeartbeat, OsTimerTic), "Unexpected set handler problem");
	Cwsw_ClockSvc__Init(&tedlos_evqx, evOs_TmrHeartbeat);

	cwsw_assert(!Cwsw_EvQX__SetEvHandler(&tedlos_evqx, evOs_QuitRqst, OsTimerTic), "Unexpected set handler problem");

	cwsw_assert(!Cwsw_EvQX__SetEvHandler(&tedlos_evqx, evOs_Tmr10msTask, taskOs10ms), "Unexpected set handler problem");
	cwsw_assert(!Cwsw_EvQX__SetEvHandler(&tedlos_evqx, evOs_Tmr1000msTask, taskOs1000ms), "Unexpected set handler problem");
}

static void
tedlos_idle(void)
{
	++idlecounts;
}

static void
tedlos__do(void)
{
	tErrorCodes_EvQ rc;
	// this loop is executed as quickly as possible
	do {
		/* posting vs dispatching:
		 * the clock service task will post (at most) one event each time called.
		 * this will cause the OS tic handler to be called; inside that function, there will be an
		 * event posted for each timer that matures, and possibly some other postings as well.
		 *
		 * because i envision this function as the main "scheduler", i kinda-sorta want all events
		 * to be dispatched from here. we'll see how this scales, it might not scale well (written
		 * 14-apr-2020, at the very beginning of "playing" with tedlos).
		 *
		 * in one of my previous jobs, we had a message pump that limited itself to no more than <x>
		 * calls to the event dispatcher (i think in that context <x> was 5).
		 */
		Task(Cwsw_ClockSvc);
		do {
			/* WARNING ABOUT TASKS:
			 * because this is a COOPERATIVE tasking system, it is IMPERATIVE that everything that
			 * is done in any particular time slot, must be completed with a bit of headroom to
			 * spare. for that reason, the following points:
			 * - generally, we recommend that each task should have its own alarm and should not
			 *   spawn sub-tasks; however, of course, there's a balance with the number of events
			 *   defined in the system, and it may make sense for the slower tasks to spawn their
			 *   own sub-tasks.
			 * - it is important to monitor the idle time and load balance if the idle time drops
			 *   too low. at the time of this writing, i would say there is no or little harm in
			 *   having one or two "loops" where there's no idle time but it will highly depend on
			 *   the specific application. for really important systems, it might be safest to
			 *   never get lower than some safety margin.
			 */
			rc = Cwsw_EvQX__HandleNextEvent(&tedlos_evqx, 0);
		} while(rc == kErr_EvQ_NoError);
		if( (rc == kErr_EvQ_NoAssociation) || (rc == kErr_EvQ_QueueEmpty) )
		{
			tedlos_idle();
		}
	} while(!quit_requested);
}


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

int
main(void)
{
	tU32 total = 0;
	int idx;
	tCwswClockTics starttic;

	(void)Init(Cwsw_Lib);
	(void)Init(Cwsw_EvQ);

	tedlos__init();
	starttic = Cwsw_ClockSvc__TimerTic();
	tedlos__do();

	for(idx = TABLE_SIZE(countbins); idx--;)
	{
		total += countbins[idx];
	}

	printf("\n\nActual 32-ms running avg:\t%li\nrunning avg:\t%i\n", total / TABLE_SIZE(countbins), countavg);
	printf("Task Chunkiness: %li\n", Cwsw_ClockSvc__GetMaxMissedTics());
	printf("\nProgress Bar: %s\n", progressbar);
	printf("\nDuration: %li ms\n", Cwsw_ClockSvc__TimerTic() - starttic);
	puts("\nGoodbye\n");

    return (EXIT_SUCCESS);
}
