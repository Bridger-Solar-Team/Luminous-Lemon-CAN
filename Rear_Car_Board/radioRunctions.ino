void setupRadios() {
  SerialPort.begin(57600, SERIAL_8N1, PIN6, PIN5); 
}

void transmitData() {
  if(millis() - lastRadioTime > 200) {
    //Initialize data string to only write once
    String dataWriting;

    //Add timestamp
    dataWriting += addComma(String(millis()));

    //Add dashboard data
    dataWriting += addComma(String(powerOn));
    dataWriting += addComma(String(leftTurn));
    dataWriting += addComma(String(rightTurn));
    dataWriting += addComma(String(horn));
    dataWriting += addComma(String(fwdRev));
    dataWriting += addComma(String(dispToggle));
    dataWriting += addComma(String(hazzards));
    dataWriting += addComma(String(cruiseControl));
    dataWriting += addComma(String(brakePressed));
    dataWriting += addComma(String(throttle));

    //Add battery box data
    dataWriting += addComma(String(batteryVoltageLV));
    
    //Add BMS data
    dataWriting += addComma(String(workingVoltageLV));
    dataWriting += addComma(String(soc));
    dataWriting += addComma(String(cellLowV));
    dataWriting += addComma(String(cellHighV));
    dataWriting += addComma(String(dcl));
    dataWriting += addComma(String(currentDraw));
    dataWriting += addComma(String(cellHighTemp));
    dataWriting += addComma(String(currentFail));
    dataWriting += addComma(String(voltageFail));
    dataWriting += addComma(String(cellLowFail));
    dataWriting += addComma(String(cellHighFail));
    dataWriting += addComma(String(thermFail));
    dataWriting += addComma(String(currSenseFail));
    dataWriting += addComma(String(bmsLogicFail));
    dataWriting += addComma(String(bmsHardFail));

    //Add rear board data
    dataWriting += addComma(String(speed));

    SerialPort.println(dataWriting);
    // Serial.println(dataWriting);
    lastRadioTime = millis();
  }
}