bool allowRun() {
  // Serial.print("Current Draw:");
  // Serial.print(currentDraw);
  if(abs(currentDraw) > 40 && !currentOver) {
    currentTimer = millis();
    currentOver = true;
    // Serial.println(" O!");
  } else if(abs(currentDraw) <= 40) {
    currentOver = false;
    currentTimer = millis();
    // Serial.println(" U");
  }

  if (
    soc > 0.05
    // && dcl > 0
    && millis() - currentTimer < 500
    // && ccl > 0
    && !overCurrent
    && !overCharge
    && !overDischarge
    && !bmsFailure
    && !overTemp
    && millis() > 10000
  ) {
    if(/*true*/ powerOn) {
      if(millis() - statusTimer > statusUpdateTime) {
        Serial.println(" OK!");
        statusTimer = millis();
      }
      return true;
    } else {
      if(millis() - statusTimer > statusUpdateTime) {
        Serial.println(" PWROFF");
        statusTimer = millis();
      }
      powerOnMillis = millis();
      return false;
    }
  }
  powerOnMillis = millis();
  Serial.print(" SOC:");
  Serial.print(soc);
  Serial.print(" DCL:");
  Serial.print(dcl);
  Serial.print(" Current Draw:");
  Serial.print(currentDraw);
  Serial.print(" CCL:");
  Serial.print(ccl);
  Serial.print(" OvCurr:");
  Serial.print(overCurrent);
  Serial.print(" OvChar:");
  Serial.print(overCharge);
  Serial.print(" OvDis");
  Serial.print(overDischarge);
  Serial.print(" BMS Fail:");
  Serial.print(bmsFailure);
  Serial.print(" OvTemp: ");
  Serial.print(overTemp);
  // Serial.print(millis() - currentTimer);
  Serial.println(" BAD");
  return false;
}

void controlContactors() {
  contactorState = allowRun();
  digitalWrite(PWR1, contactorState);
  if(millis()- powerOnMillis > 2000) {
    digitalWrite(PWR2, contactorState);
  } else {
    digitalWrite(PWR2, LOW);
    if(contactorState) {
      Serial.println("precharging");
    }
  }
  if(millis() - powerOnMillis > 7000) {
    digitalWrite(PWR3, contactorState);
  } else {
    digitalWrite(PWR3, LOW);
    if(contactorState) {
      Serial.println("stabalizing");
    }
  }
}
