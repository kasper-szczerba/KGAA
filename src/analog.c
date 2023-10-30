#include "analog.h"

void initADC(ADC_Prescaler_t prescaler)
{
    // Configure the reference voltage
    ADMUX = (1 << REFS0);

    // Configure the ADC prescaler
    ADCSRA = (ADCSRA & 0xF8) | (prescaler & 0x07);

    // Enable ADC
    ADCSRA |= (1 << ADEN);
}

void disableADC(void)
{
    // Disable ADC
    ADCSRA &= ~(1 << ADEN);
}

uint16_t getAnalogValue(uint8_t pin)
{
    // Configure the selected analog pin
    ADMUX = (ADMUX & 0xF8) | (pin & 0x07);

    // Start the ADC conversion
    ADCSRA |= (1 << ADSC);

    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC))
        ;

    // Return the result
    return ADC;
}