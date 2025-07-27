/*
 * ADC_int.h
 *
 *  Created on: Jul 24, 2025
 *      Author: anaal
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../GL_INTERRUPT/GLOBAL_INT_int.h"
#include "ADC_prv.h"


void MADC_vInit(void);
u16 MADC_u16AdcRead(A_u8Channel);


#endif /* MCAL_ADC_ADC_INT_H_ */
