/** @file
 *	@brief	Project Configuration for CWSW Library Unit test environment.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Sep 4, 2016
 *	@author Kevin L. Becker
 */

#ifndef PROJCFG_H
#define PROJCFG_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdbool.h>	/* true, false - for preprocessor usage */

// ----	Project Headers -------------------------
#include "ctassert.h"

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ==== PROJECT-INVARIANT CONSTANTS ========================================= {
/* ==== Section Notes =========================================================
 * This section is intended to be small and unchanged for all projects.
 * Here, we detect the current build environment and disable all other supported
 * environments. Configuration-specific defines (aka options specific to one of
 * these Build Targets) should be done in a follow-up section below.
 *
 * This section exists only because this is a demonstration project; I would
 * anticipate that most projects will only need to support one platform. In that
 * case, this whole section goes away, and you can simplify the sections that
 * follow.
 * ========================================================================= */
/* Configuration Check */
/* Format: XPRJ (Cross-Compile Project) _ Platform _ Tool _ Config */
#if defined(XPRJ_Debug)
	/* This configuration is Eclipse' default; we do not want it used, unless ... */
	#if (XPRJ_Debug == 99)
		#pragma message "Building Within Atmel Studio"

	#else
		#error This configuration reserved for Atmel Studio
	#endif

#elif defined(XPRJ_Release)
	/* This configuration is created by Eclipse; we do not want it used */
	#error For now, do not build with the "Release" build target active

#elif defined(XPRJ_Lin_GCC_Debug) || defined(XPRJ_Debug_Linux_GCC_Desktop)
	/* This is the configuration intended for development & debugging in a Linux VM */
	/* The 1st is intended to debug on a PowerPC Target from a Linux development environment */
	/* The 2nd (Desktop) is intended for building within S32DS on Linux for a Linux debugging session */
	#define	XPRJ_CVI_Debug				0
	#define	XPRJ_Win_MSVC_Debug			0
	#define	XPRJ_Win_MinGW_Debug	 	0

#elif defined(XPRJ_Win_MinGW_Debug)
	/* This is the configuration intended for development on Windows, using MinGW */
	#define XPRJ_Win_Cygwin_Debug_UT	0
	#define XPRJ_Win_MSVC_Debug			0
	#define XPRJ_NB_Debug				0
	#define	XPRJ_CVI_Debug				0
	#define XPRJ_Lin_GCC_Debug			0

#elif defined(XPRJ_Win_MinGW_Release)
	/* This is (at the time of this writing) intended to be a temporary configuration for Windows */
	#define XPRJ_Win_MinGW_Debug		0x01	/* FAKE OUT. PSYC. */
	#define XPRJ_Win_Cygwin_Debug_UT	0
	#define XPRJ_Win_MSVC_Debug			0
	#define XPRJ_NB_Debug				0
	#define	XPRJ_CVI_Debug				0
	#define XPRJ_Lin_GCC_Debug			0

#elif defined(XPRJ_Win_Cygwin_Debug_UT)
	/* This is the configuration intended for unit test development on Windows, using GCOV */
	#define XPRJ_Win_MinGW_Debug		0
	#define XPRJ_Win_MSVC_Debug			0
	#define XPRJ_NB_Debug				0
	#define	XPRJ_CVI_Debug				0
	#define XPRJ_Lin_GCC_Debug			0

#elif defined(XPRJ_NB_Debug)
	#define XPRJ_Win_MinGW_Debug		0
	#define XPRJ_Win_Cygwin_Debug_UT	0
	#define XPRJ_Lin_GCC_Debug			0
	#define XPRJ_Win_MSVC_Debug			0
	#define	XPRJ_CVI_Debug				0

#elif defined(XPRJ_Debug_Cx_AtmelSamv71)
	/* This configuration is intended for the Atmel SAMV71 Xplained Ultra board */

#elif defined(XPRJ_Win_MSVC_Debug)
	/* Visual Studio 8, which is decidedly shy of C11 */
	#define XPRJ_Win_MinGW_Debug		0
	#define XPRJ_Win_Cygwin_Debug_UT	0
	#define XPRJ_Lin_GCC_Debug			0
	#define XPRJ_NB_Debug				0
	#define	XPRJ_CVI_Debug				0

#elif defined(XPRJ_CVI_Debug)
	#define	XPRJ_Win_MinGW_Debug 		0
	#define XPRJ_Win_Cygwin_Debug_UT	0
	#define XPRJ_Lin_GCC_Debug			0
	#define XPRJ_NB_Debug				0
	#define	XPRJ_Win_MSVC_Debug			0

#else
#error Must define command-line symbol XPRJ_${ConfigName}

#endif

// ====	/PROJECT-INVARIANT CONSTANTS ======================================== }

// ==== PROJECT SPECIFIC CONSTANTS ========================================== {
// todo: pull in stuff from gen 0 of this same project
#if (XPRJ_Lin_GCC_Debug)
	/* enable or disable individual architectural features */
#endif

#if (XPRJ_CVI_Debug)
	// use cwsw simulated events to achieve separation between UI panels
	#define USE_NOTIFICATION_EVENTS		(1)
#endif


/*	Allow for the possibility that USE_NOTIFICATION_EVENTS might be a command-line
 *	define. Pick reasonable defaults if not defined.
 */
#if !defined(USE_NOTIFICATION_EVENTS)
#define USE_NOTIFICATION_EVENTS			(true)

#else
#endif

/*	For this component, equate simulated events with notification events. */
#if defined(USE_NOTIFICATION_EVENTS)
#define USE_SIMULATED_EVENTS	(true)
#endif


/**	Special "magic" marker for CUNIT unit testing environment.
 * 	If the command-line define of the CUNIT project defines BUILD_FOR_UNIT_TEST
 * 	with a value of 99, certain behaviors within the component are different,
 * 	depending on the needs of the unit test environment.
 */
#define CUNIT	99

/**	Special "magic" marker for the CONSOLE- based demo application.
 * 	If the command-line define of the demo project defines BUILD_FOR_UNIT_TEST
 * 	with a value of 1, certain behaviors within the component are different,
 * 	depending on the needs of the demo app environment.
 *
 * 	This value specifically chosen because most instances of value #true also
 * 	have the value "1", so that the default build, in the absence of a command-
 * 	line define, will enable console behavior.
 */
#define CONSOLE	 1

/*	Allow for the possibility that BUILD_FOR_UNIT_TEST might be a command-line
 *	define. Pick reasonable defaults if not defined.
 */
#if !defined(BUILD_FOR_UNIT_TEST)
	#if (XPRJ_Lin_GCC_Debug)		||	\
		(XPRJ_Win_MinGW_Debug)		||	\
		(XPRJ_Win_Cygwin_Debug_UT)	||	\
		(XPRJ_NB_Debug)				||  \
		(XPRJ_Win_MSVC_Debug)		||  \
		(XPRJ_CVI_Debug)
		#define BUILD_FOR_UNIT_TEST		(true)

	#else
		#define BUILD_FOR_UNIT_TEST		(false)

	#endif
#endif

// ==== /PROJECT SPECIFIC CONSTANTS ========================================= }


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

/* Define WEAK attribute */
/**	Macro to designate a function as weakly bound.
 *	This allows a project to define a default function that can be overridden by
 *	a specific implementation. Note not all compilers support this, so on projects
 *	that rely on this, you'll need to figure out a work-around.
 */
#if !defined(WEAK)
#if defined (__GNUC__)						/* GCC CS3 2009q3-68 */
#define WEAK __attribute__ ((weak))

#elif defined (__CC_ARM  )					/* Keil �Vision 4 */
#define WEAK __attribute__ ((weak))

#elif defined (__ICCARM__)					/* IAR Ewarm 5.41+ */
#define WEAK __weak

#elif defined(_MSC_VER) || defined(_CVI_)	/* visual studio 8 and LabWindows/CVI v7.1 */
#define	WEAK	/* WEAK not available */

#else
#error Unrecognized or unsupported compiler

#endif
#endif


/**	Project-specific configuration to engage Critical Section / Protected Region
 *	behavior.
 *
 *	For the demo app + UT environment for the CWSW Library, we'll define this
 *	as a macro that supplies information that might be useful to the UT enviro.
 *
 *	@ingroup cwsw_lib_crit_section_group
 *//* Note: the following moved out of Doxy space, to avoid warnings when building component-specific
 * documentation.
 *
 *	@xreq{SR_LIB_0307}
 */
#define CWSW_LIB_CRIT_SECT_ENTER(protlvl)	cb_lib_demo_cs_enter(protlvl, __FILE__, __LINE__)
extern void cb_lib_demo_cs_enter(int protlvl, char const * const filename, int const lineno);

/**	Project-specific configuration, invoked when Critical Section is already
 *	active.
 *
 *	Normally, we recommend the definition of:
 *		do {} while(0)
 *
 *	For this project's UT environment, we'll define this as a macro that
 *	supplies info that might be useful to the UT enviro.
 *
 *	@ingroup cwsw_lib_crit_section_group
 *//* Note: the following moved out of Doxy space, to avoid warnings when building component-specific
 * documentation.
 *
 *	@xreq{SR_LIB_0308}
 */
#define	CWSW_LIB_CRIT_SECT_LEAVE(protlvl)	cb_lib_demo_cs_leave(protlvl, __FILE__, __LINE__)
extern void cb_lib_demo_cs_leave(int protlvl, char const * const filename, int const lineno);


// define specifically for Eclipse CDT parser
#ifdef __CDT_PARSER__
  #define __BASE_FILE__ __FILE__
#endif


#ifdef	__cplusplus
}
#endif

#endif /* PROJCFG_H */
