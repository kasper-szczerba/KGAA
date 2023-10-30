#ifndef __ANALOG_H__
#define __ANALOG_H__

#include "main.h"

typedef enum
{
    ADC_PRESCALER_2 = 0x00,
    ADC_PRESCALER_4 = 0x02,
    ADC_PRESCALER_8 = 0x03,
    ADC_PRESCALER_16 = 0x04,
    ADC_PRESCALER_32 = 0x05,
    ADC_PRESCALER_64 = 0x06,
    ADC_PRESCALER_128 = 0x07
} ADC_Prescaler_t;

void initADC(ADC_Prescaler_t);
void disableADC();
uint16_t getAnalogValue(uint8_t);

#endif // __ANALOG_H__