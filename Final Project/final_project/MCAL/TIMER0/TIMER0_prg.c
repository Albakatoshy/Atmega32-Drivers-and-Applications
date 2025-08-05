/*
 * TIMER0_prg.c
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 *

 */

#include "TIMER0_int.h"
#include <avr/io.h>

#define SERVO_DDR   DDRB
#define SERVO_PORT  PORTB
#define SERVO_PIN   PB3

volatile uint16_t pulse_width_us = 1500;  // Default to 90°
volatile uint16_t tick_counter = 0;

void (*G_Timer0_OVF_Interrupt_Handler)(void) = NULL;
void (*G_Timer0_OCR_Interrupt_Handler)(void) = NULL;
static u32 G_u32_Treq = 0;

void MTIMER0_vInit(void){
    SERVO_DDR |= (1 << SERVO_PIN);

    // Timer0 normal mode, prescaler = 8 → 1 tick = 1µs
    TCCR0 = (1 << CS01);

    // Initial timer value for 10µs overflow
    TCNT0 = 256 - 10;

    // Enable overflow interrupt
    TIMSK |= (1 << TOIE0);

    MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
}

void SetServoAngle_Timer0(u8 angle) {
    if (angle > 180) angle = 180;
    // Map 0–180° to 1000–2000 µs
    pulse_width_us = ((angle * 1000UL) / 180) + 1000;
}

ISR(TIMER0_OVF_vect) {
    // Reload timer to overflow after 10µs
    TCNT0 = 256 - 10;
    tick_counter++;

    if (tick_counter == 1) {
        // Start pulse
        SERVO_PORT |= (1 << SERVO_PIN);
    } else if (tick_counter == (pulse_width_us / 10)) {
        // End pulse
        SERVO_PORT &= ~(1 << SERVO_PIN);
    } else if (tick_counter >= 2000) {
        // 20 ms complete
        tick_counter = 0;
    }
}


//void MTIMER0_vSetCompareMatch(u8 A_OCRR_VAL){
//	OCR0=A_OCRR_VAL;
//}
//
//void MTIMERS_vSetIntervalAsych_CB(void (*Fptr)(void), u32 A_u32_Treq)
//{
//	G_Timer0_OVF_Interrupt_Handler =Fptr;
//	G_u32_Treq = A_u32_Treq;
//	MTIMER0_vStartTimer();
//}
//
//
//void MTIMER0_vStartTimer(void){
//#if	TIMER_0 == ENABLE
//	TCCR0 = (TCCR0 & 0xF8) | (0x07 & PRE_SCALER);
//#endif
//}
//
//void MTIMER0_vStopTimer(void){
//#if	TIMER_0 == ENABLE
//	CLEAR_BIT(TCCR0, 0);
//	CLEAR_BIT(TCCR0, 1);
//	CLEAR_BIT(TCCR0, 2);
//
//#endif
//}
//
//void MTIMERS_vSetIntervalAsych_CTC(void (*Fptr)(void) , u32 A_u32_Treq , u8 A_OCRR_VAL )
//{
//	G_Timer0_OCR_Interrupt_Handler = Fptr;
//	G_u32_Treq =A_u32_Treq;
//	OCR0 = A_OCRR_VAL;
//	MTIMER0_vStartTimer();
//}



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



//void __vector_10(void)  __attribute__((signal));
//void __vector_10(void)
//{
//	static u32 lS_u32T_Counter = 0;
//	lS_u32T_Counter++;
//	if(lS_u32T_Counter == G_u32_Treq){
//		if(G_Timer0_OCR_Interrupt_Handler){
//			G_Timer0_OCR_Interrupt_Handler();
//			lS_u32T_Counter = 0;
//		}
//	}
//
//}

//void __vector_10(void) __attribute__((signal));
//void __vector_10(void) {
//    tick_counter++;
//
//    if (tick_counter == 1) {
//        // Start pulse
//        MDIO_vSetPinValue(SERVO_PORT, SERVO_PIN, DIO_PIN_HIGH);
//    }
//    if (tick_counter == pulse_width / 10) {
//        // End pulse
//        MDIO_vSetPinValue(SERVO_PORT, SERVO_PIN, DIO_PIN_LOW);
//    }
//    if (tick_counter >= 2000) {
//        tick_counter = 0;  // 20ms cycle complete
//    }
//}

