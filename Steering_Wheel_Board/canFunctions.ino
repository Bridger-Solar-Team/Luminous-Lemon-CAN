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
    //Can Frame Prep Code
    byte canFrame[8];
    canFrame[0] += powerOn << 7;
    // canFrame[0] += leftTurn << 6;
    // canFrame[0] += rightTurn << 5;
    canFrame[0] += horn << 4;
    canFrame[0] += fwdRev << 3;
    canFrame[0] += dispToggle << 2;
    canFrame[0] += hazzards << 1;
    canFrame[0] += cruiseControl;
    canFrame[1] += brakePressed << 7;
    canFrame[2] = throttle*200.0;

    //Can Frame Code
    CAN.beginPacket(DASH_CANID);
    for (int i = 0; i < 8; i++) {
      CAN.write(canFrame[i]);
    }
    CAN.endPacket();
    //End Can Frame Code
    pinsCanTime = millis();
  }
}

void updateCarFromCanInfo() {
  //From the battery box board
  batteryVoltageLV = canData[2][1]/10.0;

  //From the data logging board
  sdFailure = canData[3][1] & 0b10000000;

  //From the BMS
  soc = canData[4][0]/200.0;
  dcl = canData[4][1]/2.0;
  ccl = canData[4][2]/2.0;
  int16_t midCalcCurrent = 0;
  midCalcCurrent = ((canData[4][3] << 8) + canData[4][4]);
  currentDraw = midCalcCurrent/10.0;
  overCurrent = canData[4][6] & 0b10000000;
  overCharge = canData[4][6] & 0b01000000;
  overDischarge = canData[4][6] & 0b00100000;
  bmsFailure = canData[4][6] & 0b00010000;
  overTemp = canData[4][6] & 0b00001000;
  workingVoltageLV = canData[4][5]/10.0 + 0.7;

  //from the rear
  speed = canData[5][0];
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
    case REAR_CANID:
      canArray = 5;
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