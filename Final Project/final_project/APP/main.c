#define F_CPU 8000000UL
#include <util/delay.h>

/**********************************************************
 * Project     : Robotic Arm Controller
 * Description : Controls 3 stepper motors and 1 servo via keypad.
 * name : Abdalrahman
 *
 * Pin Mapping:
 *  - PORTB        → Keypad
 *  - PORTC        → LCD (4-bit mode)
 *  - PORTA 0–3    → Stepper 1
 *  - PORTA 4–7    → Stepper 2
 *  - PORTD 0–3    → Stepper 3
 *  - PORTD Pin 5  → Servo (PWM via Timer1)
 **********************************************************/

/* Standard Libraries */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/* MCAL Includes */
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INT_int.h"
#include "../MCAL/GL_INTERRUPT/GLOBAL_INT_int.h"
#include "../MCAL/TIMER0/TIMER0_int.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../MCAL/USART/USART_int.h"
#include "../MCAL/WGT/WGT_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/I2C/I2C_int.h"
#include "../MCAL/ADC/ADC_int.h"

/* HAL Includes */
#include "../HAL/SEVEN_SEG/SEVEN_SEG_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include "../HAL/STEPPER/STEPPER_int.h"

/* Definitions */
#define SERVO_PIN       DIO_PIN5
#define SERVO_PORT      DIO_PORTD_INDEX
#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180
#define SERVO_STEP      20

#define STEPPER_STEP_ANGLE  35

/* Function Prototypes */
void SetServoAngle(u8 angle);
void DisplayMessage(const char* msg);

/* Entry Point */
int main(void)
{

    Stepper_t stepper1 = {
        .port = DIO_PORTA_INDEX,
        .pin1 = DIO_PIN0,
        .pin2 = DIO_PIN1,
        .pin3 = DIO_PIN2,
        .pin4 = DIO_PIN3,
        .dir  = STEPPER_CW
    };


    Stepper_t stepper2 = {
        .port = DIO_PORTD_INDEX,
        .pin1 = DIO_PIN0,
        .pin2 = DIO_PIN1,
        .pin3 = DIO_PIN2,
        .pin4 = DIO_PIN3,
        .dir  = STEPPER_CW
    };

    Stepper_t stepper3 = {
        .port = DIO_PORTA_INDEX,
        .pin1 = DIO_PIN4,
        .pin2 = DIO_PIN5,
        .pin3 = DIO_PIN6,
        .pin4 = DIO_PIN7,
        .dir  = STEPPER_CW
    };

    /* Initialize Peripherals */
    HKEYPAD_vInit();
    HLCD_vInit();
    HSTEPPER_vInit(&stepper1);
    HSTEPPER_vInit(&stepper2);
    HSTEPPER_vInit(&stepper3);
    MTIMER1_vInit();
    MTIMER1_vStartTimer();
    MINT_vGlobalIntEnableDisable(INT_GLOBAL_INTERRUPT_ENABLE);

    /* Configure I/O Pins */
    MDIO_vSetPinDirection(SERVO_PORT, SERVO_PIN, DIO_PIN_DIRECTION_OUTPUT);

    /* Stepper Motor Instances */


    /* Control Variables */
    u8 servo_angle = 90;
    u8 stepper1_angle = 0;
    u8 stepper2_angle = 0;
    u8 stepper3_angle = 0;
    u8 key_pressed = 0;
    u8 gripper_open = 1;

    SetServoAngle(servo_angle);

    while (1)
    {
        key_pressed = HKEYPAD_u8GetCharWait();

        switch (key_pressed)
        {
            case '1': // Stepper 1 CW
                DisplayMessage("Stepper1: CW");
                stepper1.dir = STEPPER_CW;
                stepper1_angle += STEPPER_STEP_ANGLE;
                break;

            case '2': // Stepper 1 CCW
                DisplayMessage("Stepper1: CCW");
                stepper1.dir = STEPPER_CCW;
                stepper1_angle += STEPPER_STEP_ANGLE;
                break;

            case '3': // Stepper 3 CW
                DisplayMessage("Stepper3: CW");
                stepper3.dir = STEPPER_CW;
                stepper3_angle += STEPPER_STEP_ANGLE;
                break;

            case '4': // Stepper 3 CCW
                DisplayMessage("Stepper3: CCW");
                stepper3.dir = STEPPER_CCW;
                stepper3_angle += STEPPER_STEP_ANGLE;
                break;
            case '6': // Stepper 3 CW
                DisplayMessage("Stepper2: C CW");
                stepper2.dir = STEPPER_CCW;
                stepper2_angle += STEPPER_STEP_ANGLE;
                break;

            case '7': // Stepper 3 CCW
                DisplayMessage("Stepper2: CW");
                stepper2.dir = STEPPER_CW;
                stepper2_angle += STEPPER_STEP_ANGLE;
                break;

            case '5': // Toggle gripper
                if (gripper_open)
                {
                    SetServoAngle(180); // Close gripper
                    gripper_open = 0;
                    DisplayMessage("Gripper Closed");
                }
                else
                {
                    SetServoAngle(0); // Open gripper
                    gripper_open = 1;
                    DisplayMessage("Gripper Open");
                }
                break;

            default:
                DisplayMessage("Invalid Key");
                break;
        }

        /* Apply Movement */
        if (stepper1_angle > 0)
        {
            HSTEPPER_vMoveSpecificAngle(&stepper1, stepper1_angle);
            stepper1_angle = 0;
        }

        if (stepper3_angle > 0)
        {
            HSTEPPER_vMoveSpecificAngle(&stepper3, stepper3_angle);
            stepper3_angle = 0;
        }

        if (stepper2_angle > 0)
        {
            HSTEPPER_vMoveSpecificAngle(&stepper2, stepper2_angle);
            stepper2_angle = 0;
        }

        SetServoAngle(servo_angle);
        _delay_ms(100);  // Optional delay for debounce or visibility
    }

    return 0;
}

/* Sets the PWM value for the servo motor based on angle (0–180°) */
void SetServoAngle(u8 angle)
{
    if (angle > 180) angle = 90;
    OCR1A = ((1000UL * angle) / 180) + 1000;
}

/* Displays a short message on the LCD */
void DisplayMessage(const char* msg)
{
    HLCD_vSendCommand(LCD_CLEAR);
    _delay_ms(2);
    HLCD_vSendString(msg);
}
