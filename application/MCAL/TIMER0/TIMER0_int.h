/*
 * TIMER0_int.h
 *
 *  Created on: Jul 28, 2025
 *      Author: anaal
 */

#ifndef MCAL_TIMER0_TIMER0_INT_H_
#define MCAL_TIMER0_TIMER0_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_cfg.h"
#include "TIMER0_prv.h"


void MTIMER0_vInit(void);
void MTIMER0_vSetCompareMatch(u8 A_OCRR_VAL);
void MTIMERS_vSetIntervalAsych_CB(void (*Fptr)(void), u32 A_u32_Treq);
void MTIMER0_vStartTimer(void);
void MTIMER0_vStopTimer(void);
void MTIMERS_vSetIntervalAsych_CTC(void (*Fptr)(void) , u32 A_u32_Treq , u8 A_OCRR_VAL );

#endif /* MCAL_TIMER0_TIMER0_INT_H_ */
