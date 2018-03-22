
// turn LED ON and OFF with a short delay between states
// pin 7 will source current to the LED
// refer to source_current.ino file to see how you make the connections
// code executed on Arduino Leonardo

void setup(){
  pinMode(7, OUTPUT);
}

void loop(){
  digitalWrite(7, HIGH);  // LED turns ON
  delay(500); // time given in ms where 500 ms is 0.5 s
  digitalWrite(7, LOW); // LED turns OFF
  delay(500);
}
