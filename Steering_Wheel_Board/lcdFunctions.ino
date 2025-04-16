void updateDisplay() {
  //00MPH MTR56% CRS
  //V+87% PWR ON  T0
  
  old_line0 = line0;
  old_line1 = line1;
  line0 = "";
  line1 = "";
  if(dispToggle) {
    //Speed, 0-99 miles per hour
    
    line0 += (int)(round(speed)/10)%10; //1
    line0 += (int)round(speed)%10; //2
    line0 += "MPH "; //3,4,5,6

    //Brake pedal. BRAKE when braking, motor percent power otherwise
    if(brakePressed) {
      line0 += "BRAKE!"; //7,8,9,10,11,12
    }
    else {
      if(dcl < DCL_WARNING_SETPOINT) {
        line0 += "DCL"; //7,8,9
      } else {
        line0 += "MTR"; //7,8,9
      }
      //0-99 motor power as an integer for no decimals
      int motorPower;
      if(cruiseControl){
        motorPower = min(round(cruiseSpeed*100.0),99.0);
      } else {
        motorPower = min(round(throttle*100.0),99.0);
      }
      line0 += (motorPower/10)%10; //10
      line0 += motorPower%10; //11
      line0 += "%"; //12
    }

    //Cruise control switch. 0 when out, 1 when in
    if(cruiseControl) {
      line0 += " CRS"; //13,14,15,16
    } else {
      line0 += " N/A"; //13,14,15,16
    }
    //End of the top row

    //State of charge. 0-99%
    line1 += "V+"; //1,2
    line1 += (int)(round(soc*99)/10)%10; //3
    line1 += (int)round(soc*99)%10; //4
    line1 += "% "; //5, 6

    //Main power switch. PWR ON when on, PWROFF when off
    if(fault) {
      line1 += "FLT: "; //7, 8, 9, 10, 11
      line1 += faultCode; //12
    } else if(powerOn) {
      line1 += "PWR ON"; //7,8,9,10,11,12
    } else {
      line1 += "PWROFF"; //7,8,9,10,11,12
    }
    
    //Turn signals (T), right(R), left(L), hazard(H), and nothing(0). hazard overrides right and left
    line1 += "  T"; //13,14,15
    if(hazzards) { line1 += "H";} //16
    else if(rightTurn) { line1 += "R";} //16
    else if(leftTurn) {line1 += "L";} //16
    else {line1 += "0";} //16
  }
  else {
    line0 += (int)(workingVoltageLV/10)%10;//1
    line0 += (int)(workingVoltageLV)%10;//2
    line0 += ".";//3
    line0 += (int)round(workingVoltageLV*10)%10;//4
    line0 += " B"; //5,6
    line0 += (int)(batteryVoltageLV/10)%10;//7
    line0 += (int)(batteryVoltageLV)%10;//8
    line0 += ".";//9
    line0 += (int)round(batteryVoltageLV*10)%10;//10
    line0 += " "; //11
    line0 += (int)(currentDraw/10)%10;//12
    line0 += (int)(currentDraw)%10;//13
    line0 += ".";//14
    line0 += (int)round(currentDraw*10)%10;//15
    line0 += "A";//16

    //line1 += "XXC X.XX X.XX FF";

    line1 += (int)(cellHighTemp/10)%10;//1
    line1 += (int)(cellHighTemp)%10;//2
    line1 += "C "; //3,4
    line1 += (int)(cellLowV)%10;//5
    line1 += ".";//6
    line1 += (int)(cellLowV*10)%10;//7
    line1 += (int)round(cellLowV*100)%10;//8
    line1 += " ";//9
    line1 += (int)(cellHighV)%10;//10
    line1 += ".";//11
    line1 += (int)(cellHighV*10)%10;//12
    line1 += (int)round(cellHighV*100)%10;//13
    line1 += " ";//14
    line1 += (char)canData[4][6] & 0b11110000;//15
    line1 += (char)canData[4][6] & 0b00001111;//16


  }

  //Only update the display if the data has changed
  if(old_line0 != line0){
    lcd.setCursor(0, 0);
    lcd.print(line0);
    old_line0 = line0;
  }

  //Only update the display if the data has changed
  if(old_line1 != line1) {
    lcd.setCursor(0, 1);
    lcd.print(line1);
    old_line1 = line1;
  }
}