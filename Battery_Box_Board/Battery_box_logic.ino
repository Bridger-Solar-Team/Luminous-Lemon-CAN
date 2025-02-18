bool allowRun() {
  Serial.print(" SOC:");
  Serial.print(soc);
  Serial.print("DCL:");
  Serial.print(dcl);
  Serial.print(" Current Draw:");
  Serial.print(currentDraw);
  Serial.print(" CCL:");
  Serial.print(ccl);
  Serial.print(" OvCurr:");
  Serial.print(overCurrent);
  Serial.print(" OvChar:");
  Serial.print(overCharge);
  if (
    soc > 0.05
    && dcl > 15
    && currentDraw < 40
    && ccl > 10
    && !overCurrent
    && !overCharge
    && !overDischarge
    && !bmsFailure
    && !overTemp
    && powerOn
  ) {
    Serial.println(" OK!");
    return true;
  }
  Serial.println(" BAD");
  return false;
}

void controlContactors() {
  digitalWrite(PWR1, allowRun());
}
