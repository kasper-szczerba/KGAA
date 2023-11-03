#include "digital.h"

void setPinMode(port_t port, uint8_t pin, mode_t mode)
{
    // The DDRx register controls the direction of the data register
    volatile uint8_t *ddr;

    // Select the appropriate DDRx register based on the port
    switch (port)
    {
    case PORT_B:
        ddr = &DDRB;
        break;
    case PORT_C:
        ddr = &DDRC;
        break;
    case PORT_D:
        ddr = &DDRD;
        break;
    default:
        break;
    }

    // Set the appropriate bit in the DDRx register based on the pin and mode
    switch (mode)
    {
    case INPUT:
        *ddr &= ~(1 << pin); // Clear the bit
        break;
    case INPUT_PULLUP:
        *ddr &= ~(1 << pin); // Clear the bit
        setPinState(port, pin, HIGH);
        break;
    case OUTPUT:
        *ddr |= (1 << pin); // Set the bit
        break;
    default:
        break;
    }
}

void setPinState(port_t port, uint8_t pin, state_t state)
{
    // The PORTx register controls the state of the pin
    volatile uint8_t *port_;

    // Select the appropriate PORTx register based on the port
    switch (port)
    {
    case PORT_B:
        port_ = &PORTB;
        break;
    case PORT_C:
        port_ = &PORTC;
        break;
    case PORT_D:
        port_ = &PORTD;
        break;
    default:
        break;
    }

    // Set the appropriate bit in the PORTx register based on the pin and state
    switch (state)
    {
    case LOW:
        *port_ &= ~(1 << pin); // Clear the bit
        break;
    case HIGH:
        *port_ |= (1 << pin); // Set the bit
        break;
    default:
        break;
    }
}

void togglePinState(port_t port, uint8_t pin)
{
    // The PORTx register controls the state of the pin
    volatile uint8_t *port_;

    // Select the appropriate PORTx register based on the port
    switch (port)
    {
    case PORT_B:
        port_ = &PORTB;
        break;
    case PORT_C:
        port_ = &PORTC;
        break;
    case PORT_D:
        port_ = &PORTD;
        break;
    default:
        break;
    }

    // Toggle the appropriate bit in the PORTx register based on the pin
    *port_ ^= (1 << pin);
}

state_t getPinState(port_t port, uint8_t pin)
{
    // The PINx register reads the state of the pin
    volatile uint8_t *port_;

    // Select the appropriate PINx register based on the port
    switch (port)
    {
    case PORT_B:
        port_ = &PORTB;
        break;
    case PORT_C:
        port_ = &PORTC;
        break;
    case PORT_D:
        port_ = &PORTD;
        break;
    default:
        break;
    }

    // Return the state of the appropriate bit in the PINx register based on the pin
    return (*port_ & (1 << pin)) ? HIGH : LOW;
}