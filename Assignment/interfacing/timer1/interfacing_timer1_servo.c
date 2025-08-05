#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"
#include "../MCAL/ADC/ADC_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

void SetServoAngle(u8 angle) {
	if (angle > 180) angle = 180;
	OCR1A = ((angle * 1000UL) / 180) + 1000;
}

int main(void){
	MDIO_vInit();
	MDIO_vSetPinDirection(DIO_PORTD_INDEX, DIO_PIN5, DIO_PIN_DIRECTION_OUTPUT);
	MTIMER1_vInit();
	MTIMER1_vStartTimer();
	u8 angle = 0;

	for (u8 angle = 0; angle <= 180; angle += 10) {
		SetServoAngle(angle);
		_delay_ms(300);
	}


	for (u8 angle = 180; angle >= 10; angle -= 10) {
		SetServoAngle(angle);
		_delay_ms(300);
	}

	while(1){

	}

	return 0;
}
