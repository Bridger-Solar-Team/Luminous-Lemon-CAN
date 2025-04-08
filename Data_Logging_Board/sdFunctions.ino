void setupSD() {
  SD.begin(CS);

  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File file = SD.open("LumLemData.txt", FILE_WRITE);
  file.println("Header line");
  file.close();
}

void logData() {
  dataFile = SD.open("data.txt", FILE_WRITE);
  dataFile.println(millis());
  if(!dataFile) {
    Serial.println("Failed to open file");
  }
  dataFile.close();
}