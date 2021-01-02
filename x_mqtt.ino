
#include "cy_mqtt_v1.h"
#include <ArduinoJson.h>

char gv_ptopic[MQTT_TOPSZ];
char gv_pbuffer[30];// buffer for reading the string to (needs to be large enough to take the longest string
