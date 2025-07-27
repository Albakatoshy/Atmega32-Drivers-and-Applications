#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


void ISR_APP();

u8 led_flag = 0;

int main() {
	MDIO_vInit();
	MDIO_vSetPinDirection(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN2 , DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinValue(DIO_PORTD_INDEX , DIO_PIN2 , DIO_PIN_HIGH);
	MEXTI_vInit();
	MEXT_INT_InterruptHandler(EXT_INT0 , &ISR_APP);


	while (1) {

	}

	return 0;
}


void ISR_APP(){
	if(led_flag == 0){
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_HIGH);
		led_flag =1;
	}
	else if (led_flag==1){
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_LOW);
		led_flag =0;
	}
}
