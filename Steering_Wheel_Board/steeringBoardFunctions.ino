bool calculateFaults() {
  return overCurrent + overCharge + overDischarge + overTemp + bmsFailure;
}

void steeringCalculations() {
  //Cruise control setup
  if(cruiseControl && !cruiseActive) {
    cruiseSpeed = throttle;
    cruiseActive = true;
  } else if(!cruiseControl && cruiseActive) {
    cruiseActive = false;
  }
}

void runLights() {
  updateBlink();
  if(hazzards) {
    digitalWrite(PWR2, blink);
    digitalWrite(PWR3, blink);
  } else if (rightTurn) {
    digitalWrite(PWR2, blink);
  } else if (leftTurn) {
    digitalWrite(PWR3, blink);
  } else {
    digitalWrite(PWR2, LOW);
    digitalWrite(PWR3, LOW);
  }
}

void updateBlink() {
  if(millis()-blinkTimer > 300) {
    blinkTimer = millis();
    blink = !blink;
  }
}