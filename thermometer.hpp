#include "header.hpp"
#include "ds18x20.h"

inline void updateThermometer(){
   static uint16_t timeout=0;
   if(timeout==0){
      timeout=1000/5;
      DS18X20_start_meas( DS18X20_POWER_PARASITE, NULL );
      _delay_ms( DS18B20_TCONV_12BIT );
      DS18X20_read_decicelsius_single(DS18B20_FAMILY_CODE, &current_temperature);
   }else{
      timeout--;
   }
}
