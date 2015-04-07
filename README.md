# Simple ATTiny2313 based thermostat

To compile, type `make termo`

## Pinout

[ATtiny2313 docs](http://www.atmel.com/images/doc2543.pdf)

### Segment display
 - 1-5 //pins numbered
 - 8.8. //this way up
 - 6-10

### Pins for the segment display
 - PD0 - 3
 - PD1 - 4
 - PB0 - 10
 - PB1 - 9
 - PB2 - 8
 - PB3 - 6
 - PB4 - 5
 - PB5 - 2
 - PB6 - 1
 - PB7 - 7

### Other pins
 - PA1 - thermometer (1-Wire)
 - PD2 - encoder //order is not very important, if you swap the pins the encoder will just rotate in reverse direction
 - PD3 - encoder
 - PD4 - encoder button (swaps current/wanted temperature display)
 - PD5 - heater output (probably to some transistor and that to the relay)

### Misc. information
The DS18B20 needs a pull-up resistor (data to Vcc). I use 4.7kOhm (under 3V).
Attiny should have the reset pin pulled-up so it won't reset randomly (I don't have this in testing board, but it's useful).
There should be a condensator near Attiny's Vcc so unexpected current draws don't reset the processor.
Every diode in 7-segment display should have its resistor (I use 330Ohm under 3V).
