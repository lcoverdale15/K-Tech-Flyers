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

// Establish variables to identify x, y, and z axis accelerations
int x_axis = 1;
int y_axis = 2;
int z_axis = 3;

void setup() {
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  SPI.begin(SCLK, MISO, MOSI, CS);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  Serial.begin(115200);

  delay(500);  // Longer startup delay

  Serial.println("=== ADXL37x Setup ===");

  // Read all ID registers
  Serial.print("Reg 0x00: 0x");
  Serial.println(readRegister(0x00), HEX);
  Serial.print("Reg 0x01: 0x");
  Serial.println(readRegister(0x01), HEX);
  Serial.print("Reg 0x02: 0x");
  Serial.println(readRegister(0x02), HEX);

  // Software reset
  writeRegister(0x3F, 0x52);  // Reset command
  delay(100);

  // Configure for full bandwidth measurement
  writeRegister(ADXL373_MEASURE, 0b00000100);  // MEASURE register
  writeRegister(ADXL373_TIMING, 0b01000000);  // TIMING register 0x02 = 1280Hz
  writeRegister(ADXL373_POWER_CTL, 0b00000111);  // POWER_CTL = Full bandwidth (0x03)

  delay(200);

  // Verify
  Serial.print("POWER_CTL: 0x");
  Serial.println(readRegister(0x3F), HEX);

  // Poll status until data ready
  for (int i = 0; i < 20; i++) {
    delay(10);
    byte status = readRegister(0x04);
    Serial.print("Status[");
    Serial.print(i);
    Serial.print("]: 0x");
    Serial.println(status, HEX);
    if (status != 0) break;
  }
}

void loop() {
  byte status = readRegister(ADXL373_STATUS);

  if (status & 0x01) {
    int x = getValue(x_axis);
    int y = getValue(y_axis);
    int z = getValue(z_axis);

    Serial.print(" x = ");
    Serial.print(x);
    Serial.print(" mg | y = ");
    Serial.print(y);
    Serial.print(" mg | z = ");
    Serial.println(z);
  }

  delay(50);
}

int getValue(int axis) {
  int16_t AccelData = 0;
  int Offset = 0;
  int high, low;
  if (axis == 1) {
    high = readRegister(ADXL373_XDATA_H);
    low = readRegister(ADXL373_XDATA_L);
  } else if (axis == 2) {
    high = readRegister(ADXL373_YDATA_H);
    low = readRegister(ADXL373_YDATA_L);
  } else if (axis == 3) {
    high = readRegister(ADXL373_ZDATA_H);
    low = readRegister(ADXL373_ZDATA_L);
  }
  AccelData = (high << 4) | (low >> 4);  // Merge 8 bits from 'high' with upper 4 of 'low'

  if (AccelData & 0x800) {
    AccelData |= 0xF000;
  }

  long accel_g = (long)AccelData * 200;

  return accel_g;
}

byte readRegister(byte thisRegister) {
  byte result = 0;  // predeclare result to return
  // ADXL373 expects the register address in the upper 7 bits of the transmitted byte
  byte dataToSend = (thisRegister << 1) | 0x01;  // Combine register address with READ command
  digitalWrite(CS, LOW);                         //Set the Chip Select pin low to start an SPI packet
  SPI.transfer(dataToSend);
  result = SPI.transfer(0x00);  // Tell device to read register and save response
  digitalWrite(CS, HIGH);       //Set CS high to close communcation
  return result;
}

void writeRegister(byte thisRegister, byte thisValue) {
  // ADXL373 expects the register address in the upper 7 bits of the transmitted byte
  // Shift the register bits left by 1 bit to apply WRITE bit:
  byte dataWrite = (thisRegister << 1) | 0x00;  // Combine the register address and WRITE command
  digitalWrite(CS, LOW);                        //Set CS pin low to signal SPI packet start
  SPI.transfer(dataWrite);                      //Transfer the register address, RW, and desired register value over SPI
  SPI.transfer(thisValue);
  digitalWrite(CS, HIGH);  //Set the Chip Select pin high to signal the end of an SPI packet.
}