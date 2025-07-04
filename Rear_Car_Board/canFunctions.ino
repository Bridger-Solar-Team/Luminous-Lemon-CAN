void printCAN() {
  for(int j = 0; j < 5; j++) {
    Serial.print(j);
    Serial.print(": ");
    for (int i = 0; i < 8; i++) {
      Serial.print(canData[j][i]);
    }
    Serial.println();
  }
}

void setupCAN() {
  CAN.setPins(CRX, CTX);
  CAN.begin(1000E3);
  CAN.onReceive(readCAN);
}

void sendCanData() {
  if(millis() - pinsCanTime > pinsCanSpacing) {
    Serial.println("CAN Sent");
    //Can Frame Prep Code
    byte canFrame[8];
    canFrame[0] = (int) speed;
    // Serial.println(canFrame[0]);

    //Can Frame Code
    CAN.beginPacket(REAR_CANID);
    for (int i = 0; i < 8; i++) {
      CAN.write(canFrame[i]);
    }
    CAN.endPacket();
    
    //End Can Frame Code
    pinsCanTime = millis();
  }
}

void updateCarFromCanInfo() {
  //From the dash board
  powerOn = canData[1][0] & 0b10000000;
  leftTurn = canData[1][0] & 0b01000000;
  rightTurn = canData[1][0] & 0b00100000;
  horn = canData[1][0] & 0b00010000;
  fwdRev = canData[1][0] & 0b00001000;
  dispToggle = canData[1][0] & 0b00000100;
  hazzards = canData[1][0] & 0b00000010;
  cruiseControl = canData[1][0] & 0b00000001;
  brakePressed = canData[1][1] & 0b10000000;
  estop = canData[1][1] & 0b01000000;
  throttle = canData[1][2]/200.0;

  //From the battery box board
  batteryVoltageLV = canData[2][1]/10.0;

  //From the BMS
  //From the BMS
  soc = canData[4][0]/200.0;
  dcl = canData[4][1];
  cellLowV = canData[4][2]/50.0;

  currentDraw = ((byte) canData[4][3]);
  if(currentDraw > 120) {
    currentDraw -= 256;
  }
  currentDraw = currentDraw/2.5;

  cellHighTemp = canData[4][4];
  workingVoltageLV = canData[4][5]/10.0 + 0.7;
  currentFail = canData[4][6] & 0b10000000;
  voltageFail = canData[4][6] & 0b01000000;
  cellLowFail = canData[4][6] & 0b00100000;
  cellHighFail = canData[4][6] & 0b00010000;
  thermFail = canData[4][6] & 0b00001000;
  currSenseFail = canData[4][6] & 0b00000100;
  bmsLogicFail = canData[4][6] & 0b00000010;
  bmsHardFail = canData[4][6] & 0b00000001;
  cellHighV = canData[4][7]/50.0;
}


void readCAN(int packetSize) {
  dataID = CAN.packetId();
  canArray = 0;
  switch(dataID) {
    //Dashboard
    case DASH_CANID:
      canArray = 1;
      break;
    //Battery Box Board
    case BATTERYBOX_CANID:
      canArray = 2;
      break;
    //SD Data Logging Board
    case LOGGER_CANID:
      canArray = 3;
      break;
    //BMS Messages
    case BMS_CANID:
      canArray = 4;
      break;
    default: 
      canArray = 0;
      break;
  }

  for (int i = 0; i < 8; i++) {
    if (CAN.available()) {
      canData[canArray][i] = CAN.read();
    } else {
      canData[canArray][i] = 0;
    }
  }
  newCanData = true;
}