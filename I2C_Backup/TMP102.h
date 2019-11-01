/*
 * TMP102.h
 *
 *  Created on: 28-Oct-2019
 *      Author: Hp
 */

#ifndef TMP102_H_
#define TMP102_H_



#endif /* TMP102_H_ */

#define SLAVE_ADDRESS 0x48
#define WRITE	0x01 // Read/Write bit according to TMP102-Check during execution
#define	READ	0x00
#define TEMP_REG 0x00
#define CONFIG_REG 0x01
#define CONFIG_BYTE1 0x68 // Configuration register byte 1 // NUMBER OF FAULTS CHANGED
#define CONFIG_BYTE2 0xA0 // Configuration register byte 2 // Alert Bit Set
#define TEMP_LOW_REG 0x03    // Temp Low register
#define TLOW_1 0xF0
#define TLOW_2 0x00
//#define I2C_Transmit I2C0->C1 |= I2C_C1_TX_MASK;
//#define I2C_Start I2C0->C1 |= I2C_C1_MST_MASK;
//#define I2C_WAIT while((I2C0->S & I2C_S_IICIF_MASK)==0){} \
					    I2C->S |= I2C_S_IICIF_MASK;


void I2C_Init(void); // Initialise I2C
void I2C_Transmit(void); // I2C transmit in Master mode
int I2C_Receive(void); // I2C receive in Master mode
int I2C_Read(void);
void pause(void);
