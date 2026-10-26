################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/service/lcu/lcu_service.c 

OBJS += \
./src/service/lcu/lcu_service.o 

C_DEPS += \
./src/service/lcu/lcu_service.d 


# Each subdirectory must supply rules for building sources it contributes
src/service/lcu/%.o: ../src/service/lcu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/service/lcu/lcu_service.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


