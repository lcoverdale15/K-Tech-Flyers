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

/* Register map (from datasheet) 
#define ADXL373_REG_DEVID           0x00
#define ADXL373_REG_MEMS_ID         0x01
#define ADXL373_REG_PARTID          0x02
#define ADXL373_REG_REVID           0x03
#define ADXL373_REG_STATUS          0x04
#define ADXL373_REG_STATUS2         0x05
#define ADXL373_REG_XDATA_MSB       0x06
#define ADXL373_REG_XDATA_LSB       0x07
#define ADXL373_REG_YDATA_MSB       0x08
#define ADXL373_REG_YDATA_LSB       0x09
#define ADXL373_REG_ZDATA_MSB       0x0A
#define ADXL373_REG_ZDATA_LSB       0x0B
#define ADXL373_REG_OFF_X           0x0C
#define ADXL373_REG_OFF_Y           0x0D
#define ADXL373_REG_OFF_Z           0x0E
#define ADXL373_REG_THRESH_ACT_X_L  0x0F
#define ADXL373_REG_THRESH_ACT_X_H  0x10
#define ADXL373_REG_THRESH_ACT_Y_L  0x11
#define ADXL373_REG_THRESH_ACT_Y_H  0x12
#define ADXL373_REG_THRESH_ACT_Z_L  0x13
#define ADXL373_REG_THRESH_ACT_Z_H  0x14
#define ADXL373_REG_TIME_ACT        0x15
#define ADXL373_REG_THRESH_INACT_X_L 0x16
#define ADXL373_REG_THRESH_INACT_X_H 0x17
#define ADXL373_REG_THRESH_INACT_Y_L 0x18
#define ADXL373_REG_THRESH_INACT_Y_H 0x19
#define ADXL373_REG_THRESH_INACT_Z_L 0x1A
#define ADXL373_REG_THRESH_INACT_Z_H 0x1B
#define ADXL373_REG_TIME_INACT_L    0x1C
#define ADXL373_REG_TIME_INACT_H    0x1D
#define ADXL373_REG_THRESH_MOTION_X_L 0x1E
#define ADXL373_REG_THRESH_MOTION_X_H 0x1F
#define ADXL373_REG_THRESH_MOTION_Y_L 0x20
#define ADXL373_REG_THRESH_MOTION_Y_H 0x21
#define ADXL373_REG_THRESH_MOTION_Z_L 0x22
#define ADXL373_REG_THRESH_MOTION_Z_H 0x23
#define ADXL373_REG_HP_FILTER       0x24
#define ADXL373_REG_FIFO_SAMPLES    0x25
#define ADXL373_REG_FIFO_CTL        0x26
#define ADXL373_REG_INT_MAP1        0x27
#define ADXL373_REG_INT_MAP2        0x28
#define ADXL373_REG_EXT_TIMING      0x29
#define ADXL373_REG_MEASURE_CTL     0x2A
#define ADXL373_REG_POWER_CTL       0x2B
#define ADXL373_REG_SELF_TEST       0x2C
#define ADXL373_REG_RESET           0x2D
#define ADXL373_REG_FIFO_ACCESS     0x2E

/* Useful bits 
#define ADXL373_MEASURE_CTL_ODR_MASK     0x07
#define ADXL373_MEASURE_CTL_LN_BIT       0x10
#define ADXL373_MEASURE_CTL_FILTER_SETTLE 0x20

#define ADXL373_POWER_CTL_MEASURE        0x01
#define ADXL373_RESET_SOFT               0x52 // write to RESET in standby to reset*/

#define ADXL373_REG_DEVID               0x00    // Device ID (fixed = 0xAD)
#define ADXL373_REG_MEMS_ID             0x01    // MEMS ID (fixed = 0x1D)
#define ADXL373_REG_PARTID              0x02    // Part ID (fixed = 0xFA)
#define ADXL373_REG_REVID               0x03    // Revision ID
#define ADXL373_REG_STATUS              0x04    // Status register
#define ADXL373_REG_STATUS2             0x05    // Status 2 register

// Output Data Registers
#define ADXL373_REG_XDATA_H             0x06    // X-axis data [15:8]
#define ADXL373_REG_XDATA_L             0x07    // X-axis data [7:0]
#define ADXL373_REG_YDATA_H             0x08    // Y-axis data [15:8]
#define ADXL373_REG_YDATA_L             0x09    // Y-axis data [7:0]
#define ADXL373_REG_ZDATA_H             0x0A    // Z-axis data [15:8]
#define ADXL373_REG_ZDATA_L             0x0B    // Z-axis data [7:0]

// Offset and Threshold Registers
#define ADXL373_REG_OFF_X               0x0C
#define ADXL373_REG_OFF_Y               0x0D
#define ADXL373_REG_OFF_Z               0x0E

#define ADXL373_REG_THRESH_ACT_X_L      0x0F
#define ADXL373_REG_THRESH_ACT_X_H      0x10
#define ADXL373_REG_THRESH_ACT_Y_L      0x11
#define ADXL373_REG_THRESH_ACT_Y_H      0x12
#define ADXL373_REG_THRESH_ACT_Z_L      0x13
#define ADXL373_REG_THRESH_ACT_Z_H      0x14
#define ADXL373_REG_TIME_ACT            0x15

#define ADXL373_REG_THRESH_INACT_X_L    0x16
#define ADXL373_REG_THRESH_INACT_X_H    0x17
#define ADXL373_REG_THRESH_INACT_Y_L    0x18
#define ADXL373_REG_THRESH_INACT_Y_H    0x19
#define ADXL373_REG_THRESH_INACT_Z_L    0x1A
#define ADXL373_REG_THRESH_INACT_Z_H    0x1B
#define ADXL373_REG_TIME_INACT_L        0x1C
#define ADXL373_REG_TIME_INACT_H        0x1D

#define ADXL373_REG_THRESH_MOTION_X_L   0x1E
#define ADXL373_REG_THRESH_MOTION_X_H   0x1F
#define ADXL373_REG_THRESH_MOTION_Y_L   0x20
#define ADXL373_REG_THRESH_MOTION_Y_H   0x21
#define ADXL373_REG_THRESH_MOTION_Z_L   0x22
#define ADXL373_REG_THRESH_MOTION_Z_H   0x23

// Filter and FIFO Control
#define ADXL373_REG_HP_FILTER           0x24
#define ADXL373_REG_FIFO_SAMPLES        0x25
#define ADXL373_REG_FIFO_CTL            0x26

// Interrupt Mapping
#define ADXL373_REG_INT_MAP1            0x27
#define ADXL373_REG_INT_MAP2            0x28

// Timing and Measurement Control
#define ADXL373_REG_EXT_TIMING          0x29
#define ADXL373_REG_MEASURE_CTL         0x2A
#define ADXL373_REG_POWER_CTL           0x2B
#define ADXL373_REG_SELF_TEST           0x2C
#define ADXL373_REG_RESET               0x2D
#define ADXL373_REG_FIFO_ACCESS         0x2E

// Internal/Reserved Registers (0x2F–0x3F are internal use)

// ============================================================================
// USEFUL BIT DEFINITIONS (from datasheet)
// ============================================================================

// STATUS Register (0x04)
#define ADXL373_STATUS_DATA_RDY         0x01    // New data ready
#define ADXL373_STATUS_FIFO_RDY         0x02
#define ADXL373_STATUS_FIFO_FULL        0x04
#define ADXL373_STATUS_FIFO_OVR         0x08
#define ADXL373_STATUS_ACTIVITY         0x10
#define ADXL373_STATUS_INACTIVITY       0x20
#define ADXL373_STATUS_AWAKE            0x40
#define ADXL373_STATUS_ERR              0x80

// MEASURE_CTL (0x2A)
#define ADXL373_MEASURE_CTL_ODR_MASK        0x07    // Bits [2:0] set output data rate
#define ADXL373_MEASURE_CTL_LN_BIT          0x10    // Low-noise mode enable
#define ADXL373_MEASURE_CTL_FILTER_SETTLE   0x20    // Filter settle enable

// POWER_CTL (0x2B)
#define ADXL373_POWER_CTL_STANDBY       0x00
#define ADXL373_POWER_CTL_MEASURE       0x01
#define ADXL373_POWER_CTL_AUTOSLEEP     0x02

// RESET Register (0x2D)
#define ADXL373_RESET_SOFT              0x52    // Write 0x52 to reset (only in standby)

// FIFO_CTL (0x26)
#define ADXL373_FIFO_MODE_MASK          0x03
#define ADXL373_FIFO_MODE_BYPASS        0x00
#define ADXL373_FIFO_MODE_FIFO          0x01
#define ADXL373_FIFO_MODE_STREAM        0x02
#define ADXL373_FIFO_MODE_TRIGGER       0x03

// HP_FILTER (0x24)
#define ADXL373_HPF_CORNER_MASK         0x07    // Bits [2:0] select HP filter corner

#endif // ADXL373_H