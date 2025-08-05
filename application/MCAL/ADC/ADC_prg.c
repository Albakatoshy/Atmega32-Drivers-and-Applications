/*
 * ADC_prg.c
 *
 *  Created on: Jul 24, 2025
 *      Author: anaal
 */

#include "ADC_int.h"


void MADC_vInit(void){
	ADMUX |= (1 << ADMUX_REFS0);
	ADMUX &= ~(1 << ADMUX_REFS1);


	CLEAR_BIT(ADMUX , ADMUX_ADLAR);

//	ADCSRA =(ADCSRA &(0xF8))  | ((0x07)&(0x06)) ;
	CLEAR_BIT(ADCSRA , ADCSRA_ADPS0);
	SET_BIT(ADCSRA , ADCSRA_ADPS1 );
	SET_BIT(ADCSRA , ADCSRA_ADPS2 );

	CLEAR_BIT(ADCSRA , ADCSRA_ADATE);
	CLEAR_BIT(ADCSRA , ADCSRA_ADIE);

	SET_BIT(ADCSRA , ADCSRA_ADEN);
}


u16 MADC_u16AdcRead(u8 A_u8Channel)
{

    ADMUX = (ADMUX & 0xE0) | (A_u8Channel & 0x0F);
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);


    SET_BIT(ADCSRA, ADCSRA_ADIF);


    return ADC;
}



