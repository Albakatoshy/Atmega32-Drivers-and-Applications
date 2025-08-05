/*
 * I2C_prv.h
 *
 *  Created on: Aug 3, 2025
 *      Author: anaal
 */

#ifndef MCAL_I2C_I2C_PRV_H_
#define MCAL_I2C_I2C_PRV_H_


#define TWCR         	*((volatile u8*)0X56)
#define TWCR_TWINT        	7
#define TWCR_TWEA         	6
#define TWCR_TWSTA        	5
#define TWCR_TWSTO        	4
#define TWCR_TWWC        	3
#define TWCR_TWEN        	2
#define TWCR_TWIE        	0

#define TWDR          	*((volatile u8*)0X23)
#define TWDR_Write			0
#define TWDR_Read			1

#define TWAR            *((volatile u8*)0X22)
#define TWAR_TWGCE       	0

#define TWSR            *((volatile u8*)0x21)
#define TWSR_TWPS0         	0
#define TWSR_TWPS1          1

#endif /* MCAL_I2C_I2C_PRV_H_ */
