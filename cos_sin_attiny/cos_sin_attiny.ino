#include <math.h>

const int ledPin_0 = 0;
const int ledPin_1 = 1;

void setup(){
  pinMode(ledPin_0, OUTPUT);
  pinMode(ledPin_1, OUTPUT);
}

void loop(){
  float breath_sin = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
  float breath_cos = (exp(cos(millis()/2000.0*PI)) - 0.36787944)*108.0;
  analogWrite(ledPin_0,breath_sin);
  analogWrite(ledPin_1,breath_cos);
}

  
  
