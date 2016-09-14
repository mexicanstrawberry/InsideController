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
  DataStorage.temperature_outside             = 0;
  DataStorage.temperature_inside              = 0;
  DataStorage.temperature_water               = 0;
  DataStorage.temperature_light1              = 0;
  DataStorage.temperature_light2              = 0;
  DataStorage.temperature_light3              = 0;
  DataStorage.humidity_outside                = 0;
  DataStorage.humidity_inside                 = 0;
  DataStorage.co2                             = 0;
  DataStorage.ph                              = 0;
  DataStorage.redox                           = 0;

  DataStorage.light_speed                     = 50;
  DataStorage.light_position                  = 0;
  DataStorage.light_counter                   = 0;
  DataStorage.light_fan_1_speed               = 0;
  DataStorage.light_fan_1_desired_temperature = 42;
  DataStorage.light_fan_2_speed               = 0;
  DataStorage.light_fan_2_desired_temperature = 42;
  DataStorage.light_fan_3_speed               = 0;
  DataStorage.light_fan_3_desired_temperature = 42;
  DataStorage.hatch                           = 0;
  DataStorage.outside_fan                     = 0;
  DataStorage.inside_fan                      = 0;

  DataStorage.ir                              = 0;
  DataStorage.fs                              = 0;
  DataStorage.uv                              = 0;
    
  DataStorage.heater_air                      = 0;
  DataStorage.heater_water                    = 0;
}

void setup() {
  setDefaults();
  dht.begin();
  sensors.begin();
  SPISlaveInit();
}

void loop() {
  float h = dht.readHumidity();
  sensors.requestTemperatures();
}

