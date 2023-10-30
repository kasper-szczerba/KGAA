#ifndef __DIGITAL_H__
#define __DIGITAL_H__

#include "main.h"

typedef enum
{
    PORT_B,
    PORT_C,
    PORT_D
} port_t;

typedef enum
{
    INPUT,
    OUTPUT
} mode_t;

typedef enum
{
    LOW,
    HIGH
} state_t;

void setPinMode(port_t, uint8_t, mode_t);
void setPinState(port_t, uint8_t, state_t);
void togglePinState(port_t, uint8_t);
state_t getPinState(port_t, uint8_t);

#endif // __DIGITAL_H__