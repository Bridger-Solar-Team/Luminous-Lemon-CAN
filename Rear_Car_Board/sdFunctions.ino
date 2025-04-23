void setupSD() {
  SD.begin(CS);

  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File file = SD.open("/LumLemData.csv", FILE_APPEND);
  file.println("millis,powerOn,leftTurn,rightTurn,horn,fwdRev,dispToggle,hazzards,crsCtl,brake,throttle,lvBatt,soc,dcl,ccl,currentDraw,overCur,ovrChg,ovrDcg,bmsFail,ovrTmp,workingVoltLV,speed");
  file.close();
}

void logData() {
  dataFile = SD.open("/LumLemData.csv", FILE_APPEND);
  if(dataFile) {
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

    //Write to SD card
    dataFile.println(dataWriting);

    //Verify with console
    Serial.print("Wrote: ");
    Serial.println(dataWriting);
  }

  if(!dataFile) {
    Serial.println("Failed to open file");
  }
  dataFile.close();
}

String addComma(String data) {
  return (data + ",");
}