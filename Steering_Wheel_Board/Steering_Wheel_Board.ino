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
  //CAN setup
  CAN.setPins(CRX, CTX);
  CAN.begin(500E3);
  CAN.onReceive(readCAN);

  //Serial setup
  Serial.begin(115200);

  //LCD Setup
  lcd.init();
  lcd.backlight();

  setupPins();
}

void loop() {
  //Inputs
  updatePins();
  updateCarFromCanInfo();
  updateCarFromPins();

  //Calculation
  steeringCalculations();

  //Outputs
  sendCanData();
  printPinsData();
  runLights();
  updateDisplay();
  // testLCD();
  // lcd.noBacklight();
  // delay(1000);
  // lcd.backlight();
  // delay(1000);
}

