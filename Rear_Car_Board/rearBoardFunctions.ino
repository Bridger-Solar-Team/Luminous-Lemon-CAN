void runMotor() {
  if(powerOn) {
    digipot.setWiper(throttle*127);
  } else {
    digipot.setWiper(0);
  }

  digitalWrite(PWR1, fwdRev);
}

void runLights() {
  updateBlink();
  digitalWrite(PWR4, brakePressed);
  if (
    !overCurrent
    && !overCharge
    && !overDischarge 
    && !bmsFailure
    && !overTemp
  ) {
    digitalWrite(PWR5, LOW);
  } else {
    digitalWrite(PWR5, blink);
  }
}

void updateBlink() {
  if(millis()-blinkTimer > 1000.0/blinkFrequency) {
    blinkTimer = millis();
    blink = !blink;
  }
}