#define     CMD_NETWORK                               0x00
#define SUB_CMD_NETWORK_PING                          0x00

#define     CMD_FIRMWARE                              0x10
#define SUB_CMD_FIRMWARE_GET_FIRMWARE_VERSION         0x20
#define SUB_CMD_FIRMWARE_GET_UPTIME                   0x30
#define SUB_CMD_FIRMWARE_SET_REBOOT                   0x40

#define     CMD_SENSOR                                0x20
#define SUB_CMD_SENSOR_GET_TEMPERATURE_OUTSIDE        0x00
#define SUB_CMD_SENSOR_GET_TEMPERATURE_INSIDE         0x01
#define SUB_CMD_SENSOR_GET_TEMPERATURE_WATER          0x02
#define SUB_CMD_SENSOR_SET_TEMPERATURE_LIGHT1         0x03
#define SUB_CMD_SENSOR_GET_TEMPERATURE_LIGHT2         0x04
#define SUB_CMD_SENSOR_GET_TEMPERATURE_LIGHT3         0x05
#define SUB_CMD_SENSOR_GET_HUMIDITY_OUTSIDE           0x10
#define SUB_CMD_SENSOR_GET_HUMIDITY_INSIDE            0x11
#define SUB_CMD_SENSOR_GET_CO2                        0x20
#define SUB_CMD_SENSOR_GET_PH                         0x30
#define SUB_CMD_SENSOR_GET_REDOX                      0x40

#define     CMD_MOTOR                                 0x30
#define SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_SPEED        0x00
#define SUB_CMD_MOTOR_SET_LIGHT_MOVEMENT_SPEED        0x01
#define SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_POSITION     0x02
#define SUB_CMD_MOTOR_SET_LIGHT_MOVEMENT_POSITION     0x03
#define SUB_CMD_MOTOR_GET_LIGHT_MOVEMENT_COUNTER      0x04
#define SUB_CMD_MOTOR_GET_LIGHT_1_FAN_SPEED           0x10
#define SUB_CMD_MOTOR_SET_LIGHT_1_FAN_SPEED           0x11
#define SUB_CMD_MOTOR_GET_LIGHT_1_DESIRED_TEMPERATURE 0x12
#define SUB_CMD_MOTOR_SET_LIGHT_1_DESIRED_TEMPERATURE 0x13
#define SUB_CMD_MOTOR_GET_LIGHT_2_FAN_SPEED           0x20
#define SUB_CMD_MOTOR_SET_LIGHT_2_FAN_SPEED           0x21
#define SUB_CMD_MOTOR_GET_LIGHT_2_DESIRED_TEMPERATURE 0x22
#define SUB_CMD_MOTOR_SET_LIGHT_2_DESIRED_TEMPERATURE 0x23
#define SUB_CMD_MOTOR_GET_LIGHT_3_FAN_SPEED           0x30
#define SUB_CMD_MOTOR_SET_LIGHT_3_FAN_SPEED           0x31
#define SUB_CMD_MOTOR_GET_LIGHT_3_DESIRED_TEMPERATURE 0x32
#define SUB_CMD_MOTOR_SET_LIGHT_3_DESIRED_TEMPERATURE 0x33
#define SUB_CMD_MOTOR_GET_HATCH                       0x40
#define SUB_CMD_MOTOR_SET_HATCH                       0x41
#define SUB_CMD_MOTOR_GET_OUTSIDE_FAN                 0x50
#define SUB_CMD_MOTOR_SET_OUTSIDE_FAN                 0x51
#define SUB_CMD_MOTOR_GET_INSIDE_FAN                  0x60
#define SUB_CMD_MOTOR_SET_INSIDE_FAN                  0x61

#define     CMD_LIGHT                                 0x40
#define SUB_CMD_LIGHT_GET_INTENSITY_IR                0x00
#define SUB_CMD_LIGHT_SET_INTENSITY_IR                0x01
#define SUB_CMD_LIGHT_GET_INTENSITY_FS                0x10
#define SUB_CMD_LIGHT_SET_INTENSITY_FS                0x11
#define SUB_CMD_LIGHT_GET_INTENSITY_UV                0x20
#define SUB_CMD_LIGHT_SET_INTENSITY_UV                0x21

#define     CMD_HEATER                                0x50
#define SUB_CMD_HEATER_GET_HEATER_AIR                 0x00
#define SUB_CMD_HEATER_SET_HEATER_AIR                 0x01
#define SUB_CMD_HEATER_GET_HEATER_WATER               0x10
#define SUB_CMD_HEATER_SET_HEATER_WATER               0x11

