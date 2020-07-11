/** @file
 *	@brief	Stop Light State Machine.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jun 23, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "tedlos.h"				/* event queue used by this SME */

// ----	Module Headers --------------------------
#include "cwsw_sme.h"


// ============================================================================
// ----	Constants and Type Definitions ----------------------------------------
// ============================================================================

/** States for this State Machine. */
typedef enum eSmStates { kStateNone, kStateRed, kStateGreen, kStateYellow } tSmStates;


// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

/* proposed naming policy:
 * for public symbols that need to be public only for OS purposes, the symbol should have a
 * component prefix, followed by an identifier for that object, followed by its purpose. For timers,
 * this might be "StopLite_tmr_SME". The task might be "StopLite_tsk_SME".
 *
 * I have a desire that all timers should be grouped together in the map file when sorted by name,
 * likewise all task functions, but the same sort of list can be had by grepping *_tmr_*.
 */
tCwswSwAlarm	StopLite_tmr_SME = {
	/* .tm			= */tmr20ms,
	/* .reloadtm	= */tmr20ms,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evStoplite_Task,
	/* .tmrstate	= */kTmrState_Enabled
};


// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

// this next variable is a standard part of the template. update it to point to your state timer.
static ptCwswSwAlarm const pMyTimer = &StopLite_tmr_SME;


// ============================================================================
// ----	State Functions -------------------------------------------------------
// ============================================================================

/* the individual states are similar to a normal event handler, but return a value.
 * - each state is responsible for maintaining its own internal state.
 * 	 normally, this means the state must auto-execute its own on-entry action and then transition to
 * 	 normal operation. upon exit (for us, maturation of its internal timer or receipt of a quit
 * 	 event or a go-to-other-color event), it must auto-execute its own at-exit action.
 * - each state knows how to "guard" each transition event.
 * - each state must handle its own internal reactions.
 * 	- in this implementation, all events are associated to the SME at the OS level, and the SME will
 * 	  call the correct state handler with the passed event.
 */
static tStateReturnCodes
StateRed(ptEvQ_Event pev, uint32_t *pextra)
{
	// this var is part of the template and this definition + initialization line should not be touched.
	static tStateReturnCodes statephase = kStateUninit;
	static tCwswClockTics tmrRedState = 0;

	static tEvQ_EventID evId;


	/* this statephase management differs from that of the template version, for the following:
	 * - i prefer to have the default behavior assertively act to keep itself in the same state;
	 *   this would be similar to an "inhibitor" for a state that wants to change;
	 * - it seems simpler to me to adjust the statephase var in only one place, than the multiple
	 *   places where it's done in the template.
	 */
	switch(statephase++)
	{
	case kStateOperational:
		if(pev->evId != evStoplite_Task)
		{
			// event only, no guard, for this transition.
			// update the exit reason1
			evId = pev->evId;
		}
		else if( Cwsw_GetTimeLeft(tmrRedState) > 0 )
		{
			// not all transition inhibitors are actively inhibiting; do the default action here,
			//	including any in-state reactions.
			statephase--;
		}
		break;

	case kStateUninit:	/* on 1st entry, execute on-entry action */
	case kStateFinished:	/* upon return to this state after previous normal exit, execute on-entry action */
	default:			/* for any unexpected value, restart this state. */
		// unilaterally set statephase to normal. this is a nop for the premiere run, but necessary all other use cases
		statephase = kStateOperational;
		/* the on-entry action could be
		 * - a separate function, or as we've done here,
		 * - a list of actions within the case.
		 */
		/* the on-entry behavior does not care about what event was passed to this function;
		 * however, in this implementation, we use the launching event as the default exit reason.
		 */
		/* the on-entry behavior CAN NOT fail. it must be an atomic action that is failsafe; the
		 * purpose is to prepare / initialize the state for normal operation.
		 */
		evId = pev->evId;
		/* start my state timer.
		 * for this implementation, i'm choosing to poll a simple timer in the operational phase.
		 * we could, if we wanted, let an alarm post an event at maturation.
		 */
		/* note: the period of the state alarm, must be larger than the periodicity of the SM engine;
		 * if the timeout of the state alarm is less than the rate at which the SME is called, it
		 * will always mature with every call to the SME.
		 */
		Set(Cwsw_Clock, tmrRedState, tmr1000ms);

		// state-specific behavior
		puts("RED on");
		break;

	case kStateExit:
		/* the at-exit behavior CAN NOT fail. it must be an atomic action that is failsafe. */
		// manage the state machine: set exit reasons (statephase needs to be > exit state, which it already is)
		pev->evId = evId;
		pev->evData = 0;
		*pextra = kStateRed;	// update argument to transition function

		// perform state-specific actions
		/* (no state-specific exit actions here) */
		break;
	}

	// the next line is part of the template and should not be touched.
	return statephase;
}

static tStateReturnCodes
StateGreen(ptEvQ_Event pev, uint32_t *pextra)
{
	static tStateReturnCodes statephase = kStateUninit;
	static tCwswClockTics tmrGreenState = 0;
	static tEvQ_EventID evId;

	switch(statephase++)
	{
	case kStateOperational:
		if(pev->evId != evStoplite_Task)
		{
			// event only, no guard, for this transition.
			// update the exit reason1
			evId = pev->evId;
		}
		else if( Cwsw_GetTimeLeft(tmrGreenState) > 0 )
		{
			statephase--;
		}
		break;

	case kStateUninit:	/* on 1st entry, execute on-entry action */
	case kStateFinished:	/* upon return to this state after previous normal exit, execute on-entry action */
	default:			/* for any unexpected value, restart this state. */
		// generic state management, common to all states
		statephase = kStateOperational;
		evId = pev->evId;
		Set(Cwsw_Clock, tmrGreenState, tmr1000ms);

		// state-specific behavior
		puts("GREEN on");
		break;

	case kStateExit:
		// manage the state machine: set exit reasons
		pev->evId = evId;
		pev->evData = 0;
		*pextra = kStateGreen;	// update transition function, if any

		// state-specific behavior
		/* (no state-specific exit actions here) */
		break;
	}

	// the next line is part of the template and should not be touched.
	return statephase;
}

static tStateReturnCodes
StateYellow(ptEvQ_Event pev, uint32_t *pextra)
{
	static tStateReturnCodes statephase = kStateUninit;
	static tCwswClockTics tmrStateOn = 0;
	static tEvQ_EventID evId;

	switch(statephase++)
	{
	case kStateOperational:
		if(pev->evId != evStoplite_Task)
		{
			// event only, no guard, for this transition.
			// update the exit reason1
			evId = pev->evId;
		}
		else if( Cwsw_GetTimeLeft(tmrStateOn) > 0 )
		{
			statephase--;
		}
		break;

	case kStateUninit:	/* on 1st entry, execute on-entry action */
	case kStateFinished:	/* upon return to this state after previous normal exit, execute on-entry action */
	default:			/* for any unexpected value, restart this state. */
		// generic state management, common to all states
		statephase = kStateOperational;
		evId = pev->evId;
		Set(Cwsw_Clock, tmrStateOn, tmr100ms + tmr100ms);

		// state-specific behavior
		puts("YELLOW on");
		break;

	case kStateExit:
		// manage the state machine: set exit reasons
		pev->evId = evId;
		pev->evData = 0;
		*pextra = kStateYellow;	// update transition function, if any

		// state-specific behavior
		/* (no state-specific exit actions here) */
		break;
	}

	// the next line is part of the template and should not be touched.
	return statephase;
}


// ============================================================================
// ----	Transition Functions --------------------------------------------------
// ============================================================================

/** Transition Function.
 * 	This function turns off the specified light. We want this done in the transition function,
 * 	rather than in the exit action, because some transitions might require either a combination of
 * 	lights, or else, for a reaction that restarts the same state, should leave the light on, and
 * 	we don't want to cause a flicker.
 *
 * 	We see no harm in the entry action turning on its own lamp, even if it's already on, but we
 * 	don't want unnecessary flicker caused when the exit action turns off its lamp, and then turning
 * 	it back on, for example in a return-to-self transition.
 *
 * 	In this case, the state enumeration is also used to specify the light that should be turned off.
 *
 * 	@param [in]	ev		Unused.
 * 	@param [in]	extra	Specifies which lamp to extinguish.
 */
static void
TransitionLampOff(tEvQ_Event ev, uint32_t extra)
{
	UNUSED(ev);
	switch(extra)
	{
	case kStateRed:
		puts("RED off");
		break;

	case kStateGreen:
		puts("GREEN off");
		break;

	case kStateYellow:
		puts("YELLOW off");
		break;

	default:
		puts("Invalid lamp argument");
		break;
	}
}


static tTransitionTable tblTransitions[] = {
	/* note: as this table is laid out, it seems that Reason3 is totally redundant, as the scheduler
	 * can fully decide the next state and even the transition given only the current state and
	 * Reason1. however, remember, the scheduler passes all 3 reasons to the transition function,
	 * and our transition function uses Reason3 to decide which lamp to extinguish.
	 */
	// current			Reason1			Reason2		Reason3		Next State		Transition Func
	// normal exits
	{ StateRed,		evStoplite_Task,		0,	kStateRed,		StateGreen,		TransitionLampOff	},	// normal termination
	{ StateGreen,	evStoplite_Task, 		0,	kStateGreen,	StateYellow,	TransitionLampOff	},	// normal termination
	{ StateYellow,	evStoplite_Task, 		0,	kStateYellow,	StateRed,		TransitionLampOff	},	// normal termination

	// return-to-self transitions, for demonstration purposes only
	{ StateRed,		evStopLite_Reenter,		0,	kStateRed,		StateRed,		NULL				},	// transition to self
	{ StateGreen,	evStopLite_Reenter,		0,	kStateGreen,	StateGreen,		NULL				},	// transition to self
	{ StateYellow,	evStopLite_Reenter,		0,	kStateYellow,	StateYellow,	NULL				},	// transition to self

	// force-to-another-state transitions
	{ StateRed,		evStoplite_ForceYellow,	0,	kStateRed,		StateYellow,	TransitionLampOff	},	// commanded override
	{ StateGreen,	evStoplite_ForceYellow,	0,	kStateGreen,	StateYellow,	TransitionLampOff	},	// commanded override
	{ StateYellow,	evStoplite_ForceYellow,	0,	kStateYellow,	StateYellow,	TransitionLampOff	},	// commanded override

	// e-stop transitions
	{ StateRed,		evStoplite_StopTask,	0,	kStateRed,		NULL,			TransitionLampOff	},
	{ StateGreen,	evStoplite_StopTask,	0,	kStateGreen,	NULL,			TransitionLampOff	},
	{ StateYellow,	evStoplite_StopTask,	0,	kStateYellow,	NULL,			TransitionLampOff	},
};


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

/** This component's State Machine Engine pump.
 * 	the concept this embodies, is that all of the SME tasks are associated at the OS level with
 * 	this function, and within here, we manage the individual states of the state machine.
 */
void
Stoplite_tsk_StopliteSme(tEvQ_Event ev, uint32_t extra)
{
	static pfStateHandler currentstate = StateGreen;
	currentstate = Cwsw_Sme__SME(tblTransitions, TABLE_SIZE(tblTransitions), currentstate, ev, extra);

	if(!currentstate)
	{
		// disable alarm that launches this SME via its event.
		//	if restarted, we'll resume in the current state
		//	need a way to restart w/ the init state.
		pMyTimer->tmrstate = kTmrState_Disabled;
	}
}


uint16_t
Stoplite__Init(void)
{
	tErrorCodes_EvQ err = 0;
	struct {
		tEvQ_EventID		evId;
		ptEvQ_EvHandlerFunc	pfHandler;
	} tblAssoc[] = {
		{ evStopLite_Pause,	Stoplite_tsk_StopliteSme },
	};
	uint32_t idx = TABLE_SIZE(tblAssoc);

	while(!err && idx--)
	{
		err = Cwsw_EvQX__SetEvHandler(&tedlos_evqx, tblAssoc[idx].evId, tblAssoc[idx].pfHandler);
	}

	return err;
}