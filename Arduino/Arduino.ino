#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "MS_Commands.h"
#include "SPI.h"
#include "Arduino.h"
#include "Pin.h"

DHT               dht(DHT_Pin, DHT22);
OneWire           oneWire(Dallas_Pin);
DallasTemperature sensors(&oneWire);

DeviceAddress Temp_1, Temp_2, Temp_3;
Data_s        DataStorage;

void setDefaults(){
  DataStorage.temperature_outside             = 3.14;
  DataStorage.temperature_inside              = 3.15;
  DataStorage.temperature_water               = 3.16;
  DataStorage.temperature_light1              = 3.17;
  DataStorage.temperature_light2              = 3.18;
  DataStorage.temperature_light3              = 3.19;
  DataStorage.humidity_outside                = 3.20;
  DataStorage.humidity_inside                 = 3.21;
  DataStorage.co2                             = 314;
  DataStorage.ph                              = 3.22;
  DataStorage.redox                           = 3141;

  DataStorage.light_speed                     = 50;
  DataStorage.light_position                  = 425;
  DataStorage.light_counter                   = 2323;
  DataStorage.light_fan_1_speed               = 51;
  DataStorage.light_fan_1_desired_temperature = 52;
  DataStorage.light_fan_2_speed               = 53;
  DataStorage.light_fan_2_desired_temperature = 54;
  DataStorage.light_fan_3_speed               = 55;
  DataStorage.light_fan_3_desired_temperature = 56;
  DataStorage.hatch                           = 57;
  DataStorage.outside_fan                     = 58;
  DataStorage.inside_fan                      = 59;

  DataStorage.ir                              = 60;
  DataStorage.fs                              = 61;
  DataStorage.uv                              = 62;
    
  DataStorage.heater_air                      = 63;
  DataStorage.heater_water                    = 64;
}

void setup() {
  setDefaults();
  dht.begin();
  sensors.begin();
  SPISlaveInit();
}

void loop() {
  //float h = dht.readHumidity();
  //sensors.requestTemperatures();
}

