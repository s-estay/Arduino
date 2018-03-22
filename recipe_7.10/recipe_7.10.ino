/*
   A
  ___
F|   |B
 |___|  <--G
E|   |C
 |___|
   D  o  <-- dp

B ABCDEFGdp
*/

const byte numeral[10] = {
  B11111100,  //0
  B01100000,  //1
  B11011010,  //2
  B11110010,  //3
  B01100110,  //4
  B10110110,  //5
  B10111110,  //6
  B11100000,  //7
  B11111110,  //8
  B11110110,  //9
};

const int segmentPins[8] = {5,8,9,7,6,4,2,3};  //dp,G,F,E,D,C,B,A

void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(segmentPins[i], OUTPUT);  //set segment and dp pins as output
  }
}

void loop(){
  for(int i = 0; i < 10; i++){
    showDigit(i);
    delay(1000);
  }
}

void showDigit(int number){
  boolean isBitSet;  //A boolean holds one of two values, true or false.
  
  for(int segment = 1; segment < 8; segment++){
    if(number < 0 || number > 9){
      isBitSet = false;  //turn off all the segments
    }
    else{
      isBitSet = bitRead(numeral[number], segment);  //bitRead reads a bit of a number. Syntax: bitRead(x, n). 
    }                                                //x: the number from which to read
                                                     //n: which bit to read, starting at 0 for the least-significant (rightmost) bit
    digitalWrite(segmentPins[segment], isBitSet);  //digitalWrite() writes a HIGH or a LOW value to a digital pin. Syntax: digitalWrite(pin, value)
  }
}
