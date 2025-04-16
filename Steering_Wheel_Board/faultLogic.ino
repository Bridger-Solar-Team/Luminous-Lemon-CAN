void calculateFaults() {
  if(millis() < 1000) {return;}
  if(currentDraw > 40 && millis()-overcurrentTime > 100) {
    fault = true; 
    faultCode = 1;
  } else {
    overcurrentTime = millis();
  }
  if(cellLowV < 3.00) {fault = true; faultCode = 2;}
  if(cellHighV >= 4.20) {fault = true; faultCode = 3;}
  if(cellHighTemp > 45) {fault = true; faultCode = 4;}
  if(currentFail
    || voltageFail
    || cellLowFail
    || cellHighFail
    || thermFail
    || currSenseFail
    || bmsLogicFail
    || bmsHardFail) {fault = true; faultCode = 5;}
}