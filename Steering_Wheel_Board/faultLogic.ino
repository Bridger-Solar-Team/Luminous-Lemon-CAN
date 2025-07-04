void calculateFaults() {
  if(millis() < 1000) {return;}
  if(abs(currentDraw) >= 39.9 && millis()-overcurrentTime > 250) {fault = true; faultCode = 1;} else {overcurrentTime = millis();}
  if(cellLowV <= 3.02 && millis()-cellLowTime > 250) {fault = true; faultCode = 2;} else {cellLowTime = millis();}
  if(cellHighV >= 4.18 && millis()-cellHighTime > 250) {fault = true; faultCode = 3;} else {cellHighTime = millis();}
  // Serial.println(currentDraw);
  if(cellHighTemp >= 45) {fault = true; faultCode = 4;}
  // if(abs(currentDraw) >= 39.9) {fault = true; faultCode = 5;}
  if(estop) {fault = true; faultCode = 6;}
  if(currentFail
    || voltageFail
    || cellLowFail
    || cellHighFail
    || thermFail
    || currSenseFail
    || bmsLogicFail
    || bmsHardFail) {fault = true; faultCode = 7;}
}