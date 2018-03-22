
#include <math.h>
#define NOP __asm__ __volatile__ ("nop\n\t")  //delay 62.5ns on a 16MHz AtMega

const int threshold[] = {25, 50, 75, 100, 125, 150, 175, 200, 225};
const int sensorMin = 0;
const int sensorMax = 255;

int ledPins[] = {3, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int ledCount = 10;

void setup() {
  for (int i = 0; i < ledCount + 1; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  float sinus_wave = (sin(millis()/250.0*PI) + 1)*125.0;
  analogWrite(ledPins[0], sinus_wave);
  
  if (sinus_wave >= sensorMin && sinus_wave < threshold[0]) { //#1
    digitalWrite (ledPins[1], LOW);
    digitalWrite (ledPins[2], LOW);
    digitalWrite (ledPins[3], LOW);
    digitalWrite (ledPins[4], LOW);
    digitalWrite (ledPins[5], LOW);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW); 
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW);    
    }
  else
  if (sinus_wave >= threshold[0] && sinus_wave < threshold[1]) { //#2
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], LOW);
    digitalWrite (ledPins[3], LOW);
    digitalWrite (ledPins[4], LOW);
    digitalWrite (ledPins[5], LOW);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW); 
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW);
    }
  else
  if (sinus_wave >= threshold[1] && sinus_wave < threshold[2]) { //#3
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], LOW);
    digitalWrite (ledPins[4], LOW);
    digitalWrite (ledPins[5], LOW);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
  else
  if (sinus_wave >= threshold[2] && sinus_wave <= threshold[3]) { //#4
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], LOW);
    digitalWrite (ledPins[5], LOW);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
  else
  if (sinus_wave >= threshold[3] && sinus_wave < threshold[4]) {  //#5
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], LOW);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
  else
  if (sinus_wave >= threshold[4] && sinus_wave < threshold[5]) {  //#6
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], LOW);
    digitalWrite (ledPins[7], LOW);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
  else
  if (sinus_wave >= threshold[5] && sinus_wave <= threshold[6]) { //#7
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], HIGH);
    digitalWrite (ledPins[7], LOW);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
    else
  if (sinus_wave >= threshold[6] && sinus_wave <= threshold[7]) { //#8
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], HIGH);
    digitalWrite (ledPins[7], HIGH);
    digitalWrite (ledPins[8], LOW);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
    else
  if (sinus_wave >= threshold[7] && sinus_wave <= threshold[8]) { //#9
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], HIGH);
    digitalWrite (ledPins[7], HIGH);
    digitalWrite (ledPins[8], HIGH);
    digitalWrite (ledPins[9], LOW);
    digitalWrite (ledPins[10], LOW); 
    }
    else
  if (sinus_wave >= threshold[8] && sinus_wave <= threshold[9]) { //#10
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], HIGH);
    digitalWrite (ledPins[7], HIGH);
    digitalWrite (ledPins[8], HIGH);
    digitalWrite (ledPins[9], HIGH);
    digitalWrite (ledPins[10], LOW); 
    }
  else
  if (sinus_wave >= threshold[9] && sinus_wave <= sensorMax) {  //#11
    digitalWrite (ledPins[1], HIGH);
    digitalWrite (ledPins[2], HIGH);
    digitalWrite (ledPins[3], HIGH);
    digitalWrite (ledPins[4], HIGH);
    digitalWrite (ledPins[5], HIGH);
    digitalWrite (ledPins[6], HIGH);
    digitalWrite (ledPins[7], HIGH);
    digitalWrite (ledPins[8], HIGH);
    digitalWrite (ledPins[9], HIGH);
    digitalWrite (ledPins[10], HIGH); 
    }
  else
    NOP;
}



//for (int i = 0; i < ledCount; i++){
//  if (sinus_wave >= threshold[i] && sinus_wave < threshold[i + 1]) {
//    for (int j = 0; j < i; j++) {digitalWrite (ledPins[j + 1], HIGH);}
//  }
//  else
//    for (int k = 0; k < ledCount - i; k++) {digitalWrite (ledPins[k + 1], LOW);}
//  }

