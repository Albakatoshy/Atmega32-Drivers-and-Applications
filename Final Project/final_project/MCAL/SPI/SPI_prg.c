/*
 * SPI_prg.c
 *
 *  Created on: Jul 31, 2025
 *      Author: anaal
 */


#include "SPI_int.h"

void MSPI_voidInit(void){

#if SPI_MODE == SPI_MASTER_MODE
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN5,DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN7,DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN6,DIO_PIN_DIRECTION_INPUT);

	//master mode
	SET_BIT(SPCR,4);

	//pre scaler of clock
	SET_BIT(SPCR, 0); // SPR0 = 1
	SET_BIT(SPCR, 1); // SPR1 = 1
	CLEAR_BIT(SPSR, 0);
	//enable
	SET_BIT(SPCR,6);

#endif

#if SPI_MODE == SPI_SLAVE_MODE
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN5,DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN7,DIO_PIN_DIRECTION_INPUT);
	MDIO_vSetPinDirection(DIO_PORTB_INDEX,DIO_PIN6,DIO_PIN_DIRECTION_OUTPUT);
	//slave mode
	CLEAR_BIT(SPCR,4);
	//enable
	SET_BIT(SPCR,6);

#endif



}

u8 MSPI_u8Tranceive(u8 A_u8Byte){
	SPDR=A_u8Byte;
	while(!GET_BIT(SPSR,7));
	return SPDR;
}

void MSPI_vTransmit(u8 A_u8Byte){
	/* Start transmission */
	 SPDR = A_u8Byte;
	 /* Wait for transmission complete */
	 while(!(SPSR & (1<<7)));
}

u8   MSPI_u8Receive(void){

	 /* Wait for reception complete */
	 while(!(SPSR & (1<<7)))
	 ;
	 /* Return data register */
	 return SPDR;
}

