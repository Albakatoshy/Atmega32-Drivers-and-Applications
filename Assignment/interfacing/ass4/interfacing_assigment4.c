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

//	HLCD_vInit();
//	MADC_vInit();
//	MDIO_vSetPinDirection(DIO_PORTA_INDEX, DIO_PIN7, DIO_PIN_DIRECTION_INPUT);
//
//	u16 adcRegValue = 0;
//	u16 millVoltage = 0;
//	u16 temp = 0;

//		adcRegValue = MADC_u16AdcRead(7); // steps
//		// volt = steps * step size  (~5)
//
////		millVoltage = (adcRegValue * ((u32)5000000 / (u32)1024))*(u32)1000;
////
////		temp = millVoltage / 10;
//
//		float voltage = (adcRegValue );
//
//		HLCD_vSendCommand(LCD_CLEAR);
//		HLCD_vSetCursor(0, 0);
//
//		HLCD_vSendString("ADC7: ");
//		HLCD_vSendNumber(voltage);
//
//		_delay_ms(1000);

	MDIO_vSetPinDirection(DIO_PORTA_INDEX, DIO_PIN0, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTA_INDEX, DIO_PIN1, DIO_PIN_DIRECTION_OUTPUT);

		while(1)
		{

			// cw
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0,DIO_PIN_HIGH);
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1,DIO_PIN_LOW);
			_delay_ms(500);
			// ccw
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1,DIO_PIN_HIGH);
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0,DIO_PIN_LOW);
			_delay_ms(500);

			// stop
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0,DIO_PIN_HIGH);
			MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1,DIO_PIN_LOW);
			_delay_ms(500);

}



	return 0;
}

