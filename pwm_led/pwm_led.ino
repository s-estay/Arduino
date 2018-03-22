
// PWM signal through pin 3
// what's a PWM signal? read here: https://en.wikipedia.org/wiki/Pulse-width_modulation
// 8 bits PWM: 0 (0%) to 255 (100%)
// pin 3 will source current to the LED
// refer to source_current.ino file to see how to connect the LED
// code executed on Arduino Leonardo

void setup(){
  pinMode(3, OUTPUT); // observe that anly pins preceded by ~ in the board can output a PWM signal
}

void loop(){
  int i = 0;

  // this loop increments the PWM's output value from 0 to 255
  while(i < 256){
    analogWrite(3, i);
    delay(1); // delay of 1 ms
    i++;
  }
  
  // at this point i = 255

  // this loop decrements the PWM's output value from 255 to 0
  while(i > 0){
    analogWrite(3, i);
    delay(1);
    i--;
  }
}
