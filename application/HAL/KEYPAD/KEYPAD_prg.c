/*
 * KEYPAD_prg.c
 *
 *  Created on: Jul 21, 2025
 *      Author: anaal
 */
#include "KEYPAD_int.h"


void HKEYPAD_vInit() {

	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_C1, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_C2, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_C3, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_C4, DIO_PIN_DIRECTION_OUTPUT);

	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_C1, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_C2, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_C3, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_C4, DIO_PIN_HIGH);

	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_R1, DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_R2, DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_R3, DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(KEYPAD_PORT, KEYPAD_R4, DIO_PIN_DIRECTION_INPUT);

	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_R1, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_R2, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_R3, DIO_PIN_HIGH);
	MDIO_vSetPinValue(KEYPAD_PORT, KEYPAD_R4, DIO_PIN_HIGH);

}



u8 HKEYPAD_u8GetChar() {

	u8 Local_u8Button = RELEASED_BUTTON;
	static u8 KPD_ARR[MAX_ROW_SIZE][MAX_COL_SIZE] =
//			{ { '1', '2', '3', '4' }, { '5', '6', '7', '8' }, { '9', '0', '*',
//					'=' }, { 'A', 'B', 'C', 'D' } };
    {{ '7', '8', '9', '/' },    // Row A
    { '4', '5', '6', '*' },    // Row B
    { '1', '2', '3', '-' },    // Row C
    { 'C', '0', '=', '+' }};
	u8 Local_u8PinState;
	static u8 Local_u8ColKeyPad[MAX_COL_SIZE] = { KEYPAD_C1, KEYPAD_C2,
	KEYPAD_C3, KEYPAD_C4 };
	static u8 Local_u8RowKeyPad[MAX_ROW_SIZE] = { KEYPAD_R1, KEYPAD_R2,
	KEYPAD_R3, KEYPAD_R4 };

	for (u8 Local_u8ColIter = 0; Local_u8ColIter < MAX_COL_SIZE;
			Local_u8ColIter++) {
		MDIO_vSetPinValue(KEYPAD_PORT, Local_u8ColKeyPad[Local_u8ColIter],
				DIO_PIN_LOW);
		for (u8 Local_u8RowIter = 0; Local_u8RowIter < MAX_ROW_SIZE;
				Local_u8RowIter++) {
			Local_u8PinState = MDIO_u8GetPinValue(KEYPAD_PORT,
					Local_u8RowKeyPad[Local_u8RowIter]);
			if (Local_u8PinState == DIO_PIN_LOW) {
				Local_u8PinState = MDIO_u8GetPinValue(KEYPAD_PORT,
						Local_u8RowKeyPad[Local_u8RowIter]);
				_delay_ms(50);
				if (Local_u8PinState == DIO_PIN_LOW) {
					Local_u8Button = KPD_ARR[Local_u8RowIter][Local_u8ColIter];
					while (Local_u8PinState == DIO_PIN_LOW) {
						Local_u8PinState = MDIO_u8GetPinValue(KEYPAD_PORT,
								Local_u8RowKeyPad[Local_u8RowIter]);
					}
				}
			}

		}

		MDIO_vSetPinValue(KEYPAD_PORT, Local_u8ColKeyPad[Local_u8ColIter],
		DIO_PIN_HIGH);
	}
	return Local_u8Button;

}

u8 HKEYPAD_u8GetCharWait() {
	u8 Local_u8Button;
	do {
		Local_u8Button = HKEYPAD_u8GetChar();
		_delay_ms(10);  // prevent tight CPU lock
	} while (Local_u8Button == RELEASED_BUTTON);
	return Local_u8Button;
}

