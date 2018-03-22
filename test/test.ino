int dataPin = 2;
int latchPin = 3;
int clockPin = 4;
int one = 7;
int two = 6;
int three = 8;
int four = 9;
int total = 0;
int totals[] = {0, 0, 0, 0, 0};
int numbers[] = {7, 7, 6, 8, 9};
unsigned long previousMillis = 0; 
const long interval = 250;
byte freakinNumbers[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
//- dp - mid - top left - bot left - bot - bot right - top right - top

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
}

void loop() {
  dissectDigits();
  runDisplay();
  increment();
}

void increment() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    total++;
    if (total > 9999) {
      total = 0;
    }
  }
}

void runDisplay() {
  for (int i = 1; i < 5; i++) {
    showdig(i, totals[i]);
  }
}

void resetdig() {
  digitalWrite(one, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(three, HIGH);
  digitalWrite(four, HIGH);
}

void dissectDigits() {
  totals[1] = (total / 1000);
  totals[2] = ((total / 100) % 10);
  totals[3] = (total / 10) % 10;
  totals[4] = total % 10;
}

void showdig(int number, int digit) {
  resetdig();
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, freakinNumbers[digit]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(numbers[number], LOW);
  delay(5);
}

