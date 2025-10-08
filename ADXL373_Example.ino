/*
 Example: ADXL373 SPI demo for ESP32-S3
 - Uses VSPI by default (VSPI pins: SCK 18, MISO 19, MOSI 23 typical). 
 - Change pins per your wiring.
*/

#include <SPI.h>
#include "ADXL373.h"

// Use VSPI
SPIClass SPI_VSPI(SPI);
const int CS_PIN = 5; // change to your CS pin
ADXL373 accel(SPI_VSPI, CS_PIN, 8000000, SPI_MODE0);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  if (!accel.begin()) {
    Serial.println("ADXL373 not found or failed ID check. Check wiring and power.");
  } else {
    Serial.println("ADXL373 initialized.");
    Serial.print("PART ID: 0x"); 
    Serial.println(accel.deviceID(), HEX);
    Serial.print("MEMS ID: 0x"); 
    Serial.println(accel.memsID(), HEX);
  }

  // Example: set ODR bits (0..7). Check datasheet table to choose actual ODR value.
  accel.setMeasurementEnabled(false);
  accel.setODR(0x03); // user: pick correct bitfield for desired ODR
  accel.setLowNoiseMode(true);
  accel.setMeasurementEnabled(true);
  delay(20);
}

void loop() {
  float xg, yg, zg;
    accel.readG(xg, yg, zg);
    Serial.print("X g: "); 
    Serial.print(xg, 3);
    Serial.print("  Y g: "); 
    Serial.print(yg, 3);
    Serial.print("  Z g: "); 
    Serial.println(zg, 3);
  delay(100);
}