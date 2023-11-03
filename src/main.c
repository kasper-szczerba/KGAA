#include "main.h"
#include "digital.h"
#include "analog.h"
#include "serial.h"
#include "delay.h"
#include "array.h"

int main()
{
    setup(); // Call the setup function once

    // Keep calling the loop function until it returns false
    while (loop()) {};
    return 0;
}

void setup()
{
    // Place your setup code here
}

bool loop()
{
    // Place your loop code here
    return true; // Return false if an error occurred
}