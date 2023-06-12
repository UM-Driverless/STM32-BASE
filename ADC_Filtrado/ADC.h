
class ADC {
    private:
        ADC_HandleTypeDef adc;
    public:
        void ADC(ADC_HandleTypeDef adc); //Constructor
        uint16_t getCurrentReading(int channel);



};