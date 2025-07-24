/*
 * LCD.int.h
 *
 *  Created on: Jul 20, 2025
 *      Author: anaal
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_cfg.h"


#define LCD_CLEAR                      	0x01
#define LCD_RETURN_HOME                	0x02
#define LCD_ENRTY_MODE                 	0x06
#define LCD_CURSOR_OFF_DISPLAY_ON      	0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF     	0x08
#define LCD_CURSOR_ON_BLINKING_ON      	0x0F
#define LCD_CURSOR_ON_BLINKING_OFF     	0x0E
#define LCD_DISPLAY_SHIFT_RIGHT        	0x1C
#define LCD_DISPLAY_SHIFT_LEFT         	0x18
#define LCD_8BIT_MODE_2_LINE           	0x38
#define LCD_4BIT_MODE_2_LINE           	0x28
#define LCD_CGRAM_START                	0x40
#define LCD_DDRAM_START                	0x80

#define LINE1_BASE  0x00
#define LINE2_BASE  0x40


void HLCD_vInit();
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vSetCursor(u8 Copy_u8X,u8 Copy_u8Y);
void HLCD_vSendString(char *StringData);
void HLCD_vSendSpecialCharecter(u8 Copy_u8BlockNum, u8 *Pu8ArrayPattern, u8 Copy_u8X, u8 Copy_u8Y);
void HLCD_vSendNumber(u16 num);
