 
const int pwm_g = 10;
const int pwm_b = 11;
const int nL = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte a = B00000001;
int counter = 0;
int g = 0;
int b = 255;

void setup(){
  for(int i = 0; i < nL; ++i){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  demo1();
}

void demo1(){
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

  delay(100);

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
