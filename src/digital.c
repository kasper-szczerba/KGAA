#include "digital.h"

mode_t setPinMode(port_t port, uint8_t pin, mode_t mode)
{
    // The DDRx register controls the direction of the data register
    volatile uint8_t *selectedDdr = NULL;
    mode_t modeOnExit = MODE_ERROR;

    if (pin <= MAX_PIN_COUNT)
    {
        // Select the appropriate DDRx register based on the port
        switch (port)
        {
        case PORT_B:
            selectedDdr = &DDRB;
            break;
        case PORT_C:
            selectedDdr = &DDRC;
            break;
        case PORT_D:
            selectedDdr = &DDRD;
            break;
        default:
            break;
        }

        if (selectedDdr != NULL)
        {
            // Set the appropriate bit in the DDRx register based on the pin and mode
            switch (mode)
            {
            case INPUT:
                *selectedDdr &= ~(1 << pin); // Clear the bit
                modeOnExit = INPUT;
                break;
            case INPUT_PULLUP:
                *selectedDdr &= ~(1 << pin); // Clear the bit
                setPinState(port, pin, HIGH);
                modeOnExit = INPUT_PULLUP;
                break;
            case OUTPUT:
                *selectedDdr |= (1 << pin); // Set the bit
                modeOnExit = OUTPUT;
                break;
            default:
                break;
            }
        }
    }

    return modeOnExit;
}

state_t setPinState(port_t port, uint8_t pin, state_t state)
{
    // The PORTx register controls the state of the pin
    volatile uint8_t *selectedPort = NULL;
    state_t stateOnExit = STATE_ERROR;

    if (pin <= MAX_PIN_COUNT)
    {
        // Select the appropriate PORTx register based on the port
        switch (port)
        {
        case PORT_B:
            selectedPort = &PORTB;
            break;
        case PORT_C:
            selectedPort = &PORTC;
            break;
        case PORT_D:
            selectedPort = &PORTD;
            break;
        default:
            break;
        }

        if (selectedPort != NULL)
        {
            // Set the appropriate bit in the PORTx register based on the pin and state
            switch (state)
            {
            case LOW:
                *selectedPort &= ~(1 << pin); // Clear the bit
                stateOnExit = LOW;
                break;
            case HIGH:
                *selectedPort |= (1 << pin); // Set the bit
                stateOnExit = HIGH;
                break;
            default:
                break;
            }
        }
    }

    return stateOnExit;
}

state_t togglePinState(port_t port, uint8_t pin)
{
    // The PORTx register controls the state of the pin
    volatile uint8_t *selectedPort = NULL;
    state_t stateOnExit = STATE_ERROR;

    // Check if pin is within the valid range
    if (pin <= MAX_PIN_COUNT)
    {
        // Select the appropriate PORTx register based on the port
        switch (port)
        {
        case PORT_B:
            selectedPort = &PORTB;
            break;
        case PORT_C:
            selectedPort = &PORTC;
            break;
        case PORT_D:
            selectedPort = &PORTD;
            break;
        default:
            break;
        }

        if (selectedPort != NULL)
        {
            // Toggle the appropriate bit in the PORTx register based on the pin
            stateOnExit = *selectedPort ^= (1 << pin);
        }
    }

    return stateOnExit;
}

state_t getPinState(port_t port, uint8_t pin)
{
    // The PINx register reads the state of the pin
    volatile uint8_t *selectedPin = NULL;
    state_t stateOnExit = STATE_ERROR;

    if (pin <= MAX_PIN_COUNT)
    {
        // Select the appropriate PINx register based on the port
        switch (port)
        {
        case PORT_B:
            selectedPin = &PINB;
            break;
        case PORT_C:
            selectedPin = &PINC;
            break;
        case PORT_D:
            selectedPin = &PIND;
            break;
        default:
            break;
        }

        if (selectedPin != NULL)
        {
            // Return the state of the appropriate bit in the PINx register based on the pin
            stateOnExit = (*selectedPin & (1 << pin)) ? HIGH : LOW;
        }
    }

    return stateOnExit;
}