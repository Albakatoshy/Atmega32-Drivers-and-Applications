/*
 * EEPROM_prg.c
 *
 *  Created on: Aug 4, 2025
 *      Author: anaal
 */

#include "EEPROM_int.h"

#include "EEPROM_int.h"
#include <util/delay.h>

void EEPROM_voidWriteDataByte(u8 A_u8Data, u16 A_u8DataLocation, u16 A_u8BlockNumber)
{
    MI2C_SendStartCondition();
    MI2C_SendSlaveAddress_Write(A_u8BlockNumber);   // Let I2C driver do shifting
    MI2C_MasterWriteData(A_u8DataLocation);
    MI2C_MasterWriteData(A_u8Data);
    MI2C_SendStopCondition();

    _delay_ms(5);
}


u8 EEPROM_u8ReadDataByte(u8 A_u8DataLocation, u8 A_u8BlockNumber)
{
    u8 Local_u8Data;

    MI2C_SendStartCondition();
    MI2C_SendSlaveAddress_Write(A_u8BlockNumber);
    MI2C_MasterWriteData(A_u8DataLocation);

    MI2C_SendRepeatedStartCondition();
    MI2C_SendSlaveAddress_Read(A_u8BlockNumber);
    MI2C_MasterReadData(&Local_u8Data);
    MI2C_SendStopCondition();

    return Local_u8Data;
}

