void setup() {

  // start serial port
  cy_serial::start(__FILE__);

  Serial.println("Dallas Temperature IC Control Library Demo");

  init_ds1820();

  wifi_init(gc_hostname);
  delay(500);

  init_ota(gv_clientname);

  init_mqtt_local( );

  tick_sens.attach(60, tick_sens_int);

}

void loop() {

  check_ota();
  
  check_mqtt_reset();

  if ( gv_sens_tick ) {
    check_ds1820();

    pub_sens();
    
    gv_sens_tick = false;
  }

}

