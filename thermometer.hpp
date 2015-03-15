#include "header.hpp"

inline void updateThermometer(){
   //TODO
   static uint8_t p=0;
   if(p==0){
      current_temperature=(current_temperature+1)%1000;//simulation for now
      p=2;
   }
   else
      p--;
}
