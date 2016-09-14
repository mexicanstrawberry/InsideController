#define MISO_PIN_OUTPUT         DDRB  |=  (1 << DDB4  )
#define MISO_PIN_INPUT          DDRB  &= ~(1 << DDB4  )
#define MISO_PIN_LOW_IMPEDANCE  PORTB &= ~(1 << PORTB4)

