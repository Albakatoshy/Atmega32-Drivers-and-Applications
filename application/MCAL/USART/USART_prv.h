/*
 * USART_prv.h
 *
 *  Created on: Jul 30, 2025
 *      Author: anaal
 */

#ifndef MCAL_USART_USART_PRV_H_
#define MCAL_USART_USART_PRV_H_



#define UDR         *((volatile u8*)0x2C)
#define UCSRA       *((volatile u8*)0x2B)
#define UCSRB       *((volatile u8*)0x2A)
#define UCSRC       *((volatile u8*)0x40)
#define UBRRL       *((volatile u8*)0x29)
#define UBRRH		*((volatile u8*)(0x40))


#define UCSRA_MPCM			0
#define UCSRA_U2X			1
#define UCSRA_PE			2
#define UCSRA_DOR			3
#define UCSRA_FE			4
#define UCSRA_UDRE			5
#define UCSRA_TXC			6
#define UCSRA_RXC			7

#define UCSRB_TXB8			0
#define UCSRB_RXB8			1
#define UCSRB_UCSZ2			2
#define UCSRB_TXEN			3
#define UCSRB_RXEN			4
#define UCSRB_UDRIE			5
#define UCSRB_TXCIE			6
#define UCSRB_RXCIE			7


#endif /* MCAL_USART_USART_PRV_H_ */
