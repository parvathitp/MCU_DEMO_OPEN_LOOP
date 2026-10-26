################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/Emios_Mcl_Ip_Sa_PBcfg.c \
../generate/src/Emios_Pwm_Ip_Sa_PBcfg.c \
../generate/src/Igf_Port_Ip_Cfg.c \
../generate/src/IntCtrl_Ip_Cfg.c \
../generate/src/Lcu_Ip_Cfg.c \
../generate/src/Lcu_Ip_Sa_PBcfg.c \
../generate/src/Lpspi_Ip_Sa_PBcfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Siul2_Icu_Ip_SA_PBcfg.c \
../generate/src/Trgmux_Ip_Cfg.c \
../generate/src/Trgmux_Ip_Sa_PBcfg.c 

OBJS += \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/Emios_Mcl_Ip_Sa_PBcfg.o \
./generate/src/Emios_Pwm_Ip_Sa_PBcfg.o \
./generate/src/Igf_Port_Ip_Cfg.o \
./generate/src/IntCtrl_Ip_Cfg.o \
./generate/src/Lcu_Ip_Cfg.o \
./generate/src/Lcu_Ip_Sa_PBcfg.o \
./generate/src/Lpspi_Ip_Sa_PBcfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Siul2_Icu_Ip_SA_PBcfg.o \
./generate/src/Trgmux_Ip_Cfg.o \
./generate/src/Trgmux_Ip_Sa_PBcfg.o 

C_DEPS += \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/Emios_Mcl_Ip_Sa_PBcfg.d \
./generate/src/Emios_Pwm_Ip_Sa_PBcfg.d \
./generate/src/Igf_Port_Ip_Cfg.d \
./generate/src/IntCtrl_Ip_Cfg.d \
./generate/src/Lcu_Ip_Cfg.d \
./generate/src/Lcu_Ip_Sa_PBcfg.d \
./generate/src/Lpspi_Ip_Sa_PBcfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Siul2_Icu_Ip_SA_PBcfg.d \
./generate/src/Trgmux_Ip_Cfg.d \
./generate/src/Trgmux_Ip_Sa_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/Clock_Ip_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


