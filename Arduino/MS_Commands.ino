#include <avr/wdt.h>

#define WAIT_FOR_COMMAND     0
#define WAIT_FOR_SUBCOMMAND  1
#define WAIT_FOR_SIZE        2
#define WAIT_FOR_DATA        3

#define MILLIS    1
#define SECOND 1000 * MILLIS
#define MINUTE   60 * SECOND
#define HOUR     60 * MINUTE
#define DAY      24 * HOUR

uint8_t       commandIndex = 0;
uint8_t       command      = 0x00;
uint8_t       subCommand   = 0x00;
uint8_t       size         = 0;
bool          reboot       = false;
float         temp_f       = 0.0;
uint8_t       temp_i       = 0;
uint16_t      temp_ii      = 0;
uint32_t      temp_iii     = 0;

uint8_t processMessage(uint8_t c){  
  switch(commandIndex){
    case WAIT_FOR_COMMAND:
      command = c;
      return 0xFF;
    case WAIT_FOR_SUBCOMMAND:
      subCommand = c;
      return 0xFF;
    case WAIT_FOR_SIZE:
      size = c;
      return 0xFF;
    default:
      switch(command){
        case CMD_NETWORK:
          switch(subCommand){
            case SUB_CMD_NETWORK_PING:
              return c; // Always resend the data
            default:
              return 0xFF;
          }
        case CMD_FIRMWARE:
          switch(subCommand){
            case SUB_CMD_FIRMWARE_GET_CONTROLLER_TYPE:
              switch(commandIndex){
                case 3:
                  return CONTROLLER_TYPE;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_FIRMWARE_GET_FIRMWARE_VERSION:
              switch(commandIndex){
                case 3:
                  return FIRMWARE_MAJOR;
                case 4:
                  return FIRMWARE_MINOR;
                case 5:
                  return FIRMWARE_BUILDVERSION;
                default:
                  return 0xFF;
              }
            case SUB_CMD_FIRMWARE_GET_UPTIME:
              switch (commandIndex){
                case 3:
                  temp_iii = millis();
                  //days
                  return (int)(temp_iii / DAY);
                case 4:
                  // hours
                  return ((temp_iii % DAY) / HOUR);
                case 5:
                  // minutes
                  return ((temp_iii % HOUR) / MINUTE);
                case 6:
                  // seconds
                  return ((temp_iii % MINUTE) / SECOND);
                default:
                  return 0xFF;
              }
            case SUB_CMD_FIRMWARE_SET_REBOOT:
              switch (commandIndex){
                case 3:
                  reboot = (c == 'M');
                  return 0xFF;
                case 4:
                  if (reboot && c == 'S'){
                    wdt_enable(WDTO_250MS);
                  }
                  return 0xFF;
                default:
                  return 0xFF;
              }
            default:
              return 0xFF;
          }
        case CMD_SENSOR:
          switch(subCommand){
             case SUB_CMD_SENSOR_GET_TEMPERATURE_OUTSIDE:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_outside;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }
             case SUB_CMD_SENSOR_GET_TEMPERATURE_INSIDE:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_inside;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }                
             case SUB_CMD_SENSOR_GET_TEMPERATURE_WATER:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_water;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }
             case SUB_CMD_SENSOR_GET_TEMPERATURE_LIGHT1:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_light1;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }
             case SUB_CMD_SENSOR_GET_TEMPERATURE_LIGHT2:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_light2;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }
             case SUB_CMD_SENSOR_GET_TEMPERATURE_LIGHT3:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.temperature_light3;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }             
             case SUB_CMD_SENSOR_GET_HUMIDITY_OUTSIDE:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.humidity_outside;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }             
             case SUB_CMD_SENSOR_GET_HUMIDITY_INSIDE:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.humidity_inside;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }             
             case SUB_CMD_SENSOR_GET_CO2:
                switch (commandIndex){
                  case 3:
                    temp_ii = DataStorage.co2;
                    return (temp_ii >> 8);
                  case 4:
                    return temp_ii & 0xFF;
                  default:
                    return 0xFF;
                }             
             case SUB_CMD_SENSOR_GET_PH:
                switch (commandIndex){
                  case 3:
                    temp_f = DataStorage.ph;
                    return (int)temp_f;
                  case 4:
                    temp_i = 0;//(int)temp;
                    return (int) ( (temp_f - temp_i) * 100.0);
                  default:
                    return 0xFF;
                }             
             case SUB_CMD_SENSOR_GET_REDOX:
                switch (commandIndex){
                  case 3:
                    temp_ii = DataStorage.redox;
                    return (temp_ii >> 8);
                  case 4:
                    return temp_ii & 0xFF;
                  default:
                    return 0xFF;
                }             
             default:
                return 0xFF;
          }
        case CMD_MOTOR:
          switch(subCommand){
            case SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_SPEED:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_speed;
                default:
                  return 0xFF;
              }
            case SUB_CMD_MOTOR_SET_LIGHT_MOVEMENT_SPEED:
              switch(commandIndex){
                case 3:
                  DataStorage.light_speed = c;
                  return 0xFF;
                default:
                  return 0xFF;
              }
            case SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_POSITION:
              switch (commandIndex){
                case 3:
                  temp_ii = DataStorage.light_position;
                  return (temp_ii >> 8);
                case 4:
                  return temp_ii & 0xFF;
                default:
                  return 0xFF;
              }             
            case SUB_CMD_MOTOR_SET_LIGHT_MOVEMENT_POSITION:
              switch (commandIndex){
                case 3:
                  DataStorage.light_position = (c << 8);
                  return 0xFF;
                case 4:
                  DataStorage.light_position += c;
                  return 0xFF;
                default:
                  return 0xFF;
              }                         
            case SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_COUNTER:
              switch (commandIndex){
                case 3:
                  temp_ii = DataStorage.light_counter;
                  return (temp_ii >> 8);
                case 4:
                  return temp_ii & 0xFF;
                default:
                  return 0xFF;
              }                         
            case SUB_CMD_MOTOR_GET_LIGHT_1_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_1_speed;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_1_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_1_speed = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_LIGHT_1_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_1_desired_temperature;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_1_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_1_desired_temperature = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_LIGHT_2_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_2_speed;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_2_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_2_speed = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_LIGHT_2_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_2_desired_temperature;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_2_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_2_desired_temperature = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_LIGHT_3_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_3_speed;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_3_FAN_SPEED:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_3_speed = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_LIGHT_3_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  return DataStorage.light_fan_3_desired_temperature;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_LIGHT_3_DESIRED_TEMPERATURE:
              switch(commandIndex){
                case 3:
                  DataStorage.light_fan_3_desired_temperature = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_HATCH:
              switch(commandIndex){
                case 3:
                  return DataStorage.hatch;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_HATCH:
              switch(commandIndex){
                case 3:
                  DataStorage.hatch = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_OUTSIDE_FAN:
              switch(commandIndex){
                case 3:
                  return DataStorage.outside_fan;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_OUTSIDE_FAN:
              switch(commandIndex){
                case 3:
                  DataStorage.outside_fan = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_GET_INSIDE_FAN:
              switch(commandIndex){
                case 3:
                  return DataStorage.inside_fan;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_MOTOR_SET_INSIDE_FAN:
              switch(commandIndex){
                case 3:
                  DataStorage.inside_fan = c;
                default:
                  return 0xFF;
              }            
            default:
              return 0xFF;
          }
        case CMD_LIGHT:
          switch(subCommand){
            case SUB_CMD_LIGHT_GET_INTENSITY_IR:
              switch(commandIndex){
                case 3:
                  return DataStorage.ir;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_LIGHT_SET_INTENSITY_IR:
              switch(commandIndex){
                case 3:
                  DataStorage.ir = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_LIGHT_GET_INTENSITY_FS:
              switch(commandIndex){
                case 3:
                  return DataStorage.fs;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_LIGHT_SET_INTENSITY_FS:
              switch(commandIndex){
                case 3:
                  DataStorage.fs = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_LIGHT_GET_INTENSITY_UV:
              switch(commandIndex){
                case 3:
                  return DataStorage.uv;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_LIGHT_SET_INTENSITY_UV:
              switch(commandIndex){
                case 3:
                  DataStorage.uv = c;
                default:
                  return 0xFF;
              }            
            default:
              return 0xFF;
          }
        case CMD_HEATER:
          switch(subCommand){
            case SUB_CMD_HEATER_GET_HEATER_AIR:
              switch(commandIndex){
                case 3:
                  return DataStorage.heater_air;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_HEATER_SET_HEATER_AIR:
              switch(commandIndex){
                case 3:
                  DataStorage.heater_air = c;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_HEATER_GET_HEATER_WATER:
              switch(commandIndex){
                case 3:
                  return DataStorage.heater_water;
                default:
                  return 0xFF;
              }            
            case SUB_CMD_HEATER_SET_HEATER_WATER:
              switch(commandIndex){
                case 3:
                  DataStorage.heater_water = c;
                default:
                  return 0xFF;
              }            
            default:
              return 0xFF;
          }
        default:
          return 0xFF;
      }
  }
}
