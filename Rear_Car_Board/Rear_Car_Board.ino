#include <CAN.h>
#include <Adafruit_DS3502.h>
#include "Constants.h"

//Keep track of CAN receiving messages
char canData[6][8];
int dataID;
bool newCanData;

//Store pin state data
int pins[13];
int pinsCanSpacing = 100; //Time between CAN frames in milliseconds
unsigned long pinsCanTime = 0;

//Digipot setup
Adafruit_DS3502 digipot = Adafruit_DS3502();

void setup() {
  //CAN setup
  setupCAN();

  //Serial setup
  Serial.begin(115200);

  //Digipot Setup
  digipot.begin();
  
  //Pins Setup
  setupPins();
}

void loop() {
  // updatePins();
  updateCarFromCanInfo();
  calculateSpeed();
  
  sendCanData();
  runMotor();
  runLights();
  if(newCanData) {
    // printCAN();
    newCanData = false;
  }
  printFaults();
  printSpeed();
  printMotorInfo();
}

