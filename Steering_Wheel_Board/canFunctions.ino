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

void updateCarFromCanInfo() {
  //From the dash board
  // powerOn = canData[1][1] && 0b10000000;
  // leftTurn = canData[1][1] && 0b01000000;
  // rightTurn = canData[1][1] && 0b00100000;
  // horn = canData[1][1] && 0b00010000;
  // fwdRev = canData[1][1] && 0b00001000;
  // dispToggle = canData[1][1] && 0b00000100;
  // hazzards = canData[1][1] && 0b00000010;
  // cruiseControl = canData[1][1] && 0b00000001;
  // throttle = canData[1][2]/200.0;

  //From the battery box board
  batteryVoltageLV = canData[2][1]/10.0;
  workingvoltageLV = canData[2][2]/10.0;

  //From the data logging board
  sdFailure = canData[3][1] && 0b10000000;

  //From the BMS
  soc = canData[4][1]/200.0;
  dcl = canData[4][2]/2.0;
  dcl = canData[4][3]/2.0;
  currentDraw = canData[4][4]/2.0;
  overCurrent = canData[4][5] && 0b10000000;
  overCharge = canData[4][5] && 0b01000000;
  overDischarge = canData[4][5] && 0b00100000;
  bmsFailure = canData[4][5] && 0b00010000;
  overTemp = canData[4][5] && 0b00001000;
}


void readCAN(int packetSize) {
  int canArray = 0;
  dataID = CAN.packetId();
  switch(dataID) {
    //Dashboard
    // case DASH_CANID:
    //   canArray = 1;
    //   break;
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