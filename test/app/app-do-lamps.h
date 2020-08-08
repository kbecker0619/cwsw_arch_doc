/** @file
 *	@brief	API for the Application-layer "Actuator" component.
 *
 *	Description:
 *	General approach:
 *	- The targets for the `SET(Symbol, value)` are intended to be quick-in-and-out, and run within
 *	  the context of the calling code. That API simply sets flags to work on later.
 *	- This component needs to be called regularly to effect the outputs written by the `SET()` API.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Jul 11, 2020
 *	@author Kevin L. Becker
 */

#ifndef APP_DO_LAMPS_H
#define APP_DO_LAMPS_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdbool.h>

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

extern uint16_t AppDO__Init(void);
extern void AppDO__Task(void);

enum { AppDO };


/** Target for `SET(Lamp, on_off)`
 *	@{
 */
extern void SET_LampRed(tOnOffLogical value);
extern void SET_LampYellow(tOnOffLogical value);
extern void SET_LampGreen(tOnOffLogical value);
extern void SET_LampWalk(tOnOffLogical value);
/** @} */

#ifdef	__cplusplus
}
#endif

#endif /* APP_DO_LAMPS_H */
