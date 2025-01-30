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