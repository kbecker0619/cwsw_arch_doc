/** @file ManagedAlarms.h
 *	@brief	Project-specific configuration to specify which alarms will be managed by TEDLOS.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Apr 14, 2020
 *	Author: kevin
 */

#ifndef APP_CFG_MANAGEDALARMS_H_
#define APP_CFG_MANAGEDALARMS_H_

#ifdef	__cplusplus
extern "C" {
#endif

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_swtimer.h"

// ----	Module Headers --------------------------


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

extern tCwswSwAlarm	tmrOs10ms;
extern tCwswSwAlarm	tmrOs1000ms;


/**	List of alarms managed by the OS timer tic task.
 *
 * 	All alarms listed here, must be of type `tCwswSwAlarm`.
 *	The order in which alarm names are listed here, is the order in which they will be processed.
 *	This allows a manner of assigning priority, by placing more important alarms higher in the list.
 *	PLEASE RESPECT RMS SCHEDULING (fastest repetition rate == highest priority).
 *	Single-shot alarms should (generally) be at the end of the list.
 *
 *	Reminder: This list is not a "closed" list, meaning that this list is not all-inclusive of all
 *	alarms to be found in the system. This list only identifies the alarms that are managed by the
 *	default timer tic callback.
 */
#define ListOfManagedAlarms		\
	/* **** DO NOT EDIT THIS DEFINITION ABOVE THIS LINE **** */	\
	  &tmrOs10ms	\
	, &tmrOs1000ms	\
	/* **** DO NOT EDIT THIS DEFINITION BELOW THIS LINE **** */	\
	/* end of list */


#ifdef	__cplusplus
}
#endif

#endif /* APP_CFG_MANAGEDALARMS_H_ */
