#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"
#include "../MCAL/ADC/ADC_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

u8 flag = 0;

void callBack(void){

	if(flag == 0){
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_HIGH);
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN1 , DIO_PIN_LOW);
		flag = 1;
	}
	else if(flag == 1){
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN1 , DIO_PIN_HIGH);
		MDIO_vSetPinValue(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_LOW);
		flag = 0;
	}

}

int main(){
	MDIO_vInit();
	MEXTI_vInit();
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN3 , DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(DIO_PORTC_INDEX , DIO_PIN0 , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTC_INDEX , DIO_PIN1 , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinValue(DIO_PORTD_INDEX , DIO_PIN3 , DIO_PIN_HIGH);
	MEXT_INT_InterruptHandler(EXT_INT1 , callBack);


	while(1)
	{

	}



	return 0;
}

