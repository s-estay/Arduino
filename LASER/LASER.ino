
unsigned long pulseWidth;
int total = 0;
int average = 0;
int array[10];

void setup() {
 pinMode(2, OUTPUT);  //set pin 2 as trigger pin
 pinMode(3, INPUT);   //set pin 3 as monitor pin
 Serial.begin(9600);  //start serial communications
}

void loop() {
  total = 0;  // reset

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

  delay(3000);
}

