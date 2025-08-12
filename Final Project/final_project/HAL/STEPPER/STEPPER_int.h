/*
 * STEPPER_int.h
 *
 *  Created on: Jul 22, 2025
 *      Author: anaal
 */

#ifndef HAL_STEPPER_STEPPER_INT_H_
#define HAL_STEPPER_STEPPER_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"

#define STEPPER_STRIDE_ANGLE	0.17578125


typedef enum {
	STEPPER_CW = 0,
	STEPPER_CCW
} Stepper_Direction_t;

typedef struct {

	u8 port;
	u8 pin1;
	u8 pin2;
	u8 pin3;
	u8 pin4;
	Stepper_Direction_t dir;
	u8 mode;

} Stepper_t;

void HSTEPPER_vInit(const Stepper_t* stepper);
void HSTEPPER_vMove();
void HSTEPPER_vMoveSpecificAngle(const Stepper_t* stepper , u16 A_u16Angle);
void HSTEPPER_vMoveTwoStepperSpecificAngle(const Stepper_t* stepper1, const Stepper_t* stepper2, u16 A_u16Angle);


#endif /* HAL_STEPPER_STEPPER_INT_H_ */


