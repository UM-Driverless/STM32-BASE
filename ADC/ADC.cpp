/*
 * ADC.cpp
 *
 *  Created on: 5 may. 2023
 *      Author: alvar
 */

#include "ADC.h"

ADC::ADC(ADC_HandleTypeDef adc, uint8_t nChannels, uint8_t filterLength, float ImpulseResponse[], uint8_t IRsize) {
	this->adc = adc;
	this->nChannels = nChannels;
	this->FilterLength = filterLength;
	this->filterEnabled = true;
	this->ValueBuffer = FIR->buffer;
	DMAbuffer = malloc(nChannels*sizeof(uint16_t));
	HAL_ADCEx_Calibration_Start(&adc);
	HAL_ADC_Start_DMA(6adc, (uint32_t*) DMAbuffer, nChannels);

	//Inicializacion filtro

    FIR = malloc(nChannels*sizeof(FIRFilter));
    for(int i = 0; i < nChannels; i++) {
    	FIR[i].index = 0;
    	for(int j = 0; j < FilterLength; j++) {
    		FIR[i].buffer[j] = 0;
    	}
    }

    ImpulseResponse_array = malloc(IRsize* sizeof(float));
    for(int i = 0; i < IRSize; i++) {
    	ImpulseResponse_array[i] = ImpulseResponse[i];
    }

}

ADC::ADC(ADC_HandleTypeDef adc, uint8_t nChannels) {
	this->adc = adc;
	this->nChannels = nChannels;
	this->FilterLength = filterLength;
	this->filterEnabled = false;
	this->ValueBuffer = this->DMAbuffer;
	DMAbuffer = malloc(nChannels*sizeof(uint16_t));
	HAL_ADCEx_Calibration_Start(&adc);
	HAL_ADC_Start_DMA(6adc, (uint32_t*) DMAbuffer, nChannels);


}

void ADC::updateFIR(int channel) {
	FIRfilter *selFIR = &FIR[channel];
	//Implementacion buffer circular
	selFIR->buffer[selFIR->index++] = DMAbuffer[channel];
	if(selFIR->index == FilterLength) selFIR->index = 0;
	uint8_t indSum = selFIR->index;
	for (uint8_t i = 0; i < FilterLength; i++) {
		if (indSum > 0) indSum--;
		else indSum = FilterLength - 1;

		selFir->out += ImpulseResponse_array[i] * selFIR->buffer[indSum];
	}

}

void ADC::updateFIR4all() { //Esta funcion se debe poner en main en el DMA complete callback
	for(int i = 0; i < nChannels; i++) {
		updateFIR(i);
	}
}

uint16_t* ADC::getReading4allRaw() {
	static uint16_t returnReading[nChannels]; //Debuggeat bien static puede dar problemas
	for(int i = 0; i < nChannels; i++) {
		returnReading[i] = ValueBuffer[i];
	}
	return returnReading;
}

float* ADC::getReading4allVolt() {
	static float returnReading[nChannels];
	for(int i = 0; i < nChannels; i++) {
			returnReading[i] = (ValueBuffer[i] / ADC_RES) * REF_VOLT;
		}
		return returnReading;
}

ADC::~ADC() {
	// TODO Auto-generated destructor stub
}

