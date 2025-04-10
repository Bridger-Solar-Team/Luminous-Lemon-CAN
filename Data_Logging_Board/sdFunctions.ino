void setupSD() {
  SD.begin(CS);

  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File file = SD.open("/LumLemData.csv", FILE_APPEND);
  file.println("millis,powerOn,leftTurn,rightTurn,horn,fwdRev,dispToggle,hazzards,crsCtl,brake,throttle,lvBatt,soc,dcl,ccl,currentDraw,overCur,ovrChg,ovrDcg,bmsFail,ovrTmp,workingVoltLV");
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