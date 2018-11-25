
const int pwm_g = 10;
const int pwm_b = 11;
const int nL = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int decC = 0;
byte n = B00000001;
byte a = B00000001;
int counter = 0;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < nL; ++i){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  analogWrite(pwm_g, 255);
  analogWrite(pwm_b, 0);

  byte a = bitLL();

  digitalWrite(2, bitRead(a, 7));
  digitalWrite(3, bitRead(a, 6));
  digitalWrite(4, bitRead(a, 5));
  digitalWrite(5, bitRead(a, 4));
  digitalWrite(6, bitRead(a, 3));
  digitalWrite(7, bitRead(a, 2));
  digitalWrite(8, bitRead(a, 1));
  digitalWrite(9, bitRead(a, 0));

  delay(500);

//    Serial.print(bitRead(a, 7));
//    Serial.print(bitRead(a, 6));
//    Serial.print(bitRead(a, 5));
//    Serial.print(bitRead(a, 4));
//    Serial.print(bitRead(a, 3));
//    Serial.print(bitRead(a, 2));
//    Serial.print(bitRead(a, 1));
//    Serial.print(bitRead(a, 0));
//    Serial.print("\n");
//    delay(500);

}

byte bitLL(){
  if(counter < 7){
    a = a << 1;
    counter++;
  }
  else{
   a = B00000001;
   counter = 0;
  }
  return a;
}

void bitL(){
  for(int n = 0; n < 8; ++n){
    Serial.print(bitRead(a, 7));
    Serial.print(bitRead(a, 6));
    Serial.print(bitRead(a, 5));
    Serial.print(bitRead(a, 4));
    Serial.print(bitRead(a, 3));
    Serial.print(bitRead(a, 2));
    Serial.print(bitRead(a, 1));
    Serial.print(bitRead(a, 0));
    Serial.print("\n");
    delay(500);
    a = a << 1;
  }
  a = B00000001;
}

void seq_2(){
  for(int i = 0; i < 8; ++i){
    //digitalWrite(2, n[0]);
  }
  
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
}

void fade_2(){
  unsigned int gbC[2];
  int incC = decC == 0 ? 1 : 0;
  decC ^= decC;

  for(int i = 0; i < 255; ++i){
    --gbC[decC];
    ++gbC[incC];
  
    setC(gbC[0], gbC[1]);
    delay(5);
  }
}

void seq_1(){
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);
  
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);

  delay(500);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);

  delay(500);
    
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);

  delay(500);  
}

void fade_1(){
  unsigned int gbC[2];
  for(int decC = 0; decC < 2; ++decC){
    int incC;    
    if (decC == 1){
        incC = 0;
    }
    else{
      incC = decC + 1;
    }
    for(int i = 0; i < 255; ++i){
      --gbC[decC];
      ++gbC[incC];
      
      setC(gbC[0], gbC[1]);
      delay(5);
    }
  }
}

void setC(unsigned int green, unsigned int blue){
  analogWrite(pwm_g, green);
  analogWrite(pwm_b, blue);
}
