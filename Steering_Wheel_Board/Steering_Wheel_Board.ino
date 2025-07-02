#include <CAN.h>
#include <LiquidCrystal_I2C.h>
#include "Constants.h"

//Keep track of CAN receiving messages
char canData[6][8];
int dataID;
bool newCanData;

//Store pin state data
int pins[13];

//LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  turnOnCamera();
  
  //CAN setup
  setupCAN();

  //Serial setup
  Serial.begin(115200);
  Serial.println("New Program");

  //LCD Setup
  lcd.init();
  lcd.backlight();

  setupPins();
  Serial.println("Setup complete!");
}

void loop() {
  // Serial.print(millis());
  // Serial.println("Start of loop");
  //Inputs
  updatePins();
  updateCarFromCanInfo();
  updateCarFromPins();

  // Serial.println("Inputs read");

  //Calculation
  steeringCalculations();
  calculateFaults();

  // Serial.println("Calculated");

  //Outputs
  sendCanData();
  // Serial.println("Send can data");
  // printPinsData();
  // Serial.println("printed pins");
  runLights();
  // Serial.println("Ran lights");
  updateDisplay();
  // Serial.println("Updated display");
  
  if(newCanData) {
    printBMSdata();
    // Serial.println("CAN received");
    Serial.print("Estop: ");
    Serial.println(estop);
    newCanData = false;
  }
}

