#include "serial.h"

void initSerial(uint16_t baudrate)
{
    // Calculate the baudrate
    uint16_t baudrate_ = (F_CPU / 16 / baudrate) - 1;

    // Set the baudrate
    UBRR0H = (uint8_t)(baudrate_ >> 8);
    UBRR0L = (uint8_t)baudrate_;

    // Enable the transmitter and receiver
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Set the frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void writeToSerial(char *data)
{
    while (*data != '\0')
    {
        while (!isDataRegisterEmpty())
            ;
        UDR0 = *data;
        data++;
    }
}

bool isDataRegisterEmpty() { return (UCSR0A & (1 << UDRE0)); }