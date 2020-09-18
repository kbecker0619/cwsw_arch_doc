/** @file
 *	@brief	Substitute header for VS, LW-CVI environments.
 *
 *	Description:
 *	This file is NOT intended to provide fully tested ANSI definitions of the boolean integer
 *	type; rather, it is here to supply "good enough" definitions of C99 types for the two
 *	environments I use that don't know about them natively - namely, Visual Studio 2010, and
 *	LabWindows/CVI v7.1 (both very ancient at the time of this writing).
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Jul 30, 2020
 *	@author Kevin L. Becker
 */

#pragma once

#ifndef STDBOOL_H
#define STDBOOL_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

#define false	0
#define true	1


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

typedef char bool;


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


#ifdef	__cplusplus
}
#endif

#endif /* STDBOOL_H */
