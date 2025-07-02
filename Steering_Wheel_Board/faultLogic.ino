void calculateFaults() {
  if(millis() < 1000) {return;}
  if(currentDraw > 40 && millis()-overcurrentTime > 100) {
    fault = true; 
    faultCode = 1;
  } else {
    overcurrentTime = millis();
  }
  if(cellLowV <= 3.02) {fault = true; faultCode = 2;}
  if(cellHighV >= 4.16) {fault = true; faultCode = 3;}
  Serial.println(currentDraw);
  if(cellHighTemp >= 45) {fault = true; faultCode = 4;}
  if(abs(currentDraw) >= 39.9) {fault = true; faultCode = 5;}
  if(estop) {fault = true; faultCode = 6;}
  if(currentFail
    || voltageFail
    || cellLowFail
    || cellHighFail
    || thermFail
    || currSenseFail
    || bmsLogicFail
    || bmsHardFail) {fault = true; faultCode = 6;}
}