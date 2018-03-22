
// source current to a LED through digital pin 7
// connection: pin7 set to high - LED's anode .. LED's cathode - 1k resistor - GND
// LED's anode (+) long terminal
// LED's cathode (-) short terminal
// 1k resistor color code: brown black red
// code executed on Arduino Leonardo

void setup(){
  pinMode(7, OUTPUT);
}

void loop(){
  digitalWrite(7, HIGH);
}

