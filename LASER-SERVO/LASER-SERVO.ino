
#include <Servo.h>

Servo servo;
int angle = 0;
unsigned long pulseWidth;
int total = 0;
int average = 0;
int array[10];

void setup() {
  servo.attach(9);  //connect servo's data pin (orange) to pin 9
  pinMode(2, OUTPUT);  //set pin 2 as trigger pin
  pinMode(3, INPUT);   //set pin 3 as monitor pin
  Serial.begin(9600);  //start serial communications
}

void loop() {

  //servo.write(45); //center

  //rotate servo moturs
  for(angle = 0; angle < 90; angle += 10) {
    servo.write(angle);
    laser();
    delay(3000);
  }

  //rotate servo medurs
  for(angle = 90; angle >= 0; angle -= 10) {
    servo.write(angle);
    laser();
    delay(3000);
  }
}

void laser() {

  //reset
  average = 0;
  total = 0;
  
  //read distances and save then in array
  digitalWrite(2, LOW);  //read from laser
  for(int i = 0; i < 10; ++i) {
    pulseWidth = pulseIn(3, HIGH); //count how long the pulse is high in ms
    if(pulseWidth != 0) {  //if we get a reading that isn't zero, save it in the array
      pulseWidth = pulseWidth / 10; //10 usec = 1 cm of distance
      array[i] = pulseWidth;
    }
  }
  digitalWrite(2, HIGH);  //stop reading from laser

  //print array
  Serial.print("Distances: ");
  for(int i = 0; i < 10; ++i) {
     Serial.print(array[i]); 
     Serial.print(",");
  }
  Serial.println(); //print new line

  //print average value
  Serial.print("Average: ");
  for(int i = 0; i < 10; ++i) {
    total = total + array[i];
    average = total / 10;
  }
  Serial.print(average);
  Serial.println(); //print new line
  
}
