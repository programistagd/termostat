#ifndef INCLUDED
#define INCLUDED

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

///PROGRAM STATE VARIABLES
extern int16_t wanted_temperature;
extern int16_t current_temperature;
extern bool digit;
extern bool showWanted;

#endif
