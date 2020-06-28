/** @file
 *	@brief	Implementation of a very simple event dispatcher.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Jun 18, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdbool.h>		/* true */

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------
#include "tedlos.h"
#include "ManagedAlarms.h"
#include "tedlosevents.h"


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

static bool initialized = false;

/** How much headroom does system have?
 * 	This counter holds an instantaneous count, last timer tic to this timer tic
 */
static uint32_t idlecounts = 0;
/** Maximum idle time seen. */
static uint32_t maxcounts = 0;
/** Running average headroom. Calculated without binning a sampling of idle counts. */
static uint32_t ctIdleRunningAvg = 0;

/** Running count of last <n> idle counts. Used for sample-based averaging.
 * 	@{
 */
static uint32_t IdleCountBins[32] = {0};
static uint32_t IdleCountBinIdx = 0;
/** @} */


static ptCwswSwAlarm ManagedAlarms[] = { ListOfManagedAlarms };

static bool quit_requested = false;


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

void
tedlos_idle(void)
{
	++idlecounts;
}


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

/**	Set up the scheduler.
 *	This function ONLY sets up the scheduler itself; tasks must be set up independently.
 *	It uses hard-wired names for the event queue (#tedlos_evqx), timer tic task (#OsTimerTic),
 *	and the timer tic event (#evOs_TmrHeartbeat).
 */
void
tedlos__Init(void)
{
	tErrorCodes_EvQ err;

	// initialize clock services.
	//	since at present, clk-srv only understands one base-rate event, we'll associate it with
	//	tedlos' own private queue.
	Cwsw_ClockSvc__Init(&tedlos_evqx, evOs_TmrHeartbeat);

	// now set the event handler for the heartbeat event
	err = Cwsw_EvQX__SetEvHandler(&tedlos_evqx, evOs_TmrHeartbeat, OsTimerTic);
	cwsw_assert(!err, "Unexpected set handler problem");
	initialized = true;
}


/**	TEDLOS scheduler.
 *	Don't give me no crap about this not being a real scheduler. i know that. i envision this
 *	evolving into something more than it is now, but for now, it's an event dispatcher.
 *
 */
void
tedlos__do(ptEvQ_QueueCtrlEx tedlos_evqx)
{
	if(1)
	{
		gtk_main();
	}
	else
	{
		tErrorCodes_EvQ rc;
		// this loop is executed as quickly as possible
		do {
			/* posting vs dispatching:
			 * the clock service task will post (at most) one event each time called.
			 * this will cause the OS' tic handler to be called; inside that function, there will be an
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
				rc = Cwsw_EvQX__HandleNextEvent(tedlos_evqx, 0);
			} while(0 != tedlos_evqx->EvQ_Ctrl.Queue_Count);
			if( (rc == kErr_EvQ_NoAssociation) || (rc == kErr_EvQ_QueueEmpty) )
			{
				tedlos_idle();
			}
		} while(!quit_requested);
	}
}


void
tedlos_get_idle_stats(uint32_t *counted_avg, uint32_t *running_avg)
{
	uint32_t idx;
	uint32_t total = 0;
	idx = TABLE_SIZE(IdleCountBins);
	while(idx--)
	{
		total += IdleCountBins[idx];
	}
	*counted_avg = total / TABLE_SIZE(IdleCountBins);
	*running_avg = ctIdleRunningAvg;
}


/**	Default OS timer tic handler.
 * 	This function is not a part of the normal suite of OS-managed alarms; it is the handler for
 * 	the Clock Services timer task.
 *
 *	Note that you are free to supply your own timer tic event; you'll need to replace this file so
 *	as to avoid name clashes, or else re-associate the Clock Services timer task to your function.
 *
 *	@param [in]	ev		Passed by event dispatcher.
 *	@param [in]	extra	Passed by event dispatcher. In the default configuration, this value is
 *						supplied by the scheduler (#tedlos__do()), and is always 0.
 */
void
OsTimerTic(tEvQ_Event ev, uint32_t extra)
{
	uint32_t tmridx;
	UNUSED(extra);

	// manage SW timers
	for(tmridx = 0; tmridx < TABLE_SIZE(ManagedAlarms); tmridx++)
	{
		Cwsw_SwAlarm__ManageTimer(ManagedAlarms[tmridx]);
	}

	do {	// save idle count data
		// method 1: sample-based metrics, most recent 32 samples
		IdleCountBins[IdleCountBinIdx++] = idlecounts;
		if(idlecounts > maxcounts)							{ maxcounts = idlecounts; }
		if(IdleCountBinIdx >= TABLE_SIZE(IdleCountBins))	{ IdleCountBinIdx = 0; }

		// method 2: running average
		if(!ctIdleRunningAvg)								{ ctIdleRunningAvg = idlecounts; }
		ctIdleRunningAvg -= (uint32_t)(ctIdleRunningAvg / TO_U32(TABLE_SIZE(IdleCountBins)));
		ctIdleRunningAvg += (uint32_t)(idlecounts / TO_U32(TABLE_SIZE(IdleCountBins)));

		// reset idle counter for next iteration
		idlecounts = 0;
	} while(0);

	do {	// temporary, metric-related, so i can set breakpoints
		if(ev.evId == evOs_QuitRqst)		{ quit_requested = true; }
	} while(0);
}
