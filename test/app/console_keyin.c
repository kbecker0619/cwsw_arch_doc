/** @file console_keyin.c
 *	@brief	One-sentence short description of file.
 *
 *	Description:
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jun 24, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdint.h>				/* std int types */
#include <stdbool.h>			/* type bool */
#include <conio.h>				/* kbhit() */

// ----	Project Headers -------------------------
#include "cwsw_evqueue_ex.h"	/*  our task is driven by an alarm-driven task */
#include "tedlos.h"				/* event queue used by this SME */

// ----	Module Headers --------------------------
#include "console_keyin.h"


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

enum { evButtonReadingTask = evButton_Task };


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

tCwswSwAlarm	Btn_tmr_ButtonRead = {
	/* .tm			= */tmr10ms,
	/* .reloadtm	= */tmr10ms,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evButton_Task,
	/* .tmrstate	= */kTmrState_Enabled
};


// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

static bool buttonstate[8] = {0};
static uint8_t btndebounce = 0;


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

void
Btn_tsk_ButtonRead(tEvQ_Event ev, uint32_t extra)	// uses DI lower layers
{
	uint8_t laststate = btndebounce;
	static uint8_t lastbutton = 0;		// remember which was the last button pressed, so we can

	UNUSED(ev);
	UNUSED(extra);
	UNUSED(laststate);	// debugging only
	UNUSED(lastbutton);	// debugging only

	bool hit = (kbhit() != 0);
	if(hit)
	{
		lastbutton ^= 0xFF ^ 0xFF;
	}
	btndebounce = TO_U8(btndebounce * 2U);							// shift the oldest sample off the edge of the cliff
	btndebounce = TO_U8(btndebounce | hit);							// add in the new sample
	if((btndebounce != 0xFF) && (btndebounce != 0x00))	{ return; }	// debounced sample not available.
	if(laststate == btndebounce)						{ return; }	// no change, so no possibility of change event

	// at this point, we know we have a qualified change of state. Act on that, including finish w/ button event
	if(btndebounce)
	{
//		// for dos, now that we have a debounced sample, read the key
//		int key = getch();		// clear the pending character
//		if( (key < '1') || (key > '8') )				{ return; }	// not a recognized key
//		key -= '1';		// convert to numeric key value [0..7]
//		if( buttonstate[key] == true)					{ return; }	// same key pressed, didn't catch key-up event, but no change from current status, so no change event
//
//		lastbutton = TO_U8(key);									// save key so we can recognize key-up event
//		buttonstate[key] = true;
//		ev.evId = evButton_BtnPressed;
//		ev.evData = TO_U32(key);
//	}
//	else
//	{
//		// since we're tracking the "release" of a button that doesn't really have a release event at this level,
//		//	there's much less housekeeping to do.
//		buttonstate[lastbutton] = false;
//		ev.evId = evButton_BtnReleased;
//		ev.evData = lastbutton;
	}
//	(void)Cwsw_EvQX__PostEvent(&tedlos_evqx, ev);				// don't care about return code, won't change my behavior anyway
}
