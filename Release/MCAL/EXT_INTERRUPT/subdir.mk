################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXT_INTERRUPT/EXT_INT_prg.c \
../MCAL/EXT_INTERRUPT/GENERAL_INT_prg.c 

OBJS += \
./MCAL/EXT_INTERRUPT/EXT_INT_prg.o \
./MCAL/EXT_INTERRUPT/GENERAL_INT_prg.o 

C_DEPS += \
./MCAL/EXT_INTERRUPT/EXT_INT_prg.d \
./MCAL/EXT_INTERRUPT/GENERAL_INT_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXT_INTERRUPT/%.o: ../MCAL/EXT_INTERRUPT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


