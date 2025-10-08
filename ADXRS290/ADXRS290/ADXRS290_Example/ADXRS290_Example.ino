#include <Arduino.h>
#include <SPI.h>
#include <ADXRS290.h>

#define ADXRS290_CS   6   // <-- Change this to your actual chip select pin
#define ADXRS290_EINT 9    // <-- Change this if you use an interrupt pin

SPIClass SPI1;

volatile uint32_t i = 0;
float x, y, z;
float temp;

bool led = false;
//#define TRIGGER_LED  digitalWrite(PIN_LED, led ? 225 : 0); \
                     led =!led

void setup(void) {
  Serial.begin(115200);

  SPI1.begin(41, 45, 46, 6);
  adiGyroscope.begin(ADXRS290_CS, &SPI1, ADXRS290_EINT);

  //pinMode(PIN_LED, OUTPUT);
  //digitalWrite(PIN_LED, HIGH);

  // Waiting for the console to continue
  while (!Serial) {
    ;
  }

  adiGyroscope.tempSensorEnable(true);
}



void loop(void) {
  if (!(i % 5)) {
    //       TRIGGER_LED;

    adiGyroscope.setMeasurementMode();

    adiGyroscope.readXY(&x, &y);
    Serial.print("\tX / Y =  ");
    Serial.print(x);
    Serial.print(" / ");
    Serial.print(y);
    Serial.print("  deg/s");

    if (!(i % 100)) {
      temp = adiGyroscope.readTemperature();
      Serial.print("\tTemperature = ");
      Serial.println(temp);
    } else {
      Serial.print("\n");
    }
    adiGyroscope.setStandbyMode();
  }
  ++i;
  delay(100);
}
