void printPinsData() {
  Serial.print("Thr: ");
  Serial.print(throttle);
  Serial.print(" Brake: ");
  Serial.println(brakePressed);
}