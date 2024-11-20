/*
 * Gyro.h
 *
 *  Created on: Oct 31, 2024
 *      Author: joelrsilva
 */

#ifndef INC_GYRO_H_
#define INC_GYRO_H_

#include <stm32f4xx_hal.h>
#include "ErrorHandling.h"

// Gyroscope Register Addresses
#define WHO_AM_I            	0x0F
#define CTRL_REG1           	0x20
#define CTRL_REG2           	0x21
#define CTRL_REG3           	0x22
#define CTRL_REG4           	0x23
#define CTRL_REG5           	0x24
#define OUT_TEMP            	0x26
#define STATUS_REG          	0x27
#define OUT_X_L             	0x28
#define OUT_X_H             	0x29
#define OUT_Y_L             	0x2A
#define OUT_Y_H             	0x2B
#define OUT_Z_L             	0x2C
#define OUT_Z_H             	0x2D
#define FIFO_CTRL_REG       	0x2E

// Pin and Port Definitions for Gyro
#define SPI5_SCK_PIN		    GPIO_PIN_7
#define SPI5_MOSI_PIN 			GPIO_PIN_8
#define SPI5_MISO_PIN 			GPIO_PIN_9
#define NCS_MEMS_SPI_PIN	    GPIO_PIN_1

#define SPI5_SCK_PORT  		    GPIOF
#define SPI5_MOSI_PORT 			GPIOF
#define SPI5_MISO_PORT 			GPIOF
#define NCS_MEMS_SPI_PORT	    GPIOC

// Function Prototypes
void Gyro_Init(void);
void Gyro_DeviceIDPrint(void);
void Gyro_PowerOn(void);
void Gyro_TemperaturePrint(void);
void Gyro_RegisterConfigure(void);
void Gyro_ReadRegisters(void);
void Gyro_HALStatus(void);
void Gyro_EnableSlaveCommunication(void);
void Gyro_DisableSlaveCommunication(void);

#endif /* INC_GYRO_H_ */
