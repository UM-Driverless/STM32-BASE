/*
 * SPI.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Pablo Antolín
*/

//--En el ReadMe está la lista de TO DO y la documentación--//

#include "SPI.h"

//Implementación del constructor SPI
/*
 * CSpin --> Selector del periférico con el que nos queremos comunicar
 */
void SPI(SPI_HandleTypeDef spi, int CSpin){
	this->spi = spi;
	this->CSpin = CSpin;
	HAL_SPI_Init(spi); //Inicializa periferico SPI
	HAL_SPI_MspInit(spi); //Inicializa los pines GPIO y la configuración de interrupción

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); // (REVISAR) Pin en el que se va a escribir
}

//Implementación de la función SPIWrite
/*
 * data --> Datos que mandamos
 */
void SPIWrite(uint8_t data){ //TO DO (1)
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); //Pone el pin a Low
	dataSize = sizeOf(data) / sizeOf(uint8_t);
	HAL_SPI_Transmit(spi, data, dataSize, 100); //Transmitimos los datos
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); //Vuelve a poner el pin a High
}
