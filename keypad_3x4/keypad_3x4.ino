int keyPin_in[4] = {9,8,7,6};    //rows
int keyPin_out[3] = {12,11,10};  //columns
int bcdPin[4] = {5,4,3,2};       //bcd output
byte seq[10][4] = {
{0,0,0,0},
{0,0,0,1},
{0,0,1,0},
{0,0,1,1},
{0,1,0,0},
{0,1,0,1},
{0,1,1,0},
{0,1,1,1},
{1,0,0,0},
{1,0,0,1},
};

void setup(){
  pinMode(13, OUTPUT);
  for(int i = 0; i < 4; i++){
    pinMode(keyPin_in[i], INPUT);
  }
  for(int i = 0; i < 3; i++){
    pinMode(keyPin_out[i], OUTPUT);
  }
  for(int i = 0; i < 4; i++){
    pinMode(bcdPin[i], OUTPUT);
  }
}

void loop()
{
  for(int i = 0; i < 3; i++){
    reset();
    digitalWrite(keyPin_out[i], LOW);
    
    if(digitalRead(keyPin_out[0]) == LOW && digitalRead(keyPin_in[0]) == LOW){
        display(1);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[0]) == LOW && digitalRead(keyPin_in[1]) == LOW){
        display(4);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[0]) == LOW && digitalRead(keyPin_in[2]) == LOW){
        display(7);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[0]) == LOW && digitalRead(keyPin_in[3]) == LOW){
        start();
        delay(200);  //debounce
      }
    
    /*********/
      
    if(digitalRead(keyPin_out[1]) == LOW && digitalRead(keyPin_in[0]) == LOW){
        display(2);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[1]) == LOW && digitalRead(keyPin_in[1]) == LOW){
        display(5);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[1]) == LOW && digitalRead(keyPin_in[2]) == LOW){
        display(8);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[1]) == LOW && digitalRead(keyPin_in[3]) == LOW){
        display(0);
        delay(200);  //debounce
      }
      
          /*********/
      
    if(digitalRead(keyPin_out[2]) == LOW && digitalRead(keyPin_in[0]) == LOW){
        display(3);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[2]) == LOW && digitalRead(keyPin_in[1]) == LOW){
        display(6);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[2]) == LOW && digitalRead(keyPin_in[2]) == LOW){
        display(9);
        delay(200);  //debounce
      }
      
    if(digitalRead(keyPin_out[2]) == LOW && digitalRead(keyPin_in[3]) == LOW){
        start();
        delay(200);  //debounce
      }
  }
}
     
void reset(){
   for(int j = 0; j < 3; j++){
     digitalWrite(keyPin_out[j], HIGH);
   }
}

void display(int number){
  for(int i = 0; i < 4; i++){
    digitalWrite(bcdPin[i], seq[number][i]);
  }
}

void start(){
  for(int i = 0; i < 3; i++){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}
