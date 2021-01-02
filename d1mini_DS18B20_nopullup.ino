#include <cy_serdebug.h>
#include <cy_serial.h>

#include "cy_wifi.h"
#include "cy_ota.h"

const char* gc_hostname = "d1mds1820";


#include <Ticker.h>


Ticker tick_sens;
boolean gv_sens_tick = true;

void tick_sens_int(){
  gv_sens_tick = true;
}

