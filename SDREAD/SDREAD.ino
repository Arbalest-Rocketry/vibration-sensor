#include <SD.h>
#include <SPI.h>
#include <Arduino.h>

const int chipSelect = 10;
const char* fileName = "ViolinTest2";

void setup() {
  Serial.begin(500000);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1) {
      // No SD card, so don't do anything more - stay stuck here
    }
  }
  Serial.println("Card initialized.");
  delay(5000);
  Serial.println("Start");
  readFile(fileName);
  Serial.println("End");
}

void loop() {
  // Your loop code goes here
}

void readFile(const char* fileName) {
  // Open the file for reading.
  File dataFile = SD.open(fileName);

  if (dataFile) {
    //Serial.println("Reading contents of file:");

    // Read and print each line of the file.
    while (dataFile.available()) {
      String line = dataFile.readStringUntil('\r'); // Read until carriage return
      Serial.println(line);
      dataFile.read(); // Consume the newline character
    }

    // Close the file.
    dataFile.close();
  } else {
    Serial.println("Error opening file for reading");
  }
}
