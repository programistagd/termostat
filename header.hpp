#ifndef INCLUDED
#define INCLUDED

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

///PROGRAM STATE VARIABLES
uint16_t wanted_temperature = 500;//0-1250, in deci-Celsius
uint16_t current_temperature = 500;

bool showWanted = false;//by default show thermometer readout

#endif
