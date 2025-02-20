bool allowRun() {
  // Serial.print(" SOC:");
  // Serial.print(soc);
  // Serial.print("DCL:");
  // Serial.print(dcl);
  // Serial.print(" Current Draw:");
  // Serial.print(currentDraw);
  // Serial.print(" CCL:");
  // Serial.print(ccl);
  // Serial.print(" OvCurr:");
  // Serial.print(overCurrent);
  // Serial.print(" OvChar:");
  // Serial.print(overCharge);
  // Serial.print(" OvDis");
  // Serial.print(overDischarge);
  // Serial.print(" BMS Fail:");
  // Serial.print(bmsFailure);
  // Serial.print(" OvTemp");
  // Serial.print(overTemp);
  // Serial.print(" PowerOn:");
  // Serial.print(powerOn);
  if (
    soc > 0.05
    && dcl > 0
    && currentDraw < 40
    && ccl > 0
    && !overCurrent
    && !overCharge
    && !overDischarge
    && !bmsFailure
    && !overTemp
  ) {
    if(powerOn) {
      Serial.println(" OK!");
      return true;
    } else {
      Serial.println(" PWROFF");
      return false;
    }
  }
  Serial.println(" BAD");
  return false;
}

void controlContactors() {
  digitalWrite(PWR1, allowRun());
}
