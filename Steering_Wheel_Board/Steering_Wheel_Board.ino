#include <CAN.h>
#include <LiquidCrystal_I2C.h>
#include "Constants.h"

//Keep track of CAN receiving messages
char canData[6][8];
int dataID;
bool newCanData;

//Store pin state data
int pins[13];
int pinsCanSpacing = 100; //Time between CAN frames in milliseconds
unsigned long pinsCanTime = 0;

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
  updatePins();
  //updateCarFromCanInfo();
  updateCarFromPins();
  sendCanData();
  printPinsData();
}

