################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/_Projects/cwsw_evqueue_test/test/libs/tedlos/tedlos.c \
C:/_Projects/cwsw_evqueue_test/test/libs/tedlos/tedlos_scheduler.c 

OBJS += \
./libs/tedlos/tedlos.o \
./libs/tedlos/tedlos_scheduler.o 

C_DEPS += \
./libs/tedlos/tedlos.d \
./libs/tedlos/tedlos_scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
libs/tedlos/tedlos.o: C:/_Projects/cwsw_evqueue_test/test/libs/tedlos/tedlos.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app/cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/tedlos" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/cwsw_sme/inc" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libs/tedlos/tedlos_scheduler.o: C:/_Projects/cwsw_evqueue_test/test/libs/tedlos/tedlos_scheduler.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -D"XPRJ_Win_MinGW_Debug=1" -DUSE_NOTIFICATION_EVENTS=1 -DDEMO_APP=1 -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_lib/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../app/cfg" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_event/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_eventqueue/cwsw_evqueue_ex/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_clock/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/cwsw_clock_services/cwsw_swtimer/inc" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../libs/tedlos" -I"C:/_Projects/cwsw_evqueue_test/test/ecproject/../../component/cwsw_sme/inc" -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


