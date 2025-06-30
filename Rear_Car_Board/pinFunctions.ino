void IRAM_ATTR speedTrigger() {
  pulseSpace = millis() - pulseTime;
  pulseTime = millis();
}

void setupPins() {
  //Pins setup
  attachInterrupt(digitalPinToInterrupt(PIN9), speedTrigger, RISING);

  pinMode(PWR1, OUTPUT);
  pinMode(PWR2, OUTPUT);
  pinMode(PWR3, OUTPUT);
  
  digitalWrite(PWR1, LOW);
  digitalWrite(PWR2, LOW);
  digitalWrite(PWR3, LOW);
}

void updatePins() {

}

void calculateSpeed() {
  if(pulseSpace == 0) {
    speed = 0;
  } else {
    speed = (1/pulseSpace*1000/16)*3600.0 * 3.1415*21.25/(5280.0*12.0);
  }
  speed = min(speed, (float) 99.0);
}