/*
 * ADC.h
 *
 *  Created on: 4 jun. 2023
 *      Author: alvar
 */
#include <stm32f1xx.h>
#ifndef SRC_ADC_H_
#define SRC_ADC_H_

class ADC {
private:
	uint16_t* data;
	uint8_t nChannels;

	ADC_HandleTypeDef* adc;

public:
	ADC(uint8_t nChannels, ADC_HandleTypeDef* adc);
	uint16_t* getBufferPtr();
	uint16_t getChannelVal(uint8_t channel);
	virtual ~ADC();
};

#endif /* SRC_ADC_H_ */
