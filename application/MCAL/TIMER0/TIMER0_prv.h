/*
 * TIMER0_prv.h
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 */

#ifndef MCAL_TIMER0_TIMER0_PRV_H_
#define MCAL_TIMER0_TIMER0_PRV_H_

#define TCCR0       *((volatile u8*)0X53)
#define TCNT0       *((volatile u8*)0X52)
#define OCR0        *((volatile u8*)0X5C)
#define TIMSK       *((volatile u8*)0X59)

#define TCCR0_FOC0			7
#define TCCR0_WGM00			6
#define TCCR0_COM01			5
#define TCCR0_COM00			4
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0


#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0


#define PRE_SCALER 	DIV_8
#define  DIV_8        2
#define  DIV_64       3


#endif /* MCAL_TIMER0_TIMER0_PRV_H_ */
