#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "MS_Commands.h"

#define Fan_1_Pin       2 /* Pin  4 SOFT */
#define Fan_2_Pin       3 /* Pin  5 PWM  */
#define Fan_3_Pin       4 /* Pin  6 SOFT */
#define Light_1_Pin     5 /* Pin 11 PWM  */
#define Light_2_Pin     6 /* Pin 12 PWM  */
#define Light_3_Pin     9 /* Pin 15 PWM  */
#define Dallas_Pin      7 /* Pin 13      */
#define DHT_Pin         8 /* Pin 14      */

#define MISO_PIN_OUTPUT         DDRB  |=  (1 << DDB4  )
#define MISO_PIN_INPUT          DDRB  &= ~(1 << DDB4  )
#define MISO_PIN_LOW_IMPEDANCE  PORTB &= ~(1 << PORTB4)

#define TEMPERATURE_PRECISION  9

#define FIRMWARE_MAJOR        0x23
#define FIRMWARE_MINOR        0x42
#define FIRMWARE_BUILDVERSION 0x69

DHT               dht(DHT_Pin, DHT22);
OneWire           oneWire(Dallas_Pin);
DallasTemperature sensors(&oneWire);

DeviceAddress Temp_1, Temp_2, Temp_3;

uint8_t commandIndex = 0;
uint8_t command      = 0x00;
uint8_t subCommand   = 0x00;
uint8_t size         = 0;

// start of transaction, no command yet
void spi_change(){
    if (digitalRead(SS)){
      MISO_PIN_INPUT;
      _NOP();
      commandIndex = 0;
    }else{
      MISO_PIN_OUTPUT;
      _NOP();
    }
}

void SPISlaveInit(void) {
  
  // Initialize SPI pins.
  pinMode(SCK,  INPUT);
  pinMode(MOSI, INPUT); // We keep it as input to be high impedance when not active
  MISO_PIN_LOW_IMPEDANCE;
  MISO_PIN_INPUT;
  
  // Enable SPI as slave.
  SPCR=(1<<SPE)|(1<<SPIE); 
  SPDR=0;

  // interrupt for SS
  pinMode(2, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(2), spi_change, CHANGE);
  
  sei();
}

ISR (SPI_STC_vect){
  uint8_t c = SPDR;  // grab byte from SPI Data Register
  switch(commandIndex){
    case WAIT_FOR_COMMAND:
      command = c;
      SPDR = 0xFF;
      break;
    case WAIT_FOR_SUBCOMMAND:
      subCommand = c;
      SPDR = 0xFF;
      break;
    case WAIT_FOR_SIZE:
      size = c;
      SPDR = 0xFF;
      break;
    default:
      switch(command){
        case CMD_NETWORK:
          switch(subCommand){
            case SUB_CMD_NETWORK_PING:
              SPDR = c; // Always replay
              break;
          }
          break;
        case CMD_FIRMWARE:
          switch(subCommand){
            case SUB_CMD_FIRMWARE_GET_FIRMWARE_VERSION:
              switch(commandIndex){
                case 3:
                  SPDR = FIRMWARE_MAJOR;
                  break;
                case 4:
                  SPDR = FIRMWARE_MINOR;
                  break;
                case 5:
                  SPDR = FIRMWARE_BUILDVERSION;
                  break;
                default:
                  SPDR = 0xFF;
                  break;
              }
              break;
            case SUB_CMD_FIRMWARE_GET_UPTIME:
              break;
            case SUB_CMD_FIRMWARE_SET_REBOOT:
              break;
            default:
              SPDR = 0xFF;
              break;
          }
          break;
        case CMD_SENSOR:
          break;
        case CMD_MOTOR:
          break;
        case CMD_LIGHT:
          break;
        case CMD_HEATER:
          break;
        default:
          SPDR = 0xFF;
          break;
      }
      break;
  }


  commandIndex++;
}

void setup() {
  dht.begin();
  SPISlaveInit();
}

void loop() {
  float h = dht.readHumidity();
}


