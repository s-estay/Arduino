
const int pwm_g = 10;
const int pwm_b = 11;
const int nL = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int decC = 0;
byte a = B00000001;
int counter = 0;
int g = 0;
int b = 255;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < nL; ++i){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  demo1();
}

void pt(int *p){
  *p = 5;
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

  g += 4;
  b -= 4; 
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

void demo2(){
  while(g < 256 && b > 0){
    g += 8;
    b -= 8;

    analogWrite(pwm_g, g);
    analogWrite(pwm_b, b);
  
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
  
    delay(50);
  }

  while(g > 0 && b < 256){
    g -= 8;
    b += 8;

    analogWrite(pwm_g, g);
    analogWrite(pwm_b, b);
  
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    digitalWrite(8, 1);
    digitalWrite(9, 1);
  
    delay(50);
  }
}

void seq(){
  while(g < 256 && b > 0){
    g += 16;
    b -= 16;
    Serial.print(g);
    Serial.print(" ");
    Serial.print(b);
    Serial.print("\n");
    delay(500);  
  }

  while(g > 0 && b < 256){
    g -= 16;
    b += 16;
    Serial.print(g);
    Serial.print(" ");
    Serial.print(b);
    Serial.print("\n");
    delay(500);  
  }
}
