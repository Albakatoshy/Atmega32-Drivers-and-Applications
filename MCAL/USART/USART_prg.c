/*
 * USART_prg.c
 *
 *  Created on: Jul 30, 2025
 *      Author: anaal
 */

#include "USART_int.h"


void MUSART_vInit(void){
	// enable receiver & transmitter
	UCSRB = 0b00011000;
	// enable UCSRC reg | asynch | no parity | 1 stop bit | 8 bit data | no clk polarity
	UCSRC = 0b10000110;
	UBRRL = 51;
	UBRRH = 0;

}

void MUSART_vTransmit(u8 A_u8Byte){
	/* Wait for empty transmit buffer */
	while(!GET_BIT(UCSRA, UCSRA_UDRE));
//	while ( !( UCSRA & (1<<UDRE)) )
//	;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;

}

u8  MUSART_vReceive(void){
	/* Wait for data to be received */
	while(!GET_BIT(UCSRA, UCSRA_RXC));
//	while ( !(UCSRA & (1<<RXC)) )
//	;
	/* Get and return received data from buffer */
	return UDR;
}

void MUSART_vWriteString(u8 *_data ,u8 str_len){
    u8 l_counter = 0 ;
     for(l_counter=0 ; l_counter < str_len ; l_counter++){
    	 MUSART_vTransmit(_data[l_counter]);
     }
}

