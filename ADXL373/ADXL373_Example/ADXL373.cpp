/* ADXL373.cpp
   Implementation for ADXL373 SPI library
*/

#include "ADXL373.h"

// SPI read/write bit masks per datasheet: bit7 = read, bit6 = MB (multi-byte)
static const uint8_t SPI_READ_BIT = 0x80;
static const uint8_t SPI_MB_BIT   = 0x40;

ADXL373::ADXL373(SPIClass &spi, int csPin, uint32_t spiClockHz, uint8_t spiMode)
  : _spi(&spi), _csPin(csPin), _spiSettings(spiClockHz, MSBFIRST, spiMode)
{
  pinMode(_csPin, OUTPUT);
  csDeselect();
}

void ADXL373::csSelect() {
  digitalWrite(_csPin, LOW);
}

void ADXL373::csDeselect() {
  digitalWrite(_csPin, HIGH);
}

void ADXL373::setSpiSettings(uint32_t spiClockHz, uint8_t spiMode) {
  _spiSettings = SPISettings(spiClockHz, MSBFIRST, spiMode);
}

// Begin: init SPI and check device IDs
bool ADXL373::begin() {
  _spi->begin();
  // small delay to let device power up
  delay(5);

  // Check device registers
  uint8_t devid = deviceID();   // PARTID
  uint8_t mems  = memsID();     // MEMS ID
  uint8_t adid  = analogDevicesID(); // Analog Devices ID, optional

  // PART ID expected per datasheet: (value in datasheet TABLE)
  // We'll accept common expected values; if mismatched still allow user override.
  // For robust check, verify PARTID != 0x00 and MEMS ID != 0x00
  if (devid == 0x00 || mems == 0x00) {
    // not responding properly
    // but still allow user to continue if they want
    return false;
  }

  // Put device in standby (clear measure), then configure defaults
  setMeasurementEnabled(false);
  // Default: ODR = mid (user may change)
  setODR(0x03);
  setLowNoiseMode(false);
  setFilterFastSettle(false);

  // Clear FIFO and set standby
  writeRegister(ADXL373_REG_FIFO_CTL, 0x00);

  // Leave in measurement mode by default
  setMeasurementEnabled(true);
  delay(2);

  return true;
}

/* Low-level SPI register access */
uint8_t ADXL373::readRegister(uint8_t reg) {
  uint8_t val = 0;
  _spi->beginTransaction(_spiSettings);
  csSelect();
  // single-byte read: set read bit only
  _spi->transfer(reg | SPI_READ_BIT);
  val = _spi->transfer(0x00);
  csDeselect();
  _spi->endTransaction();
  return val;
}

bool ADXL373::readRegisters(uint8_t reg, uint8_t *buf, size_t len) {
  if (len == 0) return true;
  _spi->beginTransaction(_spiSettings);
  csSelect();
  // multi-byte read: set read bit and MB bit
  _spi->transfer(reg | SPI_READ_BIT | SPI_MB_BIT);
  for (size_t i = 0; i < len; ++i) {
    buf[i] = _spi->transfer(0x00);
  }
  csDeselect();
  _spi->endTransaction();
  return true;
}

void ADXL373::writeRegister(uint8_t reg, uint8_t value) {
  _spi->beginTransaction(_spiSettings);
  csSelect();
  // write: ensure read bit clear (bit7=0) and MB clear for single write
  _spi->transfer(reg & 0x7F);
  _spi->transfer(value);
  csDeselect();
  _spi->endTransaction();
}

/* ID helpers */
uint8_t ADXL373::deviceID() {
  return readRegister(ADXL373_REG_PARTID);
}
uint8_t ADXL373::revisionID() {
  return readRegister(ADXL373_REG_REVID);
}
uint8_t ADXL373::analogDevicesID() {
  return readRegister(ADXL373_REG_DEVID);
}
uint8_t ADXL373::memsID() {
  return readRegister(ADXL373_REG_MEMS_ID);
}

/* Soft reset (write 0x52 to RESET register while in standby) */
bool ADXL373::softReset() {
  // Datasheet: device must be in standby to accept reset. Try to put in standby.
  setMeasurementEnabled(false);
  writeRegister(ADXL373_REG_RESET, ADXL373_RESET_SOFT);
  delay(2);
  return true;
}

/* Measurement control */
void ADXL373::setMeasurementEnabled(bool on) {
  uint8_t p = readRegister(ADXL373_REG_POWER_CTL);
  if (on) p |= ADXL373_POWER_CTL_MEASURE;
  else    p &= ~ADXL373_POWER_CTL_MEASURE;
  writeRegister(ADXL373_REG_POWER_CTL, p);
}

void ADXL373::setLowNoiseMode(bool on) {
  uint8_t m = readRegister(ADXL373_REG_MEASURE_CTL);
  if (on) m |= ADXL373_MEASURE_CTL_LN_BIT;
  else    m &= ~ADXL373_MEASURE_CTL_LN_BIT;
  writeRegister(ADXL373_REG_MEASURE_CTL, m);
}

void ADXL373::setFilterFastSettle(bool on) {
  uint8_t m = readRegister(ADXL373_REG_MEASURE_CTL);
  if (on) m |= ADXL373_MEASURE_CTL_FILTER_SETTLE;
  else    m &= ~ADXL373_MEASURE_CTL_FILTER_SETTLE;
  writeRegister(ADXL373_REG_MEASURE_CTL, m);
}

void ADXL373::setODR(uint8_t odr_bits) {
  odr_bits &= ADXL373_MEASURE_CTL_ODR_MASK;
  uint8_t m = readRegister(ADXL373_REG_MEASURE_CTL);
  m = (m & ~ADXL373_MEASURE_CTL_ODR_MASK) | odr_bits;
  writeRegister(ADXL373_REG_MEASURE_CTL, m);
}

/* Read RAW accel (12-bit left aligned in MSB/LSB) */
uint16_t ADXL373::read16FromRegs(uint8_t msbReg) {
  uint8_t buf[2];
  readRegisters(msbReg, buf, 2);
  uint16_t val = ((uint16_t)buf[0] << 8) | buf[1];
  return val;
}

int16_t ADXL373::signExtend12(int16_t val12) {
  // val12 contains bits [11:0] in lower 12 bits
  if (val12 & 0x800) { // negative
    val12 |= 0xF000;   // set upper bits
  } else {
    val12 &= 0x0FFF;
  }
  return val12;
}

bool ADXL373::readRaw(int16_t &x, int16_t &y, int16_t &z) {
  uint8_t buf[6];
  if (!readRegisters(ADXL373_REG_XDATA_H, buf, 6)) return false;
  int16_t xr = ((int16_t)buf[0] << 8) | buf[1];
  int16_t yr = ((int16_t)buf[2] << 8) | buf[3];
  int16_t zr = ((int16_t)buf[4] << 8) | buf[5];
  // per datasheet, data is 12-bit left aligned: shift right 4 to get 12-bit value
  xr = xr >> 4;
  yr = yr >> 4;
  zr = zr >> 4;
  x = signExtend12(xr);
  y = signExtend12(yr);
  z = signExtend12(zr);
  return true;
}

/*bool ADXL373::readG(float &xg, float &yg, float &zg, float scale_mg_per_lsb) {
  int16_t xr, yr, zr;
  if (!readRaw(xr, yr, zr)) return false;
  // convert to g: LSB unit = 200 mg (0.200 g), user can override scale_mg_per_lsb param
  float scale_g = scale_mg_per_lsb / 1000.0f;
  xg = xr * scale_g;
  yg = yr * scale_g;
  zg = zr * scale_g;
  return true;
}

/* Offset trims */
void ADXL373::setOffsetTrim(int8_t x_off, int8_t y_off, int8_t z_off) {
  writeRegister(ADXL373_REG_OFF_X, (uint8_t)x_off);
  writeRegister(ADXL373_REG_OFF_Y, (uint8_t)y_off);
  writeRegister(ADXL373_REG_OFF_Z, (uint8_t)z_off);
}

void ADXL373::getOffsetTrim(int8_t &x_off, int8_t &y_off, int8_t &z_off) {
  x_off = (int8_t)readRegister(ADXL373_REG_OFF_X);
  y_off = (int8_t)readRegister(ADXL373_REG_OFF_Y);
  z_off = (int8_t)readRegister(ADXL373_REG_OFF_Z);
}

/* FIFO helpers */
uint8_t ADXL373::fifoSamples() {
  return readRegister(ADXL373_REG_FIFO_SAMPLES);
}

void ADXL373::fifoEnable(bool en) {
  uint8_t ctl = readRegister(ADXL373_REG_FIFO_CTL);
  if (en) ctl |= 0x01;
  else    ctl &= ~0x01;
  writeRegister(ADXL373_REG_FIFO_CTL, ctl);
}

void ADXL373::fifoControl(uint8_t mode, uint8_t watermark) {
  // mode: per datasheet bits in FIFO_CTL; watermark = FIFO watermark value
  // Here we'll write a simple scheme: bits [1:0] for mode, [7:0] watermark in FIFO_SAMPLES or FIFO_CTL depending on datasheet
  writeRegister(ADXL373_REG_FIFO_CTL, mode & 0x03);
  writeRegister(ADXL373_REG_FIFO_SAMPLES, watermark);
}

bool ADXL373::readFIFOSamples(uint8_t *buf, size_t bytesToRead) {
  // FIFO_ACCESS register offers streaming out bytes
  // Read using multibyte read from FIFO_ACCESS
  return readRegisters(ADXL373_REG_FIFO_ACCESS, buf, bytesToRead);
}

/* Interrupt mapping & misc */
void ADXL373::mapInterrupts(uint8_t intMap1, uint8_t intMap2) {
  writeRegister(ADXL373_REG_INT_MAP1, intMap1);
  writeRegister(ADXL373_REG_INT_MAP2, intMap2);
}

void ADXL373::enableIntPinPullups(bool enable) {
  // some devices have internal pullup enable; if present, map to ext timing or other registers. We'll leave as placeholder.
  (void)enable;
}

/* Activity / inactivity helpers (simple wrappers) */
void ADXL373::setActivityThreshold(uint16_t mg_threshold) {
  // Datasheet gives mapping from threshold mg to register value; user should convert
  // For now, write LSB/MSB to X-axis activity threshold registers as example
  uint16_t regVal = mg_threshold; // user conversion required
  writeRegister(ADXL373_REG_THRESH_ACT_X_L, (uint8_t)(regVal & 0xFF));
  writeRegister(ADXL373_REG_THRESH_ACT_X_H, (uint8_t)((regVal >> 8) & 0xFF));
}
void ADXL373::setInactivityThreshold(uint16_t mg_threshold) {
  uint16_t regVal = mg_threshold;
  writeRegister(ADXL373_REG_THRESH_INACT_X_L, (uint8_t)(regVal & 0xFF));
  writeRegister(ADXL373_REG_THRESH_INACT_X_H, (uint8_t)((regVal >> 8) & 0xFF));
}
void ADXL373::setActivityTime(uint16_t ms) {
  // Datasheet defines TIME_ACT register scaling; here we just write raw ms LSB for user to map
  writeRegister(ADXL373_REG_TIME_ACT, (uint8_t)(ms & 0xFF));
}

void ADXL373::readG(float &x, float &y, float &z) {
    int16_t xRaw, yRaw, zRaw;

    // Read raw acceleration data from sensor registers
    xRaw = ((int16_t)readRegister(ADXL373_REG_XDATA_H) << 8) | readRegister(ADXL373_REG_XDATA_L);
    yRaw = ((int16_t)readRegister(ADXL373_REG_YDATA_H) << 8) | readRegister(ADXL373_REG_YDATA_L);
    zRaw = ((int16_t)readRegister(ADXL373_REG_ZDATA_H) << 8) | readRegister(ADXL373_REG_ZDATA_L);

    // Convert raw readings to g's using sensitivity (0.1 g/LSB typical for ADXL373)
    const float scale = 0.1;  // g per LSB
    x = (float)xRaw * scale;
    y = (float)yRaw * scale;
    z = (float)zRaw * scale;
}

/* Self-test */
void ADXL373::selfTestEnable(bool on) {
  uint8_t s = readRegister(ADXL373_REG_SELF_TEST);
  if (on) s |= 0x01;
  else    s &= ~0x01;
  writeRegister(ADXL373_REG_SELF_TEST, s);
}