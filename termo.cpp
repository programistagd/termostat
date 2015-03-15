#include "header.hpp"
#include "galka.hpp"
#include "display.hpp"
#include "thermometer.hpp"

inline void updateGrzalka(){
   if(current_temperature>wanted_temperature+5){
      //grzalka off
   }
   if(current_temperature<wanted_temperature-5){
      //grzalka on
   }
}

int main(void)
{

   //gałka
   DDRD &=~ (1 << PD2);//PD2 and PD3 as input
   DDRD &=~ (1 << PD3);
   PORTD |= (1 << PD3)|(1 << PD2);//PD2 and PD3 pull-up enabled   */

   //termometr
   //1-wire

   //grzalka
   //output

   //display
   DDRB = 0b11111111;//all PORTB pins are output, number display
   PORTB = 0;//initially turn off all
   DDRD |= (1 << PD0) | (1 << PD1);//multiplexer
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off

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
