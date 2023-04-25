class UART {
    private:
        USART_HandleTypeDef uart;
    public:
        void UART(USART_HandleTypeDef uart);
        uint8_t* UARTread();
        void UARTwrite(uint8_t* data);

};