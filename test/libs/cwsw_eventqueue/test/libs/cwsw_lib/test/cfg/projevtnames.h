/** @file
 *	@brief	Project-specific event enumerations for Demo App for Event Queue component.
 *	@note	This file is here for demonstration purposes only, and is not instructive for real-life
 *			usage of the Event Queue component.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 */

#ifndef UT_PROJEVTNAMES_H_
#define UT_PROJEVTNAMES_H_

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

/** Project-specific list of events.
 * This list must be contained inside the enumeration; the name of the enumeration tag is
 * significant, and it is highly recommended the 1st enum (value of 0) should be reserved for No
 * Event. Other than that,
 */
enum eProjectEvents {
	evNoEvent,				/**< reserved value, used for initialization */
	evNotInit,              /**< By CWSW convention, 1 is always "component not initialized" */
	evAlreadyInit,			/**< BY CWSW convention, 2 is "already initialized" */
	evButtonPressed,		/**< debounced press event */
	evButtonCommit,
	evButtonReleased,
	evUpdateUi,
	evTerminateRequested,
	kNumOsEvqEvents
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


extern void EventHandler__evNotInitialized		(tEventPayload EventData);
extern void EventHandler__evTerminateRequested	(tEventPayload EventData);
extern void EventHandler__evButtonCommit 		(tEventPayload EventData);
extern void EventHandler__evButtonPressed		(tEventPayload EventData);
extern void EventHandler__evButtonReleased		(tEventPayload EventData);

#ifdef	__cplusplus
}
#endif

#endif /* UT_PROJEVTNAMES_H_ */
