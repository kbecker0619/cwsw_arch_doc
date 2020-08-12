################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/_Projects/cwsw_evqueue_test/app/cwsw_lib_prj/CritSect.c 

OBJS += \
./app/cwsw_lib_prj/CritSect.o 

C_DEPS += \
./app/cwsw_lib_prj/CritSect.d 


# Each subdirectory must supply rules for building sources it contributes
app/cwsw_lib_prj/CritSect.o: C:/_Projects/cwsw_evqueue_test/app/cwsw_lib_prj/CritSect.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_arch/inc/i386" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/bd_gtk" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_board/common" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_lib/inc" -I"D:\_Programs\git-sdk-64\mingw64/include/gtk-3.0" -I"D:\_Programs\git-sdk-64\mingw64/include/glib-2.0" -I"D:\_Programs\git-sdk-64\mingw64/lib/glib-2.0/include" -I"D:\_Programs\git-sdk-64\mingw64/include/pango-1.0" -I"D:\_Programs\git-sdk-64\mingw64/include/cairo" -I"D:\_Programs\git-sdk-64\mingw64/include/gdk-pixbuf-2.0" -I"D:\_Programs\git-sdk-64\mingw64/include/atk-1.0" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../app/cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../cwsw_sme/inc" -O0 -g3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


