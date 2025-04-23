void setupRadios() {
  SerialPort.begin(57600, SERIAL_8N1, PIN6, PIN5); 
}

void transmitData() {
  if(millis() - lastRadioTime > 500) {
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
    dataWriting += addComma(String(soc));
    dataWriting += addComma(String(dcl));
    dataWriting += addComma(String(ccl));
    dataWriting += addComma(String(currentDraw));
    dataWriting += addComma(String(overCurrent));
    dataWriting += addComma(String(overCharge));
    dataWriting += addComma(String(overDischarge));
    dataWriting += addComma(String(bmsFailure));
    dataWriting += addComma(String(overTemp));
    dataWriting += addComma(String(workingVoltageLV));

    //Add rear board data
    dataWriting += addComma(String(speed));

    SerialPort.println(dataWriting);
    Serial.println(dataWriting);
    lastRadioTime = millis();
  }
}