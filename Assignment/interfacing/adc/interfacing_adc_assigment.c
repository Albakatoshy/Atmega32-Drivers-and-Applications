#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"
#include "../MCAL/ADC/ADC_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

int main() {
	MDIO_vInit();
	MADC_vInit();
	MDIO_vSetPinDirection(DIO_PORTA_INDEX, DIO_PIN7, DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPortDirection(DIO_PORTC_INDEX , DIO_PIN_DIRECTION_OUTPUT);
	u16 adcRegValue = 0;



	u32 current_range = 0;

		while(1)
		{

	        adcRegValue = MADC_u16AdcRead(7);
	        current_range = adcRegValue / 128;

	        MDIO_vSetPortValue(DIO_PORTC_INDEX , (1 << (current_range + 1)) - 1);

	        _delay_ms(200);
		}



	return 0;
}

