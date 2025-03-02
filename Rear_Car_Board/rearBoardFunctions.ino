void runMotor() {
  if(powerOn) {
    digipot.setWiper(throttle*127);
  } else {
    digipot.setWiper(0);
  }
  Serial.print(" Thr:");
  Serial.println(throttle);

  digitalWrite(PWR3, fwdRev);
}

void runLights() {
  updateBlink();
  digitalWrite(PWR1, brakePressed);
  if (
    !overCurrent
    && !overCharge
    && !overDischarge 
    && !bmsFailure
    && !overTemp
  ) {
    digitalWrite(PWR2, LOW);
  } else {
    digitalWrite(PWR2, blink);
  }
  Serial.print("OvCur:");
  Serial.print(overCurrent);
  Serial.print(" OvChg:");
  Serial.print(overCharge);
  Serial.print(" OvDcg:");
  Serial.print(overDischarge);
  Serial.print(" OvTmp:");
  Serial.print(overTemp);
}

void updateBlink() {
  if(millis()-blinkTimer > 1000.0/blinkFrequency) {
    blinkTimer = millis();
    blink = !blink;
  }
}