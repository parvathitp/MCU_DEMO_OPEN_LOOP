################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/service/emios/emios_service.c 

OBJS += \
./src/service/emios/emios_service.o 

C_DEPS += \
./src/service/emios/emios_service.d 


# Each subdirectory must supply rules for building sources it contributes
src/service/emios/%.o: ../src/service/emios/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/service/emios/emios_service.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


