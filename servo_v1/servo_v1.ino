#include <Servo.h>

Servo myservo;
int angle = 0;
unsigned long pulseWidth;
int total = 0;

int L = 10;
int distance = 0;

void setup(){

  myservo.attach(9);
  
  pinMode(2, OUTPUT); // Set pin 2 as trigger pin
  pinMode(3, INPUT); //Set pin 3 as monitor pin

   digitalWrite(2, LOW); // Set trigger LOW for continous read

  Serial.begin(9600);
}

void loop(){

//  center 45°
//myservo.write(45);

int array[L]; // save values in this array
total = 0 ;



for(angle = 0; angle < 90; angle += 10){
   delay(5000);
   distance = 0;
   total = 0;
   myservo.write(angle); 
   pulseWidth = pulseIn(3, HIGH); //Count How long the pulse is high in ms.
    
    
    if(pulseWidth != 0){
      pulseWidth = pulseWidth / 10; // 10usec = 1 cm of distance
    for(int i = 0; i < 10; i++){
        array[i] = pulseWidth;

        total = total + array[i];
  }
   


  distance = total / L;
  Serial.println(distance);

  }
    }

  for(angle = 90; angle >= 0; angle -= 10){
    delay(5000);
    distance = 0;
    total = 0;
    myservo.write(angle); 
   
    
    pulseWidth = pulseIn(3, HIGH); //Count How long the pulse is high in ms.
    
    if(pulseWidth != 0){
      pulseWidth = pulseWidth / 10; // 10usec = 1 cm of distance
    for(int i = 0; i < 10; i++){
        array[i] = pulseWidth;

        total = total + array[i];
  }
   


  distance = total / L;
  Serial.println(distance);
  
  }
    
  }
  }


