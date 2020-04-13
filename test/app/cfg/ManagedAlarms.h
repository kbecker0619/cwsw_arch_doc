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

// ----	Module Headers --------------------------


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// list of alarms managed by the OS timer tic task
// must be of type `tCwswSwAlarm`
// name must be this
// must not touch 1st or last lines
// order listed here, is the order in which they will be processed. this allows a manner of
//	assigning priority, by placing more important alarms higher in the list. PLEASE RESPECT RMS
//	SCHEDULING (fastest repetition rate == highest priority). single-shot alarms should (generally)
//	be at the end of the list.
#define ListOfManagedAlarms		{	\
	  &tmrOs10ms	\
	, &tmrOs1000ms	\
}


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


#ifdef	__cplusplus
}
#endif

#endif /* APP_CFG_MANAGEDALARMS_H_ */
