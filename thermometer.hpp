#include "header.hpp"
#include "ds18x20.h"
#include "onewire.h"

inline void updateThermometer(){
   static uint16_t timeout=0;
   if(timeout==0){
      timeout=2000/5;
      show(11);
      //uint8_t status;
      uint8_t temperature[2];
      int8_t digit;
      uint16_t decimal;

      //ready = 0;

      ow_reset();
      ow_byte_wr(0xCC);//skip rom
      ow_byte_wr(0x44);
      /*do
      {
         ready = w1_write(0x44);//convert temp
      }while(ready=!1); //wait for temp convert*/
      _delay_ms(760);
      ow_reset();
      ow_byte_wr(0xCC);//skip rom
      ow_byte_wr(0xbe);//read scratchpad - ONLY 2 FIRST BYTES
      temperature[0]=ow_byte_rd();
      temperature[1]=ow_byte_rd();
      ow_reset();
      //Store temperature integer digits and decimal digits
      digit=temperature[0]>>4;
      digit|=(temperature[1]&0x7)<<4;
      //Store decimal digits
      decimal=temperature[0]&0xf;
      decimal*=625;
      //Format temperature into a string [+XXX.XXXX C]
      //sprintf(buffer, "%+d.%04u\xdfC", digit, decimal);
      current_temperature = (digit*10)%1000;//TODO decimal
   }else{
      timeout--;
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
