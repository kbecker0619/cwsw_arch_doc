/** @file
 *	@brief	Application-level button handler.
 *
 *	Description:
 *	This component knows the high-level details of the buttons available on the board, and it knows
 *	how the functionality of those buttons is mapped to this application.
 *
 *	If an AUTOSAR SWC, this would be roughly equivalent to a button sensor component.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jul 10, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "tedlos.h"			// access to OS event queue + list of events
#include "cwsw_board.h"

// ----	Module Headers --------------------------
#include "app-di-buttons.h"


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

// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

// we want to intercept button events. set those up here.
uint16_t buttons__Init(void)
{
	tErrorCodes_EvQ err = 0;
	struct {
		tEvQ_EventID		evId;
		ptEvQ_EvHandlerFunc	pfHandler;
	} tblAssoc[] = {
		{ evButton_BtnPressed,	AppButtonPress },
		{ evButton_BtnReleased,	AppButtonCommit },
		{ evButton_BtnStuck,	AppButtonStuck },
		{ evButton_BtnUnstuck,	AppButtonUnstuck },
	};
	uint32_t idx = TABLE_SIZE(tblAssoc);

	while(!err && idx--)
	{
		err = Cwsw_EvQX__SetEvHandler(&tedlos_evqx, tblAssoc[idx].evId, tblAssoc[idx].pfHandler);
	}

	return err;
}


/** Event handler for a button press.
 *	This is not designed to run inside of a task - it responds directly to the button-press event.
 */
void
AppButtonPress(tEvQ_Event ev, uint32_t extra)
{
	// in this app, we take no real action on a button press.
	//	while there is a configurable BSP-level configuration for stuck hardware, there should
	//	probably be an app-level stuck-button timeout that is situation-specific, and an
	//	accompanying reaction (which should include notifying the BSP, via an event, that we want to
	//	invoke stuck-button behavior).
	(void)printf("Button Pressed: Event: %i, Button: %i, Extra: %i\n", ev.evId, ev.evData, extra);
}


// in this app, we equate the release event with the commit event.
void
AppButtonCommit(tEvQ_Event ev, uint32_t extra)
{
	(void)printf("Button Commit: Event: %i, Button: %i, Extra: %i\n", ev.evId, ev.evData, extra);
	switch(ev.evData)
	{
	case kBoardButton1:		// Pause button pushed and committed.
		puts("Emitting Pause event");
		Cwsw_EvQX__PostEventId(&tedlos_evqx, evStopLite_Pause);
		break;

	case kBoardButton3:
		puts("Emitting Go To Yellow event");
		Cwsw_EvQX__PostEventId(&tedlos_evqx, evStoplite_ForceYellow);
		break;

	//evButton_StopTask

	default:
		break;
	}
}


// at the moment, this is the event handler for a stuck button as detected by the board.
void
AppButtonStuck(tEvQ_Event ev, uint32_t extra)
{
	(void)printf("BUTTON STUCK: Event: %i, Button: %i, Extra: %i\n", ev.evId, ev.evData, extra);
}


// respond to a button-unstuck event as detected by the board.
void
AppButtonUnstuck(tEvQ_Event ev, uint32_t extra)
{
	(void)printf("Button Unstuck: Event: %i, Button: %i, Extra: %i\n", ev.evId, ev.evData, extra);
}
