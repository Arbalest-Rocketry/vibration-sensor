#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(500000);
  if (!SD.begin()) {
    //Serial.println("Initialization failed!");
    return;
  }

  if (SD.exists("ViolinTest2")) {
    myFile = SD.open("ViolinTest2");
    if (myFile) {
      //Serial.println("Start");
      delay(10000);

      while (myFile.available()) {
        Serial.write(myFile.read()); // Send file content over serial
      }

      //Serial.println("End");
      myFile.close();
    }
  } else {
    Serial.println("File not found");
  }
}

void loop() {
  // Your loop code goes here
}
