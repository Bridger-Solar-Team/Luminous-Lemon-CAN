void printPinsData() {
  Serial.print("Pwr:");
  Serial.print(powerOn);
  Serial.print(" Left:");
  Serial.print(leftTurn);
  Serial.print(" Right:");
  Serial.print(rightTurn);
  Serial.print(" Horn:");
  Serial.print(horn);
  Serial.print(" Forward:");
  Serial.print(fwdRev);
  Serial.print(" Display Toggle:");
  Serial.print(dispToggle);
  Serial.print(" Hazzards:");
  Serial.print(hazzards);
  Serial.print(" Cruise:");
  Serial.print(cruiseControl);
  Serial.print(" Brake:");
  Serial.print(brakePressed);
  Serial.print(" Thr:");
  Serial.println(throttle);
}

void testLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Test Message");
}

void printBMSdata() {
  Serial.print("BMS says: ");
  Serial.println(soc);
}