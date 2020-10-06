#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/5624e081/app-di-buttons.o \
	${OBJECTDIR}/_ext/5624e081/app-do-lamps.o \
	${OBJECTDIR}/_ext/5624e081/console_keyin.o \
	${OBJECTDIR}/_ext/ded6c155/CritSect.o \
	${OBJECTDIR}/_ext/5624e081/main.o \
	${OBJECTDIR}/_ext/5624e081/stoplite-sme.o \
	${OBJECTDIR}/_ext/5624e081/tedlos.o \
	${OBJECTDIR}/_ext/5624e081/tedlos_scheduler.o \
	${OBJECTDIR}/_ext/a955d543/ports_api.o \
	${OBJECTDIR}/_ext/1ec747c5/cwsw_arch.o \
	${OBJECTDIR}/_ext/f6b48326/bd-di-buttons-gtk.o \
	${OBJECTDIR}/_ext/f6b48326/cwsw_board.o \
	${OBJECTDIR}/_ext/f6b48326/di_button_callbacks.o \
	${OBJECTDIR}/_ext/9e527b3/bd-di-buttons-cvi.o \
	${OBJECTDIR}/_ext/9e527b3/cwsw_board.o \
	${OBJECTDIR}/_ext/9e527b3/cwsw_board_cvi_ui.o \
	${OBJECTDIR}/_ext/9e527b3/di_button_callbacks.o \
	${OBJECTDIR}/_ext/2d469c70/cwsw_bsp_buttons.o \
	${OBJECTDIR}/_ext/9971f3d/cwsw_board.o \
	${OBJECTDIR}/_ext/46be5799/cwsw_event.o \
	${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o \
	${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o \
	${OBJECTDIR}/_ext/2f02d593/cwsw_lib.o \
	${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.o \
	${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.template.o \
	${OBJECTDIR}/_ext/e89cc024/CritSect.o \
	${OBJECTDIR}/_ext/4ccfc345/cwsw_lib.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5624e081/app-di-buttons.o: ../../app/app-di-buttons.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/app-di-buttons.o ../../app/app-di-buttons.c

${OBJECTDIR}/_ext/5624e081/app-do-lamps.o: ../../app/app-do-lamps.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/app-do-lamps.o ../../app/app-do-lamps.c

${OBJECTDIR}/_ext/5624e081/console_keyin.o: ../../app/console_keyin.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/console_keyin.o ../../app/console_keyin.c

${OBJECTDIR}/_ext/ded6c155/CritSect.o: ../../app/cwsw_lib_prj/CritSect.c
	${MKDIR} -p ${OBJECTDIR}/_ext/ded6c155
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ded6c155/CritSect.o ../../app/cwsw_lib_prj/CritSect.c

${OBJECTDIR}/_ext/5624e081/main.o: ../../app/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/main.o ../../app/main.c

${OBJECTDIR}/_ext/5624e081/stoplite-sme.o: ../../app/stoplite-sme.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/stoplite-sme.o ../../app/stoplite-sme.c

${OBJECTDIR}/_ext/5624e081/tedlos.o: ../../app/tedlos.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/tedlos.o ../../app/tedlos.c

${OBJECTDIR}/_ext/5624e081/tedlos_scheduler.o: ../../app/tedlos_scheduler.c
	${MKDIR} -p ${OBJECTDIR}/_ext/5624e081
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5624e081/tedlos_scheduler.o ../../app/tedlos_scheduler.c

${OBJECTDIR}/_ext/a955d543/ports_api.o: ../../cwsw_arch/inc/i386/peripheral/ports/ports_api.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a955d543
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a955d543/ports_api.o ../../cwsw_arch/inc/i386/peripheral/ports/ports_api.c

${OBJECTDIR}/_ext/1ec747c5/cwsw_arch.o: ../../cwsw_arch/src/i386/cwsw_arch.c
	${MKDIR} -p ${OBJECTDIR}/_ext/1ec747c5
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1ec747c5/cwsw_arch.o ../../cwsw_arch/src/i386/cwsw_arch.c

${OBJECTDIR}/_ext/f6b48326/bd-di-buttons-gtk.o: ../../cwsw_board/bd_gtk/src/bd-di-buttons-gtk.c
	${MKDIR} -p ${OBJECTDIR}/_ext/f6b48326
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f6b48326/bd-di-buttons-gtk.o ../../cwsw_board/bd_gtk/src/bd-di-buttons-gtk.c

${OBJECTDIR}/_ext/f6b48326/cwsw_board.o: ../../cwsw_board/bd_gtk/src/cwsw_board.c
	${MKDIR} -p ${OBJECTDIR}/_ext/f6b48326
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f6b48326/cwsw_board.o ../../cwsw_board/bd_gtk/src/cwsw_board.c

${OBJECTDIR}/_ext/f6b48326/di_button_callbacks.o: ../../cwsw_board/bd_gtk/src/di_button_callbacks.c
	${MKDIR} -p ${OBJECTDIR}/_ext/f6b48326
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f6b48326/di_button_callbacks.o ../../cwsw_board/bd_gtk/src/di_button_callbacks.c

${OBJECTDIR}/_ext/9e527b3/bd-di-buttons-cvi.o: ../../cwsw_board/bd_lwcvi/src/bd-di-buttons-cvi.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9e527b3
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9e527b3/bd-di-buttons-cvi.o ../../cwsw_board/bd_lwcvi/src/bd-di-buttons-cvi.c

${OBJECTDIR}/_ext/9e527b3/cwsw_board.o: ../../cwsw_board/bd_lwcvi/src/cwsw_board.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9e527b3
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9e527b3/cwsw_board.o ../../cwsw_board/bd_lwcvi/src/cwsw_board.c

${OBJECTDIR}/_ext/9e527b3/cwsw_board_cvi_ui.o: ../../cwsw_board/bd_lwcvi/src/cwsw_board_cvi_ui.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9e527b3
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9e527b3/cwsw_board_cvi_ui.o ../../cwsw_board/bd_lwcvi/src/cwsw_board_cvi_ui.c

${OBJECTDIR}/_ext/9e527b3/di_button_callbacks.o: ../../cwsw_board/bd_lwcvi/src/di_button_callbacks.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9e527b3
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9e527b3/di_button_callbacks.o ../../cwsw_board/bd_lwcvi/src/di_button_callbacks.c

${OBJECTDIR}/_ext/2d469c70/cwsw_bsp_buttons.o: ../../cwsw_board/common/src/cwsw_bsp_buttons.c
	${MKDIR} -p ${OBJECTDIR}/_ext/2d469c70
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2d469c70/cwsw_bsp_buttons.o ../../cwsw_board/common/src/cwsw_bsp_buttons.c

${OBJECTDIR}/_ext/9971f3d/cwsw_board.o: ../../cwsw_board/none/src/cwsw_board.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9971f3d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9971f3d/cwsw_board.o ../../cwsw_board/none/src/cwsw_board.c

${OBJECTDIR}/_ext/46be5799/cwsw_event.o: ../../cwsw_eventqueue/cwsw_event/src/cwsw_event.c
	${MKDIR} -p ${OBJECTDIR}/_ext/46be5799
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/46be5799/cwsw_event.o ../../cwsw_eventqueue/cwsw_event/src/cwsw_event.c

${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o: ../../cwsw_eventqueue/cwsw_event/src/cwsw_eventtable.c
	${MKDIR} -p ${OBJECTDIR}/_ext/46be5799
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o ../../cwsw_eventqueue/cwsw_event/src/cwsw_eventtable.c

${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o: ../../cwsw_eventqueue/cwsw_evqueue/src/cwsw_evqueue.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b7f6927f
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o ../../cwsw_eventqueue/cwsw_evqueue/src/cwsw_evqueue.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c

${OBJECTDIR}/_ext/2f02d593/cwsw_lib.o: ../../cwsw_lib/src/cwsw_lib.c
	${MKDIR} -p ${OBJECTDIR}/_ext/2f02d593
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2f02d593/cwsw_lib.o ../../cwsw_lib/src/cwsw_lib.c

${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.o: ../../cwsw_sme/src/cwsw_sme.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a84c1d59
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.o ../../cwsw_sme/src/cwsw_sme.c

${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.template.o: ../../cwsw_sme/src/cwsw_sme.template.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a84c1d59
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a84c1d59/cwsw_sme.template.o ../../cwsw_sme/src/cwsw_sme.template.c

${OBJECTDIR}/_ext/e89cc024/CritSect.o: ../app/cwsw_lib_prj/CritSect.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e89cc024
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e89cc024/CritSect.o ../app/cwsw_lib_prj/CritSect.c

${OBJECTDIR}/_ext/4ccfc345/cwsw_lib.o: ../libs/cwsw_lib/src/cwsw_lib.c
	${MKDIR} -p ${OBJECTDIR}/_ext/4ccfc345
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4ccfc345/cwsw_lib.o ../libs/cwsw_lib/src/cwsw_lib.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
