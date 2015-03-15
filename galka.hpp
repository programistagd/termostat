#include "header.hpp"

//UTILS
inline uint8_t read_gray_code_from_encoder(){
   uint8_t val=0;
   if(!bit_is_clear(PIND, PD2))
      val |= (1<<1);
   if(!bit_is_clear(PIND, PD3))
      val |= (1<<0);
   return val;
}

//EVENTS
inline void onGalkaRotated(uint8_t dv){//can be inlined as it's only one OP
   wanted_temperature+=10*dv;//overflow & underflow will take care of keeping it in range
   wanted_temperature%=1000;
}

//LOOP
inline void checkGalka(){
   static uint8_t oldValue = 0;
   static uint8_t buttonTimeout = 0;
   uint8_t newValue = read_gray_code_from_encoder();
   if(newValue!=oldValue){
      if( /*(val==2 && val_tmp==3) ||*/(oldValue==3 && newValue==1) ||/*(val==1 && val_tmp==0) ||*/(oldValue==0 && newValue==2))
         onGalkaRotated(1);
      else if( /*(val==3 && val_tmp==2) ||*/(oldValue==2 && newValue==0) ||/*(val==0 && val_tmp==1) ||*/(oldValue==1 && newValue==3))
         onGalkaRotated(-1);
      oldValue=newValue;
   }
   //check button
   if(buttonTimeout>0) buttonTimeout--;
   else if(!bit_is_clear(PIND, PD4)){
      showWanted=!showWanted;//toggle
      buttonTimeout=50;
   }
}
