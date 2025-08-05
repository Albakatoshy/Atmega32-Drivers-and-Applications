#include "MCAL/DIO/DIO_int.h"
#include "HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#define F_CPU 	8000000L
#include <avr/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

volatile u8 PortVal = 0;



int main()
{



	MDIO_vSetPortDirection(DIO_PORTC_INDEX , DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPortValue(DIO_PORTC_INDEX, 0xFF);
	MDIO_vSetPortDirection(DIO_PORTD_INDEX , DIO_PIN_DIRECTION_OUTPUT);


	while(1){

		PortVal = ~MDIO_u8GetPortValue(DIO_PORTC_INDEX);

		MDIO_vSetPortValue(DIO_PORTD_INDEX , PortVal);



	}

	return 0 ;
}

