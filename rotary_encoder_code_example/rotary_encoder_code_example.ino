/* LED RingCoder Example Code
  by: Jim Lindblom
  SparkFun Electronics
  date: 5/25/11
  license: Creative Commons Share-Alike v3.0. Feel free to use this code in application you'd like
  Please attribute if you find this code useful.
  
  Big thanks to Oleg for his encoder code!
  http://www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino

  This is some fancy example code designed for SparkFun's LED Ringcoder Breakout board.
  The Ringcoder board has an illuminated rotary encoder, and a 16-LED circular bar
  graph. Two shift registers are used to illuminate the bar graph LEDs. Press the rotary
  encoder down to switch modes. Twist the knob. Get hypnotized by the LEDs. Super fancy!
  
  This example code shows how you can communicate with both the encoder and the
  shift registers. Hardware connection is as follows, but can be modified however
  you'd like:
  LED Ringcoder Board          Arduino
  -------------------          -------
   GND (ground)                  GND
    B (Encoder B)                A1
    A (Encoder A)                A0
GRN (Encoder Green LED)          3
RED (Encoder Red LED)            5
SW (Encoder push button)         6
   DAT (shift data)              7
   CLR (shift clear)             8
   CLK (shift clock)             9
  LATCH (shift latch)            10
   EN (shift enable)             11
     VCC (power)                 5V
*/

// If you use other pins for the encoder, change ENC_PORT accordingly
#define ENC_PORT PINC // Use for Analog pins
//#define ENC_PORT PIND // Use for digital pins 0-7
//#define ENC_PORT PINB // Use for digital pins 8-13

#define LED_SPEED 6  // Increasing this slows down the LED rotation speed 6 is about proporitional to encoder turn
#define MODES_AVAIL 4

// Pin definitions - Encoder:
int aPin = A0;  // Encoder A pin
int bPin = A1;  // Encoder B pin
int redPin = 5;  // Encoder's red LED - PWM enabled
int grnPin = 3;  // Encoder's green LED - PWM enabled
int swhPin = 6;  // Encoder's switch pin

// Pin definitions - Shift registers:
int enPin = 11;  // Shift registers' Output Enable pin
int latchPin = 10;  // Shift registers' rclk pin
int clkPin = 9;  // Shift registers' srclk pin
int clrPin = 8;  // shift registers' srclr pin
int datPin = 7;  // shift registers' SER pin

// Global Variables
int ledCounter = 0;
int ledIndex = 0;
int mode = 0;

void setup()
{
  // Setup encoder pins
  pinMode(aPin, INPUT);
  digitalWrite(aPin, HIGH);
  pinMode(bPin, INPUT);
  digitalWrite(bPin, HIGH);
  pinMode(redPin, OUTPUT);
  analogWrite(redPin, 0);  // Red off
  pinMode(grnPin, OUTPUT);
  analogWrite(grnPin, 0);  // Green off
  pinMode(swhPin, INPUT);
  digitalWrite(swhPin, HIGH);  // Internal pull-up
  
  // Setup shift register pins
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);  // Turn all outputs on
  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, LOW);  // start latch low
  pinMode(clkPin, OUTPUT);
  digitalWrite(clkPin, LOW);  // start sck low
  pinMode(clrPin, OUTPUT);
  digitalWrite(clrPin, HIGH);  // disable master clear
  pinMode(datPin, OUTPUT);
  digitalWrite(datPin, LOW);  // start ser low
  
  Serial.begin (115200);
  Serial.println("Start");
}

void loop()
{  
  static uint8_t counter = 0;      //this variable will be changed by encoder input
  int8_t tmpdata;
  
  if (!digitalRead(swhPin))
    mode++;  // If they press the encoder button, change mode
  if (mode == MODES_AVAIL)
    mode = 0;  // Don't go above max number of modes
  while (!digitalRead(swhPin))
    ;  // Wait for them to let go of the button
  
  tmpdata = read_encoder();  // tmpdata will store encoder state
  if( tmpdata ) {
    counter += tmpdata;
    //Serial.print("Counter value: ");
    //Serial.println(counter, DEC);  // good for debugging, bad for speed
  }
    
  if (mode == 0)
  {  // mode 0: illuminates a single led, which rotates as you turn the encoder
     // Also changes the rotary encoder led
    ledCounter += tmpdata;
    if (abs(ledCounter) == LED_SPEED)
    {
      if(ledCounter > 0)
        ledIndex--;
      else if (ledCounter < 0)
        ledIndex++;
      ledCounter = 0;
    }
      
    if (ledIndex >= 16)
      ledIndex = 0;
    else if (ledIndex < 0)
      ledIndex = 15;
      
    digitalWrite(latchPin, LOW);
    shiftOut16((0x01<<ledIndex));
    digitalWrite(latchPin, HIGH);
    
    analogWrite(redPin, 255-counter);
    analogWrite(grnPin, counter);
  }
  else if (mode == 1)
  {
    // mode 1: rotate the encoder to fill up the bar graph.
    ledCounter += tmpdata;
    if (abs(ledCounter) == LED_SPEED)
    {
      if(ledCounter > 0)
        ledIndex--;
      else if (ledCounter < 0)
        ledIndex++;
      ledCounter = 0;
    }
      
    if (ledIndex >= 17)
      ledIndex = 0;
    else if (ledIndex < 0)
      ledIndex = 16;
      
    digitalWrite(latchPin, LOW);
    shiftOut16(0xFFFF^(0xFFFF<<ledIndex));
    digitalWrite(latchPin, HIGH);
    
    analogWrite(redPin, 255-counter);
    analogWrite(grnPin, counter);
  }
  else if (mode == 2)
  {
    // mode 2: implements some kind of led counter. pretty crazy.
    analogWrite(redPin, 255-counter);
    analogWrite(grnPin, counter);
    
    digitalWrite(latchPin, LOW);
    shiftOut16(((int)counter)*257);
    digitalWrite(latchPin, HIGH);
  }
  else if (mode == 3)
  { 
    // mode 3: led bargraph has a mind of its own, just rotates endlessly
    // rotate the encoder to change its color
    // May want to increase LED_SPEED if you're using this mode
    ledCounter ++;
    //if (abs(ledCounter) == LED_SPEED)
    if (abs(ledCounter) == 100)
    {
      ledIndex++;
      ledCounter = 0;
    }
      
    if (ledIndex >= 17)
      ledIndex = 0;
    else if (ledIndex < 0)
      ledIndex = 16;
      
    digitalWrite(latchPin, LOW);
    shiftOut16((0x01<<ledIndex));
    digitalWrite(latchPin, HIGH);
    
    analogWrite(redPin, 255-counter);
    analogWrite(grnPin, counter);
  }
}

// This function'll call shiftOut twice to shift 16 bits out
void shiftOut16(uint16_t data)
{
  byte datamsb;
  byte datalsb;
  
  datamsb = (data&0xFF00)>>8;
  datalsb = data & 0xFF;
  
  shiftOut(datPin, clkPin, MSBFIRST, datamsb);
  shiftOut(datPin, clkPin, MSBFIRST, datalsb);
}
 
/* returns change in encoder state (-1,0,1) */
int8_t read_encoder()
{
  static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static uint8_t old_AB = 0;
  
  old_AB <<= 2;                   //remember previous state
  old_AB |= ( ENC_PORT & 0x03 );  //add current state
  return ( enc_states[( old_AB & 0x0f )]);
}
