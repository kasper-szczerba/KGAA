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
        {
            // Do nothing
        };
        UDR0 = *data;
        data++;
    }
}

char *readFromSerial()
{
    static char buffer[SERIAL_BUFFER_SIZE];
    uint8_t i = 0;
    bool isEndOfLine = false;

    while (!isEndOfLine)
    {
        // Wait for data to be received
        while (!(UCSR0A & (1 << RXC0)))
        {
            // Do nothing
        };
        buffer[i] = UDR0;
        if (buffer[i] == '\n')
        {
            isEndOfLine = true;
            buffer[i] = '\0';
        }
        i++;
    }

    return buffer;
}

bool isDataRegisterEmpty()
{
    return (UCSR0A & (1 << UDRE0));
}