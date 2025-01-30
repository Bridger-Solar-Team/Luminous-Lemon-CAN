void setupPins() {
  //Pins setup
  pinMode(PIN1, INPUT_PULLDOWN);
  pinMode(PIN2, INPUT_PULLDOWN);
  pinMode(PIN3, INPUT_PULLDOWN);
  pinMode(PIN4, INPUT_PULLDOWN);
  pinMode(PIN5, INPUT_PULLDOWN);
  pinMode(PIN6, INPUT_PULLDOWN);
  pinMode(PIN7, INPUT_PULLDOWN);
  pinMode(PIN8, INPUT_PULLDOWN);
  pinMode(PIN9, INPUT_PULLDOWN);
  pinMode(PIN10, INPUT_PULLDOWN);
  pinMode(PIN11, INPUT_PULLDOWN);
  pinMode(PIN12, INPUT_PULLDOWN);
}

void updatePins() {
  pins[5] = digitalRead(PIN5);
  pins[6] = digitalRead(PIN6);
  pins[7] = digitalRead(PIN7);
  pins[8] = digitalRead(PIN8);
  pins[9] = digitalRead(PIN9);
  pins[10] = digitalRead(PIN10);
  pins[11] = digitalRead(PIN11);
  pins[12] = digitalRead(PIN12);
}

void updateCarFromPins() {
  powerOn = pins[5]
  leftTurn = pins[6]
  rightTurn = pins[7]
  horn = pins[8]
  fwdRev = pins[9]
  dispToggle = pins[10]
  hazzards = pins[11]
  cruiseControl = pins[12]
  // throttle = canData[1][2]/200.0;
}