/** @file stdint.h
 *	@brief	Substitute header for VS, LW-CVI environments.
 *
 *	Description:
 *	This file is NOT intended to provide fully tested ANSI definitions of the standard integer
 *	types; rather, it is here to supply "good enough" definitions of C99 integer types for the two
 *	environments I use that don't know about them natively - namely, Visual Studio 2010, and
 *	LabWindows/CVI v7.1 (both very ancient at the time of this writing).
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jul 30, 2020
 *	Author: kevin
 */

#ifndef STDINT_H
#define STDINT_H

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

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

typedef unsigned char	uint8_t;

typedef   signed short  int16_t;
typedef unsigned short	uint16_t;

typedef   signed long	int32_t;
typedef unsigned long	uint32_t;


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


#ifdef	__cplusplus
}
#endif

#endif /* STDINT_H */
