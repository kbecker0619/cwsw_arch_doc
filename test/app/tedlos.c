/** @file tedlos.c
 *	@brief	The Event-Dispatching Loop OS.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Feb 19, 2020
 *	@author: kbecker
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdbool.h>

// ----	Project Headers -------------------------
#include "cwsw_clock.h"
#include "cwsw_evhandler.h"
#include "cwsw_swtimer.h"

// ----	Module Headers --------------------------
#include "tedlos.h"


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

enum eAppStates {
	// this state machine applies only during the time that the scheduler is active; it does not
	//	track the earlier stages of initialization, nor the states that will take effect after the
	//	scheduler has been stopped.
	kAppState_NoState,
	kAppState_Init,
	kAppState_Normal,
	kAppState_PrepSleep,
	kAppState_Sleep,
	kAppState_Awake,
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

typedef enum eAppStates tAppState;


// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

//! tedlos event queue data
//!  @{
static tEvQ_Event tblEventBuff[kTedlos_EvQueueSize] = {0};		//!< OS event buffer
static tEvQ_EvTable evTbl	= {									//!< OS event table
	/* .pEvBuffer	= */tblEventBuff,
	/* .szEvTbl		= */TABLE_SIZE(tblEventBuff),
	/* .validity	= */kCT_TBL_VALID
};

static tEvHA_EvHandlerAssoc AssocArr[kNumOsEvqEvents] = {0};	//!< OS event handler LUT
static tEvQ_EvHndlrAssocTable tblEvH = {						//!< OS event handler association table
	/* .pEvtHndlrLut	= */AssocArr,
	/* .szEvtHandlerTbl = */TABLE_SIZE(AssocArr),
	/* .validity		= */kCT_TBL_VALID
};

tEvQ_QueueCtrlEx tedlos_evqx = {							//!< OS event queue
	/* .EvQ_Ctrl	= */{
		/* .pEventTable	= */&evTbl,
		/* .Queue_Count	= */0,
		/* .idxWrite	= */0,
		/* .idxRead		= */0
	},
	/* .pEvHndlrs	= */&tblEvH
};
//! @}


tAppState appstate = kAppState_NoState;


// timer objects	{
// application lifecycle timer
//static tCwswClockTics timeleft = 0;
// reload value
enum {app_duration = 5000 };	/* roughly 5 seconds */

//	}

// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

/**	Initialize the tasks from a table of task parameters.
 *	In tedlos, a "task" is nothing more than an alarm w/ an identified maturation handler.
 *	As such, the initialization table passed to this function has that parameters for each alarm,
 *	and the name of the handler.
 *
 *	This function has no special knowledge of the "quit" event; however, the OOTB timer tic handler
 *	does have a clause that looks for the quit event, so the table should have one entry that
 *	correlates the quit event to the os timer tic.
 *
 *	If you want to handle the quit event on your own, you are free to associate it with your own
 *	handler, and as long as it isn't also associated with the OS timer tic handler, you can do what
 *	you want within your handler. Be aware, though, that the OS will not exit its loop and will
 *	keep dispatching events after your handler is called.
 */
void
tedlos__InitTaskList(ptTedlosTaskDescriptor tasktable)	/* note this is a pointer to one row of the table. Termination must be whole row == 0 */
{
	uint32_t tblidx = 0;
	bool termcondition = false;
	if(!tasktable)	{ return; }
	while(!termcondition)
	{
		termcondition = ( (tasktable[tblidx].pAlarm == NULL) &&
						  (tasktable[tblidx].tm_init == 0) &&
						  (tasktable[tblidx].tm_rearm == 0) &&
						  (tasktable[tblidx].pEvqxCtrl == NULL) &&
						  (tasktable[tblidx].evid == evOsNullEvent) &&
						  (tasktable[tblidx].pf == NULL) );
		// for the following initialization calls, we rely on the robustness of the function to
		//	handle invalid parameters.
		(void)Cwsw_SwAlarm__Init( tasktable[tblidx].pAlarm,
								  tasktable[tblidx].tm_init,
								  tasktable[tblidx].tm_rearm,
								  tasktable[tblidx].pEvqxCtrl,
								  tasktable[tblidx].evid );
		(void)Cwsw_EvQX__SetEvHandler( tasktable[tblidx].pEvqxCtrl,
									   (tEvQ_EventID)tasktable[tblidx].evid,
									   tasktable[tblidx].pf );
		Cwsw_SwAlarm__SetState(tasktable[tblidx].pAlarm, kSwTimerEnabled);
		++tblidx;
	}
}


