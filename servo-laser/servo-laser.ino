
#include <Servo.h>

Servo myservo;
int angle = 0;
unsigned long pulseWidth;

void setup(){
  myservo.attach(9);

  Serial.begin(115200); // Start serial communications

  pinMode(2, OUTPUT); // Set pin 2 as trigger pin
  pinMode(3, INPUT); //Set pin 3 as monitor pin
  digitalWrite(2, LOW); // Set trigger LOW for continous read
}

void loop(){

//  center 45°
for(angle = 0; angle < 90; angle += 10){
    myservo.write(angle); 
    delay(4000);
  }
  for(angle = 90; angle >= 0; angle -= 10)
  {
    myservo.write(angle);
    delay(4000);
  }

  pulseWidth = pulseIn(3, HIGH);

  if(pulseWidth != 0){
    pulseWidth = pulseWidth / 10;
    Serial.println(pulseWidth);
  }
}

