/*
 * STEPPER_prg.c
 *
 *  Created on: Jul 22, 2025
 *      Author: anaal
 */


#include "STEPPER_int.h"
#include "STEPPER_cfg.h"

void HSTEPPER_vInit(){
	MDIO_vSetPinDirection(STEPPER_CONTROL_PORT, B, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(STEPPER_CONTROL_PORT, P, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(STEPPER_CONTROL_PORT, Y, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(STEPPER_CONTROL_PORT, O, DIO_PIN_DIRECTION_OUTPUT);
}

void HSTEPPER_vMove(){
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, B, DIO_PIN_HIGH);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, P, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, Y, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, O, DIO_PIN_LOW);
	_delay_ms(10);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, B, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, P, DIO_PIN_HIGH);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, Y, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, O, DIO_PIN_LOW);
	_delay_ms(10);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, B, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, P, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, Y, DIO_PIN_HIGH);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, O, DIO_PIN_LOW);
	_delay_ms(10);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, B, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, P, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, Y, DIO_PIN_LOW);
	MDIO_vSetPinValue(STEPPER_CONTROL_PORT, O, DIO_PIN_HIGH);
	_delay_ms(10);
}



void HSTEPPER_vMoveSpecificAngle(const Stepper_t* stepper , u16 A_u16Angle) {
	u16 steps = A_u16Angle / STEPPER_STRIDE_ANGLE;

	for (u16 i = 0; i < (steps / 4); i++) {
		if (stepper->dir == STEPPER_CW) {
			// CW sequence
			MDIO_vSetPinValue(stepper->port, stepper->pin1, DIO_PIN_HIGH);
			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_LOW);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin1, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_HIGH);
			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_LOW);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_HIGH);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_HIGH);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_LOW); // stop
		} else {
			// CCW sequence
			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_HIGH);
			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin1, DIO_PIN_LOW);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin4, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_HIGH);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin3, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_HIGH);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin2, DIO_PIN_LOW);
			MDIO_vSetPinValue(stepper->port, stepper->pin1, DIO_PIN_HIGH);
			_delay_ms(10);

			MDIO_vSetPinValue(stepper->port, stepper->pin1, DIO_PIN_LOW); // stop
		}
	}
}

