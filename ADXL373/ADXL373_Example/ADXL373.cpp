#include <ADXL373.h>

ADXL373::ADXL373()
{
  _cs = 0;
}

void
ADXL373::begin(uint8_t sclk, uint8_t miso, uint8_t mosi, uint8_t cs){
  this->_cs = cs;
  pinMode(cs, OUTPUT);
  digitalWrite(cs, HIGH);

  SPI.begin(sclk, miso, mosi, cs);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  writeRegister(0x3F, 0x52);  // Reset command
  delay(100);

  // Configure for full bandwidth measurement
  writeRegister(ADXL373_MEASURE, 0b00000100);  // MEASURE register
  writeRegister(ADXL373_TIMING, 0b01000000);  // TIMING register 0x02 = 1280Hz
  writeRegister(ADXL373_POWER_CTL, 0b00000111);  // POWER_CTL = Full bandwidth (0x03)
}

int
ADXL373::getValue(int axis) {
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

byte
ADXL373::readRegister(byte thisRegister) {
  byte result = 0;  // predeclare result to return
  // ADXL373 expects the register address in the upper 7 bits of the transmitted byte
  byte dataToSend = (thisRegister << 1) | 0x01;  // Combine register address with READ command
  digitalWrite(_cs, LOW);                         //Set the Chip Select pin low to start an SPI packet
  SPI.transfer(dataToSend);
  result = SPI.transfer(0x00);  // Tell device to read register and save response
  digitalWrite(_cs, HIGH);       //Set CS high to close communcation
  return result;
}

void
ADXL373::writeRegister(byte thisRegister, byte thisValue) {
  // ADXL373 expects the register address in the upper 7 bits of the transmitted byte
  // Shift the register bits left by 1 bit to apply WRITE bit:
  byte dataWrite = (thisRegister << 1) | 0x00;  // Combine the register address and WRITE command
  digitalWrite(_cs, LOW);                        //Set CS pin low to signal SPI packet start
  SPI.transfer(dataWrite);                      //Transfer the register address, RW, and desired register value over SPI
  SPI.transfer(thisValue);
  digitalWrite(_cs, HIGH);  //Set the Chip Select pin high to signal the end of an SPI packet.
}