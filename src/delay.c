#include "delay.h"

void delayMs(uint32_t milliseconds)
{
    // Calculate the number of loops required for the given delay
    volatile unsigned long loops = (unsigned long)milliseconds * F_CPU / 10000;

    // Decrement the loop counter until it reaches 0
    while (loops > 0)
    {
        loops--;
    }
}
