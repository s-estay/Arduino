
const int pwm_g = 10;
const int pwm_b = 11;
const int leds[] = {2};
int decC = 0;

void setup(){
  pinMode(leds[0], OUTPUT);
  digitalWrite(leds[0], HIGH);
}

void loop(){
  unsigned int gbC[2];

//  for(int decC = 0; decC < 2; ++decC){
//    int incC;    
//    if (decC == 1){
//        incC = 0;
//    }
//    else{
//      incC = decC + 1;
//    }

  
  int incC = decC == 0 ? 1 : 0;
  decC ^= decC;
     
  for(int i = 0; i < 255; ++i){
    --gbC[decC];
    ++gbC[incC];
    
    setC(gbC[0], gbC[1]);
    delay(5);
  }
}

void setC(unsigned int green, unsigned int blue){
  analogWrite(pwm_g, green);
  analogWrite(pwm_b, blue);
}
