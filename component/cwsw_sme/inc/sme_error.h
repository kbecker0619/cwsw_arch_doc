/**
 * @file
 * Error codes for the State Machine Engine.
 *
 * $Revision: $
 *
 *  Copyright (c) 2015 Kevin Becker. All rights reserved.
 */

#ifndef CWSW_SME_ERROR_H
#define CWSW_SME_ERROR_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_evqueue_ex.h"	/* this SME is built on top of the CWSW Event Queue. */

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif

/** Error codes that apply to the whole of the State Machine Engine.
 * 	They are defined here (in this separate header), because both the SME Event
 * 	Queue object, as well as the SME object itself, return all, or a subset, of
 * 	these errors.
 */
typedef tErrorCodes_EvQ sme_error_t;

#ifdef	__cplusplus
}
#endif

#endif /* CWSW_SME_ERROR_H */
