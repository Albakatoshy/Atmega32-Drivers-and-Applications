/*
 * ADC_prg.c
 *
 *  Created on: Jul 24, 2025
 *      Author: anaal
 */

#include "ADC_int.h"


void MADC_vInit(void){
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLEAR_BIT(ADMUX , ADMUX_REFS1);

	CLEAR_BIT(ADMUX , ADMUX_ADLAR);

	ADCSRA =(ADCSRA &(0xF8))  | (0x01) ;
	CLEAR_BIT(ADCSRA , ADCSRA_ADATE);
	CLEAR_BIT(ADCSRA , ADCSRA_ADIE);
}
