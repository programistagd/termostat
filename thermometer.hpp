#include "header.hpp"
#include "ds18x20.h"

#define CHECK if(status!=DS18X20_OK){ showError(); _delay_ms(500); return; }

inline void updateThermometer(){
   static uint16_t timeout=0;
   if(timeout==0){
      timeout=2000/5;
      showMeasurement();
      uint8_t status;
      status = DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );
      CHECK
      _delay_ms( DS18B20_TCONV_12BIT );//TODO try not to wait, but just update at meas done
      status = DS18X20_read_decicelsius_single(DS18B20_FAMILY_CODE, &current_temperature);
      CHECK
   }else{
      timeout--;
   }
}
