#include "header.hpp"
#include "galka.hpp"
#include "display.hpp"
#include "thermometer.hpp"

///PROGRAM STATE VARIABLES
int16_t wanted_temperature = 500;//0-1250, in deci-Celsius
int16_t current_temperature = 500;
bool digit=false;//if false it's last digit, if true it's first digit
bool showWanted = false;//by default show thermometer readout


inline void updateGrzalka(){
   if(current_temperature>wanted_temperature+5){
      PORTD &= ~(1<<PD5);
   }
   if(current_temperature<wanted_temperature-5){
      PORTD |= (1<<PD5);
   }
}

int main(void)
{

   //gałka
   DDRD &=~ (1 << PD2);//PD2 and PD3 as input
   DDRD &=~ (1 << PD3);
   PORTD |= (1 << PD3)|(1 << PD2);//PD2 and PD3 pull-up enabled   */

   //termometr
   //1-wire done in lib

   //grzalka
   DDRD |= (1<<PD5);//output

   //display
   DDRB = 0b11111111;//all PORTB pins are output, number display
   PORTB = 0;//initially turn off all
   DDRD |= (1 << PD0) | (1 << PD1);//multiplexer
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off

   //DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );
   start_reading();
   while(1)
   {
      checkGalka();
      updateThermometer();
      updateDisplay();
      updateGrzalka();

      _delay_ms(5);
   }

   return 0;
}
