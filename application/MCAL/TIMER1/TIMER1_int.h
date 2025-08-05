/*
 * TIMER0_int.h
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 */

#ifndef MCAL_TIMER0_TIMER1_INT_H_
#define MCAL_TIMER0_TIMER1_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER1_cfg.h"
#include "TIMER1_prv.h"
#include "../../MCAL/EXT_INTERRUPT/EXT_INT_int.h"


#define TRIG_TYPE_RISING	0
#define TRIG_TYPE_FALLING	1


void MTIMER1_vInit(void);
void MTIMER1_vSetCompareMatch(u16 A_OCRR_VAL);
//void MTIMERS_vSetIntervalAsych_CB(void (*Fptr)(void), u32 A_u32_Treq);
void MTIMER1_vStartTimer(void);

void MTIMER1_vSetICU_CB(void (*Fptr)(void));
u16  MTIMER1_u16GetCaptureValue(void);
void MTIMER1_vSetTrigger(u8 TriggerType);
void MTIMER1_vEnableInterrupt();
void MTIMER1_vDisableInterrupt();


//void MTIMER0_vStopTimer(void);
//void MTIMERS_vSetIntervalAsych_CTC(void (*Fptr)(void) , u32 A_u32_Treq , u8 A_OCRR_VAL );

#endif /* MCAL_TIMER0_TIMER0_INT_H_ */
