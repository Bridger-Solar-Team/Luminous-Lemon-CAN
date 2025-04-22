#include <HardwareSerial.h>
#include "Constants.h"

HardwareSerial SerialPort(2); // use UART2


void setup() {
  SerialPort.begin(57600, SERIAL_8N1, SCL, SDA); 
} 

void loop() { 
  SerialPort.print(1);
  delay(500);
  SerialPort.print(0);
  delay(500);
}