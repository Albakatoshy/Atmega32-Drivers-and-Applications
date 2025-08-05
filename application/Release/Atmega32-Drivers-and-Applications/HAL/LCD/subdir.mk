################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Atmega32-Drivers-and-Applications/HAL/LCD/LCD_prg.c 

OBJS += \
./Atmega32-Drivers-and-Applications/HAL/LCD/LCD_prg.o 

C_DEPS += \
./Atmega32-Drivers-and-Applications/HAL/LCD/LCD_prg.d 


# Each subdirectory must supply rules for building sources it contributes
Atmega32-Drivers-and-Applications/HAL/LCD/%.o: ../Atmega32-Drivers-and-Applications/HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


