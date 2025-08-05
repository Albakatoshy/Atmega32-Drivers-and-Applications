#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include"../HAL/KEYPAD/KEYPAD_int.h"
#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


void WriteNameInSinWave(const char* name)
{
    u8 i = 0;
    u8 row = 0;

    while (name[i] != '\0') {
    	if (i % 2 == 0) {
			row = 0;
		} else {
			row = 1;
		}

        HLCD_vSetCursor(i, row);       // Column = i, Row = wave
        HLCD_vSendChar(name[i]);

        i++;
        _delay_ms(250);
    }
}

int main()
{
	MDIO_vInit();
	HLCD_vInit();
	WriteNameInSinWave("ABDALRAHMAN");

	return 0 ;
}

