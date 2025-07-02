void steeringCalculations() {
  //Cruise control setup
  if(cruiseControl && !cruiseActive) {
    cruiseSpeed = throttle;
    cruiseActive = true;
  } else if(!cruiseControl && cruiseActive) {
    cruiseActive = false;
  }
}

void turnOnCamera() {
  digitalWrite(PWR4, HIGH);
}

void turnOffCamera() {
  digitalWrite(PWR4, LOW);
}

void runLights() {
  updateBlink();
  if(hazzards) {
    digitalWrite(PWR2, blink);
    digitalWrite(PWR3, blink);
  } else if (rightTurn) {
    digitalWrite(PWR2, blink);
    digitalWrite(PWR3, LOW);
  } else if (leftTurn) {
    digitalWrite(PWR3, blink);
    digitalWrite(PWR2, LOW);
  } else {
    digitalWrite(PWR2, LOW);
    digitalWrite(PWR3, LOW);
  }
}

void updateBlink() {
  if(millis()-blinkTimer > 1000.0/blinkFrequency) {
    blinkTimer = millis();
    blink = !blink;
  }
}

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}