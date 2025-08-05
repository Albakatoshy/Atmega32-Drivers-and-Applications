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
	HKEYPAD_vInit();
	MDIO_vSetPortDirection(DIO_PORTC_INDEX , DIO_PIN_DIRECTION_OUTPUT);
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

while(1){
    u8 key = HKEYPAD_u8GetChar();

    switch (key) {
        case '1':
            MDIO_vSetPortValue(DIO_PORTC_INDEX, 0xFF); // All ON
            break;
        case '2':
            MDIO_vSetPortValue(DIO_PORTC_INDEX, 0x00); // All OFF
            break;
        case '3':
               for (u8 i = 0; i < 3; i++) {
                   MDIO_vSetPortValue(DIO_PORTC_INDEX, 0xFF);
                   _delay_ms(200);
                   MDIO_vSetPortValue(DIO_PORTC_INDEX, 0x00);
                   _delay_ms(200);
               }
		   break;
        case '4':
                for (u8 i = 0; i < 8; i++) {
                    MDIO_vSetPortValue(DIO_PORTC_INDEX, (1 << i));
                    _delay_ms(100);
                }
			break;
            case '5':
                for (u8 i = 7; i >= 0; i--) {
                    MDIO_vSetPortValue(DIO_PORTC_INDEX, (1 << i));
                    _delay_ms(100);
                }
			break;

        default:
        	break;
}

}



	return 0;
}

