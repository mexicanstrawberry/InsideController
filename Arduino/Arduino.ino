#include <DHT.h>
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftPWM.h>

#define Fan_1_Pin       2 /* Pin  4 SOFT */
#define Fan_2_Pin       3 /* Pin  5 PWM  */
#define Fan_3_Pin       4 /* Pin  6 SOFT */
#define Light_1_Pin     5 /* Pin 11 PWM  */
#define Light_2_Pin     6 /* Pin 12 PWM  */
#define Light_3_Pin     9 /* Pin 15 PWM  */
#define Dallas_Pin      7 /* Pin 13      */
#define DHT_Pin         8 /* Pin 14      */

#define TEMPERATURE_PRECISION  9

DHT dht(DHT_Pin, DHT22);

OneWire oneWire(Dallas_Pin);
DallasTemperature sensors(&oneWire);

DeviceAddress Temp_1, Temp_2, Temp_3;

void test(){
  SoftPWMSet (Fan_1_Pin, 100);
  analogWrite(Fan_2_Pin, 100);
  SoftPWMSet (Fan_3_Pin, 100);
  analogWrite(Light_1_Pin, 100);
  analogWrite(Light_2_Pin, 100);
  analogWrite(Light_3_Pin, 100);
}

void setup() {
  SPI.begin();
  dht.begin();
  SoftPWMBegin();
  test();
}

void loop() {
  float h = dht.readHumidity();
}
