################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/service/lcu/subdir.mk
-include src/service/emios/subdir.mk
-include src/init/subdir.mk
-include src/eal/emios_eal/subdir.mk
-include src/application/subdir.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include TPPSDK_GD3000_Driver/tpp/subdir.mk
-include TPPSDK_GD3000_Driver/aml/wait_aml/subdir.mk
-include TPPSDK_GD3000_Driver/aml/spi_aml/subdir.mk
-include TPPSDK_GD3000_Driver/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
demo.siz \


# All Target
all: demo.elf secondary-outputs

# Tool invocations
demo.elf: $(OBJS) C:/MOONRIDER/GITHUB/MCU_DEMO_OPEN_LOOP/Project_Settings/Linker_Files/linker_flash_s32k344.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "demo.elf" "@demo.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

demo.siz: demo.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley demo.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
