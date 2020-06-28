/** @file bd_gtk.h
 *	@brief	One-sentence short description of file.
 *
 *	Description:
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jun 26, 2020
 *	Author: kevin
 */

#ifndef COMPONENT_BOARD_BD_GTK_BD_GTK_H_
#define COMPONENT_BOARD_BD_GTK_BD_GTK_H_

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdint.h>			/* uint16_t */

// ----	Project Headers -------------------------
#include "tedlos.h"

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

extern tCwswSwAlarm	Btn_tmr_ButtonRead;


// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

// ---- Discrete Functions -------------------------------------------------- {
extern uint16_t	bd_gtk__Init(void);
extern void		BdGtk_tsk_ReadButtons(tEvQ_Event ev, uint32_t extra);


// ---- /Discrete Functions ------------------------------------------------- }

// ---- Targets for Get/Set APIs -------------------------------------------- {

/** "Chapter Designator" for Get/Set API.
 *	Intentionally unused symbol, designed to get you to the correct starting
 *	point, when you want to find macros for the Get/Set API; simply highlight
 *	the Module argument in your IDE (e.g, Eclipse, NetBeans, etc.), and select
 *	Go To Definition.
 */
enum { bd_gtk };		/* Component ID for Event Queue */

/** Target symbol for Get(Cwsw_EvQ, xxx) interface */
#define bd_gtk__Get(resource)		bd_gtk__Get_ ## resource()

// ---- /Targets for Get/Set APIs ------------------------------------------- }


#ifdef	__cplusplus
}
#endif

#endif /* COMPONENT_BOARD_BD_GTK_BD_GTK_H_ */
