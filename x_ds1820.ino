#include "OneWire.h"
#include "DallasTemperature.h"

// This is an updated version of the Tester program that comes with the DallasTemp library
// It will drive a DS18x20 tempurature sensor plugged directly to the Arduino header pins 13,12,14
// The flat side of the sensor should face into the center of the board.
// More info and a video here...
// http://wp.josh.com/2014/06/23/no-external-pull-up-needed-for-ds18b20-temp-sensor/#more-1892


// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 12

// Uncomment this line if you are using the updated dallas_temp_library that
// supports the busFail() method to diagnose bus problems
// #define BUSFAIL

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


int numberOfDevices; // Number of temperature devices found
float tempC;

