/*
 * STEPPER_prg.c
 *
 *  Created on: Jul 22, 2025
 *      Author: anaal
 */


#include "STEPPER_int.h"
#include "STEPPER_cfg.h"

void HSTEPPER_vInit(const Stepper_t* stepper){
	MDIO_vSetPinDirection(stepper->port, stepper->pin1, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(stepper->port, stepper->pin2, DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(stepper->port, stepper->pin3 ,DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(stepper->port, stepper->pin4, DIO_PIN_DIRECTION_OUTPUT);
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


void HSTEPPER_vMoveTwoStepperSpecificAngle(const Stepper_t* stepper1, const Stepper_t* stepper2, u16 A_u16Angle) {
    u16 steps = A_u16Angle / STEPPER_STRIDE_ANGLE;
    for (u16 i = 0; i < (steps / 4); i++) {
        if (stepper1->dir == STEPPER_CW && stepper2->dir == STEPPER_CW) {
            // Step 1
            MDIO_vSetPinValue(stepper1->port, stepper1->pin1, DIO_PIN_HIGH);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin4, DIO_PIN_LOW);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin1, DIO_PIN_HIGH);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin4, DIO_PIN_LOW);
            _delay_ms(10);

            // Step 2
            MDIO_vSetPinValue(stepper1->port, stepper1->pin1, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin1, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_HIGH);
            _delay_ms(10);

            // Step 3
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_HIGH);
            _delay_ms(10);

            // Step 4
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin4, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin4, DIO_PIN_HIGH);
            _delay_ms(10);

            // Stop
            MDIO_vSetPinValue(stepper1->port, stepper1->pin4, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin4, DIO_PIN_LOW);

        } else {
            // CCW sequence
            // Step 1
            MDIO_vSetPinValue(stepper1->port, stepper1->pin4, DIO_PIN_HIGH);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin1, DIO_PIN_LOW);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin4, DIO_PIN_HIGH);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin1, DIO_PIN_LOW);
            _delay_ms(10);

            // Step 2
            MDIO_vSetPinValue(stepper1->port, stepper1->pin4, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin4, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_HIGH);
            _delay_ms(10);

            // Step 3
            MDIO_vSetPinValue(stepper1->port, stepper1->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin3, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_HIGH);
            _delay_ms(10);

            // Step 4
            MDIO_vSetPinValue(stepper1->port, stepper1->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper1->port, stepper1->pin1, DIO_PIN_HIGH);

            MDIO_vSetPinValue(stepper2->port, stepper2->pin2, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin1, DIO_PIN_HIGH);
            _delay_ms(10);

            // Stop
            MDIO_vSetPinValue(stepper1->port, stepper1->pin1, DIO_PIN_LOW);
            MDIO_vSetPinValue(stepper2->port, stepper2->pin1, DIO_PIN_LOW);
        }
    }
}

