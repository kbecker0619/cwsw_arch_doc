/** @file
 *  @brief      Public interface to State Machine Engine.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created: sometime in 2015.
 *	Author: kevin
 */

#ifndef CWSW_SM_ENGINE_H
#define CWSW_SM_ENGINE_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_evqueue_ex.h"	/* this SME is built on top of the CWSW Event Queue. */

// ----	Module Headers --------------------------
#include "sme_error.h"
#include "cwsw_sme_prm.h"		/* project-level parameters */


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

/** Special state definition, meaning is 'No State'.
 * 	This special value is used by the SM Engine to designate 'No State' (as in
 * 	there were no active previous states, or there is not a currently-active
 * 	state).
 */
#define	SME_STATE_NONE				(sme_smstate_t)0

/** Special state definition, meaning '1st State in the State Machine.'
 * 	This is a generic definition, and is the state that is made active during
 * 	initialization of the SM.
 */
#define SME_STATE_INITIAL			(sme_smstate_t)1


/** Special event value, meaning is 'No TransitionEvent'.
 * 	All state machines must have their 1st event in their defined list of events
 * 	defined as this value. It is reserved by the SM Engine.
 */
#define	SME_EVENT_NONE      	(sme_event_t)0


/** Special event value, with dual meaning.
 * 	When returned by SME functions that are typed to return an event, in the case
 * 	they cannot succeed in their operation, the meaning is "Unable to comply."
 *
 *  When passed to a state handler, it means, "Execute exit action."
 */
#define SME_EVENT_BAD_EVENT		(~SME_EVENT_NONE)


/**	Generic event, by convention meaning is 'Execute Entry Action'.
 * 	This is used by the SM Engine to force the state to execute the entry
 * 	action, /PROVIDED/ support code is present in the state itself. See example
 * 	code. Technically, this event is optional, but when the SM Engine calls your
 * 	state handler due to a transition, it will pass this value in the event
 * 	parameter. You do with it what you want.
 */
#define SME_EVENT_EXEC_ENTRY_ACTION	(sme_event_t)STATE_PHASE_ENTER


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

/** The type of event used by the SME, is the type of a CWSW Event Queue event. */
typedef tEvQ_EventID sme_event_t;

/** State Handler type.
 *  In this design, each state is responsible for managing its own life cycle;
 *  the 1st time it is called, it needs to execute its entry action (if such is
 *  needed), and once the decision is made to leave, it needs to execute any
 *  appropriate exit actions. See the example for our suggestion as to how to do
 *  this.
 *
 *  Because the only "legal" way to leave a state is in reaction to a received
 *  event, and because the SM Engine handles these transitions, each state must
 *  be prepared at any time to have its exit action called.
 *
 *  @param [in] ev	If an event did not provoke a transition, it is passed to
 *  the state handler. If the handler consumes the event, it should return a
 *  true value; if the handler does not handle the event, it should return a
 *  false.
 *
 *  @returns true if the handler consumed the event passed to it, else false.
 */
typedef bool (*pStateHandler_t)(sme_event_t ev);
#define SME_NULL_STATE_HANDLER		(pStateHandler_t)0



/// @{

/** Prototype for Guard Functions.
 *	In the UML, each transition can be provoked by an event, or a condition;
 *	the event can be guarded by a condition (aka a Boolean test). Notation is
 * 		"event[GUARD_CONDITION]/transition_action"
 * 	I believe that guards have access to the state's internal variables.
 *
 * 	In this incarnation of the SM Engine, guards are not run within the context
 * 	of the state object, and therefore do not have access to the state's
 * 	internal variables. Our guards are implemented as a function that returns a
 * 	boolean; an individual state can have one and only one guard function. the
 * 	guard takes no arguments.
 *
 * 	In our system, the guard function is executed after an eligible transition
 * 	event is selected.
 *
 * @returns Boolean, where #false prohibits a transition and #true allows the
 * transition.
 */
typedef bool (*sme_guard_t)(void);

/**	Transition Action type.
 */
typedef void (*pTransitionAction_t)(void);

/** One row of the State events table.
 * 	This struct is designed to associate one event with an optional guard and an
 * 	optional transition action. Complex guard conditions will need to be
 * 	combined into one function.
 *
 * 	This struct is not really intended to be used all by itself; it is intended
 * 	to be one row in a table of transition descriptors.
 *
 * 	Within UML, the guards are in the same context as the state object, and as
 * 	such, have access to the state's internal variables. In this design, that
 * 	same context does not exist; so be aware of this.
 */
typedef const struct
{
	sme_event_t			TransitionEvent;	/**< event that provokes a transition. */
	sme_guard_t			Guard;				/**< Guard evaluator. Because we aren't doing the full UML treatment, where a guard
	 	 	 	 	 	 	 	 	 	 	 *   can be almost anything, we will provide access to a function that can stand in
	 	 	 	 	 	 	 	 	 	 	 *   for full UML treatment.
	 	 	 	 	 	 	 	 	 	 	 */
	pTransitionAction_t TransitionAction;	/**< Transition action. */
	sme_smstate_t		NewState;			/**< provided event and guard qualifications pass, the state to which we will transition. */
} sme_state_event_t;
#define SME_NULL_STATE_EXIT_EVENTS_TBL	(sme_state_event_t *)0

/** One row of the State Table. */
typedef const struct
{
	sme_smstate_t		Name;				/**< State name. Used only for help/assistance when creating the state table. */
	pStateHandler_t		StateHandler;		/**< Handler function. Note an internal reaction can provoke a state change. */
	sme_state_event_t   *Events;			/**< Reference to an array of events for this state. */
//	sme_sm_descriptor_t	**pSubSM;			/**< A table of optional sub-SMs. Required for hierarchical implementations. @note The final row in this table \b MUST \b be filled with NULLs! */
} sme_state_table_t;


/** State Machine Descriptor.
 * 	This describes the entire state machine.
 */
struct sme_sm_descriptor_s
{
	sme_state_table_t	*pStateTable;		/**< Reference to this SM's state table. */
	sme_smstate_t		stPrevious;			/**< Previous state. This is not used by the SM Engine
											 *	itself, but can be very useful when debugging, to
											 *	answer the question, "How did I get here?"
											 */
	sme_smstate_t		stCurrent;			/**< Current state. */
	ptEvQ_QueueCtrl		pEventQueue;		/**< This SM's event queue. */
	sme_event_t			evPrevious;			/**< Previous event. As with stPrevious, this is
											 *	primarily meant for debugging.
											 */
//	state_timer_t		*pStateTimers;		/**< Reference to the table of timers for this SM.
//											 *	These are not used by the SM Engine itself, but the
//											 *	example code shows how to put code in the entry and
//											 *	do actions to start the state's timer and detect a
//											 *	timeout.
//											 */
//	pExceptionHandler_t	pExceptionHandler;
};
typedef struct sme_sm_descriptor_s sme_sm_descriptor_t;
#define SME_NULL_DESCRIPTOR     (sme_sm_descriptor_t *)0
#define SME_NULL_DESCRIPTOR_TBL (sme_sm_descriptor_t **)0


/** Phases available in the life span of a state.
 * 	Each state needs to have its own private, static variable of this type, plus supporting code in
 *	the internal state switch statement.
 *
 * @note: this typedef is required by all modules that implement a state
 * machine, but is not useful for any external entity; in fact, there is no way
 * to query a state for its internal phase.
 */
typedef enum {
	STATE_PHASE_UNINIT,						/**< Uninitialized state. Guards the low end. */
	STATE_PHASE_ENTER,						/**< 'enter' action */
	STATE_PHASE_DO,
	STATE_PHASE_EXIT,
	STATE_PHASE_ILLEGAL,					/**< Another guard, not strictly necessary, this one on the high end. */
	STATE_NUM_PHASES
} sme_state_phases_t;

/** Method to set the state's phase based on the event passed in.
 */
#define STATE_SET_STATE_PHASE(ev)	\
	( (ev == SME_EVENT_EXEC_ENTRY_ACTION) ? STATE_PHASE_ENTER :	\
	  (ev == SME_EVENT_BAD_EVENT) ? STATE_PHASE_EXIT : STATE_PHASE_DO )




















/// @}


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_SM_ENGINE_H */
