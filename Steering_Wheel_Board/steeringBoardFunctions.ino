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
  //Test
  if(throttle > 0.8) {
    digitalWrite(PWR1, HIGH);
    Serial.print("LED ON");
  } else {
    digitalWrite(PWR1, LOW);
  }
}