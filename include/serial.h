#ifndef __SERIAL__
#define __SERIAL__

#include "main.h"

#define DEFAULT_BAUDRATE 9600
#define SERIAL_BUFFER_SIZE 64

void initSerial(uint16_t);
void writeToSerial(char *);
char *readFromSerial();
bool isDataRegisterEmpty();

#endif // __SERIAL__