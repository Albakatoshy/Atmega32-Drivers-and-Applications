#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD.int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"
#include "../MCAL/ADC/ADC_int.h"

#define F_CPU 	8000000L
#include <avr/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

void Motor_Control_Task(void);


volatile u32 ovf_count = 0;
volatile u8 state = 0;


int main() {
	MDIO_vInit();
	MTIMER0_vInit();
	MTIMER0_vStartTimer();
	MDIO_vSetPinDirection(DIO_PORTA_INDEX , DIO_PIN0 , DIO_PIN_DIRECTION_OUTPUT);
	MDIO_vSetPinDirection(DIO_PORTA_INDEX , DIO_PIN1 , DIO_PIN_DIRECTION_OUTPUT);
	MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);
	MTIMERS_vSetIntervalAsych_CB(Motor_Control_Task, 4);




	while (1) {


	}

	return 0;
}


void Motor_Control_Task(void)
{
    ovf_count++;

    switch (state)
    {
        case 0:
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0, DIO_PIN_HIGH);
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1, DIO_PIN_LOW);
            if (ovf_count >= 19350)
            {
                ovf_count = 0;
                state = 1;
            }
            break;

        case 1:
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0, DIO_PIN_LOW);
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1, DIO_PIN_HIGH);
            if (ovf_count >= 11650)
            {
                ovf_count = 0;
                state = 2;
            }
            break;

        case 2:
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN0, DIO_PIN_LOW);
            MDIO_vSetPinValue(DIO_PORTA_INDEX, DIO_PIN1, DIO_PIN_LOW);
            if (ovf_count >= 19350)
            {
                ovf_count = 0;
                state = 0;
            }
            break;
    }
}



