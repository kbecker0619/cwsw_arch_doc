################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/bd-di-buttons-gtk.c \
D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/cwsw_board.c \
D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/di_button_callbacks.c 

OBJS += \
./libs/cwsw_board/bd_gtk/src/bd-di-buttons-gtk.o \
./libs/cwsw_board/bd_gtk/src/cwsw_board.o \
./libs/cwsw_board/bd_gtk/src/di_button_callbacks.o 

C_DEPS += \
./libs/cwsw_board/bd_gtk/src/bd-di-buttons-gtk.d \
./libs/cwsw_board/bd_gtk/src/cwsw_board.d \
./libs/cwsw_board/bd_gtk/src/di_button_callbacks.d 


# Each subdirectory must supply rules for building sources it contributes
libs/cwsw_board/bd_gtk/src/bd-di-buttons-gtk.o: D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/bd-di-buttons-gtk.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/bd_gtk" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/common" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app/cfg" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libs/cwsw_board/bd_gtk/src/cwsw_board.o: D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/cwsw_board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/bd_gtk" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/common" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app/cfg" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libs/cwsw_board/bd_gtk/src/di_button_callbacks.o: D:/_Projects/cwsw_evqueue_test/test/libs/cwsw_board/bd_gtk/src/di_button_callbacks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/bd_gtk" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/common" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../app/cfg" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_lib/inc" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_arch/inc/i386" -I"D:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


