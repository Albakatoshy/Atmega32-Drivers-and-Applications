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


void HSTEPPER_vInit();
void HSTEPPER_vMove();
void HSTEPPER_vMoveSpecificAngle(u16 A_u8Angle);


#endif /* HAL_STEPPER_STEPPER_INT_H_ */


