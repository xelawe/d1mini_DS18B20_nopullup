
void init_mqtt_local( ) {

  init_mqtt(gv_clientname);

  delay(500);
}


void pub_sens() {

  char buffer[256];
  //dtostrf(fire.NUMFirePIXELS, 0, 0, buffer);

  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<200> jsondoc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);

  // Add values in the document
  //

  // Add the "DS1820"
  //  jsondoc["DS18B20"] = (int)(tempC * 100 + 0.5) / 100.0;
  JsonObject ds18b20 = jsondoc.createNestedObject("DS18B20");
  ds18b20["Temperature"] = (int)(tempC * 100 + 0.5) / 100.0;;

  int n  = serializeJson(jsondoc, buffer);

  //client.publish(mqtt_pubtopic_sensor, buffer, true);
  client.publish(mqtt_GetTopic_P(gv_ptopic, mqtt_pre_tele, gv_clientname, (PGM_P)F("SENSOR")), buffer, true);
}
