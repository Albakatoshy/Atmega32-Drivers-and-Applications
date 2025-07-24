/*
 * SEVEN_SEG_prg.c
 *
 *  Created on: Jul 20, 2025
 *      Author: anaal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SEVEN_SEG_int.h"
#include "SEVEN_SEG_config.h"

static u8 seven_seg_commnoc_cathode[10] = { 0b11000000, // 0
		0b11111001, // 1
		0b10100100, // 2
		0b10110000, // 3
		0b10011001, // 4
		0b10010010, // 5
		0b10000010, // 6
		0b11111000, // 7
		0b10000000, // 8
		0b10010000  // 9
		};

void HSSD_vInit(void) {
	MDIO_vSetPortValue(HSSD_INIT_PORT, DIO_PORT_HIGH);
}

void HSSD_DisplayNumber(u8 A_u8Num) {
	MDIO_vSetPortDirection(HSSD_INIT_PORT , DIO_PORT_DIRECTION_OUTPUT);
	if (A_u8Num < 10){

	#if 	HSSD_TYPE == HSSD_COMMON_CATHODE
		MDIO_vSetPortValue(HSSD_INIT_PORT, seven_seg_commnoc_cathode[A_u8Num]);

	#elif 	HSSD_TYPE == HSSD_COMMON_ANODE
		MDIO_vSetPortValue(HSSD_INIT_PORT , ~(seven_seg_commnoc_cathode[A_u8Num]));

	#endif
	}
	else{
		MDIO_vSetPortValue(HSSD_INIT_PORT , (seven_seg_commnoc_cathode[1]));
	}
}
