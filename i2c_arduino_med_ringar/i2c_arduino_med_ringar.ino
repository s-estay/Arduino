#include <Wire.h>

const int ledPin = 13; // onboard LED
static_assert(LOW == 0, "Expecting LOW to be 0");

const int pwm_g = 10;
const int pwm_b = 11;
const int nL = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte a = B00000001;
int counter = 0;
int g = 0;
int b = 255;
int flag = 0;
int c = 0;


void setup() {
  Wire.begin(0x09);                // join i2c bus with address #8
  //Serial.begin(9600);
  Wire.onReceive(receiveEvent); // register event
  pinMode(ledPin, OUTPUT);
    for(int i = 0; i < nL; ++i){
    pinMode(leds[i], OUTPUT);
  }
  digitalWrite(ledPin, LOW); // turn it off
}

void loop() {

  if (flag == 0){
    demo1(100);
  }
  else{
    demo1(20);
    c++;
  }

  if( flag == 1 && c == 100)
  {
    flag =0;
    c = 0;
  }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    int num = Wire.read(); // receive byte as a character
    //Serial.println(num);
    if (num == 1)
    {
      flag = 1;
      digitalWrite(ledPin, HIGH); // turn it off
    }
  }
}

void demo1(int del){
  analogWrite(pwm_g, g);
  analogWrite(pwm_b, b);

  byte a = bitSL();

  digitalWrite(2, bitRead(a, 7));
  digitalWrite(3, bitRead(a, 6));
  digitalWrite(4, bitRead(a, 5));
  digitalWrite(5, bitRead(a, 4));
  digitalWrite(6, bitRead(a, 3));
  digitalWrite(7, bitRead(a, 2));
  digitalWrite(8, bitRead(a, 1));
  digitalWrite(9, bitRead(a, 0));

  delay(del);

  g += 1;
  b -= 1; 
}

byte bitSL(){
  if(counter < 7){
    a = a << 1;
    counter++;
  }
  else{
    bitWrite(a, 0, 1);
    counter = 0; 
  }
  return a;
}
