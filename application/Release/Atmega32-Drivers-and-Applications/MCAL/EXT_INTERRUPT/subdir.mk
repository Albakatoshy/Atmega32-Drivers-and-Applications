################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/EXT_INT_prg.c \
../Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/GENERAL_INT_prg.c 

OBJS += \
./Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/EXT_INT_prg.o \
./Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/GENERAL_INT_prg.o 

C_DEPS += \
./Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/EXT_INT_prg.d \
./Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/GENERAL_INT_prg.d 


# Each subdirectory must supply rules for building sources it contributes
Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/%.o: ../Atmega32-Drivers-and-Applications/MCAL/EXT_INTERRUPT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


