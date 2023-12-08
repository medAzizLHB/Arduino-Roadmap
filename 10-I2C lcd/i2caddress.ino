#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("\nI2C Scanner");

  Wire.begin();

  scanI2CDevices();
}

void loop() {
  // Nothing to do here
}

void scanI2CDevices() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Found device at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");

      deviceCount++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }


