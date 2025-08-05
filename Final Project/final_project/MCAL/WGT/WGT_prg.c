/*
 * WGT_prg.c
 *
 *  Created on: Jul 30, 2025
 *      Author: anaal
 */

#include "WGT_int.h"

void MWDT_vEnable(u8 A_u8TimerOut){

	//Set timeOut
	WDTCR= (WDTCR &0xF8) | (A_u8TimerOut&0x07) ;

	//Enable
	SET_BIT(WDTCR , WDTCR_WDE);


}


void MWDT_vDisable(void){

	WDTCR = 0b00011000;
	WDTCR = 0;

}
