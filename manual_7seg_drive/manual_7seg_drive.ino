

void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 0);
  delay(500);            
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 1);
  delay(500);          
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 1);
  digitalWrite(4, 0);
  delay(500);           
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 1);
  digitalWrite(4, 1);
  delay(500);      
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  digitalWrite(5, 0);
  digitalWrite(4, 0);
  delay(500);        
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  digitalWrite(5, 0);
  digitalWrite(4, 1);
  delay(500);          
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  digitalWrite(5, 1);
  digitalWrite(4, 0);
  delay(500);      
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  digitalWrite(5, 1);
  digitalWrite(4, 1);
  delay(500);         
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 0);
  delay(500);       
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 1);
  delay(500);      
}
