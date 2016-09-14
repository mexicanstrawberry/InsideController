#define TEMPERATURE_PRECISION  9

#define FIRMWARE_MAJOR        0x23
#define FIRMWARE_MINOR        0x42
#define FIRMWARE_BUILDVERSION 0x69

struct Data_s {
  float    temperature_outside;
  float    temperature_inside;
  float    temperature_water;
  float    temperature_light1;
  float    temperature_light2;
  float    temperature_light3;
  float    humidity_outside;
  float    humidity_inside;
  uint16_t co2;
  float    ph;
  uint16_t redox;

  uint8_t  light_speed;
  uint16_t light_position;
  uint16_t light_counter;
  uint8_t  light_fan_1_speed;
  uint8_t  light_fan_1_desired_temperature;
  uint8_t  light_fan_2_speed;
  uint8_t  light_fan_2_desired_temperature;
  uint8_t  light_fan_3_speed;
  uint8_t  light_fan_3_desired_temperature;
  uint8_t  hatch;
  uint8_t  outside_fan;
  uint8_t  inside_fan;

  uint8_t  ir;
  uint8_t  fs;
  uint8_t  uv;

  uint8_t heater_air;
  uint8_t heater_water;
};

