#include <math.h>

void setup()
{
  pinMode(13, OUTPUT);
  //pinMode(13, OUTPUT);
}

void loop()
{
  float val = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
  //float sinus_wave = (sin(millis()/2000.0*PI) + 1)*128.0;
  analogWrite(13, val);
  //analogWrite(13, sinus_wave);
}
