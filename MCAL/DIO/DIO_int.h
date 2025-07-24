/*
 * DIO_interface.h
 *
 *  Created on: Jul 17, 2025
 *      Author: anaal
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../LIB/STD_TYPES.h"

#define DIO_PIN_DIRECTION_OUTPUT		1
#define DIO_PIN_DIRECTION_INPUT			0

#define DIO_PORT_DIRECTION_OUTPUT		0xFF
#define DIO_PORT_DIRECTION_INPUT		0x00

#define DIO_PORT_HIGH					0xFF
#define DIO_PORT_LOW					0x00

#define DIO_PIN_HIGH					1
#define DIO_PIN_LOW			     		0


#define DIO_PIN0						0
#define DIO_PIN1						1
#define DIO_PIN2						2
#define DIO_PIN3						3
#define DIO_PIN4						4
#define DIO_PIN5						5
#define DIO_PIN6						6
#define DIO_PIN7						7

#define DIO_PORTA_INDEX					0
#define DIO_PORTB_INDEX					1
#define DIO_PORTC_INDEX					2
#define DIO_PORTD_INDEX					3


void MDIO_vInit(void);

/*Pin Functions*/
void MDIO_vSetPinDirection(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinDirection);
void MDIO_vSetPinValue(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinVal);
u8   MDIO_u8GetPinValue(u8 A_u8PortNum , u8 A_u8PinNum);
void MDIO_vTogglePin(u8 A_u8PortNum , u8 A_u8PinNum);



/*PORT Functions*/
void MDIO_vSetPortDirection(u8 A_u8PortNum ,u8 A_u8PinDirection);
void MDIO_vSetPortValue(u8 A_u8PortNum , u8 A_u8PinVal);
u8   MDIO_u8GetPortValue(u8 A_u8PortNum);



#endif /* MCAL_DIO_DIO_INT_H_ */
