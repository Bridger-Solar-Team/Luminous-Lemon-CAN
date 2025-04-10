#include <CAN.h>

#include <SPI.h>
#include <SD.h>

#include "Constants.h"

//Keep track of CAN receiving messages
char canData[6][8];
int dataID;
bool newCanData;

//Store pin state data
int pins[13];
int pinsCanSpacing = 100; //Time between CAN frames in milliseconds
unsigned long pinsCanTime = 0;

//Data logging file
File dataFile;
unsigned long lastLogTime = 0;


void setup() {
  //CAN setup
  setupCAN();

  //Serial setup
  Serial.begin(115200);


  //Setup SD card
  setupSD();
}

void loop() {
  //Inputs
  updateCarFromCanInfo();

  //Logging every 100ms
  if (millis()-lastLogTime > 100) {
    lastLogTime = millis();
    logData();
  }
}

