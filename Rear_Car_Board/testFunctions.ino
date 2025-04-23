// void printFaults() {
//   Serial.print("OvCur:");
//   Serial.print(overCurrent);
//   Serial.print(" OvChg:");
//   Serial.print(overCharge);
//   Serial.print(" OvDcg:");
//   Serial.print(overDischarge);
//   Serial.print(" OvTmp:");
//   Serial.print(overTemp);
// }

void printMotorInfo() {
  Serial.print(" Fwd:");
  Serial.print(fwdRev);
  Serial.print(" Thr:");
  Serial.println(throttle);
}

void printSpeed() {
  Serial.print(" Spd:");
  Serial.print(speed);
  Serial.print(" PulseSpace:");
  Serial.print(pulseSpace);
}