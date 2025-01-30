// void update_display() {
//   //00MPH MTR56% CRS
//   //V+87% PWR ON  T0
  
//   old_line0 = line0;
//   old_line1 = line1;
//   line0 = "";
//   line1 = "";

//   //Speed, 0-99 miles per hour
//   line0 += "?"; //1
//   line0 += "?"; //2
//   line0 += "MPH "; //3,4,5,6

//   //Brake pedal. BRAKE when braking, motor percent power otherwise
//   if(brakePressed) {
//     line0 += "BRAKE!"; //7,8,9,10,11,12
//   }
//   else {
//     if(dcl < DCL_WARNING_SETPOINT) {
//       line0 += "DCL"; //7,8,9
//     } else if(ccl < CCL_WARNING_SETPOINT) {
//       line0 += "CCL"; //7,8,9
//     } else {
//       line0 += "MTR"; //7,8,9
//     }
//     //0-99 motor power as an integer for no decimals
//     int motorPower;
//     if(cruise_control){
//       motorPower = min(round((cruise_speed/255.0)*100),99);
//     } else {
//       motorPower = min(round(throttle*100.0),99);
//     }
//     line0 += (motorPower/10)%10; //10
//     line0 += motorPower%10; //11
//     line0 += "%"; //12
//   }

//   //Cruise control switch. 0 when out, 1 when in
//   if(cruiseControl) {
//     line0 += " CRS"; //13,14,15,16
//   }
//   else if(true_ccl_fault) {
//     line0 += " CCL"; //13, 14, 15, 16
//   }
//   else if(true_dcl_fault) {
//     line0 += " DCL"; //13,14,15,16
//   }
//   else if (true_dcl_fault || true_ccl_fault) {
//     line0 += " BTH"; //13,14,15,16
//   }
//   else if(true_fault) {
//     line0 += " BPS"; //13,14,15,16
//   }
//   else {
//     line0 += " N/A"; //13,14,15,16
//   }
//   //End of the top row

//   //State of charge. 0-99%
//   line1 += "V+"; //1,2
//   line1 += (round(soc*99)/10)%10; //3
//   line1 += round(soc*99)%10; //4
//   line1 += "% "; //5, 6

//   //Main power switch. PWR ON when on, PWROFF when off
//   if(fault) {
//     line1 += "FAULT "; //7, 8, 9, 10, 11, 12
//   }
//   else if(powerOn) {
//     line1 += "PWR ON"; //7,8,9,10,11,12
//   }
//   else {
//     line1 += "PWROFF"; //7,8,9,10,11,12
//   }
  
//   //Turn signals (T), right(R), left(L), hazard(H), and nothing(0). hazard overrides right and left
//   line1 += "  T"; //13,14,15
//   if(hazard_pressed) {
//     line1 += "H"; //16
//   }
//   else if(right_turn) {
//     line1 += "R"; //16
//   }
//   else if(left_turn) {
//     line1 += "L"; //16
//   }
//   else {
//     line1 += "0"; //16
//   }

//   //Only update the display if the data has changed
//   if(old_line0 != line0){
//     lcd.setCursor(0, 0);
//     lcd.print(line0);
//     old_line0 = line0;
//   }

//   //Only update the display if the data has changed
//   if(old_line1 != line1) {
//     lcd.setCursor(0, 1);
//     lcd.print(line1);
//     old_line1 = line1;
//   }
// }