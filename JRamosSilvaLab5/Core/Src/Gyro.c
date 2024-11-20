/*
 * Gyro.c
 *
 * Created on: Oct 31, 2024
 * Author: joelrsilva
 */

#include "Gyro.h"

// External SPI handle and static HAL status
extern SPI_HandleTypeDef hspi5;
static HAL_StatusTypeDef gyro_hal_status = HAL_OK;

// Helper function to write to a register
static void Gyro_WriteRegister(uint8_t registerAddress, uint8_t value) {
    uint8_t data[2] = {registerAddress & 0x7F, value};  // MSB is 0 for write
    Gyro_EnableSlaveCommunication();
    gyro_hal_status = HAL_SPI_Transmit(&hspi5, data, 2, HAL_MAX_DELAY);
    Gyro_DisableSlaveCommunication();

    if (gyro_hal_status != HAL_OK) {
        APPLICATION_ASSERT(gyro_hal_status == HAL_OK);
    }
}

void Gyro_Init(void) {
    GPIO_InitTypeDef GPIO_Init;

    // Enable clocks for GPIO ports
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_Init.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_Init.Mode = GPIO_MODE_AF_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Alternate = GPIO_AF5_SPI5;
	HAL_GPIO_Init(GPIOF, &GPIO_Init);

	GPIO_Init.Pin = GPIO_PIN_1;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_Init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_Init);

    // SPI configuration
	hspi5.Instance = SPI5;
	hspi5.Init.Mode = SPI_MODE_MASTER;
	hspi5.Init.Direction = SPI_DIRECTION_2LINES;
	hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi5.Init.CLKPolarity = SPI_POLARITY_HIGH;
	hspi5.Init.CLKPhase = SPI_PHASE_2EDGE;
	hspi5.Init.NSS = SPI_NSS_SOFT;
	hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi5.Init.CRCPolynomial = 0;

    // Initialize SPI and verify
    Gyro_DisableSlaveCommunication();
    gyro_hal_status = HAL_SPI_Init(&hspi5);
    Gyro_HALStatus();
}

void Gyro_DeviceIDPrint(void) {
    uint16_t receivedWord = 0;
    uint8_t addressByte = WHO_AM_I | 0x80; // readuing it

    Gyro_EnableSlaveCommunication();
    gyro_hal_status = HAL_SPI_TransmitReceive(&hspi5, &addressByte, (uint8_t *)&receivedWord, 2, HAL_MAX_DELAY);
    Gyro_DisableSlaveCommunication();

    if (gyro_hal_status == HAL_OK) {
        uint8_t deviceID = (receivedWord >> 8) & 0xFF;
        printf("Gyro Device ID: 0x%02X\n", deviceID);
    } else {
        printf("Failed to read Device ID.\n");
    }
}

void Gyro_PowerOn(void) {
    uint8_t ctrl_reg1_value = 0x0F;
    Gyro_WriteRegister(CTRL_REG1, ctrl_reg1_value);
    Gyro_HALStatus();
    APPLICATION_ASSERT(gyro_hal_status == HAL_OK);
}

void Gyro_TemperaturePrint(void) {
    uint16_t receivedTemp = 0;
    uint8_t addressByte = OUT_TEMP | 0x80;

    Gyro_EnableSlaveCommunication();
    gyro_hal_status = HAL_SPI_TransmitReceive(&hspi5, &addressByte, (uint8_t *)&receivedTemp, 2, HAL_MAX_DELAY);
    Gyro_DisableSlaveCommunication();

    if (gyro_hal_status == HAL_OK) {
        int8_t temperatureData = (uint8_t)((receivedTemp >> 8) & 0xFF);
        int8_t temperature = (40 - temperatureData);
        printf("Gyro Temperature: %d°C\n", temperature);
    } else {
        printf("Failed to read temperature.\n");
    }
}

void Gyro_RegisterConfigure(void) {
    Gyro_PowerOn();
    Gyro_WriteRegister(CTRL_REG5, 0x80);
}

void Gyro_ReadRegisters(void) {
    uint8_t addressByte;
    [[maybe_unused]]uint8_t out_x_l, out_x_h, out_y_l, out_y_h, out_z_l, out_z_h;
    [[maybe_unused]]int16_t out_x, out_y, out_z;

    // X-axis
    addressByte = OUT_X_L | 0x80;
    Gyro_EnableSlaveCommunication();
    gyro_hal_status = HAL_SPI_Transmit(&hspi5, &addressByte, 1, HAL_MAX_DELAY);
    gyro_hal_status = HAL_SPI_Receive(&hspi5, &out_x_l, 1, HAL_MAX_DELAY);
    Gyro_DisableSlaveCommunication();

    addressByte = OUT_X_H | 0x80;
    Gyro_EnableSlaveCommunication();
    gyro_hal_status = HAL_SPI_Transmit(&hspi5, &addressByte, 1, HAL_MAX_DELAY);
    gyro_hal_status = HAL_SPI_Receive(&hspi5, &out_x_h, 1, HAL_MAX_DELAY);
    Gyro_DisableSlaveCommunication();

    out_x = (int16_t)((out_x_h << 8) | out_x_l);
    printf("OUT_X: %d\n", out_x);


}

void Gyro_HALStatus(void) {
    if (gyro_hal_status != HAL_OK) {
        printf("HAL Error: %d\n", gyro_hal_status);
        while (1) {
        	//infinite loop for error
        }
    }
}

void Gyro_EnableSlaveCommunication(void) {
    HAL_GPIO_WritePin(NCS_MEMS_SPI_PORT, NCS_MEMS_SPI_PIN, GPIO_PIN_RESET);
}

void Gyro_DisableSlaveCommunication(void) {
    HAL_GPIO_WritePin(NCS_MEMS_SPI_PORT, NCS_MEMS_SPI_PIN, GPIO_PIN_SET);
}
