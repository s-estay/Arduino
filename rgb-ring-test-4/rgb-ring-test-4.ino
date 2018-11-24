const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int numberLeds = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 12};

void setup(){
}

void loop(){
  //blinkColor(0, 255, 255); //green
  //blinkColor(255, 0, 255); //blue
  //blinkColor(255, 255, 0); //red

  //point();

  test();

}

void test(){
  pinMode(leds[2], OUTPUT);

  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW); //fel
  digitalWrite(leds[2], HIGH);
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
