/** @file cwsw_sme_transition.c
 *	@brief	One-sentence short description of file.
 *
 *	Description:
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jun 28, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------
#include "cwsw_sme.h"


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

/** Search for the next state.
 *	If found, execute transition function, if any specified.
 */
pfStateHandler
Cwsw_Sme_FindNextState(
	ptTransitionTable	pTblTransition,		// 1st row of transition table
	uint32_t			szTblTransition,	// size in rows of transition table
	pfStateHandler		currentstate,
	tEvQ_Event			ev, 				// 1st two exit reasons
	uint32_t 			extra)				// 3rd exit reason
{
	pfStateHandler nextstate = currentstate;
	uint32_t tblidx = szTblTransition;
	while(tblidx--)
	{
		if(pTblTransition[tblidx].pfCurrent == currentstate)
		{
			if(pTblTransition[tblidx].reason1 == ev.evId)
			{
				if(pTblTransition[tblidx].reason2 == ev.evData)
				{
					if(pTblTransition[tblidx].reason3 == extra)
					{
						nextstate = pTblTransition[tblidx].pfNext;
						if(pTblTransition[tblidx].pfTransition)
						{
							pTblTransition[tblidx].pfTransition(ev, extra);
						}
						break;
					}
				}
			}
		}
	}

	return nextstate;
}
