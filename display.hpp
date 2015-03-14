#include "header.hpp"

bool digit=false;//if false it's last digit, if true it's first digit

inline uint8_t getNumber(){
   uint8_t displayedNumber = (showWanted?wanted_temperature:current_temperature)/10;
   if(digit) return displayedNumber/10;
   return displayedNumber%10;
}

inline uint8_t getPins(uint8_t number){
   switch(number){
      case 0:  return 0b00000001;//TODO
      case 1:  return 0b00000010;
      case 2:  return 0b00000100;
      case 3:  return 0b00001000;
      case 4:  return 0b00010000;
      case 5:  return 0b00100000;
      case 6:  return 0b01000000;
      case 7:  return 0b00000011;
      case 8:  return 0b00010100;
      case 9:  return 0b00101000;
      default: return 0;
   }
}

inline void updateDisplay(){
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off
   PORTB = 0;//turn everything off
   digit=!digit;
   uint8_t number = getNumber();
   //update which digit
   if(!digit)   PORTD |= (1<<PD0);//swapped
   else        PORTD |= (1<<PD1);
   PORTB = getPins(number);//set displayed digit
   if(showWanted){
      PORTB |= (1<<PB7);//set dot
   }
}
