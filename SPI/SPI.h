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
	public:
		void SPI(SPI_HandleTypeDef spi, int CSpin); //Constructor
		void SPIWrite(uint8_t data);
		uint8_t SPIread(uint8_t addr);
};


#endif /* SRC_SPI_H_ */
