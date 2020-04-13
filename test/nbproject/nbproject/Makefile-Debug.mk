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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1ec31bae/cwsw_clock_svc.o \
	${OBJECTDIR}/_ext/62410ec1/cwsw_swtimer.o \
	${OBJECTDIR}/_ext/46be5799/cwsw_event.o \
	${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o \
	${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o \
	${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o \
	${OBJECTDIR}/_ext/e89cc024/CritSect.o \
	${OBJECTDIR}/_ext/511dfd52/main.o \
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

${OBJECTDIR}/_ext/1ec31bae/cwsw_clock_svc.o: ../../component/cwsw_clock/src/cwsw_clock_svc.c
	${MKDIR} -p ${OBJECTDIR}/_ext/1ec31bae
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1ec31bae/cwsw_clock_svc.o ../../component/cwsw_clock/src/cwsw_clock_svc.c

${OBJECTDIR}/_ext/62410ec1/cwsw_swtimer.o: ../../component/cwsw_swtimer/src/cwsw_swtimer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/62410ec1
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/62410ec1/cwsw_swtimer.o ../../component/cwsw_swtimer/src/cwsw_swtimer.c

${OBJECTDIR}/_ext/46be5799/cwsw_event.o: ../../cwsw_eventqueue/cwsw_event/src/cwsw_event.c
	${MKDIR} -p ${OBJECTDIR}/_ext/46be5799
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/46be5799/cwsw_event.o ../../cwsw_eventqueue/cwsw_event/src/cwsw_event.c

${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o: ../../cwsw_eventqueue/cwsw_event/src/cwsw_eventtable.c
	${MKDIR} -p ${OBJECTDIR}/_ext/46be5799
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/46be5799/cwsw_eventtable.o ../../cwsw_eventqueue/cwsw_event/src/cwsw_eventtable.c

${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o: ../../cwsw_eventqueue/cwsw_evqueue/src/cwsw_evqueue.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b7f6927f
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b7f6927f/cwsw_evqueue.o ../../cwsw_eventqueue/cwsw_evqueue/src/cwsw_evqueue.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evhandler.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evqueue_ex.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c

${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o: ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c
	${MKDIR} -p ${OBJECTDIR}/_ext/d267d43d
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d267d43d/cwsw_evthndlrassoc.o ../../cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c

${OBJECTDIR}/_ext/e89cc024/CritSect.o: ../app/cwsw_lib_prj/CritSect.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e89cc024
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e89cc024/CritSect.o ../app/cwsw_lib_prj/CritSect.c

${OBJECTDIR}/_ext/511dfd52/main.o: ../app/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/511dfd52
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511dfd52/main.o ../app/main.c

${OBJECTDIR}/_ext/4ccfc345/cwsw_lib.o: ../libs/cwsw_lib/src/cwsw_lib.c
	${MKDIR} -p ${OBJECTDIR}/_ext/4ccfc345
	${RM} "$@.d"
	$(COMPILE.c) -g -DXPRJ_NB_${CND_CONF}=1 -I../app/cfg -I../libs/cwsw_lib/inc -I../../cwsw_eventqueue/cwsw_event/inc -I../../cwsw_eventqueue/cwsw_evqueue/inc -I../../cwsw_eventqueue/cwsw_evqueue_ex/inc -I../../component/cwsw_clock/inc -I../../component/cwsw_swtimer/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4ccfc345/cwsw_lib.o ../libs/cwsw_lib/src/cwsw_lib.c

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
