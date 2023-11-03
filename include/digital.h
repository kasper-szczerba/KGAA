#ifndef __DIGITAL_H__
#define __DIGITAL_H__

#include "main.h"

#define MAX_PIN_COUNT 7

typedef enum
{
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_ERROR
} port_t;

typedef enum
{
    INPUT,
    INPUT_PULLUP,
    OUTPUT,
    MODE_ERROR
} mode_t;

typedef enum
{
    LOW,
    HIGH,
    STATE_ERROR
} state_t;

mode_t setPinMode(port_t, uint8_t, mode_t);
state_t setPinState(port_t, uint8_t, state_t);
state_t togglePinState(port_t, uint8_t);
state_t getPinState(port_t, uint8_t);

#endif // __DIGITAL_H__