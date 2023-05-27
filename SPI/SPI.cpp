/*
 * SPI.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Pablo Antolín
*/

//--En el ReadMe está la lista de TO DO y la documentación--//

#include "SPI.h"

//Función para seleccionar el banco de pines
/*
 * PIN_B --> Entrada para seleccionar el banco de pines
 */
GPIO_TypeDef* Select_Bank_Pin(int PIN_B){
	switch(PIN_B){
			case 1:
				return GPIOA;
				break;
			case 2:
				return GPIOB;
				break;
			default:
				return GPIOC; //Manejar como excepción
	}
}
//Función para seleccionar el pin en el que tenemos que escribir
/*
 * PIN_W --> Entrada de la función para seleccionar el pin
 * PIN_B --> Entrada para seleccionar el banco de pines
 */
uint16_t Select_Write_Pin(int PIN_W){
	switch(PIN_W) {
		case 1:
			return GPIO_PIN_1;
			break;
		case 2:
			return GPIO_PIN_2;
			break;
		case 3:
			return GPIO_PIN_3;
			break;
		case 4:
			return GPIO_PIN_4;
			break;
		case 5:
			return GPIO_PIN_5;
			break;
		case 6:
			return GPIO_PIN_6;
			break;
		case 7:
			return GPIO_PIN_7;
			break;
		case 8:
			return GPIO_PIN_8;
			break;
		case 9:
			return GPIO_PIN_9;
			break;
		case 10:
			return GPIO_PIN_10;
			break;
		case 11:
			return GPIO_PIN_11;
			break;
		case 12:
			return GPIO_PIN_12;
			break;
		case 13:
			return GPIO_PIN_13;
			break;
		case 14:
			return GPIO_PIN_14;
			break;
		case 15:
			return GPIO_PIN_15;
			break;
		default:
			return -1; //Manejar como una excepción
	}
}
//Implementación del constructor SPI
/*
 * CSpin --> Selector del periférico con el que nos queremos comunicar
 * BPin --> Selector del banco de pines
 */
SPI::SPI(SPI_HandleTypeDef* spi, int CSpin, int BPin){
	this->spi = spi;
	this->CSpin = CSpin;
	HAL_SPI_Init(spi); //Inicializa periferico SPI
	HAL_SPI_MspInit(this->spi); //Inicializa los pines GPIO y la configuración de interrupción
	GPIO_TypeDef* BANK_SELECTED = Select_Bank_Pin(BPin); //Llamamos a la función para seleccionar el banco del pin
	uint16_t PIN_SELECTED = Select_Write_Pin(CSpin); //Llamamos a la función para seleccionar el pin
	HAL_GPIO_WritePin(BANK_SELECTED, PIN_SELECTED, GPIO_PIN_SET); //Pin en el que se va a escribir
}
//Implementación de la función SPIWrite
/*
 * data --> Datos que mandamos
 */
void SPI::SPIWrite(uint8_t data, GPIO_TypeDef* BANK_SELECTED){
	HAL_GPIO_WritePin(GPIOB, PIN_SELECTED, GPIO_PIN_RESET); //Pone el pin a Low
	size_t dataS = sizeof(data) / sizeof(uint8_t); //Calculamos el tamaño de los datos
	uint8_t dataSize = static_cast<uint8_t>(dataS); //Convertimos el tipo size_t (dataS) al tipo uint8_t
	HAL_SPI_Transmit(spi, &data, dataSize, 100); //Transmitimos los datos
	HAL_GPIO_WritePin(BANK_SELECTED, PIN_SELECTED, GPIO_PIN_SET); //Vuelve a poner el pin a High
}
//Implementación de la función SPIRead
/*
 * addr --> Dirección dónde se van a leer los datos
 */
uint8_t* SPI::SPIRead(uint8_t addr, GPIO_TypeDef* BANK_SELECTED, uint8_t dataSize){ //TO DO(1)
	uint8_t* data;
	HAL_GPIO_WritePin(BANK_SELECTED, PIN_SELECTED, GPIO_PIN_RESET); //Pone el pin a Low
	HAL_SPI_Transmit(BANK_SELECTED, addr, dataSize, 100); //Transmite la dirección a leer (Repasar)
	HAL_SPI_Receive(spi, data, dataSize, 100); //Recibimos los datos
	HAL_GPIO_WritePin(BANK_SELECTED, PIN_SELECTED, GPIO_PIN_RESET); //Vuelve a poner el pin a High
	return data;
}
