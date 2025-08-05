/*
 * STEPPER_cfg.h
 *
 *  Created on: Jul 22, 2025
 *      Author: anaal
 */

#ifndef HAL_STEPPER_STEPPER_CFG_H_
#define HAL_STEPPER_STEPPER_CFG_H_



#if !proteus_test
#define STEPPER_CONTROL_PORT	DIO_PORTA_INDEX

#define B	DIO_PIN0
#define P	DIO_PIN1
#define Y	DIO_PIN2
#define O	DIO_PIN3
#endif

#define STEPPER_DIR_CW   0
#define STEPPER_DIR_CCW  1




#endif /* HAL_STEPPER_STEPPER_CFG_H_ */
