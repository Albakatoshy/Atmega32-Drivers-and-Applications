#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../MCAL/USART/USART_int.h"
#include "../MCAL/WGT/WGT_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/I2C/I2C_int.h"
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

void MyCallbackFunction(void){
	TOGGLE_BIT(PORTB , PB3);
}


u8 key = 0;
u16 value = 0;
u8 digit_count = 0;

int main(void) {
	MDIO_vInit();
	HKEYPAD_vInit();
	HLCD_vInit();
	MUSART_vInit();

	MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX , DIO_PIN3 ,DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX , DIO_PIN4 ,DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN0 ,DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(DIO_PORTD_INDEX , DIO_PIN1 ,DIO_PIN_DIRECTION_OUTPUT);
	MTIMER0_vInit();

    MDIO_vSetPinValue(DIO_PORTB_INDEX , DIO_PIN4  , DIO_PIN_LOW);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_R1, DIO_PIN_HIGH);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX, DIO_PIN3, DIO_PIN_DIRECTION_OUTPUT);

    while (1) {
        MDIO_vSetPinValue(DIO_PORTB_INDEX , DIO_PIN4  , DIO_PIN_LOW);
		u8 KeyPad_data = HKEYPAD_u8GetCharWait();
        _delay_ms(200);
        HLCD_vSendChar(KeyPad_data);
		if (KeyPad_data >= '0' && KeyPad_data <= '9') {
			value = value * 10;
			value += (KeyPad_data - '0');
		}
		else if (KeyPad_data == '+' && value > 0){
			MUSART_vTransmit(value);
		    value = 0;
		}
    }
    return 0;

}




