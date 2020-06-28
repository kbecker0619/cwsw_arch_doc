/** @file bd_gtk.c
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

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ========================================================================== {

// ----	System Headers --------------------------
#include <stdbool.h>
#include <gtk/gtk.h>

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------
#include "bd_gtk.h"

#include "ManagedAlarms.h"
#include "tedlosevents.h"


// ========================================================================== }
// ----	Constants -------------------------------------------------------------
// ========================================================================== {

/* https://developer.gnome.org/gtk-tutorial/stable/c489.html
 * since GTK doesn't expose names that correlate to the events we want to process, use our own.
 * each of these names correlates with an event callback in `gtkbutton.h`
 */
enum sButtonSignals {
	kBtnNoSignal,
	kBtnPressed,
	kBtnReleased,
	kBtnClicked,
	kBtnActivate
};


// ========================================================================== }
// ----	Type Definitions ------------------------------------------------------
// ========================================================================== {

// ========================================================================== }
// ----	Global Variables ------------------------------------------------------
// ========================================================================== {

tCwswSwAlarm	Btn_tmr_ButtonRead = {
	/* .tm			= */tmr10ms,
	/* .reloadtm	= */tmr10ms,
	/* .pEvQX		= */&tedlos_evqx,
	/* .evid		= */evButton_Task,
	/* .tmrstate	= */kTmrState_Enabled
};


// ========================================================================== }
// ----	Module-level Variables ------------------------------------------------
// ========================================================================== {

static int    argc = 0;
static char **argv = NULL;

static GObject *btn0		= NULL;
static GObject *btn1		= NULL;
//static GObject *btn2		= NULL;
static GObject *btn3		= NULL;
//static GObject *btn4		= NULL;
//static GObject *btn5		= NULL;
//static GObject *btn6		= NULL;
//static GObject *btn7		= NULL;
static GObject *btnQuit		= NULL;

static GtkBuilder *pUiPanel	= NULL;
static GObject *pWindow		= NULL;
static GError *error		= NULL;

//static bool buttonstate[8]	= {0};
static uint8_t btndebounce	= 0;


// ========================================================================== }
// ----	Private Functions -----------------------------------------------------
// ========================================================================== {
/* i know very well that this is more complicated than it need be, however, this UI is there to use
 * and show the CWSW BSP, and as such, i need to translate GTK events into things the BSP under-
 * stands.
 *
 * for simpleness, each event and each button has its own callback, which then set flags as
 * appropriate for the CWSW code to process.
 */

/* on a physical board, my DI task will read all inputs at once, and will iterate through the
 * handlers for the individual assignments. to kinda-sorta replicate that behavior, we'll have one
 * button handler, and will detect which button was pressed by the widget address.
 *
 * note that on a real board, the DI action would be descended from a task, not a dispatched event
 * from the GUI framework.
 */
static void
cbButtonClicked(GtkWidget *widget, gpointer data)
{
	UNUSED(data);

	// 'twould rather use a switch statement, but can't b/c GCC complains about a pointer not be a scalar type
	if(widget == (GtkWidget *)btn0)
	{
		return;
	}

	if(widget == (GtkWidget *)btn1)
	{
		return;
	}

	if(widget == (GtkWidget *)btn3)
	{
		Cwsw_EvQX__PostEventId(&tedlos_evqx, evStoplite_ForceYellow);
	}
	// no recognized objects, just leave
	return;
}
static void
cbButtonPressed(GtkWidget *widget, gpointer data)
{
	UNUSED(data);
	// 'twould rather use a switch statement, but can't b/c GCC complains about a pointer not be a scalar type
	if(widget == (GtkWidget *)btn0)
	{
		return;
	}

	if(widget == (GtkWidget *)btn1)
	{
		return;
	}
	// no recognized objects, just leave
	return;
}
static void
cbButtonReleased(GtkWidget *widget, gpointer data)
{
	UNUSED(data);
	// 'twould rather use a switch statement, but can't b/c GCC complains about a pointer not be a scalar type
	if(widget == (GtkWidget *)btn0)
	{
		return;
	}

	if(widget == (GtkWidget *)btn1)
	{
		return;
	}
	// no recognized objects, just leave
	return;
}
static void
cbButtonActivated(GtkWidget *widget, gpointer data)
{
	UNUSED(data);
	// 'twould rather use a switch statement, but can't b/c GCC complains about a pointer not be a scalar type
	if(widget == (GtkWidget *)btn0)
	{
		return;
	}

	if(widget == (GtkWidget *)btn1)
	{
		return;
	}
	// no recognized objects, just leave
	return;
}

// time handling from demo @ http://zetcode.com/gui/gtk2/gtkevents/
//	this one designed to be called @ 1ms intervals. it is intended to simulate a 1ms heartbeat tic
//	from a real exercise kit.
static gboolean
tmHeartbeat(GtkWidget *widget)
{
	tErrorCodes_EvQ rc;
	UNUSED(widget);

	// this is MVP. i do NOT want to tie this BSP to tedlos' scheduler, but at the moment i don't
	//	know how to separate / abstract the 2 entities.

	// for the moment, this is a straight copy-n-paste from tedlos_do()
	Task(Cwsw_ClockSvc);
	do {
		rc = Cwsw_EvQX__HandleNextEvent(&tedlos_evqx, 0);
	} while(0 != tedlos_evqx.EvQ_Ctrl.Queue_Count);
	if( (rc == kErr_EvQ_NoAssociation) || (rc == kErr_EvQ_QueueEmpty) )
	{
		tedlos_idle();
	}

	return true;
}


// ========================================================================== }
// ----	Public Functions ------------------------------------------------------
// ========================================================================== {

uint16_t
bd_gtk__Init(void)
{
	bool nope = false;

	// initialize gtk lib. in this environment, no command line options are available.
	gtk_init(&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	pUiPanel = gtk_builder_new();
	if(gtk_builder_add_from_file(pUiPanel, "../app/board.ui", &error) == 0)
	{
		g_printerr("Error loading file: %s\n", error->message);
		g_clear_error(&error);
		return 1;
	}

	/* Connect signal handlers to the constructed widgets. */
	// here & below: reaction to bad "connection" call from https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-destroy
	pWindow = gtk_builder_get_object (pUiPanel, "GTK_Board");		// run-time association, must match "ID" field.
	if(pWindow)
	{
		// make the "x" in the window upper-right corner close the window
		g_signal_connect(pWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
		btnQuit = gtk_builder_get_object(pUiPanel, "btnQuit");
		if(!btnQuit)	{ nope = true; }

		if(!nope)		// connect quite, get handle for button 0
		{
			// make the quit button an alias for the "X"
			g_signal_connect(btnQuit, "clicked", G_CALLBACK(gtk_main_quit), NULL);

			/* we want button-press and button-release events. for convenience and exploration, we'll also
			 * capture the click event.
			 */
			btn0 = gtk_builder_get_object(pUiPanel, "btn0");// run-time association w/ "ID" field in UI
			if(!btn0)	{ nope = true; }
		}

		if(!nope)		// connect btn0, get handle for button 1
		{
			g_signal_connect(btn0, "clicked",	G_CALLBACK(cbButtonClicked), NULL);
			g_signal_connect(btn0, "activate",	G_CALLBACK(cbButtonActivated), NULL);
			g_signal_connect(btn0, "pressed",	G_CALLBACK(cbButtonPressed), NULL);
			g_signal_connect(btn0, "released",	G_CALLBACK(cbButtonReleased), NULL);

			btn1 = gtk_builder_get_object(pUiPanel, "btn1");
			if(!btn1)	{ nope = true; }
		}

		if(!nope)		// connect btn1, get handle for button 3 ("Force Yellow")
		{
			g_signal_connect(btn1, "clicked", G_CALLBACK(cbButtonClicked), NULL);
			btn3 = gtk_builder_get_object(pUiPanel, "btn3");
			if(!btn3)	{ nope = true; }
		}

		if(!nope)		// set up 1ms heartbeat
		{
			g_timeout_add(1, (GSourceFunc) tmHeartbeat, (gpointer)pWindow);
		}
	}

	if(nope)
	{
		gtk_widget_destroy((GtkWidget *)pWindow);
		return 1;
	}

	return 0;
}


void
Btn_tsk_ButtonRead(tEvQ_Event ev, uint32_t extra)	// uses DI lower layers
{
	uint8_t laststate = btndebounce;
	static uint8_t lastbutton = 0;		// remember which was the last button pressed, so we can

	UNUSED(ev);
	UNUSED(extra);
	UNUSED(laststate);	// debugging only
	UNUSED(lastbutton);	// debugging only

//	bool hit = (kbhit() != 0);
//	if(hit)
//	{
//		lastbutton ^= 0xFF ^ 0xFF;
//	}
//	btndebounce = TO_U8(btndebounce * 2U);							// shift the oldest sample off the edge of the cliff
//	btndebounce = TO_U8(btndebounce | hit);							// add in the new sample
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


// }
