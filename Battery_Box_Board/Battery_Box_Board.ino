#include <CAN.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include "Constants.h"

//Keep track of CAN receiving messages
char canData[6][8];
int dataID;
bool newCanData;

//Store pin state data
int pins[13];
int pinsCanSpacing = 100; //Time between CAN frames in milliseconds
unsigned long pinsCanTime = 0;

//Voltage sensors
Adafruit_INA219 batterySensor(0x40);

void setup() {
  //CAN setup
  setupCAN();

  //Serial setup
  Serial.begin(115200);

  setupPins();

  //Set up voltage monitors
  batterySensor.begin();
}

void loop() {
  //Inputs
  updatePins();
  updateCarFromCanInfo();
  updateCarFromPins();

  //Outputs
  sendCanData();
  controlContactors();
}

