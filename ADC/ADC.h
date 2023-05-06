
#ifndef SRC_ADC_H_
#define SRC_ADC_H_
#include <stdlib.h>
#include "stm32f1xx_hal_adc.h"

#define REF_VOLT 3.3
#define ADC_RES 4096 //12 bit 2^12 = 4096

typedef struct {
	uint8_t index;
	float output;
	uint16_t* buffer[];

} FIRfilter;

class ADC {
private:
	ADC_HandleTypeDef adc;
	volatile uint16_t * DMAbuffer;
	volatile uint16_t * ValueBuffer;
	uint8_t nChannels;

	//FIR Filter
	bool filterEnabled;
	uint8_t FilterLength;
	FIRfilter *FIR;
	float *ImpulseResponse_array;

	void updateFIR(int channel);



public:

	void ADC(ADC_HandleTypeDef adc, uint8_t nChannels); //Constructor
	void ADC(ADC_HandleTypeDef adc, uint8_t nChannels, uint8_t filterLength, float ImpulseResponse[], uint8_t IRsize); //Constructor con filtro fir
	uint16_t getReadingFromChannel(int channel); //Obtiene la lectura para un canal
	uint16_t * getReading4allRaw(); //Obtiene la lectura de todos los canales SE DEBE LIBERAR MEMORY
	float * getReading4allVolt(); //Obtiene la lectura de todos los canales
	void updateFIR4all();



};

#endif
