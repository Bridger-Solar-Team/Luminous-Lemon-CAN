#include <HardwareSerial.h>
#include "Constants.h"

HardwareSerial SerialPort(2); // use UART2

unsigned long lastTime = 0;
int dataToSend = 0;

void setup() {
  Serial.begin(115200);
  SerialPort.begin(57600, SERIAL_8N1, PIN5, PIN6); 
} 

void sendData() {
  if(millis() - lastTime > 500) {
    SerialPort.print(dataToSend);
    Serial.println(dataToSend);
    dataToSend++;
    dataToSend = dataToSend%2;
    lastTime = millis();
  }
}

void loop() { 
  sendData();
  while(SerialPort.available() > 0) {
    Serial.print(SerialPort.read());
  }
  delay(1);
}