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
  pins[1] = digitalRead(PIN1);
  pins[2] = digitalRead(PIN2);
  pins[3] = digitalRead(PIN3);
  pins[4] = digitalRead(PIN4);
  pins[5] = digitalRead(PIN5);
  pins[6] = digitalRead(PIN6);
  pins[7] = digitalRead(PIN7);
  pins[8] = digitalRead(PIN8);
  pins[9] = digitalRead(PIN9);
  pins[10] = digitalRead(PIN10);
  pins[11] = digitalRead(PIN11);
  pins[12] = analogRead(PIN12);
}

void updateCarFromPins() {
  powerOn = pins[1]%2;
  leftTurn = pins[2]%2;
  rightTurn = pins[3]%2;
  horn = pins[4]%2;
  fwdRev = pins[5]%2;
  dispToggle = pins[6]%2;
  hazzards = pins[7]%2;
  cruiseControl = pins[8]%2;
  brakePressed = pins[9]%2;
  throttle = pins[12]/4095.0;
}