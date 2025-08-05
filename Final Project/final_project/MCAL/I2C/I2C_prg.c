/*
 * I2C_prg.c
 *
 *  Created on: Aug 3, 2025
 *      Author: anaal
 */


#include "I2C_int.h"


void MI2C_vMasterInit(void){
	CLEAR_BIT(TWSR,TWSR_TWPS0);
	CLEAR_BIT(TWSR,TWSR_TWPS1);
	TWDR=2;
	SET_BIT(TWCR,TWCR_TWEN);
	SET_BIT(TWCR, TWCR_TWIE);
}


void MI2C_vSlaveInit(u8 slave_add){
	TWAR=slave_add<<1;
	//enable ACK
    SET_BIT(TWCR, TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);
}

I2C_error_t MI2C_SendStartCondition(void){
	u8 L_Error = no_error;
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	while(!(GET_BIT(TWCR , TWCR_TWINT)));
	if((TWSR & 0xF8) == 0x08){

	}
	else{
		L_Error = start_condtion_error ;
	}

	return L_Error;
}

I2C_error_t MI2C_SendRepeatedStartCondition(void){
	u8 L_Error = no_error;
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	while(!(GET_BIT(TWCR , TWCR_TWINT)));
	if((TWSR & 0xF8) == 0x10){

	}
	else{
		L_Error = repeated_start_condtion_error ;
	}

	return L_Error;
}

I2C_error_t MI2C_SendSlaveAddress_Write(u8 data){
	u8 L_Error = no_error;
	TWDR = (data << 1); // 7-bit address with R/W = 0
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

	while(!(GET_BIT(TWCR , TWCR_TWINT)));
	if((TWSR & 0xF8) == 0x18){

	}
	else{
		L_Error = slave_data_write_ack_error;
	}

	return L_Error;
}

I2C_error_t MI2C_SendSlaveAddress_Read(u8 data){
	u8 L_Error = no_error;
	TWDR = (data << 1) | 1; // R/W = 1 for read mode
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

	while(!(GET_BIT(TWCR , TWCR_TWINT)));
	if((TWSR & 0xF8) == 0x40){

	}
	else{
		L_Error = slave_data_read_ack_error;
	}

	return L_Error;
}


I2C_error_t MI2C_MasterReadData(u8 *data_read){

	u8 L_Error = no_error;
	SET_BIT(TWCR , TWCR_TWINT);
	while(!(GET_BIT(TWCR , TWCR_TWINT)));
	if((TWSR & 0xF8) == 0x50){
		*data_read = TWDR;
	}
	else{
		L_Error = master_read_data_error;
	}

	return L_Error;
}


I2C_error_t MI2C_MasterWriteData(u8 data){
	u8 L_Error =no_error;
	TWDR =data;
	SET_BIT(TWCR , TWCR_TWINT);
	while(!(GET_BIT(TWCR , TWCR_TWINT)));

	if((TWSR & 0xF8) == 0x28){

	}
	else{
		L_Error = master_write_data_error;
	}

	return L_Error;
}


void MI2C_SendStopCondition(void){
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN) | (1 << TWCR_TWSTO);
}
