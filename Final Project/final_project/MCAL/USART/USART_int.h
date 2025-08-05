/*
 * USART_int.h
 *
 *  Created on: Jul 30, 2025
 *      Author: anaal
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_cfg.h"
#include "USART_prv.h"

void MUSART_vInit(void);
void MUSART_vTransmit(u8 A_u8Byte);
u8   MUSART_vReceive(void);
void MUSART_vWriteString(u8 *_data ,u8 str_len);


#endif /* MCAL_USART_USART_INT_H_ */
