/*
 * SPI_prv.h
 *
 *  Created on: Jul 31, 2025
 *      Author: anaal
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_


#define SPDR          *((volatile u8*)0x2F)
#define SPSR          *((volatile u8*)0x2E)
#define SPCR          *((volatile u8*)0x2D)

#define SPI_MASTER_MODE		0
#define SPI_SLAVE_MODE		1


#endif /* MCAL_SPI_SPI_PRV_H_ */
