char message[3];

void setup() {
  // set baud rate then delay to give user time to open serial monitor
  Serial.begin(9600);
  delay(5000);
  Serial.print("AT");
  delay(600); //HC06 requires 500 msec for reply
  int8_t count = 0; //declare and intialize count 
  while(1) { //loop until OKsetname is read and cleared from buffer
    if(Serial.available()) {
        message[count] = Serial.read(); //read in char
        count++; 
        if(count == 2) break; //after we get all 9 char break out of loop
    }
    delay(10);
  }

  //print out each message to make sure it worked
  Serial.println("");
  Serial.println(message);
}

void loop() {
 //do nothing
  delay(50);
}

