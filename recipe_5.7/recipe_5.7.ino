const int potPin = 0;
int ledPin = 9;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int val;
  int percent;
  
  val = analogRead(potPin);
  percent = map(val, 0, 1023, 0, 100);
  
  digitalWrite(ledPin, HIGH);
  delay(percent);
  digitalWrite(ledPin, LOW);
  delay(100 - percent);
  Serial.println(percent);
}
