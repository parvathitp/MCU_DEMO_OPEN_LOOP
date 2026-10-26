################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/eal/emios_eal/emios_eal.c 

OBJS += \
./src/eal/emios_eal/emios_eal.o 

C_DEPS += \
./src/eal/emios_eal/emios_eal.d 


# Each subdirectory must supply rules for building sources it contributes
src/eal/emios_eal/%.o: ../src/eal/emios_eal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/eal/emios_eal/emios_eal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


