/*
 * GENERAL_INT_int.h
 *
 *  Created on: Jul 23, 2025
 *      Author: anaal
 */



#ifndef MCAL_EXT_INTERRUPT_GENERAL_INT_INT_H_
#define MCAL_EXT_INTERRUPT_GENERAL_INT_INT_H_

#include "GENERAL_INT_prv.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#define INT_GLOBAL_INTERRUPT_ENABLE			1
#define INT_GLOBAL_INTERRUPT_DISABLE		0

void MINT_vGlobalIntEnableDisable(u8 A_u8Mode);


#endif /* MCAL_EXT_INTERRUPT_GENERAL_INT_INT_H_ */
