
// turn LED ON and OFF using switch
// we read the state of the switch through pin 7
// switch is connected between pin 7 and GND
// we use the microcontroller's internal 20k pullup resistor
// why do we use a pullup resistor? read here: https://learn.sparkfun.com/tutorials/pull-up-resistors
// you can choose between LED ON or LED OFF when switch is pressed
// pin 8 will source current to the LED
// refer to source_current.ino file to see how to connect the LED
// code executed on Arduino Leonardo

void setup(){
  pinMode(7, INPUT_PULLUP); // internal 20k pullup resistor
  pinMode(8, OUTPUT);
}

void loop(){
  digitalWrite(8, !digitalRead(7)); // when switch is pressed LED turns ON
  // digitalWrite(8, digitalRead(7)); // when switch is pressed LED turns OFF
}
