/** @file
 *	@brief	Application-layer "Actuator" component.
 *
 *	Description:
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jul 11, 2020
 *	Author: kevin
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdint.h>		// standard integral types
#include <stdio.h>		// printf

// ----	Project Headers -------------------------
#include "cwsw_board.h"

// ----	Module Headers --------------------------
#include "app-do-lamps.h"


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

enum eDoBitAssignments {
	kDoGreen, kDoYellow, kDoRed, kDoWalk,
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

static uint32_t do_map = 0, do_last_map = 0;


// ============================================================================
// ----	Private Functions -----------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

uint16_t
AppDO__Init(void)
{
	// set up timers
	// set up event handlers
	do_map = do_last_map = 0;
	return 0;
}

void
AppDO__Task(void)
{
	// not clear yet that an event needs to be posted. if one is needed, then probably the right
	//	place to do that is in the SET() API.
	if(do_map != do_last_map)
	{
		if(BIT_TEST(do_map, kDoGreen) != BIT_TEST(do_last_map, kDoGreen))
		{
			Set(Cwsw_Board, kBoardLed1, BIT_TEST(do_map, kDoGreen));
		}
		if(BIT_TEST(do_map, kDoYellow) != BIT_TEST(do_last_map, kDoYellow))
		{
			Set(Cwsw_Board, kBoardLed2, BIT_TEST(do_map, kDoYellow));
		}
		if(BIT_TEST(do_map, kDoRed) != BIT_TEST(do_last_map, kDoRed))
		{
			Set(Cwsw_Board, kBoardLed3, BIT_TEST(do_map, kDoRed));
		}
		if(BIT_TEST(do_map, kDoWalk) != BIT_TEST(do_last_map, kDoWalk))
		{
			Set(Cwsw_Board, kBoardLed4, BIT_TEST(do_map, kDoWalk));
		}

		do_last_map = do_map;
	}
}


void
SET_LampGreen(tOnOffLogical value)
{
	value = !!value;	// normalize on chance value is not a member of enumeration
	printf("Green %s\t", value ? "On" : "Off");
	if(value)	{ BIT_SET(do_map, kDoGreen); }
	else		{ BIT_CLR(do_map, kDoGreen); }
}

void
SET_LampYellow(tOnOffLogical value)
{
	value = !!value;	// normalize on chance value is not a member of enumeration
	printf("Yellow %s\t", value ? "On" : "Off");
	if(value)	{ BIT_SET(do_map, kDoYellow); }
	else		{ BIT_CLR(do_map, kDoYellow); }
}

void
SET_LampRed(tOnOffLogical value)
{
	value = !!value;	// normalize on chance value is not a member of enumeration
	printf("Red %s\t", value ? "On" : "Off");
	if(value)	{ BIT_SET(do_map, kDoRed); }
	else		{ BIT_CLR(do_map, kDoRed); }
}

void
SET_LampWalk(tOnOffLogical value)
{
	value = !!value;	// normalize on chance value is not a member of enumeration
	printf("Walk %s\t", value ? "On" : "Off");
	if(value)	{ BIT_SET(do_map, kDoWalk); }
	else		{ BIT_CLR(do_map, kDoWalk); }
}

