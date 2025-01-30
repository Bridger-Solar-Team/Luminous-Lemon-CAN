void printPinsData() {
  Serial.print("Thr: ");
  Serial.print(throttle);
  Serial.print(" Brake: ");
  Serial.print(brakePressed);
  Serial.print(" Left: ");
  Serial.println(leftTurn);
}