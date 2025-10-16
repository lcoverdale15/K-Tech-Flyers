/* ADXL373.h
   Full Arduino-style library header for ADXL373 (SPI primary).
   Author: ChatGPT (generated for user)
   Based on ADXL373 datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/adxl373.pdf
*/

#ifndef ADXL373_H
#define ADXL373_H

#include <Arduino.h>
#include <SPI.h>

class ADXL373 {
public:
  // SPI constructor (primary use-case)
  // spi: reference to SPI (e.g., VSPI, HSPI), csPin: chip select pin, spiClockHz: preferred SPI clock
  ADXL373(SPIClass &spi, int csPin, uint32_t spiClockHz = 8000000, uint8_t spiMode = SPI_MODE0);

  // Begin the device; returns true if comms look OK (checks device IDs).
  bool begin();

  // Basic register access
  uint8_t readRegister(uint8_t reg);
  bool readRegisters(uint8_t reg, uint8_t *buf, size_t len);
  void writeRegister(uint8_t reg, uint8_t value);

  // Device control
  bool softReset();
  uint8_t deviceID();      // PRODUCT ID
  uint8_t revisionID();    // REV ID
  uint8_t analogDevicesID();
  uint8_t memsID();

  // Measurement control
  void setMeasurementEnabled(bool on);
  void setLowNoiseMode(bool on);
  void setFilterFastSettle(bool on);
  void setODR(uint8_t odr_bits); // 3-bit ODR field per datasheet

  // Read acceleration
  // returns true on success. x,y,z are signed 16-bit values scaled to ADXL373 12-bit (200 mg/LSB)
  bool readRaw(int16_t &x, int16_t &y, int16_t &z);

  // Convenience that returns float g values (g units). scaleFactor default is 0.200 -> 200 mg/LSB
  //bool readG(float &xg, float &yg, float &zg, float scale_mg_per_lsb = 200.0f);

  // Offsets & calibration
  void setOffsetTrim(int8_t x_off, int8_t y_off, int8_t z_off);
  void getOffsetTrim(int8_t &x_off, int8_t &y_off, int8_t &z_off);

  // FIFO helpers
  uint8_t fifoSamples(); // number of samples in FIFO (reg)
  void fifoEnable(bool en);
  void fifoControl(uint8_t mode, uint8_t watermark);
  // Read FIFO sample(s): caller provides buffer sized for numSamples*6 bytes (per-sample 3 axes, MSB/LSB each)
  bool readFIFOSamples(uint8_t *buf, size_t bytesToRead);

  // Interrupt mapping / enable
  void mapInterrupts(uint8_t intMap1, uint8_t intMap2);
  void enableIntPinPullups(bool enable);

  // Activity / inactivity / motion helpers
  void setActivityThreshold(uint16_t mg_threshold); // sets generic threshold (user converts mg->register units)
  void setInactivityThreshold(uint16_t mg_threshold);
  void setActivityTime(uint16_t ms);

  // Self test
  void selfTestEnable(bool on);

  // Low-level: set SPI speed and mode
  void setSpiSettings(uint32_t spiClockHz, uint8_t spiMode);

  void readG(float &x, float &y, float &z);

private:
  SPIClass *_spi;
  int _csPin;
  SPISettings _spiSettings;

  // internal helpers
  void csSelect();
  void csDeselect();
  uint16_t read16FromRegs(uint8_t msbReg); // read MSB/LSB pair and pack
  int16_t signExtend12(int16_t val12);

  // constants
  static constexpr float MG_PER_LSB = 200.0f; // 200 mg/LSB per datasheet (12-bit)
};

#define ADXL373_REG_DEVID               0x00    // Device ID (fixed = 0xAD)
#define ADXL373_REG_DEVID_MST           0x01    // MEMS ID (fixed = 0x1D)
#define ADXL373_REG_PARTID              0x02    // Part ID (fixed = 0xFA)
#define ADXL373_REG_REVID               0x03    // Revision ID
#define ADXL373_REG_STATUS              0x04    // Status register
#define ADXL373_REG_STATUS2             0x05    // Status 2 register

// Output Data Registers
#define ADXL373_REG_FIFO_ENTRIES2       0x06
#define ADXL373_REG_FIFO_ENTRIES        0x07
#define ADXL373_REG_XDATA_H             0x08    // X-axis data [15:8]
#define ADXL373_REG_XDATA_L             0x09    // X-axis data [7:0]
#define ADXL373_REG_YDATA_H             0x0A    // Y-axis data [15:8]
#define ADXL373_REG_YDATA_L             0x0B    // Y-axis data [7:0]
#define ADXL373_REG_ZDATA_H             0x0C    // Z-axis data [15:8]
#define ADXL373_REG_ZDATA_L             0x0D    // Z-axis data [7:0]

// Offset and Threshold Registers
#define ADXL373_REG_MAXPREAK_X_H        0x15
#define ADXL373_REG_MAXPREAK_X_L        0x16
#define ADXL373_REG_MAXPREAK_Y_H        0x17
#define ADXL373_REG_MAXPREAK_Y_L        0x18
#define ADXL373_REG_MAXPREAK_Z_H        0x19
#define ADXL373_REG_MAXPREAK_Z_L        0x1A

#define ADXL373_REG_OFFSET_X            0x20
#define ADXL373_REG_OFFSET_Y            0x21
#define ADXL373_REG_OFFSET_Z            0x22

#define ADXL373_REG_THRESH_ACT_X_L      0x24
#define ADXL373_REG_THRESH_ACT_X_H      0x23
#define ADXL373_REG_THRESH_ACT_Y_L      0x26
#define ADXL373_REG_THRESH_ACT_Y_H      0x25
#define ADXL373_REG_THRESH_ACT_Z_L      0x28
#define ADXL373_REG_THRESH_ACT_Z_H      0x27
#define ADXL373_REG_TIME_ACT            0x29

#define ADXL373_REG_THRESH_INACT_X_L    0x2B
#define ADXL373_REG_THRESH_INACT_X_H    0x2A
#define ADXL373_REG_THRESH_INACT_Y_L    0x2D
#define ADXL373_REG_THRESH_INACT_Y_H    0x2C
#define ADXL373_REG_THRESH_INACT_Z_L    0x2F
#define ADXL373_REG_THRESH_INACT_Z_H    0x2E
#define ADXL373_REG_TIME_INACT_L        0x31
#define ADXL373_REG_TIME_INACT_H        0x30
#define ADXL373_REG_THRESH_ACT2_X_H     0x32
#define ADXL373_REG_THRESH_ACT2_X_L     0x33
#define ADXL373_REG_THRESH_ACT2_Y_H     0x34
#define ADXL373_REG_THRESH_ACT2_Y_L     0x35
#define ADXL373_REG_THRESH_ACT2_Z_H     0x36
#define ADXL373_REG_THRESH_ACT2_Z_L     0x37

// Filter and FIFO Control
#define ADXL373_REG_HPF                 0x38
#define ADXL373_REG_FIFO_SAMPLES        0x39
#define ADXL373_REG_FIFO_CTL            0x3A

// Interrupt Mapping
#define ADXL373_REG_INT_MAP1            0x3B
#define ADXL373_REG_INT_MAP2            0x3C

// Timing and Measurement Control
#define ADXL373_REG_TIMING              0x3D
#define ADXL373_REG_MEASURE             0x3E
#define ADXL373_REG_POWER_CTL           0x3F
#define ADXL373_REG_SELF_TEST           0x40
#define ADXL373_REG_RESET               0x41
#define ADXL373_REG_FIFO_DATA           0x42

#endif // ADXL373_H