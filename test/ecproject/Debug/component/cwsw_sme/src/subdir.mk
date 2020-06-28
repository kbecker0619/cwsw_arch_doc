################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/_Projects/cwsw_evqueue_test/component/cwsw_sme/src/cwsw_sme.template.c \
C:/_Projects/cwsw_evqueue_test/component/cwsw_sme/src/sme.c 

OBJS += \
./component/cwsw_sme/src/cwsw_sme.template.o \
./component/cwsw_sme/src/sme.o 

C_DEPS += \
./component/cwsw_sme/src/cwsw_sme.template.d \
./component/cwsw_sme/src/sme.d 


# Each subdirectory must supply rules for building sources it contributes
component/cwsw_sme/src/cwsw_sme.template.o: C:/_Projects/cwsw_evqueue_test/component/cwsw_sme/src/cwsw_sme.template.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app/cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/board/bd_gtk" -ID:/_Programs/git-sdk-64/mingw64/include/gtk-3.0 -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 `pkg-config --cflags gtk+-3.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

component/cwsw_sme/src/sme.o: C:/_Projects/cwsw_evqueue_test/component/cwsw_sme/src/sme.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app/cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/cwsw_sme/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/board/bd_gtk" -ID:/_Programs/git-sdk-64/mingw64/include/gtk-3.0 -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 `pkg-config --cflags gtk+-3.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


