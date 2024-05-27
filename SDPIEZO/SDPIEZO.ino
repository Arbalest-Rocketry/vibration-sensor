#include <SD.h>
#include <SPI.h>
#include <Arduino.h>

const int piezoPin = A4;
const int chipSelect = 10;

String FileName() {
  String fileName;
    String OGfile = "filename";

    for (int i = 1; i < 100; i++) {
      
    if (!SD.exists((String(OGfile) + String(i)).c_str()) && SD.exists(String(OGfile).c_str())) {
         fileName = String(OGfile) + String(i);
        break;

    } else {
       fileName = OGfile; 
    }   
}
return fileName;
}
  

void setup() {
  Serial.begin(500000);
  pinMode(6, OUTPUT);
  analogWrite(6, 0);
  analogWrite(6, 10);
  delay(1000);
  
  //while (!Serial) {
   // ; // wait for serial port to connect.
  //}

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    //while (1) {
      // No SD card, so don't do anything more - stay stuck here
    //}
  }
  Serial.println("card initialized.");
  analogWrite(6, 255);
  // Write data to the file
  writeFile();
  
  // Read data from the file only once
  

  // Stay in a loop, indicating the end of the program
  while (1) {
    // Stay stuck here, as the loop should only run once.
  }
}

void loop() {}

void writeFile() {

  String filenameObj = FileName();
  // Open the file for writing.
  File dataFile = SD.open(filenameObj.c_str(), FILE_WRITE);

  if (dataFile) {
    // Print numbers 1 to 10 to the file.
    unsigned long startTime = micros();
    while (micros() - startTime < 30000000) {
      int sensorValue = analogRead(piezoPin);
      dataFile.print(micros());
      dataFile.print(", ");
      dataFile.println(sensorValue / 1.0);
      delayMicroseconds(500);
    }
    //dataFile.println("File name is " + filenameObj);
    // Close the file.
    dataFile.close();
    analogWrite(6, 0);
    Serial.println("end");
    Serial.println("saved to " + filenameObj);
    
  } else {
    // If the file isn't open, pop up an error:
    Serial.print("error opening ");
    Serial.println(filenameObj);
  }
}



