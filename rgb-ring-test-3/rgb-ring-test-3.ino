const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int numberLeds = 8;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 12};

void setup(){
  for(int i = 0; i < numberLeds; ++i){
    pinMode(leds[i], OUTPUT);
  }
  setColourLed(0, 0, 0);
}

void loop(){
  blinkColor(0, 255, 255); //green
  blinkColor(255, 0, 255); //blue
  blinkColor(255, 255, 0); //red

  //point();
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
