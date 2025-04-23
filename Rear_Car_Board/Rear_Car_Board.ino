#include <CAN.h>
#include <Adafruit_DS3502.h>
#include <SPI.h>
#include <SD.h>
#include <HardwareSerial.h>

#include "Constants.h"

//rfd900+ serial radio setup
HardwareSerial SerialPort(2); // use UART2

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

//Data logging file
File dataFile;
unsigned long lastLogTime = 0;

void setup() {
  //CAN setup
  setupCAN();

  //Serial setup
  Serial.begin(115200);

  //Digipot Setup
  digipot.begin();
  
  //Pins Setup
  setupPins();

  //Setup SD card
  setupSD();

  //Setup Telemetry Radio
  setupRadios();
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

  //Logging every 100ms
  if (millis()-lastLogTime > 100) {
    lastLogTime = millis();
    logData();
    printFaults();
    printSpeed();
    printMotorInfo();
  }
  
  //Telemetry
  transmitData();
}

