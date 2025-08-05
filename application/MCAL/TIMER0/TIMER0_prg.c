/*
 * TIMER0_prg.c
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 *

 */

#include "TIMER0_int.h"
#include <avr/io.h>

void (*G_Timer0_OVF_Interrupt_Handler)(void) = NULL;
void (*G_Timer0_OCR_Interrupt_Handler)(void) = NULL;
static u32 G_u32_Treq = 0;


void MTIMER0_vInit(void){
	SET_BIT(TCCR0, WGM01);           // CTC Mode
	CLEAR_BIT(TCCR0, WGM00);

	SET_BIT(TIMSK, OCIE0);           // Enable Compare Match interrupt

	TCCR0 &= 0b11111000;             // Clear prescaler bits
	TCCR0 |= DIV_64;      // Set prescaler
}


void MTIMER0_vSetCompareMatch(u8 A_OCRR_VAL){
	OCR0=A_OCRR_VAL;
}

void MTIMERS_vSetIntervalAsych_CB(void (*Fptr)(void), u32 A_u32_Treq)
{
	G_Timer0_OVF_Interrupt_Handler =Fptr;
	G_u32_Treq = A_u32_Treq;
	MTIMER0_vStartTimer();
}


void MTIMER0_vStartTimer(void){
#if	TIMER_0 == ENABLE
	TCCR0 = (TCCR0 & 0xF8) | (0x07 & PRE_SCALER);
#endif
}

void MTIMER0_vStopTimer(void){
#if	TIMER_0 == ENABLE
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);

#endif
}

void MTIMERS_vSetIntervalAsych_CTC(void (*Fptr)(void) , u32 A_u32_Treq , u8 A_OCRR_VAL )
{
	G_Timer0_OCR_Interrupt_Handler = Fptr;
	G_u32_Treq =A_u32_Treq;
	OCR0 = A_OCRR_VAL;
	MTIMER0_vStartTimer();
}



//void __vector_11(void)  __attribute__((signal));
//void __vector_11(void)
//{
//	static u32 lS_u32T_OVF = 0;
//	lS_u32T_OVF++;
//	if(lS_u32T_OVF == G_u32_Treq){
//		if(G_Timer0_OVF_Interrupt_Handler){
//			G_Timer0_OVF_Interrupt_Handler();
//			lS_u32T_OVF = 0;
//		}
//	}
//
//}


void __vector_10(void) __attribute__((signal, used));
void __vector_10(void)
{
    static volatile u32 lS_u32T_Counter = 0;

    lS_u32T_Counter++;

    if (lS_u32T_Counter >= G_u32_Treq) {
        lS_u32T_Counter = 0;  // Reset first to avoid reentrancy issues

        if (G_Timer0_OCR_Interrupt_Handler != NULL) {
            G_Timer0_OCR_Interrupt_Handler();  // Call the user callback
        }
    }
}

