
//code to test TNE097 L4T3
//MSP430 sends char 'g' to Arduino
//Arduino responds with char 'r' to MSP430

char readByte;
char transmitByte = 'r';

void setup(){
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){ //send data only when you receive data:
    readByte = Serial.read(); //read the incoming byte
    if(readByte == 'g'){ //if MSP transmit 'g'
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); //toggle LED
    }
    Serial.println(transmitByte); //transmit to MSP
  }
}
