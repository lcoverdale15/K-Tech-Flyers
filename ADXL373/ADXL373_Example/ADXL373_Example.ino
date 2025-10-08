/*
 Example: ADXL373 SPI demo for ESP32-S3
 - Uses VSPI by default (VSPI pins: SCK 18, MISO 19, MOSI 23 typical). 
 - Change pins per your wiring.
*/

#include <SPI.h>
#include "ADXL373.h"

const int CS_PIN   = 10;      // Your chip select pin
const int SCK_PIN  = 14;      // HSPI SCK
const int MISO_PIN = 12;      // HSPI MISO
const int MOSI_PIN = 13;      // HSPI MOSI

ADXL373 accel(SPI, CS_PIN, 500000, SPI_MODE3);

uint8_t readReg(uint8_t reg) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0x80 | reg);      // 0x80 for single-byte read
  uint8_t val = SPI.transfer(0x00);
  digitalWrite(CS_PIN, HIGH);
  return val;
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

  uint8_t devid = readReg(0x00);
  Serial.print("Raw DEVID = 0x");
  Serial.println(devid, HEX);
}

void loop() {}
