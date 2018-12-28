
const int pwm_r = 11;
const int pwm_g = 10;
const int pwm_b = 9;

int counter = 0;
byte a = B00000001;

const int nL = 5;
const int leds[] = {2, 3, 4, 5, 6};

void setup(){
  setColourRgb(0,0,0);

  for(int i = 0; i < nL; ++i){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  spectrum();

  //byte a = bitSL();
//
//  digitalWrite(2, 1);
//  digitalWrite(3, 1);
//  digitalWrite(4, 1);
//  digitalWrite(5, 1);
//  digitalWrite(6, 1);
}

void spectrum(){
  unsigned int rgbColour[3];
  
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  
  
  for (int decColour = 0; decColour < 3; decColour += 1){
    int incColour = decColour == 2 ? 0 : decColour + 1;
  
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }
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

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue){
  analogWrite(pwm_r, red);
  analogWrite(pwm_g, green);
  analogWrite(pwm_b, blue);
}
