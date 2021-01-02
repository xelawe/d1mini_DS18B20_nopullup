
void init_ds1820(void)
{

  // This lines just make it so you can plug a DS18B20 directly into
  // digitial pins DATA on PIN 12

  digitalWrite( 12 , HIGH );
  pinMode( 12  , INPUT_PULLUP ); // Mandatory to make it work on ESP8266



  // For testing purposes, reset the bus every loop so we can see if any devices appear or fall off
  sensors.begin();

  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();

  Serial.print("Count:");
  Serial.print(numberOfDevices, DEC);
  Serial.println();
  // report parasite power requirements
}


void check_ds1820(void)
{

  DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
 
  sensors.requestTemperatures(); // Send the command to get temperatures

  // Loop through each device, print out temperature data
  for (int i = 0; i < numberOfDevices; i++)
  {
    // Search the wire for address
    if (sensors.getAddress(tempDeviceAddress, i))
    {
      // Output the device ID
      Serial.print(" #");
      Serial.print(i, DEC);
      Serial.print("=");

      tempC = sensors.getTempC(tempDeviceAddress);

      Serial.print(tempC);

    }

  }

  Serial.println("");

}


