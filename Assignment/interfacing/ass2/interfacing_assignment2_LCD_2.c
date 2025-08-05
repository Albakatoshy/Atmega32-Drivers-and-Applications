#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include"../HAL/KEYPAD/KEYPAD_int.h"
#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

u8 customChar[8] = {
  0x00,
  0x0E,
  0x11,
  0x11,
  0x1F,
  0x11,
  0x11,
  0x00
};

u8 customChar2[] = {
  0x1F,
  0x01,
  0x1F,
  0x11,
  0x11,
  0x1F,
  0x00,
  0x00
};


int main()
{

	MDIO_vInit();
	HLCD_vInit();
	HLCD_vSendSpecialCharecter(0, customChar , 0 , 0);
	HLCD_vSendSpecialCharecter(1	 , customChar2 , 1 , 0);


	return 0 ;
}

