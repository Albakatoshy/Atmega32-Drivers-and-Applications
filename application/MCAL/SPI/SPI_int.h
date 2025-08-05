/*
 * SPI_int.h
 *
 *  Created on: Jul 31, 2025
 *      Author: anaal
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "SPI_cfg.h"
#include "SPI_prv.h"


void MSPI_voidInit(void);
u8 	 MSPI_u8Tranceive(u8 A_u8Byte);
void MSPI_vTransmit(u8 A_u8Byte);
u8   MSPI_u8Receive(void);

#endif /* MCAL_SPI_SPI_INT_H_ */
