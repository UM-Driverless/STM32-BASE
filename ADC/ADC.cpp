/*
 * ADC.cpp
 *
 *  Created on: 4 jun. 2023
 *      Author: alvar
 */

#include "ADC.h"
#include "stdlib.h"


/*
	Constructor
	Recibe: 
		-El numero de canales que usaremos
		-El puntero al ADC
	Crea un array con tantos elementos como canales vaos a usar.
*/

ADC::ADC(uint8_t nChannels, ADC_HandleTypeDef* adc) {
	this->adc = adc;
	this->nChannels = nChannels;
	this->data = (uint16_t*) malloc(nChannels*sizeof(uint16_t));

	HAL_ADC_Start_DMA(adc, (uint32_t*) data, nChannels);

}

/*
	getBufferPtr()
	Devuelve el puntero al array que contiene todas las lecturas del ADC.
	La conversion DMA se incia cuando se llama a la funcion.
*/

uint16_t* ADC::getBufferPtr(){
	HAL_ADC_Start_DMA(adc, (uint32_t*) data, nChannels);
	return this->data;
}

/*
	getChannelVal
	Devuelve el valor del canal pasado por parametro
	El valor se devuelve en 16 bits puros:
		-0 V -> 0
		-3,3 -> 4096
	La conversion DMA se incia cuando se llama a la funcion.
	Si estos retrasos provocan problemas deberiamos replantear la clase para que 
	haga conversiones continuamente y tenga el valor listo cuando se haga la llamada
*/
uint16_t ADC::getChannelVal(uint8_t channel) {
	HAL_ADC_Start_DMA(adc, (uint32_t*) data, nChannels);
	return this->data[channel];
}
ADC::~ADC() {
	// TODO Auto-generated destructor stub
}

