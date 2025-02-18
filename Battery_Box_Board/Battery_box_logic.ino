bool allowRun() {
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
    return true;
  }
  return false;
}

void controlContactors() {
  digitalWrite(PWR1, allowRun());
  // Serial.print("Contactor state: ");
  // Serial.println(allowRun());
}
