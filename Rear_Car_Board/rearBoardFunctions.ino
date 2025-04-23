void runMotor() {
  if(powerOn) {
    digipot.setWiper(throttle*127);
  } else {
    digipot.setWiper(0);
  }

  digitalWrite(PWR3, fwdRev);
}

void runLights() {
  updateBlink();
  digitalWrite(PWR1, brakePressed);
  if (
    !currentFail
    && !voltageFail
    && !cellLowFail 
    && !cellHighFail
    && !thermFail
    && !currSenseFail
    && !bmsLogicFail
    && !bmsHardFail
  ) {
    digitalWrite(PWR2, LOW);
  } else {
    digitalWrite(PWR2, blink);
  }
}

void updateBlink() {
  if(millis()-blinkTimer > 1000.0/blinkFrequency) {
    blinkTimer = millis();
    blink = !blink;
  }
}