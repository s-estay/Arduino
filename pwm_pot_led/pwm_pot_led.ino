
// PWM signal through pin 3
// what's a PWM signal? read here: https://en.wikipedia.org/wiki/Pulse-width_modulation
// 8 bits PWM: 0 (0% or GND) to 255 (100% or VCC)
// PWM signal is controlled by a potentiometer connected to pin A2
// the potentiometer have 3 leads: 1 (or 3) connects to GND, 2 to A2 and 3 (or 1) to VCC
// the potentiometer input signal is an analog signal
// the microcontroller converts this analog signal into digital using a 10 bits ADC
// ADC: analog to digital converter
// a 10 bits ADC signal ranges between 0 - 1023
// the ADC signal is equivalent to the input analog voltage where 0 is GND and 1023 is VCC (5V)
// the PWM signal is also equivalent to a voltage where 0 is GND and 255 is VCC (5V)
// the relation between ADC and PWM signals is given by PWM = ADC/4
// pin 3 will source current to the LED
// refer to source_current.ino file to see how to connect the LED
// code executed on Arduino Leonardo

void setup(){
  pinMode(3, OUTPUT); // observe that only pins preceded by ~ in the board can output a PWM signal
  pinMode(A2, INPUT); // A2: analog input 2
}

void loop(){
  analogWrite(3, analogRead(A2)/4);
}
