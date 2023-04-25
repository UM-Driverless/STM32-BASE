class SPI {
    private:
        SPI_HandleTypeDef spi;
        int CSpin;
    public:
        void SPI (SPI_HandleTypeDef spi, int CSpin); //Constructor
        void SPIwrite(uint8_t addr, uint8_t data);
        uint8_t SPIread(uint8_t addr);
        
};