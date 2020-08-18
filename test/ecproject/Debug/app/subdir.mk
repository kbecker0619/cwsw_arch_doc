################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/_Projects/cwsw_evqueue_test/app/app-di-buttons.c \
C:/_Projects/cwsw_evqueue_test/app/app-do-lamps.c \
C:/_Projects/cwsw_evqueue_test/app/console_keyin.c \
C:/_Projects/cwsw_evqueue_test/app/main.c \
C:/_Projects/cwsw_evqueue_test/app/stoplite-sme.c \
C:/_Projects/cwsw_evqueue_test/app/tedlos.c \
C:/_Projects/cwsw_evqueue_test/app/tedlos_scheduler.c 

OBJS += \
./app/app-di-buttons.o \
./app/app-do-lamps.o \
./app/console_keyin.o \
./app/main.o \
./app/stoplite-sme.o \
./app/tedlos.o \
./app/tedlos_scheduler.o 

C_DEPS += \
./app/app-di-buttons.d \
./app/app-do-lamps.d \
./app/console_keyin.d \
./app/main.d \
./app/stoplite-sme.d \
./app/tedlos.d \
./app/tedlos_scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
app/app-di-buttons.o: C:/_Projects/cwsw_evqueue_test/app/app-di-buttons.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/app-do-lamps.o: C:/_Projects/cwsw_evqueue_test/app/app-do-lamps.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/console_keyin.o: C:/_Projects/cwsw_evqueue_test/app/console_keyin.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/main.o: C:/_Projects/cwsw_evqueue_test/app/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/stoplite-sme.o: C:/_Projects/cwsw_evqueue_test/app/stoplite-sme.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/tedlos.o: C:/_Projects/cwsw_evqueue_test/app/tedlos.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app/tedlos_scheduler.o: C:/_Projects/cwsw_evqueue_test/app/tedlos_scheduler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_clock_services/cwsw_swtimer/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


