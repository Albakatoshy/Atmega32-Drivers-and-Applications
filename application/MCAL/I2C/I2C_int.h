/*
 * I2C_int.h
 *
 *  Created on: Aug 3, 2025
 *      Author: anaal
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "I2C_prv.h"
#include "I2C_cfg.h"

typedef enum{
	no_error,
	start_condtion_error,
	repeated_start_condtion_error,
	slave_data_write_ack_error,
	slave_data_read_ack_error,
	master_write_data_error,
	master_read_data_error,


}I2C_error_t;

void MI2C_vMasterInit(void);
void MI2C_vSlaveInit(u8 slave_add);

I2C_error_t MI2C_SendStartCondition(void);
I2C_error_t MI2C_SendRepeatedStartCondition(void);

I2C_error_t MI2C_SendSlaveAddress_Write(u8 data);
I2C_error_t MI2C_SendSlaveAddress_Read(u8 data);

I2C_error_t   MI2C_MasterReadData(u8 *data_read);
I2C_error_t MI2C_MasterWriteData(u8 data);

void MI2C_SendStopCondition(void);


#endif /* MCAL_I2C_I2C_INT_H_ */
