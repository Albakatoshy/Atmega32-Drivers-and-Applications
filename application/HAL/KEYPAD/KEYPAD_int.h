/*
 * KEYPAD_int.h
 *
 *  Created on: Jul 21, 2025
 *      Author: anaal
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_cfg.h"

void HKEYPAD_vInit();
u8 HKEYPAD_u8GetChar();
u8 HKEYPAD_u8GetCharWait();

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
