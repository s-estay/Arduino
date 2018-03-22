const int pot = 0;
const int led = 9;
int a = 0;
float b;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  a = analogRead(pot);
  b = a/4.0;
  analogWrite(led, b);
}

//<pre class="brush: cpp">
//</pre>
