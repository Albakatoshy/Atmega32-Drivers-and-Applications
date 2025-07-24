/*
 * hal_lcd.c
 *
 *  Created on: Jul 20, 2025
 *      Author: anaal
 */
#include "LCD.int.h"
#include "LCD_cfg.h"



void HLCD_vSendCommand(u8 A_u8Command){
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPortValue(LCD_DATA_PORT , A_u8Command);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_HIGH  );
	_delay_ms(1);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_LOW);

}


void HLCD_vSendChar(u8 A_u8Char){
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN_CFG , DIO_PIN_HIGH  );
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPortValue(LCD_DATA_PORT , A_u8Char);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_HIGH  );
	_delay_ms(1);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_LOW);
}


void HLCD_vInit(){
	MDIO_vSetPortDirection(LCD_DATA_PORT , DIO_PORT_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(LCD_CONTROL_PORT , LCD_RS_PIN_CFG , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(LCD_CONTROL_PORT , LCD_RW_PIN_CFG , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_DIRECTION_OUTPUT);

	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(20);
	HLCD_vSendCommand(0b00000110);
}



void HLCD_vSendString(char *StringData)
{
	u8 Local_u8Iterator=0;
	while(StringData[Local_u8Iterator]!='\0')
	{
		HLCD_vSendChar(StringData[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}

void HLCD_vSetCursor(u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Local_u8Position = 0;
    switch(Copy_u8Y)
    {
        case 0:
            Local_u8Position = Copy_u8X + LINE1_BASE;
            break;
        case 1:
            Local_u8Position = Copy_u8X + LINE2_BASE;
            break;
    }

    HLCD_vSendCommand(Local_u8Position + LCD_DDRAM_START);
}

void HLCD_vSendSpecialCharecter(u8 Copy_u8BlockNum,u8 *Pu8ArrayPattern,u8 Copy_u8X,u8 Copy_u8Y)
{

	u8 Local_u8Position=Copy_u8BlockNum*8;
	HLCD_vSendCommand(Local_u8Position+LCD_CGRAM_START);

	for(u8 i=0;i<8;i++)
	{
		HLCD_vSendChar(Pu8ArrayPattern[i]);
	}

	HLCD_vSetCursor(Copy_u8X,Copy_u8Y);
	HLCD_vSendChar(Copy_u8BlockNum);
}


void HLCD_vSendNumber(u16 num) {
    if (num == 0) {
        HLCD_vSendChar('0');
        return;
    }

    u8 digits[5];  // enough for up to 65535
    s8 i = 0;

    while (num > 0) {
        digits[i++] = (num % 10) + '0';
        num /= 10;
    }

    // print digits in reverse
    while (--i >= 0) {
        HLCD_vSendChar(digits[i]);
    }
}

