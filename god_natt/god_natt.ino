#include <math.h>

const int photoPin = 0;
const int ledPin = 11;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int voltage = analogRead(photoPin);
  int range = map(voltage,0,1023,0,100);
  float breath = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
  Serial.println(range);
    
  if(range < 50){
    analogWrite(ledPin,breath);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}

  
  
