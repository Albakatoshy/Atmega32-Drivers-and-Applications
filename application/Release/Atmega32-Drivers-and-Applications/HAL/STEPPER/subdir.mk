################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Atmega32-Drivers-and-Applications/HAL/STEPPER/STEPPER_prg.c 

OBJS += \
./Atmega32-Drivers-and-Applications/HAL/STEPPER/STEPPER_prg.o 

C_DEPS += \
./Atmega32-Drivers-and-Applications/HAL/STEPPER/STEPPER_prg.d 


# Each subdirectory must supply rules for building sources it contributes
Atmega32-Drivers-and-Applications/HAL/STEPPER/%.o: ../Atmega32-Drivers-and-Applications/HAL/STEPPER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


