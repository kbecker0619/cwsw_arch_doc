################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c \
C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c \
C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c 

OBJS += \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.o \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.o \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.o 

C_DEPS += \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.d \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.d \
./cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.d 


# Each subdirectory must supply rules for building sources it contributes
cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.o: C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evhandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Lin_GCC_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_cwsw" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_tedlos" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../os-board-fusion" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.o: C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evqueue_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Lin_GCC_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_cwsw" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_tedlos" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../os-board-fusion" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.o: C:/_Projects/cwsw_evqueue_test/cwsw_eventqueue/cwsw_evqueue_ex/src/cwsw_evthndlrassoc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Lin_GCC_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_cwsw" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg_tedlos" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../os-board-fusion" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


