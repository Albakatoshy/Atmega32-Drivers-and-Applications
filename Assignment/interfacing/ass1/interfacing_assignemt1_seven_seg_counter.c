#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


volatile u8 PushButton_1 = 0;
volatile u8 PushButton_2 = 0;
volatile u8 DisplayedNum = 0;
volatile u8 SevenSegFlag = 0;



int main()
{

	HSSD_vInit();
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN0 , DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN1 , DIO_PIN_DIRECTION_INPUT);


	while(1){

		if(MDIO_u8GetPinValue(DIO_PORTD_INDEX , DIO_PIN0) == DIO_PIN_HIGH){
			_delay_ms(30);
			DisplayedNum++;
			if(DisplayedNum > 9){
				DisplayedNum = 0;
			}
			HSSD_DisplayNumber(DisplayedNum);
		}
		if(MDIO_u8GetPinValue(DIO_PORTD_INDEX , DIO_PIN1) == DIO_PIN_HIGH){
			_delay_ms(30);
			if(DisplayedNum == 0){
				DisplayedNum = 9;
			}
			else{
				DisplayedNum--;
			}
			HSSD_DisplayNumber(DisplayedNum);
		}


	}

	return 0 ;
}

