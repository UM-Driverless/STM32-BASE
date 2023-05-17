/*
 * SPI.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Mi Equipo
 */

#ifndef SRC_SPI_H_
#define SRC_SPI_H_

class SPI {
	private:
		SPI_HandleTypeDef spi;
		int CSpin;
		uint16_t PIN_SELECTED;
		uint16_t BANK_SELECTED;
	protected:
		int Select_Bank_Pin(int PIN_B);
		int Select_Write_Pin(int PIN_W);
	public:
		void SPI(); //Constructor vacio
		void SPI(SPI_HandleTypeDef spi, int CSpin, int BPin); //Constructor
		void SPIWrite(uint8_t data);
		uint8_t SPIRead(uint8_t addr, );
};


#endif /* SRC_SPI_H_ */

