#include <math.h>

const int photoPin = 3;
const int ledPin = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  int voltage = analogRead(photoPin);
  int range = map(voltage,0,1023,0,100);
  float breath = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
    
  if(range == 0){
    analogWrite(ledPin,breath);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}

  
  
