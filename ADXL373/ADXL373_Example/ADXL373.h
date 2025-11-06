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
private:
   uint8_t _cs;
public:
   ADXL373();
   void begin(uint8_t sclk, uint8_t miso, uint8_t mosi, uint8_t cs);
   int getValue(int axis);
   byte readRegister(byte thisRegister);
   void writeRegister(byte thisRegister, byte thisValue);
  
};

#define ADXL373_DEVID               0x00    // Device ID (fixed = 0xAD)
#define ADXL373_DEVID_MST           0x01    // MEMS ID (fixed = 0x1D)
#define ADXL373_PARTID              0x02    // Part ID (fixed = 0xFA)
#define ADXL373_REVID               0x03    // Revision ID
#define ADXL373_STATUS              0x04    // Status register
#define ADXL373_STATUS2             0x05    // Status 2 register

// Output Data Registers
#define ADXL373_FIFO_ENTRIES2       0x06
#define ADXL373_FIFO_ENTRIES        0x07
#define ADXL373_XDATA_H             0x08    // X-axis data [15:8]
#define ADXL373_XDATA_L             0x09    // X-axis data [7:0]
#define ADXL373_YDATA_H             0x0A    // Y-axis data [15:8]
#define ADXL373_YDATA_L             0x0B    // Y-axis data [7:0]
#define ADXL373_ZDATA_H             0x0C    // Z-axis data [15:8]
#define ADXL373_ZDATA_L             0x0D    // Z-axis data [7:0]

// Offset and Threshold Registers
#define ADXL373_MAXPREAK_X_H        0x15
#define ADXL373_MAXPREAK_X_L        0x16
#define ADXL373_MAXPREAK_Y_H        0x17
#define ADXL373_MAXPREAK_Y_L        0x18
#define ADXL373_MAXPREAK_Z_H        0x19
#define ADXL373_MAXPREAK_Z_L        0x1A

#define ADXL373_OFFSET_X            0x20
#define ADXL373_OFFSET_Y            0x21
#define ADXL373_OFFSET_Z            0x22

#define ADXL373_THRESH_ACT_X_L      0x24
#define ADXL373_THRESH_ACT_X_H      0x23
#define ADXL373_THRESH_ACT_Y_L      0x26
#define ADXL373_THRESH_ACT_Y_H      0x25
#define ADXL373_THRESH_ACT_Z_L      0x28
#define ADXL373_THRESH_ACT_Z_H      0x27
#define ADXL373_TIME_ACT            0x29

#define ADXL373_THRESH_INACT_X_L    0x2B
#define ADXL373_THRESH_INACT_X_H    0x2A
#define ADXL373_THRESH_INACT_Y_L    0x2D
#define ADXL373_THRESH_INACT_Y_H    0x2C
#define ADXL373_THRESH_INACT_Z_L    0x2F
#define ADXL373_THRESH_INACT_Z_H    0x2E
#define ADXL373_TIME_INACT_L        0x31
#define ADXL373_TIME_INACT_H        0x30
#define ADXL373_THRESH_ACT2_X_H     0x32
#define ADXL373_THRESH_ACT2_X_L     0x33
#define ADXL373_THRESH_ACT2_Y_H     0x34
#define ADXL373_THRESH_ACT2_Y_L     0x35
#define ADXL373_THRESH_ACT2_Z_H     0x36
#define ADXL373_THRESH_ACT2_Z_L     0x37

// Filter and FIFO Control
#define ADXL373_HPF                 0x38
#define ADXL373_FIFO_SAMPLES        0x39
#define ADXL373_FIFO_CTL            0x3A

// Interrupt Mapping
#define ADXL373_INT_MAP1            0x3B
#define ADXL373_INT_MAP2            0x3C

// Timing and Measurement Control
#define ADXL373_TIMING              0x3D
#define ADXL373_MEASURE             0x3E
#define ADXL373_POWER_CTL           0x3F
#define ADXL373_SELF_TEST           0x40
#define ADXL373_RESET               0x41
#define ADXL373_FIFO_DATA           0x42

#endif // ADXL373_H