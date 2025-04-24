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

  pinMode(PWR1, OUTPUT);
  pinMode(PWR2, OUTPUT);
  pinMode(PWR3, OUTPUT);
  pinMode(PWR4, OUTPUT);
  pinMode(PWR5, OUTPUT);
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
  powerOn = (pins[1]%2 && !fault);
  rightTurn = pins[2]%2;
  leftTurn = pins[3]%2;
  hazzards = pins[4]%2;
  fwdRev = pins[5]%2;
  dispToggle = pins[6]%2;
  horn = pins[7]%2;
  cruiseControl = pins[8]%2;
  brakePressed = pins[9]%2;
  brakePressed = false;
  throttle = floatMap(pins[12]/4095.0, tLow, tHigh, 0.0, 1.0);
  throttle = max(throttle, (float) 0.0);
  throttle = min(throttle, (float) 1.0);
  throttle = throttle * (dcl/40.0);
}