/** @file
 *	@brief	Implementation of the CWSW State Machine Engine.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created: sometime in 2015.
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------
#include "cwsw_sm_engine.h"


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

/** Given a control table, return the current row (i.e., info for the current state).
 */
static sme_state_table_t *
get_current_state_info(sme_sm_descriptor_t * const pSmCtrl)
{
	if(!pSmCtrl)				return NULL;	// SME_BAD_DESCRIPTOR_REFERENCE;
	if(!pSmCtrl->pStateTable)	return NULL;	// SME_BAD_STATE_TABLE;

    /* A quick word about the indexing math in this statement.
     * Because all of our states are base-1 (SME_STATE_NONE is 0), but the state
     * machine tables are base-0, we must compensate before we call the state's
     * entry function. But, just in case someone did their own compensation for,
     * floor the index value at 0. (By the way, we know the MAX works because we
     * know the index is signed, and we know the state-table indexes are signed,
     * because they're either enumerated values, or simple defines.
     */
	return &pSmCtrl->pStateTable[ MAX(pSmCtrl->stCurrent - 1, 0) ];
}

/** Return the current state's handler.
 */
static pStateHandler_t
get_current_state_handler(sme_sm_descriptor_t * const pSmCtrl)
{
	pStateHandler_t		pf;

	if(!pSmCtrl)				return NULL;	// SME_BAD_DESCRIPTOR_REFERENCE;
	if(!pSmCtrl->pStateTable)	return NULL;	// SME_BAD_STATE_TABLE;

	pf = get_current_state_info(pSmCtrl)->StateHandler;
	return pf;
}

static void
exec_entry_actions(sme_state_table_t * const current_state_info)
{
	if(!current_state_info)	return;
	if(current_state_info->StateHandler)
	{
		(void)current_state_info->StateHandler(SME_EVENT_EXEC_ENTRY_ACTION);
	}
	else
	{
		volatile bool breakpt = false;	// developer has specified a terminal pseudo-state
		breakpt ^= 1;
	}

#if 0
	if(current_state_info->pSubSM)
	{
		sme_sm_descriptor_t **tbl_subsm = current_state_info->pSubSM;
		size_t idx_subsm;

		/* @todo Because we do not support concurrent regions as such, we need a way to descend into
		 * nested SMs only if they're active. Perhaps one way would be to move this into a 2-element
		 * struct, with one field being an 'enabled' flag.  This would have the side benefit of
		 * implementing concurrent regions 'by accident', or along for the ride; the down side is
		 * that somebody will need manage this extra bit of complexity.
		 */
		for(idx_subsm = 0; tbl_subsm[idx_subsm]; idx_subsm++)
		{
			sme_state_table_t *subsm_current_state_info = get_current_state_info(tbl_subsm[idx_subsm]);
			exec_entry_actions(subsm_current_state_info);
		}
	}
#endif
}


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

/** Initialize a State Machine.
 *  @param [in] pSmCtrl	Reference to the state machine's control structure.
 */
sme_error_t
sme_Init(sme_sm_descriptor_t * const pSmCtrl)
{
	pStateHandler_t pEntryStateHandler;
	sme_error_t err;

	if(!pSmCtrl)				{ return kErr_EvQ_BadParm; }

	/* initialize the event queue */
	err							= Cwsw_EvQ__FlushEvents(pSmCtrl->pEventQueue);
	if(err)						{ return err; }

	if(!pSmCtrl->pStateTable)	return kErr_EvQ_BadTable;	// should be SME_BAD_STATE_TABLE?

	pSmCtrl->stPrevious			= SME_STATE_NONE;
	pSmCtrl->stCurrent			= SME_STATE_INITIAL;
	pSmCtrl->evPrevious			= SME_EVENT_NONE;

	pEntryStateHandler			= get_current_state_handler(pSmCtrl);
	if(!pEntryStateHandler)		return kErr_EvQ_NoAssociation;

	(void)pEntryStateHandler(SME_EVENT_EXEC_ENTRY_ACTION);

	return						kErr_EvQ_NoError;
}


