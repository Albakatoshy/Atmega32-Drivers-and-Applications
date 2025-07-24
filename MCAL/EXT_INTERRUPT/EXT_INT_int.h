/*
 * EXT_INT_int.h
 *
 *  Created on: Jul 23, 2025
 *      Author: anaal
 */



#ifndef MCAL_EXT_INTERRUPT_EXT_INT_INT_H_
#define MCAL_EXT_INTERRUPT_EXT_INT_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXT_INT_prv.h"


#define	EXT_INT_LOW_LEVEL_SENSTIVITY				0
#define	EXT_INT_ANY_LOGIC_CHANGE_SENSTIVITY			1
#define	EXT_INT_FALLING_EDGE_SENSTIVITY				2
#define	EXT_INT_RISING_EDGE_SENSTIVITY				3

#define	EXT_INT0	0
#define	EXT_INT1	1
#define	EXT_INT2	2

#define EXT_INT_ENABLE		1
#define EXT_INT_DISABLE		0

typedef enum {
    EXT_INT_OK = 0,
    NULL_POINTER_ERROR,
    INVALID_EXT_INT
} EXT_INT_STD_ERR;

void MEXT_INT_vEnableDisablePrepheral(u8 A_u8ExtIntx , u8 A_u8Mode );
void MEXT_INT_vIntSenstivity(u8 A_u8ExtTIntx , u8 A_u8Senstivity);
EXT_INT_STD_ERR MEXT_INT_InterruptHandler(u8 A_u8ExtTIntx , void (*LocalPtrInterruptHandler)(void));

#endif /* MCAL_EXT_INTERRUPT_EXT_INT_INT_H_ */
