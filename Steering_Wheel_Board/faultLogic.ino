void calculateFaults() {
  if(millis() < 1000) {return;}
  if(currentDraw > 40) {fault = true;}
  if(cellLowV < 3.00) {fault = true;}
  if(cellHighV >= 4.20) {fault = true;}
  if(cellHighTemp > 45) {fault = true;}
  if(currentFail
    || voltageFail
    || cellLowFail
    || cellHighFail
    || thermFail
    || currSenseFail
    || bmsLogicFail
    || bmsHardFail) {fault = true;}
}