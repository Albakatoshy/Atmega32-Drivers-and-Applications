/*
 * TIMER0_prg.c
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 *

 */

#include "TIMER1_int.h"
#include <avr/io.h>

void (*G_Timer1_OVF_Interrupt_Handler)(void) = NULL;
void (*G_Timer1_OCR_Interrupt_Handler)(void) = NULL;
void (*G_Timer1_ICU_Interrupt_Handler)(void) = NULL;


void MTIMER1_vInit()
{
	//SELECT REQ MODE->15
	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	//NON-INVERTED MODE
	CLEAR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	//ICR =20000
	ICR1=20000;
	//PRESCALER->8
	CLEAR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);
}
void MTIMER1_vSetCompareMatch(u16 A_OCRR_VAL)
{
	OCR1A=A_OCRR_VAL;
}



//
//void MTIMERS_vSetIntervalAsych_CB(void (*Fptr)(void), u32 A_u32_Treq)
//{
//	G_Timer1_OVF_Interrupt_Handler =Fptr;
//	G_u32_Treq = A_u32_Treq;
//	MTIMER0_vStartTimer();
//}
//
//

void MTIMER1_vStartTimer(void) {
#if TIMER_1 == ENABLE
	// Clear the lower 3 bits of TCCR1B (CS12:0), then set the prescaler
	TCCR1B = (TCCR1B & 0xF8) | (0x07 & PRE_SCALER);
#endif
}



u16  MTIMER1_u16GetCaptureValue(void){
	return ICR1 ;
}


void MTIMER1_vSetTrigger(u8 TriggerType){
	switch(TriggerType){
		case TRIG_TYPE_RISING:
			// ICES1 bit is written to one, a rising (positive)
			SET_BIT(TCCR1B , 6);
			break;

		case TRIG_TYPE_FALLING:
			//e ICES1 bit is written to zero, a falling (negative) edge
			CLEAR_BIT(TCCR1B , 6);
			break;


	}
}

void MTIMER1_vEnableInterrupt(){
	SET_BIT(TIMSK , TIMSK_TICIE1);

}

void MTIMER1_vDisableInterrupt(){
	CLEAR_BIT(TIMSK , TIMSK_TICIE1);

}


void MTIMER1_vSetICU_CB(void (*Fptr)(void)){
	G_Timer1_ICU_Interrupt_Handler =Fptr;
}


void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if(G_Timer1_ICU_Interrupt_Handler){
		G_Timer1_ICU_Interrupt_Handler();
	}
}

