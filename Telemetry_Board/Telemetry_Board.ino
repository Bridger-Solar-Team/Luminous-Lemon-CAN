#include <HardwareSerial.h>
#include "Constants.h"

HardwareSerial SerialPort(2); // use UART2

unsigned long lastTime = 0;
int dataToSend = 0;
bool receivedData = false;
bool delayed = false;

void setup() {
  Serial.begin(115200);
  SerialPort.begin(57600, SERIAL_8N1, PIN6, PIN5); 
} 

void sendData() {
  if(millis() - lastTime > 500) {
    SerialPort.print(dataToSend+2);
    Serial.println(dataToSend+2);
    dataToSend++;
    dataToSend = dataToSend%2;
    lastTime = millis();
  }
}

void loop() { 
  // sendData();
  while(SerialPort.available() > 0) {
    if(!delayed) {
      delay(10);
      delayed = true;
    }
    // Serial.print("Remote data: ");
    Serial.print((char) SerialPort.read());
    receivedData = true;
    delay(1);
  }
  if(receivedData){
    Serial.println();
    receivedData = false;
    delayed = false;
  }
}