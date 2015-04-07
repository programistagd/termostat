#include "header.hpp"
#include "ds18x20.h"
#include "onewire.h"

inline void updateThermometer(){
   /*static uint16_t timeout=0;
   if(timeout==0){
      timeout=2000/5;
      show(11);
      current_temperature = ds18b20_gettemp();
   }else{
      timeout--;
   }*/
   if(try_reading(current_temperature)){
      start_reading();
   }
}
/*inline void updateThermometer(){
if(DS18X20_conversion_in_progress()==DS18X20_CONVERSION_DONE){
uint8_t status;
status = DS18X20_read_decicelsius_single(DS18B20_FAMILY_CODE, &current_temperature);
if(status==DS18X20_ERROR_CRC){ show(12); _delay_ms(500);}
if(status!=DS18X20_OK){ show(10); _delay_ms(500);}
DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );
}
}
*/
