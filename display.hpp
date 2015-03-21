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

uint8_t pins[13] = {
   B|C|D|E|F|G,//0
   D|F,//1
   A|B|C|F|G,//...
   A|B|D|F|G,
   A|D|E|F,
   A|B|D|E|G,
   A|B|C|D|E|G,
   D|F|G,
   A|B|C|D|E|F|G,
   A|B|D|E|F|G,//9
   A|B|C|E|G,//E
   A,//-
   B|C|E|G,//C
};

uint8_t show(uint8_t digit){
   PORTD &= ~((1 << PD0)|(1 << PD1));//at start turn them off
   PORTB = pins[digit];
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
   if(number<10)
      PORTB = pins[number];//set displayed digit
   if(showWanted){
      PORTB |= (1<<PB7);//set dot
   }
}
