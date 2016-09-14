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
  uint8_t c = SPDR;
  SPDR = processMessage(c);
  commandIndex++;
}

