
int led0 = 13;
int pwmR = 9;
int pwmG = 10;
int pwmB = 11;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(pwmG, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  for(int i = 0; i = 255; ++i){
    analogWrite(pwmR, i);
    analogWrite(pwmG, i);
    analogWrite(pwmB, i);
    }
}
