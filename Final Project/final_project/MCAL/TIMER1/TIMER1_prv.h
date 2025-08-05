/*
 * TIMER0_prv.h
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 */

#ifndef MCAL_TIMER0_TIMER1_PRV_H_
#define MCAL_TIMER0_TIMER1_PRV_H_

#define TCCR1A       *((volatile u8*)0x4F)
#define TCCR1B       *((volatile u8*)0x4E)
#define TCNT1H       *((volatile u8*)0x4D)
#define TCNT1L       *((volatile u8*)0x4C)
#define TCNT1       *((volatile u16*)0x4C)
#define OCR1AH       *((volatile u8*)0x4B)
#define OCR1AL       *((volatile u8*)0x4A)
#define OCR1A        *((volatile u16*)0x4A)
#define OCR1BH       *((volatile u8*)0x49)
#define OCR1BL       *((volatile u8*)0x48)
#define OCR1B        *((volatile u16*)0x48)
#define ICR1H        *((volatile u8*)0x47)
#define ICR1L        *((volatile u8*)0x46)
#define ICR1         *((volatile u16*)0x46)
#define TIMSK        *((volatile u8*)0x59)
#define TIFR        *((volatile u8*)0x38)


#define TCCR1_FOC0			7
#define TCCR1_WGM00			6
#define TCCR1_COM01			5
#define TCCR1_COM00			4
#define TCCR1_WGM01			3
#define TCCR1_CS02			2
#define TCCR1_CS01			1
#define TCCR1_CS00			0


#define TIMSK_TICIE1		5


#define PRE_SCALER 	DIV_8
#define  DIV_8        2
#define  DIV_64       3


#endif /* MCAL_TIMER0_TIMER0_PRV_H_ */
