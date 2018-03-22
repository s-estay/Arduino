
// sink current through a LED to digital pin 7
// connection: VCC - LED's anode .. LED's cathode - 1k resistor - pin7 set to low
// VCC is 5V
// LED's anode (+) long terminal
// LED's cathode (-) short terminal
// 1k resistor color code: brown black red
// code executed on Arduino Leonardo

void setup(){
  pinMode(7, OUTPUT);
}

void loop(){
  digitalWrite(7, LOW);
}

