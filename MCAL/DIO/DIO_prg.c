/*
 * DIO_prg.c
 *
 *  Created on: Jul 17, 2025
 *      Author: anaal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_prv.h"
#include "DIO_int.h"


void MDIO_vInit(void){

	DDRA 	= 0;
	DDRB 	= 0;
	DDRC 	= 0;
	DDRD 	= 0;

	PORTA 	= 0;
	PORTB  	= 0;
	PORTC  	= 0;
	PORTD  	= 0;

	PINA 	= 0;
	PINB	= 0;
	PINC	= 0;
	PIND	= 0;
}

void MDIO_vSetPinDirection(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinDirection){
	if(A_u8PinDirection == DIO_PIN_DIRECTION_OUTPUT){
		switch(A_u8PortNum){
			case DIO_PORTA_INDEX:
				SET_BIT(DDRA , A_u8PinNum );
				break;
			case DIO_PORTB_INDEX:
				SET_BIT(DDRB , A_u8PinNum );
				break;
			case DIO_PORTC_INDEX:
				SET_BIT(DDRC , A_u8PinNum );
				break;
			case DIO_PORTD_INDEX:
				SET_BIT(DDRD , A_u8PinNum );
				return;

			default:break;
		}
	}
	else if(A_u8PinDirection == DIO_PIN_DIRECTION_INPUT){
		switch(A_u8PortNum){
			case DIO_PORTA_INDEX:
				CLEAR_BIT(DDRA , A_u8PinNum );
				break;
			case DIO_PORTB_INDEX:
				CLEAR_BIT(DDRB , A_u8PinNum );
				break;
			case DIO_PORTC_INDEX:
				CLEAR_BIT(DDRC , A_u8PinNum );
				break;
			case DIO_PORTD_INDEX:
				CLEAR_BIT(DDRD , A_u8PinNum );
				break;

			default:break;
		}
	}
	else{

	}
}



void MDIO_vSetPinValue(u8 A_u8PortNum , u8 A_u8PinNum , u8 A_u8PinVal) {

	if(A_u8PinVal == DIO_PIN_HIGH){
		switch(A_u8PortNum){
			case DIO_PORTA_INDEX:
				SET_BIT(PORTA , A_u8PinNum );
				break;
			case DIO_PORTB_INDEX:
				SET_BIT(PORTB , A_u8PinNum );
				break;
			case DIO_PORTC_INDEX:
				SET_BIT(PORTC , A_u8PinNum );
				break;
			case DIO_PORTD_INDEX:
				SET_BIT(PORTD , A_u8PinNum );
				break;

			default:break;
			}
		}
	else if(A_u8PinVal == DIO_PIN_LOW){
		switch(A_u8PortNum){
			case DIO_PORTA_INDEX:
				CLEAR_BIT(PORTA , A_u8PinNum );
				break;
			case DIO_PORTB_INDEX:
				CLEAR_BIT(PORTB , A_u8PinNum );
				break;
			case DIO_PORTC_INDEX:
				CLEAR_BIT(PORTC , A_u8PinNum );
				break;
			case DIO_PORTD_INDEX:
				CLEAR_BIT(PORTD , A_u8PinNum );
				break;

			default:break;
			}
		}
	else{

	}
}


u8 MDIO_u8GetPinValue(u8 A_u8PortNum , u8 A_u8PinNum){
	u8 L_u8PinVal = 0;

	switch (A_u8PortNum) {
		case DIO_PORTA_INDEX:
			L_u8PinVal = GET_BIT(PINA , A_u8PinNum );
			break;
		case DIO_PORTB_INDEX:
			L_u8PinVal = GET_BIT(PINB , A_u8PinNum );
			break;
		case DIO_PORTC_INDEX:
			L_u8PinVal = GET_BIT(PINC , A_u8PinNum );
			break;
		case DIO_PORTD_INDEX:
			L_u8PinVal = GET_BIT(PIND , A_u8PinNum );
			break;
		default:
			return 0xFF;
	}

	return L_u8PinVal;
}

void DIO_vTogglePin(u8 A_u8PortNum , u8 A_u8PinNum){
	switch(A_u8PortNum){
		case DIO_PORTA_INDEX:
			TOGGLE_BIT(PORTA , A_u8PinNum );
			break;
		case DIO_PORTB_INDEX:
			TOGGLE_BIT(PORTB , A_u8PinNum );
			break;
		case DIO_PORTC_INDEX:
			TOGGLE_BIT(PORTC , A_u8PinNum );
			break;
		case DIO_PORTD_INDEX:
			TOGGLE_BIT(PORTD , A_u8PinNum );
			break;

		default:break;
		}
}

/*PORT Functions*/
void MDIO_vSetPortDirection(u8 A_u8PortNum ,u8 A_u8PinDirection){
	switch(A_u8PortNum){
		case DIO_PORTA_INDEX:
			DDRA = A_u8PinDirection?0xff:0;
			break;
		case DIO_PORTB_INDEX:
			DDRB = A_u8PinDirection?0xff:0;
			break;
		case DIO_PORTC_INDEX:
			DDRC = A_u8PinDirection?0xff:0;
			break;
		case DIO_PORTD_INDEX:
			DDRD = A_u8PinDirection?0xff:0;
			break;
		default:break;
	}
}


void MDIO_vSetPortValue(u8 A_u8PortNum , u8 A_u8PinVal){
	switch(A_u8PortNum){
		case DIO_PORTA_INDEX:
			PORTA = A_u8PinVal;
			break;
		case DIO_PORTB_INDEX:
			PORTB = A_u8PinVal;
			break;
		case DIO_PORTC_INDEX:
			PORTC = A_u8PinVal;
			break;
		case DIO_PORTD_INDEX:
			PORTD = A_u8PinVal;
			break;

		default:break;
	}
}


u8  MDIO_u8GetPortValue(u8 A_u8PortNum ){
	u8 L_u8PortValue = 0;
	switch(A_u8PortNum){
		case DIO_PORTA_INDEX:
			L_u8PortValue =  PINA;
			break;
		case DIO_PORTB_INDEX:
			L_u8PortValue =  PINB;
			break;
		case DIO_PORTC_INDEX:
			L_u8PortValue =  PINC;
			break;
		case DIO_PORTD_INDEX:
			L_u8PortValue =  PIND;
			break;
		default:break;
	}

	return L_u8PortValue;
}
