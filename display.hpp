#include "header.hpp"

/*PINOUT
   1-5
   8.8.
   6-10
   1-PB6
   2-PB5
   3-PD0
   4-PD1
   5-PB4
   6-PB3
   7-PB7
   8-PB2
   9-PB1
   10-PB0
   8=
    G
   E F
    A
   C D
    B
*/


inline uint8_t getNumber(){
   uint8_t displayedNumber = (showWanted?wanted_temperature:current_temperature)/10;
   if(digit) return displayedNumber/10;
   return displayedNumber%10;
}

#define A (1<<PB0)
#define B (1<<PB1)
#define C (1<<PB2)
#define D (1<<PB3)
#define E (1<<PB4)
#define F (1<<PB5)
#define G (1<<PB6)

inline uint8_t getPins(uint8_t number){//TODO array
   switch(number){
      case 0:  return B|C|D|E|F|G;
      case 1:  return D|F;
      case 2:  return A|B|C|F|G;
      case 3:  return A|B|D|F|G;
      case 4:  return A|D|E|F;
      case 5:  return A|B|D|E|G;
      case 6:  return A|B|C|D|E|G;
      case 7:  return D|F|G;
      case 8:  return A|B|C|D|E|F|G;
      case 9:  return A|B|D|E|F|G;
      default: return 0;
   }
}

uint8_t showError(){
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off
   PORTB = A|B|C|E|G;
   PORTD |= (1<<PD0);
}

uint8_t showMeasurement(){
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off
   PORTB = A;
   PORTD |= (1<<PD0);
}

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G

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
