/** @file
 *	@brief	One-sentence short description of file.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Jul 10, 2020
 *	@author Kevin L. Becker
 */

#ifndef APP_STOPLITE_H
#define APP_STOPLITE_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_sme.h"

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

extern tCwswSwAlarm	StopLite_tmr_SME;


// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

extern uint16_t Stoplite__Init(void);

///	SMEs for the demo app, a single-sided stop lamp.
/// Recall, all SMEs are normal event handlers, intended to be called in reaction to the posting of
/// a timer maturation.
extern void Stoplite_tsk_StopliteSme(tEvQ_Event ev, uint32_t extra);


#ifdef	__cplusplus
}
#endif

#endif /* APP_STOPLITE_H */
