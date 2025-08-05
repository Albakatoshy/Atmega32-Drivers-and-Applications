#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../MCAL/USART/USART_int.h"
#include "../MCAL/WGT/WGT_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/I2C/I2C_int.h"
#include "../HAL/EEPROM/EEPROM_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"
#include "../MCAL/ADC/ADC_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include <avr/io.h>




int main(void) {

	MDIO_vInit();
	HLCD_vInit();

	while(1){

	}

    return 0;

}




