#ifndef __MAIN_H__
#define __MAIN_H__

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 5
#define LED_PORT PORTB

int main();
void setup();
bool loop();

#endif // __MAIN_H__