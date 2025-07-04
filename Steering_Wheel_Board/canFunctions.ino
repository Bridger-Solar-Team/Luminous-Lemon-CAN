

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
  // Serial.println("Starting can sending");
  if(millis() - pinsCanTime > pinsCanSpacing) {
    //Can Frame Prep Code
    byte canFrame[8];
    if(!fault) {
      canFrame[0] += powerOn << 7;
    } else {
      canFrame[0] = 0;
    }
    // canFrame[0] += leftTurn << 6;
    // canFrame[0] += rightTurn << 5;
    canFrame[0] += horn << 4;
    canFrame[0] += fwdRev << 3;
    canFrame[0] += dispToggle << 2;
    canFrame[0] += hazzards << 1;
    canFrame[0] += cruiseControl;
    canFrame[1] += brakePressed << 7;
    canFrame[1] += fault << 6;

    canFrame[2] = useThrottle*200.0;

    // Serial.println("Built CAN bytes");

    //Can Frame Code
    CAN.beginPacket(DASH_CANID);
    // Serial.println("Began can packet");
    for (int i = 0; i < 8; i++) {
      CAN.write(canFrame[i]);
      // Serial.print("Wrote byte number ");
      // Serial.println(i);
    }
    // Serial.println("Wrote CAN frame");
    CAN.endPacket();
    // Serial.println("Ended can packet");
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