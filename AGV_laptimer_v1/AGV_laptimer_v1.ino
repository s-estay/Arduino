/*
 *  AGV laptimer
 *  Created by Sebastian Estay https://github.com/sfinrod - 14 May 2017
 *  
 *  Credits and References:
 *    Timer: David Watts https://youtu.be/DQmMHcBvigM
 *    [1] millis() function explanation: James Lewis https://www.baldengineer.com/millis-tutorial.html
 */

// 595 shift register
const int dataPin = 11; // 595 pin 14: SER
const int latchPin = 3; // 595 pin 12: RCLK
const int clockPin = 4; // 595 pin 11: SRCLK

// segments bubble display
const int one = 7; // common cathode 1
const int two = 6; // common cathode 2
const int three = 8; // common cathode 3 
const int four = 9; // common cathode 4

const int button = 2;
const int LED = 13; // on-board LED
boolean buttonState = false;
const int interruptPin = 2;

int total = 0;
int totals[] = {0, 0, 0, 0, 0};
int numbers[] = {7, 7, 6, 8, 9};
unsigned long previousMillis = 0; 
const long interval = 84; // 84

// dp - mid (g) - top left (f) - bot left (e) - bot (d) - bot right (c) - top right (b) - top (a)
byte freakinNumbers[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

void setup(void){
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP); // internal 20k pullup resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonISR, CHANGE);
}

void dissectDigits(void);
void runDisplay(void);
void increment(void);
void resetdig(void);

void loop(void){
  dissectDigits();
  runDisplay();
  increment();
}

void dissectDigits(void){
  totals[1] = (total / 1000);
  totals[2] = ((total / 100) % 10);
  totals[3] = (total / 10) % 10;
  totals[4] = total % 10;
}

void runDisplay(void){
  for (int i = 1; i < 5; ++i){
    showdig(i, totals[i]);
  }
}

void showdig(int number, int digit){
  resetdig();
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, freakinNumbers[digit]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(numbers[number], LOW);
  delay(5);
}

void resetdig(void){
  digitalWrite(one, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(three, HIGH);
  digitalWrite(four, HIGH);
}

void increment(void){
  unsigned long currentMillis = millis(); // [1]
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    ++total;
    if (total > 9999){
      total = 0;
    }
  }
}

// interrupt handler
void buttonISR(void){
  buttonState ^= digitalRead(button);
  if(buttonState == HIGH){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
