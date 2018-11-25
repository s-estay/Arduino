const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int numberLeds = 8;
//const int leds[] = {2, 3, 4, 5, 6, 7, 8, 12};
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int j = 0;

void setup(){
//  for(int i = 0; i < numberLeds; ++i){
//    pinMode(leds[i], OUTPUT);  
//  }
//  pinMode(13, OUTPUT);
}

void loop(){
  //blinkColor(0, 255, 255); //green
  //blinkColor(255, 0, 255); //blue
  //blinkColor(255, 255, 0); //red

  //point();

  //blue
  //analogWrite(9, 0);
  //analogWrite(11, 255);
  //test_3();


  for(int i = 0; i < 256; ++i){
    analogWrite(10, i);
    analogWrite(11, 255);
    test_5();
  }
  
  
}

void test(){
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW); //fel
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW); 
  digitalWrite(leds[4], LOW);
  digitalWrite(leds[5], LOW); //fel
  digitalWrite(leds[6], LOW);
  digitalWrite(leds[7], LOW);

  //blue
  analogWrite(9, 0);
  analogWrite(11, 255);
  
  delay(500);
  
  //green
  analogWrite(9, 255);
  analogWrite(11, 0);
  
  delay(500);
}

void test_2(){
  for(int i = 0; i < numberLeds; ++i){
    digitalWrite(leds[i], LOW);
  }
  
  digitalWrite(leds[j], HIGH);

  //blue
  analogWrite(10, 0);
  analogWrite(11, 255);

  delay(500);

  if(j < numberLeds){
    ++j;  
  }
  else{
    j = 0;
  }
}

void test_3(){ 
  digitalWrite(13, 1);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(13, 0);    // turn the LED off by making the voltage LOW
  delay(500);
}

void test_4(){
  for(int i = 0; i < 8; ++i){
    pinMode(leds[i], OUTPUT);  
  }

  analogWrite(10, 0);
  analogWrite(11, 255);
  
  digitalWrite(leds[0], 1);
  delay(500);
  digitalWrite(leds[0], 0);
  delay(500);
}

void test_5(){ 
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

void point(){
  for(int i = 0; i < numberLeds; ++i){
    chooseLed(leds[i], HIGH);
    setColourLed(255, 255, 0); //red
  }

  delay(50);

  for(int i = 0; i < numberLeds; ++i){
    chooseLed(leds[i], LOW);
  }

  delay(50);
}

void blinkColor(int r, int b, int g){
  for(int i = 0; i < numberLeds; ++i){
    chooseLed(leds[i], HIGH);
    delay(50);
    setColourLed(r, g, b);
  }

  for(int i = 0; i < numberLeds; ++i){
    chooseLed(leds[i], LOW);
    delay(50);
    setColourLed(r, g, b);
  }
}

void chooseLed(int led, uint8_t value){
  digitalWrite(led, value);
  digitalWrite(led, value);
}

void setColourLed(unsigned int red, unsigned int green, unsigned int blue){ 
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
