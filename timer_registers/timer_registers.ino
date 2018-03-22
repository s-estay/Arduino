
const byte ps_1 = (1 << CS10);
const byte ps_8 = (1 << CS11);
const byte ps_64 = (1 << CS11) | (1 << CS10);
const byte ps_256 = (1 << CS12);
const byte ps_1024 = (1 << CS12) | (1 << CS10);

void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  TCCR1A &= ~B00000011; // reset bits WGM11, WGM10
  TCCR1B &= ~B00011111; // reset bits WGM13, WGM12, CS12, CS11, CS10
  TCNT1 = 3035; // set initial timer value
  TCCR1B |= ps_64; // pre-scaler clock/1
  TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
}

void loop(){
  //Serial.println(TCCR1B,BIN);
  //while ((TIFR1 & (1 << TOV1)) > 0){ } // wait for the overflow event
  //TIFR1 &= ~(1 << TOV1); // reset the overflow flag
}

ISR(TIMER1_OVF_vect){ // TC1 Overflow Interrupt Vector
  digitalWrite(13, !digitalRead(13));
  Serial.println(millis());
  TCNT1 = 3035; // reset initial timer value
}
