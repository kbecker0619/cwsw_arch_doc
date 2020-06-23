/** @file
 *	@brief	Project-level parameters for the CWSW State Machine Engine.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jun 22, 2020
 *	Author: kevin
 */

#ifndef CWSW_SME_PRM_H
#define CWSW_SME_PRM_H

#ifdef	__cplusplus
extern "C" {
#endif

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdint.h>			/* uint8_t */
#include <stdbool.h>		/* bool */

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

/** State type.
 * 	In this implementation of the SM Engine, each state has an ID that must be
 * 	unique within the context in which that SM is used. We think that most
 * 	systems will have fewer than 255 individual states that are visible to each
 * 	other within the same context, but this is in the parameter file because it
 * 	could change for a specific project.
 *
 *	Note the generic type is owned by the SM Engine; however, the actual states
 *	are in the context of the project-level SM. The Engine's idea of a "state"
 *	must by definition (in 'C', anyway) be generic, and the SM's definition
 *	of its member states must be compatible with the generic type used
 *	here.
 */
typedef uint8_t sme_smstate_t;


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_SME_PRM_H */
