/** @file
 *	@brief	Configuration options for the BSP Button handler.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Sep 15, 2020
 *	Author: kevin
 */

#ifndef CWSW_BSP_BUTTONS_CFG_H
#define CWSW_BSP_BUTTONS_CFG_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
// in this project, the button events are defined in the overall project event list.
//	the events named below, are initialized from that global list.
#include "tedlosevents.h"

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

/// Button events.
enum {
	/// Button release. In this implementation, equivalent to a Commit event.
	evBntPressed = evButton_BtnPressed,

	/// Button pressed / activated event.
	evBtnReleased = evButton_BtnReleased,
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

// ---- Targets for Get/Set APIs -------------------------------------------- {
/** Target 1 for TM(tmr) */
#define GET_tmrdebounce()	Cwsw_GetTimeLeft(tmrdebounce)	/* timer local to one SM state */
#define GET_tmrPressed()	Cwsw_GetTimeLeft(tmrPressed)	/* timer local to one SM state */

// ---- /Targets for Get/Set APIs ------------------------------------------- }


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_BSP_BUTTONS_CFG_H */
