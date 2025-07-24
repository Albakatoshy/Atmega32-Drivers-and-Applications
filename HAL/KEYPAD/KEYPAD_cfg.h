/*
 * KEYPAD_cfg.h
 *
 *  Created on: Jul 21, 2025
 *      Author: anaal
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_


#define KEYPAD_PORT 	DIO_PORTB_INDEX

#define KEYPAD_C1		DIO_PIN0
#define KEYPAD_C2		DIO_PIN1
#define KEYPAD_C3		DIO_PIN2
#define KEYPAD_C4		DIO_PIN3
#define KEYPAD_R1		DIO_PIN4
#define KEYPAD_R2		DIO_PIN5
#define KEYPAD_R3		DIO_PIN6
#define KEYPAD_R4		DIO_PIN7

#define RELEASED_BUTTON		255

#define MAX_ROW_SIZE		4
#define MAX_COL_SIZE		4



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
