/*
 * hal_lcd.c
 *
 *  Created on: Jul 20, 2025
 *      Author: anaal
 */
#include "LCD_cfg.h"
#include "LCD_int.h"


void HLCD_vSend4Bits(u8 nibble);
void HLCD_vEnablePulse();



void HLCD_vSendCommand(u8 A_u8Command){
#if LCD_MODE == LCD_8BIT_MODE
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPortValue(LCD_DATA_PORT , A_u8Command);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_HIGH  );
	_delay_ms(1);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_LOW);
#endif


#if LCD_MODE == LCD_4BIT_MODE
	// RS = 0 for command
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN_CFG, DIO_PIN_LOW);
	// RW = 0 for write
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN_CFG, DIO_PIN_LOW);

	// Send high nibble
	HLCD_vSend4Bits(A_u8Command >> 4);
	HLCD_vEnablePulse();

	// Send low nibble
	HLCD_vSend4Bits(A_u8Command & 0x0F);
	HLCD_vEnablePulse();
#endif
}


void HLCD_vSendChar(u8 A_u8Char){
#if LCD_MODE == LCD_8BIT_MODE
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS_PIN_CFG , DIO_PIN_HIGH  );
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW_PIN_CFG , DIO_PIN_LOW  );
	MDIO_vSetPortValue(LCD_DATA_PORT , A_u8Char);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_HIGH  );
	_delay_ms(1);
	MDIO_vSetPinValue(LCD_CONTROL_PORT , LCD_EN_PIN_CFG , DIO_PIN_LOW);
#endif

#if LCD_MODE == LCD_4BIT_MODE
	// RS = 1 for data
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN_CFG, DIO_PIN_HIGH);
	// RW = 0 for write
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN_CFG, DIO_PIN_LOW);

	// Send high nibble
	HLCD_vSend4Bits(A_u8Char >> 4);
	HLCD_vEnablePulse();

	// Send low nibble
	HLCD_vSend4Bits(A_u8Char & 0x0F);
	HLCD_vEnablePulse();
#endif

}


void HLCD_vInit(){
#if LCD_MODE == LCD_8BIT_MODE
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
#endif

#if LCD_MODE == LCD_4BIT_MODE
	MDIO_vSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN_CFG, DIO_PIN_DIRECTION_OUTPUT);
		MDIO_vSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN_CFG, DIO_PIN_DIRECTION_OUTPUT);
		MDIO_vSetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN_CFG, DIO_PIN_DIRECTION_OUTPUT);

		// Set high nibble (D4–D7) as output
		MDIO_vSetPinDirection(LCD_DATA_PORT, DIO_PIN4, DIO_PIN_DIRECTION_OUTPUT);
		MDIO_vSetPinDirection(LCD_DATA_PORT, DIO_PIN5, DIO_PIN_DIRECTION_OUTPUT);
		MDIO_vSetPinDirection(LCD_DATA_PORT, DIO_PIN6, DIO_PIN_DIRECTION_OUTPUT);
		MDIO_vSetPinDirection(LCD_DATA_PORT, DIO_PIN7, DIO_PIN_DIRECTION_OUTPUT);

		_delay_ms(50);

		HLCD_vSendCommand(0x33); // Initialize sequence
		HLCD_vSendCommand(0x32); // Set to 4-bit mode
		HLCD_vSendCommand(0x28); // 2 line, 5x8 font
		HLCD_vSendCommand(0x0C); // Display ON, cursor OFF
		HLCD_vSendCommand(0x01); // Clear display
		_delay_ms(2);
		HLCD_vSendCommand(0x06); // Entry mode set (increment cursor)
#endif
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

void HLCD_vSend4Bits(u8 nibble){
	MDIO_vSetPinValue(LCD_DATA_PORT, DIO_PIN4, (nibble >> 0) & 0x01);
	MDIO_vSetPinValue(LCD_DATA_PORT, DIO_PIN5, (nibble >> 1) & 0x01);
	MDIO_vSetPinValue(LCD_DATA_PORT, DIO_PIN6, (nibble >> 2) & 0x01);
	MDIO_vSetPinValue(LCD_DATA_PORT, DIO_PIN7, (nibble >> 3) & 0x01);
}

void HLCD_vEnablePulse(){
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN_CFG, DIO_PIN_HIGH);
	_delay_ms(1);
	MDIO_vSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN_CFG, DIO_PIN_LOW);
	_delay_ms(1);
}

