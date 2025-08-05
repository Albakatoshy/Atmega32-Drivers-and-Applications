/*
 * EEPROM_int.h
 *
 *  Created on: Aug 4, 2025
 *      Author: anaal
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/I2C/I2C_int.h"
#include "avr/delay.h"



#define DEVICE1       0
#define DEVICE2       1


void EEPROM_voidWriteDataByte(u8 A_u8Data, u16 A_u8DataLocation, u16 A_u8BlockNumber);
u8 EEPROM_u8ReadDataByte(u8 A_u8DataLocation, u8 A_u8BlockNumber);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */
