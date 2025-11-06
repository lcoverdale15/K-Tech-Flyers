/*
 Example: ADXL373 SPI demo for ESP32-S3
 - Uses VSPI by default (VSPI pins: SCK 18, MISO 19, MOSI 23 typical). 
 - Change pins per your wiring.
*/

#include <SPI.h>
#include "ADXL373.h"

#define CS 10
#define MOSI 13
#define MISO 14
#define SCLK 12
#define WRITE 0x00
#define READ 0x80

ADXL373 accel;

// Establish variables to identify x, y, and z axis accelerations
int x_axis = 1;
int y_axis = 2;
int z_axis = 3;

void setup() {

  accel.begin(SCLK, MISO, MOSI, CS);

  Serial.begin(115200);

  delay(500);  // Longer startup delay
}

void loop() {
  byte status = accel.readRegister(ADXL373_STATUS);

  if (status & 0x01) {
    int x = accel.getValue(x_axis);
    int y = accel.getValue(y_axis);
    int z = accel.getValue(z_axis);

    Serial.print(" x = ");
    Serial.print(x);
    Serial.print(" mg | y = ");
    Serial.print(y);
    Serial.print(" mg | z = ");
    Serial.println(z);
  }

  delay(50);
}