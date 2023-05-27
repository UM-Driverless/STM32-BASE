/*
 * SPI.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Pablo Antolín
 */

#ifndef SRC_SPI_H_
#define SRC_SPI_H_

#include "stm32f1xx.h"

class SPI {
	private:
		SPI_HandleTypeDef* spi;
		int CSpin;
		uint16_t PIN_SELECTED;
		GPIO_TypeDef BANK_SELECTED;
	protected:
		GPIO_TypeDef* Select_Bank_Pin(int PIN_B);
		uint16_t Select_Write_Pin(int PIN_W);
	public:
		SPI(); //Constructor vacio
		SPI(SPI_HandleTypeDef* spi, int CSpin, int BPin); //Constructor
		void SPIWrite(uint8_t data, GPIO_TypeDef* BANK_SELECTED);
		uint8_t* SPIRead(uint8_t addr, GPIO_TypeDef* BANK_SELECTED, uint8_t dataSize);
};


#endif /* SRC_SPI_H_ */

