/*
 * GENERAL_INT_prg.c
 *
 *  Created on: Jul 23, 2025
 *      Author: anaal
 */

#include "GLOBAL_INT_int.h"

void MINT_vGlobalIntEnableDisable(u8 A_u8Mode){
	switch(A_u8Mode){
		case INT_GLOBAL_INTERRUPT_ENABLE:
			SET_BIT(SREG , GLOBAL_INTERRUPT_BIT);
			break;

		case INT_GLOBAL_INTERRUPT_DISABLE:
			CLEAR_BIT(SREG , GLOBAL_INTERRUPT_BIT);
			break;
	}
}
